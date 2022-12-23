//
// Created by danchang11 on 2022/12/20.
//

#ifndef NIANNIAN_UTILS_HPP
#define NIANNIAN_UTILS_HPP

#include <iostream>

class Utilities
{
public:
    // Used answers from: https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
    //TODO: not robust. Only correctly handles whole positive numbers.
    static inline bool IsInteger(const std::string & s)
    {
        if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

        char * p;
        strtol(s.c_str(), &p, 10);
        return (*p == 0);
    }
};

#endif //NIANNIAN_UTILS_HPP
