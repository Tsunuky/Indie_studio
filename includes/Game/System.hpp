/*
** EPITECH PROJECT, 2019
** C++Day01
** File description:
** System.hpp
*/

#ifndef __SYSTEM_ECS_HPP__
#define __SYSTEM_ECS_HPP__

#include <iostream>
#include <memory>
#include <thread>
#include <functional>
#include <tuple>
#include <chrono>
#include <ctime>

#include "Core/Dot.hpp"
#include "Core/ECS.hpp"
#include "Core/Enums.hpp"
#include <SFML/Audio.hpp>

template <class T>
using StorageSPtr = std::shared_ptr<Storage<T>>;
using EntityVecSPtr = std::shared_ptr<std::vector<Entity>>;
using KeyBoard = std::vector<std::map<KEYS, INPUT>>;

class Chrono {
private:
	int time;
public:
	Chrono (int _time = 300) : time(_time) {};
	void Run() {
		while (time > 0) {
			std::this_thread::sleep_for (std::chrono::seconds(1));
			time--;
			// std::cout << "time remaing = "<< time/60 << "m "<< time%60<<"s" << '\n';
		}
	};
	int getTime() { return time; };
	virtual ~Chrono () = default;
};

class Isystem {
public:
	virtual void update(std::vector<INPUT>) = 0;
	virtual ~Isystem () = default;
};

class ExplosionCountDown : public Isystem {
private:
	EntityVecSPtr _Explosion;
	StorageSPtr<std::pair<int, int>> _TimeRemaing;
	StorageSPtr<bool> _IsVisible;
	Chrono &_c;
public:
	ExplosionCountDown (StorageSPtr<bool> IsVisible, StorageSPtr<std::pair<int, int>> TimeRemaing, Chrono &c, EntityVecSPtr &Explosion);
	virtual ~ExplosionCountDown () = default;
public:
	virtual void update(std::vector<INPUT>);
};

class BombCountDown : public Isystem {
private:
	sf::Music music;
	EntityVecSPtr _Explosion;
	EntityVecSPtr _Wall;
	EntityVecSPtr _Bomb;
	Chrono &_c;
	StorageSPtr<std::pair<int, int>> _TimeRemaing;
	StorageSPtr<bool> _IsVisible;
	StorageSPtr<bool> _Destroyable;
	StorageSPtr<dot<float>> _Position;
	StorageSPtr<std::pair<int, int>> _MaxBomb;
	StorageSPtr<int> _BombOwnerShip;
private:
	int ExpPosToId(dot<float> i);
	int WallPosToId(dot<float> i);
	int BombPosToIm(dot<float> i);
	int BombPosToId(dot<float> i);
	int CalculExplodeRadius(dot<float>, int, int);
	void BombExplode(int j);
public:
	BombCountDown (StorageSPtr<bool> IsVisible, EntityVecSPtr &Bomb, StorageSPtr<std::pair<int, int>> TimeRemaing, Chrono &c, \
		StorageSPtr<dot<float>> Position, EntityVecSPtr &Explosion, EntityVecSPtr &Wall, StorageSPtr<bool> Destroyable, \
		StorageSPtr<std::pair<int,int>> MaxBomb, StorageSPtr<int> BombOwnerShip);
	virtual ~BombCountDown () = default;
public:
	virtual void update(std::vector<INPUT>);
};

