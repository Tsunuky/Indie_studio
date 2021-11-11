/*
** EPITECH PROJECT, 2019
** C++Day01
** File description:
** System_Ctor.cpp
*/

#include "Game/System.hpp"

CollidingSystem::CollidingSystem (EntityVecSPtr &Player, StorageSPtr<dot<float>> &Position, EntityVecSPtr &Wall,\
	EntityVecSPtr &Bomb, StorageSPtr<bool> &c,  StorageSPtr<dot<float>> &OldPosition, StorageSPtr<bool> WallPass, \
	StorageSPtr<bool> Destroyable, StorageSPtr<std::tuple<float ,std::chrono::time_point<std::chrono::system_clock> ,float>> SpeedRemaingTimeBeforeMoveAgain, StorageSPtr<bool> Dead) : \
	_Player(Player), _Position(Position), _Wall(Wall), _Bomb(Bomb), _IsVisible(c), \
	_OldPosition(OldPosition), _WallPass(WallPass), _Destroyable(Destroyable), _SpeedRemaingTimeBeforeMoveAgain(SpeedRemaingTimeBeforeMoveAgain), _Dead(Dead)
	{};

PoseBomb::PoseBomb (EntityVecSPtr &Player, StorageSPtr<dot<float>> &Position, StorageSPtr<bool> IsVisible, EntityVecSPtr &Bomb,\
	StorageSPtr<std::pair<int, int>> TimeRemaing, Chrono &c, StorageSPtr<int> FirePower, uint *num, StorageSPtr<std::string> Path, \
	StorageSPtr<dot<float>> OldPosition, StorageSPtr<std::pair<int,int>> MaxBomb, StorageSPtr<int> BombOwnerShip, StorageSPtr<bool> Dead) :
	_Player(Player), _Position(Position), _IsVisible(IsVisible), _Bomb(Bomb), _TimeRemaing(TimeRemaing), _c(c), _FirePower(FirePower), \
	_Path(Path), _OldPosition(OldPosition), _MaxBomb(MaxBomb), _BombOwnerShip(BombOwnerShip), _Dead(Dead)
	{ _num = num; };

BombCountDown::BombCountDown (StorageSPtr<bool> IsVisible, EntityVecSPtr &Bomb, StorageSPtr<std::pair<int, int>> TimeRemaing, Chrono &c, \
	StorageSPtr<dot<float>> Position, EntityVecSPtr &Explosion, EntityVecSPtr &Wall, StorageSPtr<bool> Destroyable, \
	StorageSPtr<std::pair<int,int>> MaxBomb, StorageSPtr<int> BombOwnerShip) :
	_c(c), _Bomb(Bomb), _TimeRemaing(TimeRemaing), _IsVisible(IsVisible), _Position(Position), _Explosion(Explosion), \
	_Wall(Wall), _Destroyable(Destroyable), _MaxBomb(MaxBomb), _BombOwnerShip(BombOwnerShip)
	{};

ExplosionCountDown::ExplosionCountDown (StorageSPtr<bool> IsVisible, StorageSPtr<std::pair<int, int>> TimeRemaing, Chrono &c, EntityVecSPtr &Explosion) :
	_Explosion(Explosion), _TimeRemaing(TimeRemaing), _IsVisible(IsVisible), _c(c)
	{};
