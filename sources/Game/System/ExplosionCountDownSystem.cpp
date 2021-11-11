/*
** EPITECH PROJECT, 2019
** C++Day01
** File description:
** ExplosionCountDownSystem.hpp
*/

#include "Game/System.hpp"

void ExplosionCountDown::update(std::vector<INPUT>)
{
	for (size_t j = 0; j < _Explosion->size(); j++) {
		if (_IsVisible->_storage[(*_Explosion)[j]._id] == true) {
			int time_elapsed = _TimeRemaing->_storage[(*_Explosion)[j]._id].second - _c.getTime();
			if (time_elapsed >= 1) {
				std::cout << time_elapsed << '\n';
				_IsVisible->_storage[(*_Explosion)[j]._id] = false;
			}
		}
	}
}
