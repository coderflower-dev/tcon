#include <iostream>
#include <tcon.h>


int main() {
    //Inits the TCON object map and file
    tcon::config test;
    //Loads the file "example.tcon"
    tcon::loadFile(test, "example.tcon");
    //Reads from the name "world"
    std::cout << tcon::readValue(test, "world");
    return 0;
}
     
