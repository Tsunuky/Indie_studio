/*
** EPITECH PROJECT, 2019
** C++Day01
** File description:
** placeDump.cpp
*/

#include "Game/Placement.hpp"

void Placement::dumpMap(void)
{
        for (int i = 0; i < _mapInfo.map.size(); i++)
                std::cout << _mapInfo.map[i] << '\n';
}

void Placement::dumpPlayers(void)
{
	std::cout << "DUMP PLAYERS : (" << _places.size() << ")\n";
        for (uint i = 0; i < _places.size(); i++)
                std::cout << "PLAYER N°" << i + 1 << " : (" << _places[i].getX() << ";" << _places[i].getY() << ")" << '\n';
}
