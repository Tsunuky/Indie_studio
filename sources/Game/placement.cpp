/*
** EPITECH PROJECT, 2019
** C++Day01
** File description:
** placement.cpp
*/

#include "Game/Placement.hpp"

Placement::Placement(std::vector<std::string> map, uint playerNbr)
{
        for (uint i = 0; i < map.size(); i++)
                _mapInfo.map.push_back(map[i]);
        _mapInfo.length = map[0].size();
        _mapInfo.width = map.size();
        _playerNbr = playerNbr;
        _mapInfo.firstUp = _mapInfo.length / 4;
        _mapInfo.secondUp = _mapInfo.firstUp * 3;
        _mapInfo.firstDown = _mapInfo.width / 4;
        _mapInfo.secondDown = _mapInfo.firstDown * 3;
	if (playerNbr >= 1) {
                std::cout << "(1) : " << playerNbr << "\n";
                findUpLeft();
        }
	if (playerNbr >= 2) {
                std::cout << "(2) : " << playerNbr << "\n";
                findUpRight();
        }
	if (playerNbr >= 3) {
                std::cout << "(3) : " << playerNbr << "\n";
                findDownLeft();
        }
	if (playerNbr == 4) {
                std::cout << "(4) : " << playerNbr << "\n";
                findDownRight();
        }
        std::cout << "END" << "\n";
}

int Placement::checkMap(int startX, int startY, int firstLim, int secondLim)
{
        for (int i = startX; i < firstLim; i++)
                for (int k = startY; k < secondLim; k++)
                        if (_mapInfo.map[i][k] == ' ' || _mapInfo.map[i][k] == '|')
                                return 0;
        return 1;
}
