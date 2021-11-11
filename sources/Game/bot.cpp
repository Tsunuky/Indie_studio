/*
** EPITECH PROJECT, 2019
** Indie Studio
** File description:
** bot.cpp
*/

#include "Game/Bot.hpp"

void Bot::putDangerZone(int bombSize, uint length, uint width)
{
        int size = bombSize * -1;

        for (uint i = 1; i <= size && (i + length) < _map.size(); i++) {
                if (_map[length + i][width] == SPACE || _map[length + i][width] == BOT)
                        _map[i + length][width] = bombSize;
                else
                        break;
        }
        for (uint i = 1; i <= size && (i + width) < _map[length].size(); i++) {
                if (_map[length][width + i] == SPACE || _map[length][width + i] == BOT)
                        _map[length][i + width] = bombSize;
                else
                        break;
        }
        for (uint i = 1; i <= size && (width - i) >= 0; i++) {
                if (_map[length][width - i] == SPACE || _map[length][width - i] == BOT)
                        _map[length][width - i] = bombSize;
                else
                        break;
        }
        for (uint i = 1; i <= size && (length - i) >= 0; i++) {
                if (_map[length - i][width] == SPACE || _map[length - i][width] == BOT)
                        _map[length - i][width] = bombSize;
                else
                        break;
        }
}

void Bot::findDangerZone(void)
{
        for (uint i = 0; i < _map.size(); i++) {
                for (uint k = 0; k < _map[i].size(); k++) {
                        if (_map[i][k] < 0)
                                _bombPos.push_back({_map[i][k], i, k});
                }
        }
        for (uint i = 0; i < _bombPos.size(); i++)
                putDangerZone(_bombPos[i].size, _bombPos[i].length, _bombPos[i].width);
}
