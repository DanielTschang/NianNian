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
    static const std::string GetResources()
    {
        return "./resources/";
    }
    static const std::string GetFonts()
    {
        return "./Fonts/";
    }
    
private:
    std::string path;
    std::string configPath;
    std::string fontPath;
};

#endif