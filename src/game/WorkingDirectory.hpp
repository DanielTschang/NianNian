#ifndef WorkingDirectory_hpp
#define WorkingDirectory_hpp


#include <string>

#ifdef MACOS
#include "CoreFoundation/CoreFoundation.h"
#endif

class WorkingDirectory
{
public:
    WorkingDirectory();
    
    static const std::string GetWindowConfig()
    {
        return "./Config/";
    }
    static const std::string Get()
    {
        return "./resources/";
    }
    
private:
    std::string path;
    std::string configPath;
};

#endif