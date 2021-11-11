/*
** EPITECH PROJECT, 2019
** C++Day01
** File description:
** placeFinding.cpp
*/


#include "Game/Placement.hpp"

void Placement::findUpRight(void)
{
        _mapInfo.map[_mapInfo.firstDown][_mapInfo.secondUp] = '.';
        for (int stop = 0; stop < 10; stop++) {
                for (int x = 0; x < 10; x++) {
                        for (int y = 0; y < 10; y++) {
                                if (!isInMapLength(_mapInfo.firstDown - x - 1) || !isInMapWidth(_mapInfo.firstDown - x, _mapInfo.secondUp + y + 1))
                                        break;
                                if (_mapInfo.map[_mapInfo.firstDown - x][_mapInfo.secondUp + y] == '.' && (_mapInfo.map[_mapInfo.firstDown - x - 1][_mapInfo.secondUp + y] == ' ' || _mapInfo.map[_mapInfo.firstDown - x - 1][_mapInfo.secondUp + y] == '|')
                                && isInMapLength(_mapInfo.firstDown - x - 1))
                                        _mapInfo.map[_mapInfo.firstDown - x - 1][_mapInfo.secondUp + y] = '.';
                                if (_mapInfo.map[_mapInfo.firstDown - x][_mapInfo.secondUp + y] == '.' && (_mapInfo.map[_mapInfo.firstDown - x][_mapInfo.secondUp + y + 1] == ' ' || _mapInfo.map[_mapInfo.firstDown - x][_mapInfo.secondUp + y + 1] == '|')
                                && isInMapWidth(_mapInfo.firstDown - x, _mapInfo.secondUp + y + 1))
                                        _mapInfo.map[_mapInfo.firstDown - x][_mapInfo.secondUp + y + 1] = '.';
                                if (_mapInfo.map[_mapInfo.firstDown - x][_mapInfo.secondUp + y] == '.' && (_mapInfo.map[_mapInfo.firstDown - x + 1][_mapInfo.secondUp + y] == ' ' || _mapInfo.map[_mapInfo.firstDown - x + 1][_mapInfo.secondUp + y] == '|')
                                && isInMapLength(_mapInfo.firstDown - x + 1) && isInMapWidth(_mapInfo.firstDown - x + 1, _mapInfo.secondUp + y) && isInRangeWidth(_mapInfo.firstDown - x + 1, _mapInfo.firstDown))
                                        _mapInfo.map[_mapInfo.firstDown - x + 1][_mapInfo.secondUp + y] = '.';
                                if (_mapInfo.map[_mapInfo.firstDown - x][_mapInfo.secondUp + y] == '.' && (_mapInfo.map[_mapInfo.firstDown - x][_mapInfo.secondUp + y - 1] == ' ' || _mapInfo.map[_mapInfo.firstDown - x][_mapInfo.secondUp + y - 1] == '|')
                                && isInMapWidth(_mapInfo.firstDown - x, _mapInfo.secondUp + y - 1) && isInRangeLength(_mapInfo.secondUp - y + 1, _mapInfo.secondUp + 1))
                                        _mapInfo.map[_mapInfo.firstDown - x][_mapInfo.secondUp + y - 1] = '.';
                        }
                }
        }
        addSecondPlayer(0, _mapInfo.secondUp, _mapInfo.firstDown + 1, _mapInfo.length);
}

