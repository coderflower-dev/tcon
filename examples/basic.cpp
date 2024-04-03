#include <iostream>
#include "config.h"


int main() {
    tcon::config test;
    tcon::loadFile(test, "test.txt");
    std::cout << tcon::readValue(test, "world");
    return 0;
}
     
