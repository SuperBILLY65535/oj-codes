#include <iostream>
#include <cstring>

int main()
{
    int foo[8];
    std::cout << sizeof(foo) << ' ';
    unsigned fill = 0x7f;
    std::memset(foo, fill, sizeof(foo));
    for(auto i: foo) std::cout << i << ' ';
    return 0;
}

/*

test results:
fill = 0xff yields output 32 -1 -1 -1 -1 -1 -1 -1 -1
fill = 0x7f yields output 32 2139062143 2139062143 2139062143 2139062143 2139062143 2139062143 2139062143 2139062143
fill = 0xffffffff yields same output as fill = 0xff

*/