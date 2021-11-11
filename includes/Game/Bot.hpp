/*
** EPITECH PROJECT, 2019
** Indie Studio
** File description:
** Bot.hpp
*/

#ifndef __BOT__HPP__
#define __BOT__HPP__

#include <iostream>
#include <vector>
#include <map>
#include "Core/Enums.hpp"
#include "Game/System.hpp"

enum MOVES {
        NONE = -2,
        DANGER,
        SPACE,
	BUFF,
        BREAKABLEWALL,
	WALL,
        BOMB,
        BOT,
        PLAYER,
        DIRECTION,
        UP,
        DOWN,
        RIGHT,
        LEFT,
};

struct pos {
        int x;
        int y;
};

struct bombPos {
        int size;
        uint length;
        uint width;
};

class Bot {
private:
	uint _id;
        pos _botPos;
	pos _oldPos;
        int _visibility;
        bool _bombeIsSet;
        INPUT _direction;
	INPUT _OldInput;
	std::vector<std::pair<int, INPUT>> _distance;
        std::vector<bombPos> _bombPos;
        std::vector<std::vector<int>> _map;

        // SETTERS
        void setPos(int x, int y) { _botPos.x = x; _botPos.y = y; }
        void setVisibility(int visibility) { _visibility = visibility; }
        void setBoolBomb(bool boolean) { _bombeIsSet = boolean; }

        // GETTERS
        pos getPos(void) const { return _botPos; }
        int getVisibility(void) const { return _visibility; }
        void getMap(std::vector<std::string> map);
        void getNumber(std::string line, uint i, uint k);
	INPUT getDirection() { return _direction; }


	INPUT statementUp();
	INPUT statementDown();
	INPUT statementLeft();
	INPUT statementRight();

        // DUMP FUNCTIONS
        void dumpBotInfo(void);
        void dumpMap(void);
        void dumpBomb(void);

        bool isSpace(int x, int y) { return _map[x][y] == 0; }
        bool isDanger(int x, int y) { return _map[x][y] == -1; }
        bool isInMapLength(int size) { return (size > _map.size() || size < 0) ? false : true; }
        bool isInMapWidth(int length, int size) {
            if (_map.size() <= length)
                return false;
            return (size > _map[length].size() || size < 0) ? false : true;
        }

	bool danger(int x, int y, int);
	int nbWall(int, int);
	INPUT botMovesBomb(void);
	bool FindUp(int, int);
        bool FindDown(int, int);
        bool FindLeft(int, int);
        bool FindRight(int, int);
        void createFirstMoves(void);
        INPUT botMoves(void);
	void putDangerZone(int bombSize, uint length, uint width);
	void findDangerZone(void);

public:
        INPUT move(void);


