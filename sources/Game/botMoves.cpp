/*
** EPITECH PROJECT, 2019
** Indie Studio
** File description:
** botMoves.cpp
*/

#include "Game/Bot.hpp"

void Bot::createFirstMoves(void)
{
    	_map[_botPos.x][_botPos.y] = DIRECTION;
    	if (isInMapLength(_botPos.x + 1) && isInMapWidth(_botPos.x + 1, _botPos.y) && _map[_botPos.x + 1][_botPos.y] == SPACE)
        	_map[_botPos.x + 1][_botPos.y] = DIRECTION;
    	if (isInMapLength(_botPos.x) && isInMapWidth(_botPos.x, _botPos.y + 1) && _map[_botPos.x][_botPos.y + 1] == SPACE)
        	_map[_botPos.x][_botPos.y + 1] = DIRECTION;
    	if (isInMapLength(_botPos.x - 1) && isInMapWidth(_botPos.x - 1, _botPos.y) && _map[_botPos.x - 1][_botPos.y] == SPACE)
        	_map[_botPos.x - 1][_botPos.y] = DIRECTION;
    	if (isInMapLength(_botPos.x) && isInMapWidth(_botPos.x, _botPos.y - 1) && _map[_botPos.x][_botPos.y - 1] == SPACE)
        	_map[_botPos.x][_botPos.y - 1] = DIRECTION;
}

bool Bot::FindUp(int x, int y)
{
	int i = 0;

	_distance[0].first = 0;
	if (_map[x][y] == WALL) {
		std::cout << "------------------> UP : BUMP IN A WALL" << '\n';
		return false;
	}
	for (int rangeX = 0; rangeX < _visibility; rangeX++) {
    		for (int rangeY = 0; rangeY < _visibility; rangeY++) {
			if (!isInMapLength(x + rangeX) || !isInMapWidth(x + rangeX, y + rangeY) || !isInMapWidth(x + rangeX, y - rangeY)) {
				if (_map[x][y] == DIRECTION || _map[x][y] == SPACE)
					return true;
				std::cout << "NOT IN MAP UP" << '\n';
				return false;
			}
        		if (_map[x + rangeX][y + rangeY] == PLAYER || _map[x - rangeX][y + rangeY] == BUFF)
				return true;

        		if (_map[x + rangeX][y + rangeY] == SPACE || _map[x + rangeX][y + rangeY] == DIRECTION) { // UP::UP
				_map[x + rangeX][y + rangeY] = DIRECTION;
				_distance[0].first++;
			}
        		if (_map[x + rangeX][y + rangeY] == SPACE || _map[x + rangeX][y + rangeY] == DIRECTION) {// UP::LEFT
             			_map[x + rangeX][y + rangeY] = DIRECTION;
				_distance[0].first++;
			}
        		if (_map[x + rangeX][y - rangeY] == SPACE || _map[x + rangeX][y - rangeY] == DIRECTION) {// UP::RIGHT
            			_map[x + rangeX][y - rangeY] = DIRECTION;
				_distance[0].first++;
			}
        		if (_map[x - rangeX][y + rangeY] == SPACE || _map[x - rangeX][y + rangeY] == DIRECTION) {// UP::DOWN
            			_map[x - rangeX][y + rangeY] = DIRECTION;
				_distance[0].first++;
			}
    		}
		if ((i++) >= _visibility)
			break;
	}
	std::cout << "END FCT UP" << '\n';
	_direction = INPUT::UP;
    	return false;
}

bool Bot::FindDown(int x, int y)
{
	int i = 0;

	_distance[1].first = 0;
	if (_map[x][y] == WALL) {
		std::cout << "------------------> DOWN : BUMP IN A WALL" << '\n';
		return false;
	}
	for (int rangeX = 0; rangeX < _visibility; rangeX++) {
    		for (int rangeY = 0; rangeY < _visibility; rangeY++) {
			if (!isInMapLength(x - rangeX) || !isInMapWidth(x - rangeX, y + rangeY) || !isInMapWidth(x - rangeX, y - rangeY)) {
				if (_map[x][y] == DIRECTION || _map[x][y] == SPACE)
					return true;
				std::cout << "NOT IN MAP DOWN" << '\n';
				return false;
			}
        		if (_map[x - rangeX][y + rangeY] == PLAYER || _map[x - rangeX][y + rangeY] == BUFF)
				return true;
        		if (_map[x - rangeX][y + y] == SPACE || _map[x - rangeX][y + y] == DIRECTION) {// DOWN::DOWN
				_map[x - rangeX][y + rangeY] = DIRECTION;
				_distance[1].first++;
			}
        		if (_map[x - rangeX][y - rangeY] == SPACE || _map[x - rangeX][y - rangeY] == DIRECTION) {// DOWN::LEFT
            			_map[x - rangeX][y - rangeY] = DIRECTION;
				_distance[1].first++;
			}
        		if (_map[x - rangeX][y + rangeY] == SPACE || _map[x - rangeX][y + rangeY] == DIRECTION) {// DOWN::RIGHT
            			_map[x - rangeX][y + rangeY] = DIRECTION;
				_distance[1].first++;
			}
        		if (_map[x - rangeX][y + rangeY] == SPACE || _map[x - rangeX][y + rangeY] == DIRECTION) {// DOWN::UP
            			_map[x - rangeX][y + rangeY] = DIRECTION;
				_distance[1].first++;
			}
    		}
		if ((i++) >= _visibility)
			break;
	}
	_direction = INPUT::DOWN;
	std::cout << "END FCT DOWN" << '\n';
    	return false;
}