class PoseBomb : public Isystem {
private:
	uint *_num;
	EntityVecSPtr _Player;
	EntityVecSPtr _Bomb;
	Chrono &_c;
	StorageSPtr<std::pair<int, int>> _TimeRemaing;
	StorageSPtr<int> _FirePower;
	StorageSPtr<dot<float>> _Position;
	StorageSPtr<dot<float>> _OldPosition;
	StorageSPtr<bool> _IsVisible;
	StorageSPtr<std::string> _Path;
	StorageSPtr<std::pair<int, int>> _MaxBomb;
	StorageSPtr<int> _BombOwnerShip;
	StorageSPtr<bool> _Dead;
private:
	int findBomb(int i);
	void check(int i, std::vector<INPUT> a);
public:
	PoseBomb (EntityVecSPtr &Player, StorageSPtr<dot<float>> &Position, StorageSPtr<bool> IsVisible, EntityVecSPtr &Bomb, \
		StorageSPtr<std::pair<int, int>> TimeRemaing, Chrono &c, StorageSPtr<int> FirePower, uint *num, StorageSPtr<std::string> Path, \
		StorageSPtr<dot<float>> OldPosition, StorageSPtr<std::pair<int,int>> MaxBomb, StorageSPtr<int> BombOwnerShip, StorageSPtr<bool> Dead);
	virtual ~PoseBomb () = default;
public:
	virtual void update(std::vector<INPUT> a);
};

class CollidingSystem : public Isystem {
private:
	EntityVecSPtr _Player;
	EntityVecSPtr _Wall;
	EntityVecSPtr _Bomb;
	StorageSPtr<dot<float>> _Position;
	StorageSPtr<dot<float>> _OldPosition;
	StorageSPtr<bool> _IsVisible;
	StorageSPtr<bool> _WallPass;
	StorageSPtr<bool> _Destroyable;
	StorageSPtr<bool> _Dead;
	StorageSPtr<std::tuple<float ,std::chrono::time_point<std::chrono::system_clock>,float>> _SpeedRemaingTimeBeforeMoveAgain;//time to wait/moment auquel je l'qi lancer / size step
private:
	void WallCollinding(int i, dot<float> tmp);
	int BombCollinding(int i, dot<float> tmp);
	void colliding(uint i, std::vector<INPUT>);
public:
	CollidingSystem (EntityVecSPtr &Player, StorageSPtr<dot<float>> &Position, EntityVecSPtr &Wall,\
		EntityVecSPtr &Bomb, StorageSPtr<bool> &c,  StorageSPtr<dot<float>> &OldPosition ,\
		StorageSPtr<bool> WallPass, StorageSPtr<bool> Destroyable, StorageSPtr<std::tuple<float ,std::chrono::time_point<std::chrono::system_clock>,float>> SpeedRemaingTimeBeforeMoveAgain, StorageSPtr<bool> Dead);
	virtual ~CollidingSystem () = default;
public:
	virtual void update (std::vector<INPUT> a);
};

class CollidingSystemExplosion : public Isystem {
private:
	EntityVecSPtr _Player;
	EntityVecSPtr _Explosion;
	StorageSPtr<dot<float>> _Position;
	StorageSPtr<bool> _IsVisible;
	StorageSPtr<bool> _Dead;
public:
	CollidingSystemExplosion (StorageSPtr<bool> IsVisible, EntityVecSPtr &Explosion, StorageSPtr<dot<float>> Position, EntityVecSPtr &Player, StorageSPtr<bool> Dead) :
	_Player(Player), _Explosion(Explosion), _Position(Position), _IsVisible(IsVisible), _Dead(Dead) {};
	virtual void update(std::vector<INPUT>) {
		for (uint i = 0; i < _Player->size(); ++i) {
			dot<float> tmp = _Position->_storage[(*_Player)[i]._id];
			for (uint j = 0; j < _Explosion->size(); ++j) {
				if (tmp == _Position->_storage[(*_Explosion)[j]._id] && _IsVisible->_storage[(*_Explosion)[j]._id] == true) {
					_IsVisible->_storage[(*_Player)[i]._id] = false;
					_Dead->_storage[(*_Player)[i]._id] = true;
				}
			}
		}
	};
	virtual ~CollidingSystemExplosion () = default;
};

class PopBuff : public Isystem {
private:
	EntityVecSPtr _Wall;
	EntityVecSPtr _PowerUp;

