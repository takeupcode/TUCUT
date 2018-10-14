//
//  LogManager.h
//  TUCUT (Take Up Code Utility)
//
//  Created by Abdul Wahid Tanner on 10/28/17.
//  Copyright © 2017 Take Up Code. All rights reserved.
//

#ifndef TUCUT_Log_LogManager_h
#define TUCUT_Log_LogManager_h

#include <sstream>
#include <string>

namespace TUCUT {
namespace Log {

class LogManager
{
public:
    static LogManager * initialize (const std::string & logPath, const std::string baseName, const std::string extName = ".log");
    
    static void deinitialize ();
    
    static LogManager * instance ();
    
    std::string logFileName ();
    
    void logDebug(const std::string & message) const;
    
    void logInfo(const std::string & message) const;
    
    void logFatal(const std::string & message) const;
    
private:
    LogManager (const std::string & logFileName);
    
    std::ofstream open () const;
    
    void close (std::ofstream & fs) const;
    
    static std::string time (bool includePunctuation = true);
    
    static LogManager * mInstance;
    std::string mLogPath;
    std::string mLogFileName;
};

#define INTERNAL_TUCUTLOG_FUNC_FINAL( level ) log ## level
#define INTERNAL_TUCUTLOG_FUNC( level ) INTERNAL_TUCUTLOG_FUNC_FINAL( level )

#define TUCUTLOG(level, msg) \
do { \
    std::stringstream ss; \
    ss << msg; \
    TUCUT::Log::LogManager::instance()->INTERNAL_TUCUTLOG_FUNC(level)(ss.str()); \
} while(false)
    
} // namespace Log
} // namespace TUCUT

#endif // TUCUT_Log_LogManager_h
