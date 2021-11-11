/*
** EPITECH PROJECT, 2019
** Indie Studio
** File description:
** bot.cpp
*/

#include "Game/Bot.hpp"

void Bot::dumpBotInfo(void)
{
        std::cout << "BOT POS (X, Y) : (" << _botPos.x << ", " << _botPos.y << ")" << std::endl;
        std::cout << "BOT VISIBILITY : " << _visibility << std::endl;
        std::cout << "BOT BOMB SET : ";
        _bombeIsSet ? std::cout << "TRUE" << std::endl : std::cout << "FALSE" << std::endl;
        std::cout << "DIRECTION OF THE BOT : ";
        if (_direction == INPUT::NO_INPUT)
                std::cout << "NO MOVES" << std::endl;
        else if (_direction == INPUT::UP)
                std::cout << "UP" << std::endl;
        else if (_direction == INPUT::DOWN)
                std::cout << "DOWN" << std::endl;
        else if (_direction == INPUT::RIGHT)
                std::cout << "RIGHT" << std::endl;
        else if (_direction == INPUT::LEFT)
                std::cout << "LEFT" << std::endl;
}

void Bot::dumpMap(void)
{
        for (uint i = 0; i < _map.size(); i++) {
                for (uint k = 0; k < _map[i].size(); k++)
                        std::cout << _map[i][k] << '\t';
                std::cout << std::endl << std::endl;
        }
}

void Bot::dumpBomb(void)
{
        for (uint i = 0; i < _bombPos.size(); i++) {
                std::cout << "BOMB SIZE = " << _bombPos[i].size << " | BOMB LENGTH = ";
                std::cout << _bombPos[i].length << " | BOMB WIDTH = " << _bombPos[i].width << std::endl;
        }
}
