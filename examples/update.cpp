#include <iostream>

#include "config.h"


int main() {
    tcon::config test;
    tcon::loadFile(test, "example.tcon");
    std::cout << tcon::readValue(test, "world");
    std::cout << '\n';
    tcon::changeValue(test, "world","HELLO WORLD TEST UPDATE");
    std::cout << tcon::readValue(test, "world");
    tcon::updateFile(test);
    return 0;
}
     
