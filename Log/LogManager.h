//
//  LogManager.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/28/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//
#ifndef TUCUT_Log_LogManager_h
#define TUCUT_Log_LogManager_h

#include <fstream>
#include <sstream>
#include <string>

namespace TUCUT::Log
{
  class LogManager
  {
  public:
    ~LogManager ();

    static LogManager * initialize (
      std::string const & logPath,
      std::string const baseName,
      std::string const extName = ".log");
    
    static void deinitialize ();
    
    static LogManager * instance ();
    
    std::string logFileName ();
    
    void logDebug (std::string const & message);
    
    void logInfo (std::string const & message);
    
    void logFatal (std::string const & message);
    
  private:
    LogManager () = default;
    
    void open ();
    void close ();
    
    static std::string time (bool includePunctuation = true);
    
    std::string mLogPath;
    std::string mLogFileName;
    bool mInitialized = false;
    std::ofstream mLogFile;
  };

} // namespace TUCUT::Log

#define INTERNAL_TUCUTLOG_FUNC_FINAL( level ) log ## level
#define INTERNAL_TUCUTLOG_FUNC( level ) \
  INTERNAL_TUCUTLOG_FUNC_FINAL( level )

#define TUCUTLOG(level, msg) \
do { \
    std::stringstream ss; \
    ss << msg; \
    TUCUT::Log::LogManager::instance()-> \
      INTERNAL_TUCUTLOG_FUNC(level)(ss.str()); \
} while(false)

#endif // TUCUT_Log_LogManager_h
