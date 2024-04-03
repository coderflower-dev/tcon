#include <iostream>
#include "config.h"


int main() {
    tcon::config test;
    tcon::loadFile(test, "example.tcon");
    std::cout << tcon::readValue(test, "world");
    return 0;
}
     
