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
    static void initialize (const std::string & logFileName);
    
    static void deinitialize ();
    
    static LogManager * instance ();
    
    void logDebug(const std::string & message) const;
    
    void logInfo(const std::string & message) const;
    
    void logFatal(const std::string & message) const;
    
private:
    LogManager (const std::string & logFileName);
    
    std::ofstream open () const;
    
    void close (std::ofstream & fs) const;
    
    std::string time () const;
    
    static LogManager * mInstance;
    std::string mLogFileName;
};

#define INTERNAL_TUCUTLOG_FUNC_FINAL( level ) log ## level
#define INTERNAL_TUCUTLOG_FUNC( level ) INTERNAL_TUCUTLOG_FUNC_FINAL( level )

#define TUCUTLOG(level, msg) \
do { \
    std::stringstream ss; \
    ss << msg; \
    LogManager::instance()->INTERNAL_TUCUTLOG_FUNC(level)(ss.str()); \
} while(false)
    
} // namespace Log
} // namespace TUCUT

#endif // TUCUT_Log_LogManager_h
