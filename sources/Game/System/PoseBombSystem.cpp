/*
** EPITECH PROJECT, 2019
** C++Day01
** File description:
** PoseBombSystem.cpp
*/

#include "Game/System.hpp"

void PoseBomb::check(int i, std::vector<INPUT> a)
{
	if (_Dead->_storage[(*_Player)[i]._id] == true)
		return;
	if (a[i] == INPUT::BOMB && _MaxBomb->_storage[(*_Player)[i]._id].first < _MaxBomb->_storage[(*_Player)[i]._id].second) {
		for (size_t j = 0; j < _Bomb->size(); j++) {
			if (_Position->_storage[(*_Bomb)[j]._id] == _Position->_storage[(*_Player)[i]._id] && _IsVisible->_storage[(*_Bomb)[j]._id] == true) {
				return;
			}
		}
		std::cout << "BOMB POSER" << '\n';
		*_num+=1;
		_Bomb->push_back({*_num, {0}});
		_Position->AddComponent(*_num, _Position->_storage[(*_Player)[i]._id]);
		_OldPosition->AddComponent(*_num, _Position->_storage[(*_Player)[i]._id]);
		_Path->AddComponent(*_num, "./media/Bomb.obj");
		_TimeRemaing->AddComponent(*_num, {_FirePower->_storage[(*_Player)[i]._id], _c.getTime()});
		_IsVisible->AddComponent(*_num, true);
		_BombOwnerShip->AddComponent(*_num, (*_Player)[i]._id);
		_MaxBomb->_storage[(*_Player)[i]._id].first++;
	}
}

void PoseBomb::update(std::vector<INPUT> a)
{
	for (uint i = 0; i < _Player->size(); ++i) {
		check(i, a);
	}
}

int PoseBomb::findBomb(int i)
{
	dot<float> PlayerPos = _Position->_storage[(*_Player)[i]._id];

	for (size_t j = 0; j < _Bomb->size(); j++) {
		if (_Position->_storage[(*_Bomb)[j]._id] == PlayerPos)
			return j;
		}
	return 0;
}