        Bot() = default;
        Bot(uint id, int size, int x, int y, EntityVecSPtr Player, EntityVecSPtr Wall, EntityVecSPtr Bomb, \
                EntityVecSPtr PowerUp, EntityVecSPtr Explosion, StorageSPtr<dot<float>> Position, \
                StorageSPtr<bool> IsVisible, StorageSPtr<std::pair<int,int>> TimeRemaing, \
		StorageSPtr<std::tuple<float , std::chrono::time_point<std::chrono::system_clock> ,float>> SpeedRemaingTimeBeforeMoveAgain, StorageSPtr<bool> Dead
	): _id(id), _visibility(size), _Player(Player), _Wall(Wall), _Bomb(Bomb), _PowerUp(PowerUp), \
                _Explosion(Explosion), _Position(Position), _IsVisible(IsVisible), _TimeRemaing(TimeRemaing), _SpeedRemaingTimeBeforeMoveAgain(SpeedRemaingTimeBeforeMoveAgain), _Dead(Dead) { setPos(x, y); _direction = INPUT::NO_INPUT;
			for (size_t i = 0; i < 20; i++) {
				_map.push_back({});
				for (size_t j = 0; j < 20; j++) {
					_map[i].push_back(SPACE);
				}
			}
			_bombeIsSet = false;
			_distance.push_back({0, INPUT::UP});
			_distance.push_back({0, INPUT::DOWN});
			_distance.push_back({0, INPUT::LEFT});
			_distance.push_back({0, INPUT::RIGHT});
		};
        virtual ~Bot() = default;
private:
        EntityVecSPtr _Player;
        EntityVecSPtr _Wall;
        EntityVecSPtr _Bomb;
        EntityVecSPtr _PowerUp;
        EntityVecSPtr _Explosion;
        StorageSPtr<dot<float>> _Position;
	StorageSPtr<bool> _IsVisible;
        StorageSPtr<bool> _Dead;
	StorageSPtr<std::pair<int,int>> _TimeRemaing;
	StorageSPtr<std::tuple<float , std::chrono::time_point<std::chrono::system_clock> ,float>> _SpeedRemaingTimeBeforeMoveAgain;

public:
	void actualizeMap(void);
	// 	dot<float> tmp;
	//
	// 	for (size_t i = 0; i < _map.size(); i++) {
	// 		for (size_t j = 0; j < _map[i].size(); j++) {
	// 			_map[i][j] = SPACE;
	// 		}
	// 	}
	//
	// 	// for (size_t i = 0; i < _Wall->size(); i++) {
	// 	// 	bool visible = _IsVisible->Find((*_Wall)[i]._id)->second;
	// 	// 	tmp = _Position->Find((*_Wall)[i]._id)->second;
	// 	//
	// 	// 	if (visible == true) {
	// 	// 		_map[(int)tmp.getX()][(int)tmp.getY()] = WALL;
	// 	// 	} else {
	// 	// 		std::cout << "lol" << '\n';
	// 	// 		_map[(int)tmp.getX()][(int)tmp.getY()] = SPACE;
	// 	// 	}
	// 	// }
	// 	//
	// 	// for (size_t i = 0; i < _PowerUp->size(); i++) {
	// 	// 	bool visible = _IsVisible->Find((*_PowerUp)[i]._id)->second;
	// 	//
	// 	// 	if (visible) {
	// 	// 		tmp = _Position->Find((*_PowerUp)[i]._id)->second;
	// 	// 		_map[(int)tmp.getX()][(int)tmp.getY()] = BUFF;
	// 	// 	}
	// 	// }
	// 	//
	// 	// for (size_t i = 0; i < _Bomb->size(); i++) {
	// 	// 	bool visible = _IsVisible->Find((*_Bomb)[i]._id)->second;
	// 	//
	// 	// 	if (visible) {
	// 	// 		tmp = _Position->Find((*_Bomb)[i]._id)->second;
	// 	// 		_map[(int)tmp.getX()][(int)tmp.getY()] = -_TimeRemaing->Find((*_Bomb)[i]._id)->first;
	// 	// 	}
	// 	// }
	// 	//
	// 	// for (size_t i = 0; i < _Explosion->size(); i++) {
	// 	// 	bool visible = _IsVisible->Find((*_Explosion)[i]._id)->second;
	// 	//
	// 	// 	if (visible) {
	// 	// 		tmp = _Position->Find((*_Explosion)[i]._id)->second;
	// 	// 		_map[(int)tmp.getX()][(int)tmp.getY()] = DANGER;
	// 	// 	}
	// 	// }
	// 	//
	// 	// for (size_t i = 0; i < _Player->size(); i++) {
	// 	// 	bool visible = _IsVisible->Find((*_Player)[i]._id)->second;
	// 	//
	// 	// 	if (visible) {
	// 	// 		tmp = _Position->Find((*_Player)[i]._id)->second;
	// 	// 		_map[(int)tmp.getX()][(int)tmp.getY()] = PLAYER;
	// 	// 	}
	// 	// }
	//
	// 	dumpMap();
	// }
};

#endif
