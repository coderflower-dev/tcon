#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>



//LOW LEVEL FUNCTIONS

std::vector<std::string> split(std::string stringToSplit, char delimeter) {
    std::vector<std::string> parsedData;
    std::string parsed;
    for (int i = 0; i < stringToSplit.length(); i++) {
        if(stringToSplit[i] == delimeter) {
            parsedData.push_back(parsed);
            parsed = "";
        }
        else {
            parsed += stringToSplit[i];
        }
    }
    if (!parsed.empty()) { // Make sure to add the last segment if it's not empty
        parsedData.push_back(parsed);
    }
    return parsedData;
}

std::string fileread(std::string filePath)
{
    std::string text;
    std::ifstream read(filePath);
    std::ostringstream ss;
    ss << read.rdbuf(); // reading data
    text = ss.str();
    return text;
}

//API
namespace tcon
{
    
    struct config
    {
        std::string filecontents;
        std::map<std::string, std::string> object;
    };

    void loadFile(config& configFile, const std::string& filePath) {
        configFile.filecontents = fileread(filePath);
        std::vector<std::string> lines = split(configFile.filecontents, '\n');
        for (const auto& element : lines) {
            auto parse = split(element, '=');
            if (parse.size() == 2) { // Ensure there is a key and a value
                configFile.object[parse[0]] = parse[1];
            }
        }
    }

    std::string readValue(tcon::config configFile, std::string name)
    {
        return configFile.object[name];
    }
}
