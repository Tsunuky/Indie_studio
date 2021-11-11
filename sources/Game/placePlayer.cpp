/*
** EPITECH PROJECT, 2019
** C++Day01
** File description:
** placePlayer.cpp
*/

#include "Game/Placement.hpp"

void Placement::addFirstPlayer(int startX, int startY, int firstLim, int secondLim)
{
        for (int i = startX; i < firstLim; i++) {
                for (int k = startY; k < secondLim; k++) {
                        if (_mapInfo.map[i][k] == '.') {
                                dot<float>pos(i, k, 0);
                                _places.push_back(pos);
                                return;
                        }
                }
        }
}

void Placement::addSecondPlayer(int startX, int startY, int firstLim, int secondLim)
{
        for (int i = startX; i < firstLim; i++) {
                for (int k = secondLim; k > startY; k--) {
                        if (_mapInfo.map[i][k] == '.') {
                                dot<float>pos(i, k, 0);
                                _places.push_back(pos);
                                return;
                        }
                }
        }
}

void Placement::addThirdPlayer(int startX, int startY, int firstLim, int secondLim)
{
        for (int i = startX; i >= firstLim; i--) {
                for (int k = startY; k < secondLim; k++) {
                        std::cout << _mapInfo.map[i][k];
                        if (_mapInfo.map[i][k] == '.') {
                                dot<float>pos(i, k, 0);
                                _places.push_back(pos);
                                return;
                        }
                }
        }
}

void Placement::addFourthPlayer(int startX, int startY, int firstLim, int secondLim)
{
        for (int i = startX; i > firstLim; i--) {
                for (int k = startY; k > secondLim; k--) {
                        if (_mapInfo.map[i][k] == '.') {
                                dot<float>pos(i, k, 0);
                                _places.push_back(pos);
                                return;
                        }
                }
        }
}
