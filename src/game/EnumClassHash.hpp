
#ifndef NIANNIAN_ENUMCLASSHASH_HPP
#define NIANNIAN_ENUMCLASSHASH_HPP


#include <iostream>

struct EnumClassHash
{
    template <typename T>
    std::size_t operator()(T t) const
    {
        return static_cast<std::size_t>(t);
    }
};


#endif //NIANNIAN_ENUMCLASSHASH_HPP
