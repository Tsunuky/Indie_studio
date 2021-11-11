/*
** EPITECH PROJECT, 2019
** Indie Studio
** File description:
** Parsers.hpp
*/

#ifndef __PLACEMENT__HPP__
#define __PLACEMENT__HPP__

#include <iostream>
#include <string>
#include <vector>

#include "Core/Dot.hpp"
#include "Bot.hpp"




struct mapInfo {
        int length;
        int width;
        int firstUp;
        int secondUp;
        int firstDown;
        int secondDown;
        std::vector<std::string> map;
};
#endif /* __PLACEMENT__HPP__ */

class Placement
{
private:
        std::vector<dot<float>> _places;
        mapInfo _mapInfo;
        uint _playerNbr;

public:
        bool isInMapLength(int size) { return (size > _mapInfo.map.size() || size < 0) ? false : true; }
        bool isInMapWidth(int length, int size) { return (size > _mapInfo.map[length].size() || size < 0) ? false : true; }
        bool isInRangeWidth(int firstX, int secondX) { return firstX <= secondX; }
        bool isInRangeLength(int firstY, int secondY) { return firstY < secondY; }

        void dumpMap(void);
        void dumpPlayers(void);

	dot<float> getPlace(int player) {
                _places[player].setZ(0);
                return _places[player];
        };

        int checkMap(int, int, int, int);

        void addFirstPlayer(int, int, int, int);
        void addThirdPlayer(int, int, int, int);
        void addFourthPlayer(int, int, int, int);
        void addSecondPlayer(int, int, int, int);

        void findUpLeft(void);
        void findUpRight(void);
        void findDownLeft(void);
        void findDownRight(void);

        Placement(std::vector<std::string>, uint);
        virtual ~Placement() = default;
};