bool Bot::FindRight(int x, int y)
{
	int i = 0;

	_distance[3].first = 0;
	if (_map[x][y] == WALL) {
		std::cout << "------------------> RIGHT : BUMP IN A WALL" << '\n';
		return false;
	}
	for (int rangeX = 0; rangeX < _visibility; rangeX++) {
    		for (int rangeY = 0; rangeY < _visibility; rangeY++) {
			if (!isInMapLength(x + rangeX) || !isInMapLength(x - rangeX) || !isInMapWidth(x + rangeX, y + rangeY) || !isInMapWidth(x - rangeX, y + rangeY)) {
				if (_map[x][y] == DIRECTION || _map[x][y] == SPACE)
					return true;
				std::cout << "NOT IN MAP RIGHT" << '\n';
				return false;
			}
        		if (_map[x - rangeX][y + rangeY] == PLAYER || _map[x - rangeX][y + rangeY] == BUFF)
				return true;
        		if (_map[rangeX - rangeX][y + rangeY] == SPACE || _map[rangeX - rangeX][y + rangeY] == DIRECTION) {// DOWN::DOWN
				_map[x - rangeX][y + rangeY] = DIRECTION;
				_distance[3].first++;
			}
        		if (_map[x - rangeX][y - rangeY] == SPACE || _map[x - rangeX][y - rangeY] == SPACE == DIRECTION) { // DOWN::LEFT
            			_map[x - rangeX][y - rangeY] = DIRECTION;
				_distance[3].first++;
			}
        		if (_map[x - rangeX][y + rangeY] == SPACE || _map[x - rangeX][y + rangeY] == DIRECTION) { // DOWN::RIGHT
            			_map[x - rangeX][y + rangeY] = DIRECTION;
				_distance[3].first++;
			}
        		if (_map[x + rangeX][y + rangeY] == SPACE || _map[x + rangeX][y + rangeY] == DIRECTION) { // DOWN::UP
            			_map[x + rangeX][y + rangeY] = DIRECTION;
				_distance[3].first++;
			}
		}
		if ((i++) >= _visibility)
			break;
	}
	_direction = INPUT::RIGHT;
	std::cout << "END FCT RIGHT" << '\n';
    	return false;
}

bool Bot::FindLeft(int x, int y)
{
	int i = 0;

	_distance[2].first = 0;
	if (_map[x][y] == WALL) {
		std::cout << "------------------> LEFT : BUMP IN A WALL" << '\n';
		return false;
	}
	for (int rangeX = 0; rangeX < _visibility; rangeX++) {
    		for (int rangeY = 0; rangeY < _visibility; rangeY++) {
			if (!isInMapLength(x + rangeX) || !isInMapLength(x - rangeX) || !isInMapWidth(x + rangeX, y - rangeY) || !isInMapWidth(x - rangeX, y - rangeY)) {
				if (_map[x][y] == DIRECTION || _map[x][y] == SPACE)
					return true;
				std::cout << "NOT IN MAP LEFT" << '\n';
				return false;
			}
        		if (_map[x - rangeX][y + rangeY] == PLAYER || _map[x - rangeX][y + rangeY] == BUFF)
				return true;
        		if ((_map[rangeX - rangeX][y + rangeY] == SPACE || _map[rangeX - rangeX][y + rangeY] == DIRECTION)) { // DOWN::DOWN
				_map[x - rangeX][y + rangeY] = DIRECTION;
				_distance[2].first++;
			}
        		if (_map[x - rangeX][y - rangeY] == SPACE || _map[x - rangeX][y - rangeY] == DIRECTION) { // DOWN::LEFT
            			_map[x - rangeX][y - rangeY] = DIRECTION;
				_distance[2].first++;
			}
        		if (_map[x - rangeX][y + rangeY] == SPACE || _map[x - rangeX][y + rangeY] == DIRECTION) { // DOWN::RIGHT
            			_map[x - rangeX][y + rangeY] = DIRECTION;
				_distance[2].first++;
			}
        		if (_map[x + rangeX][y + rangeY] == SPACE || _map[x + rangeX][y + rangeY] == DIRECTION) { // DOWN::UP
            			_map[x + rangeX][y + rangeY] = DIRECTION;
				_distance[2].first++;
			}
    		}
		if ((i++) >= _visibility)
			break;
	}
	_direction = INPUT::LEFT;
	std::cout << "END FCT LEFT" << '\n';
    	return false;
}

