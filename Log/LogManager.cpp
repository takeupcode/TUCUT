//
//  LogManager.cpp
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/28/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#include "LogManager.h"

#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <stdexcept>

namespace TUCUT {
namespace Log {

LogManager * LogManager::mInstance = nullptr;

LogManager::LogManager (const std::string & logFileName)
: mLogFileName(logFileName)
{ }

void LogManager::initialize (const std::string & logFileName)
{
    if (mInstance)
    {
        throw std::logic_error("LogManager is already initialized.");
    }
    
    mInstance = new LogManager(logFileName);
}

void LogManager::deinitialize ()
{
    if (!mInstance)
    {
        throw std::logic_error("LogManager must be initialized.");
    }
    
    delete mInstance;
    mInstance = nullptr;
}

LogManager * LogManager::instance ()
{
    if (!mInstance)
    {
        throw std::logic_error("LogManager must be initialized.");
    }

    return mInstance;
}

void LogManager::logDebug(const std::string & message) const
{
    std::ofstream fs = open();
    
    fs << time() << " debug=\"true\" message=\"" << message << "\"\n";
    
    close (fs);
}

void LogManager::logInfo(const std::string & message) const
{
    std::ofstream fs = open();
    
    fs << time() << " info=\"true\" message=\"" << message << "\"\n";
    
    close (fs);
}

void LogManager::logFatal(const std::string & message) const
{
    std::ofstream fs = open();
    
    fs << time() << " fatal=\"true\" message=\"" << message << "\"\n";
    
    close (fs);
    
    exit(1);
}

std::ofstream LogManager::open () const
{
    std::ofstream fs(mLogFileName, std::ios_base::app);
    if (fs.fail())
    {
        std::string message = "Could not open ";
        message += mLogFileName;
        throw std::runtime_error(message);
    }
    
    return fs;
}

void LogManager::close (std::ofstream & fs) const
{
    fs.close();
}

std::string LogManager::time () const
{
    auto timeNow = std::chrono::system_clock::now();
    
    auto timeSinceEpoch = timeNow.time_since_epoch();
    auto secondsSinceEpoch = std::chrono::duration_cast<std::chrono::seconds>(timeSinceEpoch);
    auto fraction = timeSinceEpoch - secondsSinceEpoch;
    auto milli = std::chrono::duration_cast<std::chrono::milliseconds>(fraction);
    
    auto timetNow = std::chrono::system_clock::to_time_t(timeNow);
    
    char dtBuffer[30];
    strftime(dtBuffer, sizeof(dtBuffer), "%Y-%m-%dT%H:%M:%S:", localtime(&timetNow));
    
    std::stringstream ss;
    ss << dtBuffer << std::setfill('0') << std::setw(3) << milli.count();
    return ss.str();
}

} // namespace Log
} // namespace TUCUT