	StorageSPtr<dot<float>> _Position;
	StorageSPtr<bool> _IsVisible;

public:
	PopBuff (StorageSPtr<bool> IsVisible, StorageSPtr<dot<float>> Position, EntityVecSPtr Wall, EntityVecSPtr PowerUp) :
	_Wall(Wall), _PowerUp(PowerUp), _Position(Position), _IsVisible(IsVisible) {};
	virtual ~PopBuff () = default;
public:
	void update(std::vector<INPUT>) {
		for (uint i = 0; i < _PowerUp->size(); ++i) {
			dot<float> tmp = _Position->_storage[(*_PowerUp)[i]._id];
			for (uint j = 0; j < _Wall->size(); ++j) {
				if (_Position->_storage[(*_Wall)[j]._id] == tmp && _IsVisible->_storage[(*_Wall)[j]._id] == false) {
					_IsVisible->_storage[(*_PowerUp)[i]._id] = true;
				}
			}
		}
	}
};

class AddBuff : public Isystem {
private:
	EntityVecSPtr _PowerUp;
	EntityVecSPtr _Player;

	StorageSPtr<int> _TypePowerUp;//fireUp
	StorageSPtr<int> _FirePower;//fireUp
	StorageSPtr<std::pair<int, int>> _MaxBomb;//actual bomb/maxBomb
	StorageSPtr<std::tuple<float ,std::chrono::time_point<std::chrono::system_clock> ,float>> _SpeedRemaingTimeBeforeMoveAgain;//time to wait/moment auquel je l'qi lancer / size step
	StorageSPtr<dot<float>> _Position;
	StorageSPtr<bool> _IsVisible;
	StorageSPtr<bool> _WallPass;
public:
	AddBuff (EntityVecSPtr PowerUp,\
		EntityVecSPtr Player,\
		StorageSPtr<int> TypePowerUp,\
		StorageSPtr<int> FirePower,\
		StorageSPtr<std::pair<int,int>> MaxBomb,\
		StorageSPtr<dot<float>> Position,\
		StorageSPtr<bool> IsVisible,\
		StorageSPtr<bool> WallPass,\
		StorageSPtr<std::tuple<float ,std::chrono::time_point<std::chrono::system_clock>,float>> _s) : _PowerUp(PowerUp), _Player(Player), _TypePowerUp(TypePowerUp), _FirePower(FirePower), \
	_MaxBomb(MaxBomb), _SpeedRemaingTimeBeforeMoveAgain(_s), _Position(Position), _IsVisible(IsVisible), _WallPass(WallPass) {} ;
	void update(std::vector<INPUT>) {
		for (size_t i = 0; i < _PowerUp->size(); i++) {
			dot<float> tmp = _Position->_storage[(*_PowerUp)[i]._id];
			for (size_t j = 0; j < _Player->size(); j++) {
				if (_Position->_storage[(*_Player)[j]._id] == tmp && _IsVisible->_storage[(*_PowerUp)[i]._id]) {
					int type = _TypePowerUp->_storage[(*_PowerUp)[i]._id];
					auto it = std::next(_PowerUp->begin(), i);
					_PowerUp->erase(it);
					if (type == 1) {
						_MaxBomb->_storage[(*_Player)[j]._id].second += 1;
					} else if (type == 2) {
						_FirePower->_storage[(*_Player)[j]._id] += 1;
					} else if (type == 3) {
						if (std::get<0>(_SpeedRemaingTimeBeforeMoveAgain->_storage[(*_Player)[j]._id]) > 100) {
							std::get<0>(_SpeedRemaingTimeBeforeMoveAgain->_storage[(*_Player)[j]._id]) -= 100;
							std::get<2>(_SpeedRemaingTimeBeforeMoveAgain->_storage[(*_Player)[j]._id]) += 2;
						}
					} else if (type == 4)
						_WallPass->_storage[(*_Player)[j]._id] = true;
				}
			}
		}
	}
	virtual ~AddBuff () = default;
};

#endif
