/*
** EPITECH PROJECT, 2019
** Indie Studio
** File description:
** Parsers.hpp
*/

#ifndef __PARSER__HPP__
#define __PARSER__HPP__

// nom de map
// vecteur de string
#include <boost/algorithm/string.hpp>
#include <boost/config.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>
#include <map>

struct mapPool {
        std::string _title;
        std::map<std::string, std::string> _section;
};

class Parsers {
private:
        std::vector<mapPool> _mapParsing;
        void parseSection(const std::string &);
public:
        Parsers(std::string str) { parserConfFile(str); };
        virtual ~Parsers() = default;
        std::vector<mapPool> getAllParser() const { return _mapParsing; };
        mapPool getPartParser(int i) const { return _mapParsing[i]; };
        mapPool getPartParser(std::string str) const {
                for (uint i = 0; i < _mapParsing.size(); ++i) {
                        if (_mapParsing[i]._title == str)
                                return _mapParsing[i];
                }
                throw std::invalid_argument("Section Name doesn't know");
        };
        int getIndex(const std::string name) const {
                for (uint i = 0; i < _mapParsing.size(); ++i) {
                        if (_mapParsing[i]._title == name)
                                return i;
                }
                return -1;
        };
        void dump(void) {
                for (uint i = 0; i < _mapParsing.size(); i++) {
                        std::cerr << "VECTOR : " << i << "\n\n";
                        std::cerr << "TITLE : " << _mapParsing[i]._title << '\n';
                        std::cerr << "LIB : " << _mapParsing[i]._section["lib"] << '\n';
                        std::cerr << "GAME : " << _mapParsing[i]._section["game"] << '\n';
                        std::cerr << "LENGTH : " << _mapParsing[i]._section["length"] << '\n';
                        std::cerr << "WIDTH : " << _mapParsing[i]._section["width"] << '\n';
                        std::cerr << '\n' << "/* --------------- */" << '\n';
                }
        }
        void parserConfFile(const std::string &);
        // void parserMap(std::vector<std::string>);
};

#endif /* __PARSER__HPP__ */
