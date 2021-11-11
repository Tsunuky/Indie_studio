/*
** EPITECH PROJECT, 2019
** Indie Studio
** File description:
** botGetters.cpp
*/

#include "Game/Bot.hpp"
//
// void Bot::getMap2(std::vector<std::string> map)
// {
//         for (uint i = 0; i < map.size(); i++) {
//                 for (uint k = 0; k < map[i].size(); k++) {
//                         if (map[i][k] == 'X')
//                                 _map[i][k] = WALL;
//                         if (map[i][k] == '|')
//                                 _map[i][k] = BREAKABLEWALL;
//                         if (map[i][k] == ' ')
//                                 _map[i][k] = SPACE;
//                         if (map[i][k] == 'B') {
//                                 _map[i][k] = BOT;
//                                 _botPos.x = i;
//                                 _botPos.y = k;
//                         }
//                         if (map[i][k] == 'P')
//                                 _map[i][k] = PLAYER;
//                         if (map[i][k] <= '9' && map[i][k] >= '0')
//                                 getNumber(map[i], i, k);
//                 }
//         }
//         findDangerZone();
// }

void Bot::getMap(std::vector<std::string> map)
{
        for (uint i = 0; i < map.size(); i++) {
                _map.push_back({});
                for (uint k = 0; k < map[i].size(); k++) {
                        if (map[i][k] == 'X')
                                _map[i].push_back(WALL);
                        if (map[i][k] == '|')
                                _map[i].push_back(BREAKABLEWALL);
                        if (map[i][k] == ' ')
                                _map[i].push_back(SPACE);
                        if (map[i][k] == 'B') {
                                _map[i].push_back(BOT);
                                _botPos.x = i;
                                _botPos.y = k;
                        }
                        if (map[i][k] == 'P')
                                _map[i].push_back(PLAYER);
                        if (map[i][k] <= '9' && map[i][k] >= '0')
                                getNumber(map[i], i, k);
                }
        }
        findDangerZone();
}

void Bot::getNumber(std::string line, uint i, uint k)
{
        const char *newLine = line.c_str();
        int number = newLine[k] - '0';

        _map[i].push_back(number * -1);
}
