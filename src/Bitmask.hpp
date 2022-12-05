#pragma once

#include <stdint.h>

class Bitmask
{
public:
    Bitmask();
    void SetMask(Bitmask& other); 

    uint32_t GetMask() const; 
    
    // Returns true if bit at pos is 1(=1), else false.
    bool GetBit(int pos) const; 
   
    // Sets bit at specified pos to 1 or 0 (true or false).
    void SetBit(int pos, bool on);
	
    // Sets bit at pos to 1.
    void SetBit(int pos); 
	
    // Sets bit at pos to 0.
    void ClearBit(int pos);
    
    // Sets all bits to 0.
    void Clear(); 
    
private:
    uint32_t bits; // 1.
};