void Placement::findDownRight(void)
{
        _mapInfo.map[_mapInfo.secondDown][_mapInfo.secondUp] = '.';
        for (int stop = 0; stop < 10; stop++) {
                for (int x = 0; x < 10; x++) {
                        for (int y = 0; y < 10; y++) {
                                if (!isInMapLength(_mapInfo.secondDown + x + 1) || !isInMapWidth(_mapInfo.secondDown + x, _mapInfo.secondUp + y + 1))
                                        break;
                                if (_mapInfo.map[_mapInfo.secondDown + x][_mapInfo.secondUp + y] == '.' && (_mapInfo.map[_mapInfo.secondDown + x + 1][_mapInfo.secondUp + y] == ' ' || _mapInfo.map[_mapInfo.secondDown + x + 1][_mapInfo.secondUp + y] == '|')
                                && isInMapLength(_mapInfo.secondDown + x + 1) && isInMapWidth(_mapInfo.secondDown + x + 1, _mapInfo.secondUp + y))
                                        _mapInfo.map[_mapInfo.secondDown + x + 1][_mapInfo.secondUp + y] = '.';
                                if (_mapInfo.map[_mapInfo.secondDown + x][_mapInfo.secondUp + y] == '.' && (_mapInfo.map[_mapInfo.secondDown + x][_mapInfo.secondUp + y + 1] == ' ' || _mapInfo.map[_mapInfo.secondDown + x][_mapInfo.secondUp + y + 1] == '|')
                                && isInMapLength(_mapInfo.secondDown + x) && isInMapWidth(_mapInfo.secondDown + x, _mapInfo.secondUp + y + 1))
                                        _mapInfo.map[_mapInfo.secondDown + x][_mapInfo.secondUp + y + 1] = '.';
                                if (_mapInfo.map[_mapInfo.secondDown + x][_mapInfo.secondUp + y] == '.' && (_mapInfo.map[_mapInfo.secondDown + x - 1][_mapInfo.secondUp + y] == ' ' || _mapInfo.map[_mapInfo.secondDown + x - 1][_mapInfo.secondUp + y] == '|')
                                && isInMapLength(_mapInfo.secondDown + x - 1) && isInMapWidth(_mapInfo.secondDown + x - 1, _mapInfo.secondUp + y) && isInRangeWidth(_mapInfo.secondDown, _mapInfo.secondDown + x - 1))
                                        _mapInfo.map[_mapInfo.secondDown + x - 1][_mapInfo.secondUp + y] = '.';
                                if (_mapInfo.map[_mapInfo.secondDown + x][_mapInfo.secondUp + y] == '.' && (_mapInfo.map[_mapInfo.secondDown + x][_mapInfo.secondUp + y + 1] == ' ' || _mapInfo.map[_mapInfo.secondDown + x][_mapInfo.secondUp + y - 1] == '|')
                                && isInMapWidth(_mapInfo.secondDown + x, _mapInfo.secondUp + y - 1) && isInRangeLength(_mapInfo.secondUp + y - 1, _mapInfo.secondUp + 1))
                                        _mapInfo.map[_mapInfo.secondDown + x][_mapInfo.secondUp + y - 1] = '.';
                        }
                }
        }
        addFourthPlayer(_mapInfo.width - 1, _mapInfo.length - 1, _mapInfo.secondDown - 1, _mapInfo.secondUp - 1);
}

void Placement::findUpLeft(void)
{
        _mapInfo.map[_mapInfo.firstDown][_mapInfo.firstUp] = '.';
        for (int stop = 0; stop < 10; stop++){
                for (int x = 0; x < 10; x++) {
                        for (int y = 0; y < 10; y++) {
                                if (!isInMapLength(_mapInfo.firstDown - x - 1) || !isInMapWidth(_mapInfo.firstDown - x, _mapInfo.firstUp - y - 1))
                                        break;
                                if (_mapInfo.map[_mapInfo.firstDown - x][_mapInfo.firstUp - y] == '.' && (_mapInfo.map[_mapInfo.firstDown - x - 1][_mapInfo.firstUp - y] == ' '
                                || _mapInfo.map[_mapInfo.firstDown - x - 1][_mapInfo.firstUp - y] == '|') && isInMapLength(_mapInfo.firstDown - x - 1))
                                        _mapInfo.map[_mapInfo.firstDown - x - 1][_mapInfo.firstUp - y] = '.';
                                if (_mapInfo.map[_mapInfo.firstDown - x][_mapInfo.firstUp - y] == '.' && (_mapInfo.map[_mapInfo.firstDown - x][_mapInfo.firstUp - y - 1] == ' '
                                || _mapInfo.map[_mapInfo.firstDown - x][_mapInfo.firstUp - y - 1] == '|') && isInMapWidth(_mapInfo.firstDown - x, _mapInfo.firstUp - y - 1))
                                        _mapInfo.map[_mapInfo.firstDown - x][_mapInfo.firstUp - y - 1] = '.';
                                if (_mapInfo.map[_mapInfo.firstDown - x][_mapInfo.firstUp - y] == '.' && (_mapInfo.map[_mapInfo.firstDown - x + 1][_mapInfo.firstUp - y] == ' ' || _mapInfo.map[_mapInfo.firstDown - x + 1][_mapInfo.firstUp - y] == '|')
                                && isInMapLength(_mapInfo.firstDown - x + 1) && isInMapWidth(_mapInfo.firstDown - x + 1, _mapInfo.firstUp - y) && isInRangeWidth(_mapInfo.firstDown - x + 1, _mapInfo.firstDown))
                                        _mapInfo.map[_mapInfo.firstDown - x + 1][_mapInfo.firstUp - y] = '.';
                                if (_mapInfo.map[_mapInfo.firstDown - x][_mapInfo.firstUp - y] == '.' && (_mapInfo.map[_mapInfo.firstDown - x][_mapInfo.firstUp - y + 1] == ' ' || _mapInfo.map[_mapInfo.firstDown - x][_mapInfo.firstUp - y + 1] == '|')
                                && isInMapWidth(_mapInfo.firstDown - x, _mapInfo.firstUp - y - 1) && isInRangeLength(_mapInfo.firstUp - y + 1, _mapInfo.firstUp + 1))
                                        _mapInfo.map[_mapInfo.firstDown - x][_mapInfo.firstUp - y + 1] = '.';
                        }
                }
        }
        addFirstPlayer(0, 0, _mapInfo.firstDown, _mapInfo.firstUp);
}