bool Bot::danger(int x, int y, int op)
{
	if (op == 0) {
		if (_map[_botPos.x + 1][_botPos.y] < 0 || _map[_botPos.x + 1][_botPos.y] == DANGER)
			return true;
		return false;
	}
	if (op == 1) {
		if (_map[_botPos.x - 1][_botPos.y] < 0 || _map[_botPos.x - 1][_botPos.y] == DANGER)
			return true;
		return false;
	}
	if (op == 2) {
	  	if (_map[_botPos.x][_botPos.y - 1] < 0 || _map[_botPos.x][_botPos.y - 1] == DANGER)
			return true;
		return false;
  	}
	if (op == 3) {
		if (_map[_botPos.x][_botPos.y + 1] < 0 || _map[_botPos.x][_botPos.y + 1] == DANGER)
			return true;
		return false;
	}
	return false;
}

INPUT Bot::statementRight()
{
	if (FindRight(_botPos.x, _botPos.y + 1) && !danger(_botPos.x, _botPos.y, 3)) {
		std::cout << "RIGHT" << '\n';
		if (_oldPos.x == _botPos.x && _oldPos.y == _botPos.y + 1) {
			_oldPos.x = _botPos.x;
			_oldPos.y = _botPos.y;
			return INPUT::NO_INPUT;
		}
		_oldPos.x = _botPos.x;
		_oldPos.y = _botPos.y;
		_botPos.y++;
		return INPUT::RIGHT;
	}
	return INPUT::NO_INPUT;
}

INPUT Bot::statementLeft()
{
	if (FindLeft(_botPos.x, _botPos.y - 1) && !danger(_botPos.x, _botPos.y, 2)) {
		std::cout << "LEFT" << '\n';
		if (_oldPos.x == _botPos.x && _oldPos.y == _botPos.y - 1) {
			return statementRight();
		}
		_oldPos.x = _botPos.x;
		_oldPos.y = _botPos.y;
		_botPos.y--;
		return INPUT::LEFT;
	}
	return statementRight();
}

INPUT Bot::statementDown()
{
	if (FindDown(_botPos.x - 1, _botPos.y) && !danger(_botPos.x, _botPos.y, 1)) {
		std::cout << "DOWN" << '\n';
		if (_oldPos.x == _botPos.x - 1 && _oldPos.y == _botPos.y) {
			return statementLeft();
		}
		_oldPos.x = _botPos.x;
		_oldPos.y = _botPos.y;
		_botPos.x--;
		return INPUT::DOWN;
	}
	return statementLeft();
}

INPUT Bot::statementUp()
{
	if (FindUp(_botPos.x + 1, _botPos.y) && !danger(_botPos.x, _botPos.y, 0)) {
		std::cout << "UP" << '\n';
		if (_oldPos.x == _botPos.x + 1 && _oldPos.y == _botPos.y) {
			return statementDown();
		}
		_oldPos.x = _botPos.x;
		_oldPos.y = _botPos.y;
		_botPos.x++;
		return INPUT::UP;
	}
	return statementDown();
}

INPUT Bot::botMoves(void)
{
	int direction;
	int tmp;

	_direction = INPUT::NO_INPUT;
	if (_map[_botPos.x][_botPos.y] == SPACE && (danger(_botPos.x, _botPos.y, 0) || danger(_botPos.x, _botPos.y, 1)
	|| danger(_botPos.x, _botPos.y, 2) || danger(_botPos.x, _botPos.y, 3)))
		return INPUT::NO_INPUT;
	return statementUp();

	// direction = (_distance[0].first <= _distance[1].first ? _distance[1].first : _distance[0].first);
	// tmp = (_distance[2].first <= _distance[3].first ? _distance[3].first : _distance[2].first);
	// direction = (direction <= tmp ? tmp : direction);
	// for (uint i = 0; i < _distance.size(); i++)
	// 	if (direction == _distance[i].first) {
	// 		if (_distance[i].second == _OldInput) {
	// 			_OldInput = INPUT::NO_INPUT;
	// 			return INPUT::NO_INPUT;
	// 		}
	// 		return _distance[i].second;
	// 	}
	// return _direction;
}

