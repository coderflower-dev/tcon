#include <iostream>

#include <tcon.h>


int main() {
    //Init the TCON object map and file
    tcon::config test;
    //Loads the file
    tcon::loadFile(test, "example.tcon");
    //Reads from the name "world"
    std::cout << tcon::readValue(test, "world");
    std::cout << '\n';
    //Changes the value of "world" to "HELLO WORLD TEST UPDATE"
    tcon::changeValue(test, "world","HELLO WORLD TEST UPDATE");
    std::cout << tcon::readValue(test, "world");
    //Writes the changes to the TCON file
    tcon::updateFile(test);
    return 0;
}
     