void Placement::findDownLeft(void)
{
        _mapInfo.map[_mapInfo.secondDown][_mapInfo.firstUp] = '.';
        for  (int stop = 0; stop < 10; stop++) {
                for (int x = 0; x < 10; x++) {
                        for (int y = 0; y < 10; y++) {
                                if (!isInMapLength(_mapInfo.secondDown + x + 1) || !isInMapWidth(_mapInfo.secondDown + x, _mapInfo.firstUp - y - 1))
                                        break;
                                if (_mapInfo.map[_mapInfo.secondDown + x][_mapInfo.firstUp - y] == '.' && isInMapLength(_mapInfo.secondDown + x + 1) && isInMapWidth(_mapInfo.secondDown + x + 1, _mapInfo.firstUp - y)
                                && (_mapInfo.map[_mapInfo.secondDown + x + 1][_mapInfo.firstUp - y] == ' ' || _mapInfo.map[_mapInfo.secondDown + x + 1][_mapInfo.firstUp - y] == '|'))
                                        _mapInfo.map[_mapInfo.secondDown + x + 1][_mapInfo.firstUp - y] = '.';
                                if (_mapInfo.map[_mapInfo.secondDown + x][_mapInfo.firstUp - y] == '.' && isInMapLength(_mapInfo.secondDown + x) && isInMapWidth(_mapInfo.secondDown + x, _mapInfo.firstUp - y - 1)
                                && (_mapInfo.map[_mapInfo.secondDown + x][_mapInfo.firstUp - y - 1] == ' ' || _mapInfo.map[_mapInfo.secondDown + x][_mapInfo.firstUp - y - 1] == '|'))
                                        _mapInfo.map[_mapInfo.secondDown + x][_mapInfo.firstUp - y - 1] = '.';
                                if (_mapInfo.map[_mapInfo.secondDown + x][_mapInfo.firstUp - y] == '.' && (_mapInfo.map[_mapInfo.secondDown + x - 1][_mapInfo.firstUp - y] == ' ' || _mapInfo.map[_mapInfo.secondDown + x - 1][_mapInfo.firstUp - y] == '|')
                                && isInMapLength(_mapInfo.secondDown + x - 1) && isInMapWidth(_mapInfo.secondDown + x - 1, _mapInfo.firstUp - y) && isInRangeWidth(_mapInfo.secondDown, _mapInfo.secondDown + x - 1))
                                        _mapInfo.map[_mapInfo.secondDown + x - 1][_mapInfo.firstUp - y] = '.';
                                if (_mapInfo.map[_mapInfo.secondDown + x][_mapInfo.firstUp - y] == '.' && (_mapInfo.map[_mapInfo.secondDown + x][_mapInfo.firstUp - y + 1] == ' ' || _mapInfo.map[_mapInfo.secondDown + x][_mapInfo.firstUp - y + 1] == '|')
                                && isInMapWidth(_mapInfo.secondDown + x, _mapInfo.firstUp - y + 1) && isInRangeLength(_mapInfo.firstUp - y + 1, _mapInfo.firstUp + 1))
                                        _mapInfo.map[_mapInfo.secondDown + x][_mapInfo.firstUp - y + 1] = '.';
                        }
                }
        }
        addThirdPlayer(_mapInfo.width - 1, 0, _mapInfo.secondDown + 1, _mapInfo.firstUp);
}