int Bot::nbWall(int x, int y)
{
	int nb = 0;

	if (_map[_botPos.x + 1][_botPos.y] < 0 || _map[_botPos.x + 1][_botPos.y] == WALL)
		nb++;
	if (_map[_botPos.x - 1][_botPos.y] < 0 || _map[_botPos.x - 1][_botPos.y] == WALL)
		nb++;
	if (_map[_botPos.x][_botPos.y - 1] < 0 || _map[_botPos.x][_botPos.y - 1] == WALL)
		nb++;
	if (_map[_botPos.x][_botPos.y + 1] < 0 || _map[_botPos.x][_botPos.y + 1] == WALL)
		nb++;
	return nb;
}

void Bot::actualizeMap(void) {
	dot<float> tmp;

	if (_map.empty()) {
		for (uint i = 0; i < 20; i++) {
			_map.push_back({});
			for (uint k = 0; k < 20; k++) {
				_map[i].push_back({});
			}
		}
	}
	for (size_t i = 0; i < _map.size(); i++) {
		for (size_t j = 0; j < _map[i].size(); j++) {
			_map[i][j] = SPACE;
		}
	}

	for (size_t i = 0; i < _Wall->size(); i++) {
		bool visible = _IsVisible->Find((*_Wall)[i]._id)->second;
		dot<float> tmp1 = _Position->Find((*_Wall)[i]._id)->second;

		if (visible == true && tmp1.getZ() != -60) {
			_map[tmp1.getX()][tmp1.getY()] = WALL;
		}
	}

	for (size_t i = 0; i < _PowerUp->size(); i++) {
		bool visible = _IsVisible->Find((*_PowerUp)[i]._id)->second;

		if (visible) {
			tmp = _Position->Find((*_PowerUp)[i]._id)->second;
			_map[(int)tmp.getX()][(int)tmp.getY()] = BUFF;
		}
	}

	for (size_t i = 0; i < _Bomb->size(); i++) {
		bool visible = _IsVisible->Find((*_Bomb)[i]._id)->second;

		if (visible) {
			tmp = _Position->Find((*_Bomb)[i]._id)->second;
			_map[(int)tmp.getX()][(int)tmp.getY()] = -(_TimeRemaing->Find((*_Bomb)[i]._id)->second).first;
		}
	}

	for (size_t i = 0; i < _Explosion->size(); i++) {
		bool visible = _IsVisible->Find((*_Explosion)[i]._id)->second;

		if (visible) {
			tmp = _Position->Find((*_Explosion)[i]._id)->second;
			tmp.dump();
			_map[(int)tmp.getX()][(int)tmp.getY()] = DANGER;
		}
	}

	for (size_t i = 0; i < _Player->size(); i++) {
		bool visible = _IsVisible->Find((*_Player)[i]._id)->second;

		if (visible) {
			tmp = _Position->Find((*_Player)[i]._id)->second;
			_map[(int)tmp.getX()][(int)tmp.getY()] = PLAYER;
		}
	}
}

INPUT Bot::move(void)
{
	auto end = std::chrono::system_clock::now();
	float elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds> (end-std::get<1>(_SpeedRemaingTimeBeforeMoveAgain->_storage[(*_Player)[_id]._id])).count();

	if (elapsed_seconds < std::get<0>(_SpeedRemaingTimeBeforeMoveAgain->_storage[(*_Player)[_id]._id])) {
		_OldInput = INPUT::NO_INPUT;
		return INPUT::NO_INPUT;
	}
	if (_Dead->_storage[(*_Player)[_id]._id] == true)
		return INPUT::NO_INPUT;
	if (_bombeIsSet == false && nbWall(_botPos.x, _botPos.y) >= 3) {
		_bombeIsSet = true;
		_OldInput = INPUT::BOMB;
		_oldPos.x = _botPos.x;
		_oldPos.y = _botPos.y;
		return INPUT::BOMB;
	} else if (_bombeIsSet == true)
		_bombeIsSet = false;
    	_direction = botMoves();
	return _direction;

}
