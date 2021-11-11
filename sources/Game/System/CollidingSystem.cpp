/*
** EPITECH PROJECT, 2019
** C++Day01
** File description:
** CollidingSystem.cpp
*/

#include "Game/System.hpp"

void CollidingSystem::colliding(uint i, std::vector<INPUT> a)
{
	using namespace std;
	using namespace chrono;

	dot<float> tmp = {0, 0, 0};
	tmp = _Position->_storage[(*_Player)[i]._id];

	_OldPosition->_storage[(*_Player)[i]._id] = _Position->_storage[(*_Player)[i]._id];

	if (_Dead->_storage[(*_Player)[i]._id] == true)
		return;
	auto end = std::chrono::system_clock::now();
	float elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds> (end-std::get<1>(_SpeedRemaingTimeBeforeMoveAgain->_storage[(*_Player)[i]._id])).count();

	// std::cout << elapsed_seconds << " < "<<  std::get<0>(_SpeedRemaingTimeBeforeMoveAgain->_storage[(*_Player)[i]._id]) << '\n';
	if (elapsed_seconds < std::get<0>(_SpeedRemaingTimeBeforeMoveAgain->_storage[(*_Player)[i]._id]))
		return;

	if (a[i] == INPUT::LEFT) {
		tmp.setY(tmp.getY()+1);
		if (BombCollinding(i, tmp) == 0)
			WallCollinding(i, tmp);
	} else if (a[i] == INPUT::RIGHT) {
		tmp.setY(tmp.getY()-1);
		if (BombCollinding(i, tmp) == 0)
			WallCollinding(i, tmp);
	} else if (a[i] == INPUT::UP) {
		tmp.setX(tmp.getX()+1);
		if (BombCollinding(i, tmp) == 0)
			WallCollinding(i, tmp);
	} else if (a[i] == INPUT::DOWN) {
		tmp.setX(tmp.getX()-1);
		if (BombCollinding(i, tmp) == 0)
			WallCollinding(i, tmp);
	}
}

void CollidingSystem::update(std::vector<INPUT> a)
{
	for (uint i = 0; i < _Player->size(); ++i) {
		colliding(i, a);
	}
};

void CollidingSystem::WallCollinding(int i, dot<float> tmp)
{
	for (uint j = 0; j < _Wall->size(); ++j) {
		if (_Position->_storage[(*_Wall)[j]._id] == tmp && _IsVisible->_storage[(*_Wall)[j]._id] == true) {
			if (_Destroyable->_storage[(*_Wall)[j]._id] == true && _WallPass->_storage[(*_Player)[i]._id])
				break;
			return;
		}
	}
	std::get<1>(_SpeedRemaingTimeBeforeMoveAgain->_storage[(*_Player)[i]._id]) = std::chrono::system_clock::now();
	_Position->_storage[(*_Player)[i]._id] = tmp;
}

int CollidingSystem::BombCollinding(int i, dot<float> tmp)
{
	for (uint j = 0; j < _Bomb->size(); ++j) {
		if (_Position->_storage[(*_Bomb)[j]._id] == tmp &&
		_IsVisible->_storage[(*_Bomb)[j]._id] == true) {
			return 1;
		}
	}
	return 0;
}
