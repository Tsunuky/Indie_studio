/*
** EPITECH PROJECT, 2019
** Indie Studio
** File description:
** parsers.cpp
*/

#include "Core/Parsers.hpp"

// parse line by line
// to access value : _mapParsing[x]._section["nameOfSection"]
void Parsers::parseSection(const std::string &line)
{
        std::vector<std::string> newVec;

        if (line[0] == '[') {
                _mapParsing.push_back({});
                for (uint i = 1; i < line.size(); i++) {
                        if (line[i] == ']')
                                break;
                        _mapParsing[_mapParsing.size() - 1]._title += line[i];
                }
                return;
        }
        boost::split(newVec, line, boost::algorithm::is_any_of("\t="));
        boost::algorithm::to_lower(newVec[0]);
        if (newVec[1][0] == '\"') {
                for (uint i = 0; i < newVec[1].size(); i++)
                        if (newVec[1][i] == '\"')
                                newVec[1].erase(newVec[1].begin() + i);
        }
        _mapParsing[_mapParsing.size() - 1]._section[newVec[0]] = newVec[1];
}

// open file and start parser
// remove commentary from lines before going to parseSection
void Parsers::parserConfFile(const std::string &parseFile)
{
        std::string newFile(parseFile);
        std::ifstream file(newFile);
        std::string line;

        if (!file.is_open())
                throw std::invalid_argument("Can't open init file");
        while (std::getline(file, line)) {
                if (line[0] == '#' || line == "")
                        continue;
                for (uint i = 0; i < line.size(); i++) {
                        if (line[i] == '#' || line[i] == ';') {
                                line.erase(i, line.size() - 1);
                                break;
                        }
                }
                parseSection(line);
        }
        // dump();
}
