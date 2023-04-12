//
//  LogManager.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/28/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//
#include "LogManager.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <stdexcept>

TUCUT::Log::LogManager::~LogManager ()
{
  deinitialize();
}

TUCUT::Log::LogManager * TUCUT::Log::LogManager::initialize (
  std::string const & logPath,
  std::string const baseName,
  std::string const extName)
{
  LogManager * lm = instance();
  if (lm->mInitialized)
  {
    lm->logInfo("LogManager is already initialized.");

    return lm;
  }

  std::filesystem::create_directory(logPath);

  std::filesystem::path logFileName(logPath);
  logFileName /= baseName;
  logFileName += "-" + time(false) + extName;

  lm->mLogFileName = logFileName.string();
  lm->open();
  lm->mInitialized = true;

  return lm;
}

void TUCUT::Log::LogManager::deinitialize ()
{
  LogManager * lm = instance();
  if (not lm->mInitialized)
  {
    throw std::logic_error("LogManager must be initialized.");
  }

  lm->close();
  lm->mInitialized = false;
}

TUCUT::Log::LogManager * TUCUT::Log::LogManager::instance ()
{
  static LogManager * lm = nullptr;
  if (lm == nullptr)
  {
    lm = new LogManager();
  }

  return lm;
}
    
std::string TUCUT::Log::LogManager::logFileName ()
{
  if (not mInitialized)
  {
    throw std::logic_error("LogManager must be initialized.");
  }

  return mLogFileName;
}

void TUCUT::Log::LogManager::logDebug (
  std::string const & message)
{
  if (not mInitialized)
  {
    throw std::logic_error("LogManager must be initialized.");
  }

  mLogFile << time()
    << " debug=\"true\" message=\"" << message << "\"\n";
}

void TUCUT::Log::LogManager::logInfo (
  std::string const & message)
{
  if (not mInitialized)
  {
    throw std::logic_error("LogManager must be initialized.");
  }

  mLogFile << time()
    << " info=\"true\" message=\"" << message << "\"\n";
}

void TUCUT::Log::LogManager::logFatal (
  std::string const & message)
{
  if (not mInitialized)
  {
    throw std::logic_error("LogManager must be initialized.");
  }

  mLogFile << time()
    << " fatal=\"true\" message=\"" << message << "\"\n";

  exit(1);
}

void TUCUT::Log::LogManager::open ()
{
  mLogFile.open(mLogFileName, std::ios_base::app);
  if (mLogFile.fail())
  {
    std::string message = "Could not open ";
    message += mLogFileName;
    throw std::runtime_error(message);
  }
}

void TUCUT::Log::LogManager::close ()
{
  mLogFile.close();
}

std::string TUCUT::Log::LogManager::time (
  bool includePunctuation)
{
  auto timeNow = std::chrono::system_clock::now();

  auto timeSinceEpoch = timeNow.time_since_epoch();
  auto secondsSinceEpoch =
    std::chrono::duration_cast<std::chrono::seconds>(
      timeSinceEpoch);
  auto fraction = timeSinceEpoch - secondsSinceEpoch;
  auto milli =
    std::chrono::duration_cast<std::chrono::milliseconds>(
      fraction);

  auto timetNow = std::chrono::system_clock::to_time_t(timeNow);

  char dtBuffer[30];
  const char * format = "%Y-%m-%dT%H:%M:%S:";
  if (!includePunctuation)
  {
    format = "%Y%m%dT%H%M%S";
  }

  strftime(dtBuffer, sizeof(dtBuffer), format,
    localtime(&timetNow));

  std::stringstream ss;
  ss << dtBuffer << std::setfill('0')
    << std::setw(3) << milli.count();
  return ss.str();
}
