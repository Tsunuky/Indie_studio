/*
** EPITECH PROJECT, 2019
** C++Day01
** File description:
** BombCountDownSystem.cpp
*/

#include "Game/System.hpp"

void BombCountDown::update(std::vector<INPUT>)
{
	for (size_t j = 0; j < _Bomb->size(); j++) {
		std::cout << "j = " << '\n';
		if (_IsVisible->_storage[(*_Bomb)[j]._id] == true) {
			int time_elapsed = _TimeRemaing->_storage[(*_Bomb)[j]._id].second - _c.getTime();
			if (time_elapsed >= 3) {
				if (!music.openFromFile("media/explosion.ogg"))
					throw std::runtime_error("Could not load music");
				music.play();
				_MaxBomb->_storage[_BombOwnerShip->_storage[(*_Bomb)[j]._id]].first -= 1;
				_IsVisible->_storage[(*_Bomb)[j]._id] = false;
				BombExplode(j);
			}
		}
	}
}

int BombCountDown::CalculExplodeRadius(dot<float> tmpPos, int j, int _time)
{
	int tmpWallPos = WallPosToId(tmpPos);

	// if (tmpWallPos != -1) {
	// 	if (_IsVisible->_storage[tmpWallPos] == false) {
	// 		std::cout << "VISIBLE FALSE" << '\n';
	// 		int plopi = BombPosToId(tmpPos);
	//
	// 		if (plopi == -1)
	// 			std::cout << "BOMB NOT FOUND" << '\n';
	// 		else
	// 			std::cout << "BOMB FOUND" << '\n';
	// 	}
	// 	else
	// 		std::cout << "VISIBLE TRUE" << '\n';
	// 	if (_Destroyable->_storage[tmpWallPos] == true)
	// 		std::cout << "MUR DETRUISBLE" << '\n';
	// 	else
	// 		std::cout << "MUR NON DETRUISBLE" << '\n';
	// } else {
	// 	std::cout << "MUR NOT FOUND" << '\n';
	//
	// 	int plopi = BombPosToId(tmpPos);
	//
	// 	if (plopi == -1)
	// 		std::cout << "BOMB NOT FOUND" << '\n';
	// 	else
	// 		std::cout << "BOMB FOUND" << '\n';
	// }
	//

	if (tmpWallPos == -1 || _IsVisible->_storage[tmpWallPos] == false) {
		int tmpPosBomb = BombPosToIm(tmpPos);
		if (tmpPosBomb != -1) {
			if (!music.openFromFile("media/explosion.ogg"))
				throw std::runtime_error("Could not load music");
			music.play();
			_IsVisible->_storage[(*_Bomb)[tmpPosBomb]._id] = false;
			_MaxBomb->_storage[_BombOwnerShip->_storage[(*_Bomb)[j]._id]].first -= 1;
			BombExplode(tmpPosBomb);
		}
		_IsVisible->_storage[ExpPosToId(tmpPos)] = true;
		_TimeRemaing->_storage[ExpPosToId(tmpPos)].second = _time;
	} else if (_Destroyable->_storage[tmpWallPos] == true && _IsVisible->_storage[tmpWallPos] == true) {
		_IsVisible->_storage[tmpWallPos] = false;
		_IsVisible->_storage[ExpPosToId(tmpPos)] = true;
		_TimeRemaing->_storage[ExpPosToId(tmpPos)].second = _time;
		return 1;
	} else if (_Destroyable->_storage[tmpWallPos] == false && _IsVisible->_storage[tmpWallPos] == true) {
		return 1;
	}
	return 0;
}

void BombCountDown::BombExplode(int j)
{
	int Power = _TimeRemaing->_storage[(*_Bomb)[j]._id].first;
	dot<float> BombPos = _Position->_storage[(*_Bomb)[j]._id];
	int _time = _c.getTime();

	int plop = ExpPosToId(BombPos);
	_IsVisible->_storage[plop] = true;
	_TimeRemaing->_storage[plop].second = _time;

	for (int k = 1; k < Power; k++) {
		dot<float> tmpPos = BombPos;
		tmpPos.IncX(k);
		std::cout << "k = "<< k << '\n';
		if (CalculExplodeRadius(tmpPos, j, _time) == 1)
			break;
	}
	for (int k = 1; k < Power; k++) {
		dot<float> tmpPos = BombPos;
		tmpPos.IncX(-k);
		int tmpWallPos = WallPosToId(tmpPos);

		if (CalculExplodeRadius(tmpPos, j, _time) == 1)
			break;
	}
	for (int k = 1; k < Power; k++) {
		dot<float> tmpPos = BombPos;
		tmpPos.IncY(k);
		int tmpWallPos = WallPosToId(tmpPos);

		if (CalculExplodeRadius(tmpPos, j, _time) == 1)
			break;
	}
	for (int k = 1; k < Power; k++) {
		dot<float> tmpPos = BombPos;
		tmpPos.IncY(-k);
		int tmpWallPos = WallPosToId(tmpPos);

		if (CalculExplodeRadius(tmpPos, j, _time) == 1)
			break;
	}
}

int BombCountDown::ExpPosToId(dot<float> i) {
	for (int j = 0; j < _Explosion->size(); j++) {
		if (i == _Position->_storage[(*_Explosion)[j]._id])
			return (*_Explosion)[j]._id;
	}
	return -1;
}

int BombCountDown::WallPosToId(dot<float> i) {
	for (int j = 0; j < _Wall->size(); j++) {
		if (i == _Position->_storage[(*_Wall)[j]._id])
			return (*_Wall)[j]._id;
	}
	return -1;
}

int BombCountDown::BombPosToIm(dot<float> i) {
	for (int j = 0; j < _Bomb->size(); j++) {
		if (i == _Position->_storage[(*_Bomb)[j]._id] && _IsVisible->_storage[(*_Bomb)[j]._id] == true)
			return j;
	}
	return -1;
}

int BombCountDown::BombPosToId(dot<float> i) {
	for (int j = 0; j < _Bomb->size(); j++) {
		if (i == _Position->_storage[(*_Bomb)[j]._id] && _IsVisible->_storage[(*_Bomb)[j]._id] == true)
			return (*_Bomb)[j]._id;
	}
	return -1;
}
