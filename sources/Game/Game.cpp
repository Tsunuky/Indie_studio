/*
** EPITECH PROJECT, 2019
** C++Day01
** File description:
** Game.cpp
*/

#include "Game/Game.hpp"
#include "Game/Placement.hpp"

__attribute__((constructor))
void constructor(void){}

extern "C" Igame *getLib(void)
{
        Igame *plop = new BombermanSystem();
        return plop;
}

__attribute__((destructor))
void destructor(void){}

bool BombermanSystem::isBorder(uint k, uint l)
{
        if (k == 0 || k == _map.first.size() - 1)
                return true;
        if (l == 0 || l == _map.first[k].size() - 1)
                return true;
        return false;
}

void BombermanSystem::initGame(uint nbrPlayer, uint nbrBot, int nbrMap)
{
	MapGenerator gen;
        uint nbr = nbrPlayer + nbrBot;

	_nbrBot = nbrBot;
	_nbrPlayer = nbrPlayer;
	_map = gen.generator(2000, nbrMap);
	Placement _placement{_map.first, nbrPlayer+nbrBot};
	_placement.dumpPlayers();


	for (uint i = _num; _num < nbrPlayer + i; _num++) {
		_Player->push_back({_num, {0}});
		_Position->AddComponent(_num, _placement.getPlace(_num));
		_OldPosition->AddComponent(_num, _placement.getPlace(_num));
                if (!isBorder(_placement.getPlace(_num).getX(), _placement.getPlace(_num).getY()))
                        _map.first[_placement.getPlace(_num).getX()][_placement.getPlace(_num).getY()] = ' ';
                if (!isBorder(_placement.getPlace(_num).getX() - 1, _placement.getPlace(_num).getY()))
                        _map.first[_placement.getPlace(_num).getX() - 1][_placement.getPlace(_num).getY()] = ' ';
                if (!isBorder(_placement.getPlace(_num).getX(), _placement.getPlace(_num).getY() - 1))
                        _map.first[_placement.getPlace(_num).getX()][_placement.getPlace(_num).getY() - 1] = ' ';
                if (!isBorder(_placement.getPlace(_num).getX() + 1, _placement.getPlace(_num).getY()))
                        _map.first[_placement.getPlace(_num).getX() + 1][_placement.getPlace(_num).getY()] = ' ';
                if (!isBorder(_placement.getPlace(_num).getX(), _placement.getPlace(_num).getY() + 1))
                        _map.first[_placement.getPlace(_num).getX()][_placement.getPlace(_num).getY() + 1] = ' ';
		_Playable->AddComponent(_num, true);
		_Path->AddComponent(_num, "./media/goblin-sapper-animated-X.X");
		_IsVisible->AddComponent(_num, true);
		_FirePower->AddComponent(_num, 2);
		_MaxBomb->AddComponent(_num, {0, 1});
		_WallPass->AddComponent(_num, false);
		_SpeedRemaingTimeBeforeMoveAgain->AddComponent(_num, {600, std::chrono::system_clock::now(), 16});
		_Dead->AddComponent(_num, false);
	}
	for (uint i = _num; _num < i + nbrBot; ++_num) {
		_Player->push_back({_num, {0}});
		_Position->AddComponent(_num, _placement.getPlace(_num));
		_bot.push_back({_num, 5, (int)_placement.getPlace(_num).getX(), (int)_placement.getPlace(_num).getY(), _Player, _Wall, _Bomb, _PowerUp, _Explosion, _Position, _IsVisible, _TimeRemaing, _SpeedRemaingTimeBeforeMoveAgain, _Dead});
		_OldPosition->AddComponent(_num, _placement.getPlace(_num));
                if (!isBorder(_placement.getPlace(_num).getX(), _placement.getPlace(_num).getY()))
                        _map.first[_placement.getPlace(_num).getX()][_placement.getPlace(_num).getY()] = ' ';
                if (!isBorder(_placement.getPlace(_num).getX() - 1, _placement.getPlace(_num).getY()))
                        _map.first[_placement.getPlace(_num).getX() - 1][_placement.getPlace(_num).getY()] = ' ';
                if (!isBorder(_placement.getPlace(_num).getX(), _placement.getPlace(_num).getY() - 1))
                        _map.first[_placement.getPlace(_num).getX()][_placement.getPlace(_num).getY() - 1] = ' ';
                if (!isBorder(_placement.getPlace(_num).getX() + 1, _placement.getPlace(_num).getY()))
                        _map.first[_placement.getPlace(_num).getX() + 1][_placement.getPlace(_num).getY()] = ' ';
                if (!isBorder(_placement.getPlace(_num).getX(), _placement.getPlace(_num).getY() + 1))
                        _map.first[_placement.getPlace(_num).getX()][_placement.getPlace(_num).getY() + 1] = ' ';
		_Path->AddComponent(_num, "./media/goblin-sapper-animated-X.X");
		_Playable->AddComponent(_num, false);
		_IsVisible->AddComponent(_num, true);
		_FirePower->AddComponent(_num, 2);
		_MaxBomb->AddComponent(_num, {0, 1});
		_WallPass->AddComponent(_num, false);
		_SpeedRemaingTimeBeforeMoveAgain->AddComponent(_num, {600, std::chrono::system_clock::now(), 16});
		_Dead->AddComponent(_num, false);
		// _Hardness->AddComponent(_num, Hardness[_num - i]);
	}
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (_map.first[i][j] == ' ')
				_map.second[i][j] = '0';
		}
	}
	for (uint i = 0; i < _map.first.size(); i++) {
		for (uint j = 0; j < _map.first[i].size(); j++) {
			if (_map.first[i][j] == 'X') {
				_Wall->push_back({++_num, {0}});
				_Position->AddComponent(_num, {static_cast<float>(i), static_cast<float>(j), 0});
				_OldPosition->AddComponent(_num, {static_cast<float>(i), static_cast<float>(j), 0});
				_Size->AddComponent(_num, 20);
				_Texture->AddComponent(_num, "./media/GrassedWall.bmp");
				_IsVisible->AddComponent(_num, true);
				_Shape->AddComponent(_num, SCENE_TYPE::CUBE);
				_Destroyable->AddComponent(_num, false);
			}
			if (_map.first[i][j] == '|') {
				_Wall->push_back({++_num, {0}});
				_Position->AddComponent(_num, {static_cast<float>(i), static_cast<float>(j), 0});
				_OldPosition->AddComponent(_num, {static_cast<float>(i), static_cast<float>(j), 0});
				_Size->AddComponent(_num, 20);
				_Texture->AddComponent(_num, "./media/Crate.bmp");
				_Shape->AddComponent(_num, SCENE_TYPE::CUBE);
				_IsVisible->AddComponent(_num, true);
				_Destroyable->AddComponent(_num, true);
			}
		}
	}
	for (uint i = 0; i < _map.first.size(); i++) {
		for (uint j = 0; j < _map.first[i].size(); j++) {
			_Wall->push_back({++_num, {0}});
			_Position->AddComponent(_num, {static_cast<float>(i), static_cast<float>(j), -60});
			_OldPosition->AddComponent(_num, {static_cast<float>(i), static_cast<float>(j), -60});
			_Size->AddComponent(_num, 60);
			_Texture->AddComponent(_num, "./media/grass2.bmp");
			_Shape->AddComponent(_num, SCENE_TYPE::CUBE);
			_IsVisible->AddComponent(_num, true);
		}
	}
	for (uint i = 0; i < _map.first.size(); i++) {
		for (uint j = 0; j < _map.first[i].size(); j++) {
			_Explosion->push_back({++_num, {0}});
			_Position->AddComponent(_num, {static_cast<float>(i), static_cast<float>(j), 0});
			_OldPosition->AddComponent(_num, {static_cast<float>(i), static_cast<float>(j), 0});
			_Texture->AddComponent(_num, "./media/Red.png");
			_Size->AddComponent(_num, 20);
			_Shape->AddComponent(_num, SCENE_TYPE::CUBE);
			_TimeRemaing->AddComponent(_num, {0, 0});
			_IsVisible->AddComponent(_num, false);
		}
	}
	for (uint i = 0; i < _map.second.size(); i++) {
		for (uint j = 0; j < _map.second[i].size(); j++) {
			if (_map.second[i][j] == '1') {
				_PowerUp->push_back({++_num, {0}});
				_Position->AddComponent(_num, {static_cast<float>(i), static_cast<float>(j), 0});
				_OldPosition->AddComponent(_num, {static_cast<float>(i), static_cast<float>(j), 0});
				_Texture->AddComponent(_num, "./media/black.jpg");
				_Size->AddComponent(_num, 20);
				_Shape->AddComponent(_num, SCENE_TYPE::CUBE);
				_TimeRemaing->AddComponent(_num, {0, 0});
				_IsVisible->AddComponent(_num, false);
				_TypePowerUp->AddComponent(_num, 1); //bomb
			} else if (_map.second[i][j] == '2') {
				_PowerUp->push_back({++_num, {0}});
				_Position->AddComponent(_num, {static_cast<float>(i), static_cast<float>(j), 0});
				_OldPosition->AddComponent(_num, {static_cast<float>(i), static_cast<float>(j), 0});
				_Texture->AddComponent(_num, "./media/blue.jpg");
				_Size->AddComponent(_num, 20);
				_Shape->AddComponent(_num, SCENE_TYPE::CUBE);
				_TimeRemaing->AddComponent(_num, {0, 0});
				_IsVisible->AddComponent(_num, false);
				_TypePowerUp->AddComponent(_num, 2); //fire
			} else if (_map.second[i][j] == '3') {
				_PowerUp->push_back({++_num, {0}});
				_Position->AddComponent(_num, {static_cast<float>(i), static_cast<float>(j), 0});
				_OldPosition->AddComponent(_num, {static_cast<float>(i), static_cast<float>(j), 0});
				_Texture->AddComponent(_num, "./media/Green.jpg");
				_Size->AddComponent(_num, 20);
				_Shape->AddComponent(_num, SCENE_TYPE::CUBE);
				_TimeRemaing->AddComponent(_num, {0, 0});
				_IsVisible->AddComponent(_num, false);
				_TypePowerUp->AddComponent(_num, 3); //speed
			} else if (_map.second[i][j] == '4') {
				_PowerUp->push_back({++_num, {0}});
				_Position->AddComponent(_num, {static_cast<float>(i), static_cast<float>(j), 0});
				_OldPosition->AddComponent(_num, {static_cast<float>(i), static_cast<float>(j), 0});
				_Texture->AddComponent(_num, "./media/lgbt.jpg");
				_Size->AddComponent(_num, 20);
				_Shape->AddComponent(_num, SCENE_TYPE::CUBE);
				_TimeRemaing->AddComponent(_num, {0, 0});
				_IsVisible->AddComponent(_num, false);
				_TypePowerUp->AddComponent(_num, 4); //wallPass
			}
		}
	}
	tmp = true;

}
