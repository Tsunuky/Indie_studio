/*
** EPITECH PROJECT, 2019
** C++Day01
** File description:
** Game.hpp
*/

#ifndef __GAME__HPP__
#define __GAME__HPP__

// #include "Game.hpp"

#include <boost/algorithm/string.hpp>
#include <fstream>

#include "Game/MapGenerator.hpp"
#include "Game/ThreadPool.hpp"
#include "Game/Bot.hpp"

class Igame {
public:
	virtual ~Igame () = default;
	virtual void getInput(std::vector<INPUT>) = 0;
	virtual void Calcul(void) = 0;
	virtual Object_t getObjectByNumber(int a) = 0;
	virtual std::vector<std::vector<Entity>> getEntity(void) = 0;
	virtual void initGame(uint nbrPlayer, uint nbrBot, int) = 0;
	virtual void readData() = 0;
	virtual uint getNum() = 0;
	virtual void dump() = 0;
};

class BombermanCore : public Igame {
protected:
	uint _num = 0;
	uint _nbrPlayer, _nbrBot;

	EntityVecSPtr _Player;
	EntityVecSPtr _Wall;
	EntityVecSPtr _Bomb;
	EntityVecSPtr _PowerUp;//pos/Oldpod/visible/texture/TYPE:POWERUP
	EntityVecSPtr _Explosion;

	StorageSPtr<dot<float>> _Position;
	StorageSPtr<dot<float>> _OldPosition;

	StorageSPtr<bool> _Dead;
	StorageSPtr<bool> _Destroyable;
	StorageSPtr<bool> _Playable;
	StorageSPtr<bool> _IsVisible;
	StorageSPtr<int> _Size;

	//Attach To a player
	//-------------------------------------
	StorageSPtr<int> _TypePowerUp;//fireUp
	StorageSPtr<int> _FirePower;//fireUp
	StorageSPtr<std::tuple<float , std::chrono::time_point<std::chrono::system_clock> ,float>> _SpeedRemaingTimeBeforeMoveAgain;//time to wait/moment auquel je l'qi lancer / size step
	StorageSPtr<std::pair<int, int>> _MaxBomb;//actual bomb/maxBomb
	StorageSPtr<int> _BombOwnerShip;
	StorageSPtr<bool> _WallPass;

	StorageSPtr<std::pair<int,int>> _TimeRemaing;
	StorageSPtr<std::string> _Texture;
	StorageSPtr<std::string> _Path;
	StorageSPtr<SCENE_TYPE> _Shape;

	// StorageSPtr<int> _Hardness;
	std::pair<std::vector<std::string>, std::vector<std::string>> _map;

	std::vector<INPUT> _Input;
	std::vector<Bot> _bot;
public:
	BombermanCore () {
		_Player = std::make_shared<std::vector<Entity>>();
		_Wall = std::make_shared<std::vector<Entity>>();
		_Bomb = std::make_shared<std::vector<Entity>>();
		_PowerUp = std::make_shared<std::vector<Entity>>();
		_Explosion = std::make_shared<std::vector<Entity>>();

		_Position = std::make_shared<Storage<dot<float>>>();
		_OldPosition = std::make_shared<Storage<dot<float>>>();

		_Dead = std::make_shared<Storage<bool>>();
		_Destroyable = std::make_shared<Storage<bool>>();
		_Playable = std::make_shared<Storage<bool>>();
		_IsVisible = std::make_shared<Storage<bool>>();
		_Size = std::make_shared<Storage<int>>();

		_TypePowerUp = std::make_shared<Storage<int>>();
		_FirePower = std::make_shared<Storage<int>>();
		_SpeedRemaingTimeBeforeMoveAgain = std::make_shared<Storage<std::tuple<float ,std::chrono::time_point<std::chrono::system_clock> ,float>>>();
		_MaxBomb = std::make_shared<Storage<std::pair<int, int>>>();
		_BombOwnerShip = std::make_shared<Storage<int>>();
		_WallPass = std::make_shared<Storage<bool>>();

		_TimeRemaing = std::make_shared<Storage<std::pair<int,int>>>();
		_Texture = std::make_shared<Storage<std::string>>();
		_Path = std::make_shared<Storage<std::string>>();
		_Shape = std::make_shared<Storage<SCENE_TYPE>>();

		// _KeyBoardConfig = std::make_shared<std::map<KEYS, INPUT>>();
		std::cout << "BombermanCore Init" << '\n';
	};
	virtual ~BombermanCore () = default;

	virtual void getInput(std::vector<INPUT> a) {
		_Input = a;

		for (size_t i = a.size(); i < _Player->size(); i++) {
			_Input.push_back({INPUT::NO_INPUT});
		}
	};


	virtual void getNumStr(std::string line) { _num = std::stoi(line); };
	virtual void getNbrBot(std::string line) { _nbrBot = std::stoi(line); };
	virtual void getNbrPlayer(std::string line) { _nbrPlayer = std::stoi(line); };
	virtual void getPlayer(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(","));
		_Player->push_back({(uint)std::stoi(result[0]), {0}});
		for (int i = 1; i < result.size(); i++)
			_Player->push_back({(uint)std::stoi(result[i]), {0}});
	};
	virtual void getWall(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(","));
		_Wall->push_back({(uint)std::stoi(result[0]), {0}});
		for (int i = 1; i < result.size(); i++)
			_Wall->push_back({(uint)std::stoi(result[i]), {0}});
	};
	virtual void getBomb(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(","));
		_Bomb->push_back({(uint)std::stoi(result[0]), {0}});
		for (int i = 1; i < result.size(); i++)
			_Bomb->push_back({(uint)std::stoi(result[i]), {0}});
	};
	virtual void getPowerUp(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(","));
		_PowerUp->push_back({(uint)std::stoi(result[0]), {0}});
		for (int i = 1; i < result.size(); i++)
			_PowerUp->push_back({(uint)std::stoi(result[i]), {0}});
	};
	virtual void getExplosion(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(","));
		_Explosion->push_back({(uint)std::stoi(result[0]), {0}});
		for (int i = 1; i < result.size(); i++)
			_Explosion->push_back({(uint)std::stoi(result[i]), {0}});
	};

	virtual void getPos(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(",{}"));
		_Position->AddComponent(std::stoi(result[1]), {std::stof(result[2]), std::stof(result[3]), std::stof(result[4])});
		for (int i = 5; i < result.size() - 1; i += 5)
			_Position->AddComponent(std::stof(result[1 + i]), {std::stof(result[2 + i]), std::stof(result[3 + i]), std::stof(result[4 + i])});
	};
	virtual void getOldPos(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(",{}"));
		_OldPosition->AddComponent(std::stoi(result[1]), {std::stof(result[2]), std::stof(result[3]), std::stof(result[4])});
		for (int i = 5; i < result.size() - 1; i += 5)
			_OldPosition->AddComponent(std::stof(result[1 + i]), {std::stof(result[2 + i]), std::stof(result[3 + i]), std::stof(result[4 + i])});
	};

	virtual void getDead(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(",{}"));
		_Dead->AddComponent(std::stoi(result[1]), {result[2] == "1" ? true : false});
		for (int i = 3; i < result.size() - 1; i += 3)
			_Dead->AddComponent(std::stoi(result[1 + i]), {result[2 + i] == "1" ? true : false});
	};
	virtual void getDestroyable(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(",{}"));
		_Destroyable->AddComponent(std::stoi(result[1]), {result[2] == "1" ? true : false});
		for (int i = 3; i < result.size() - 1; i += 3)
			_Destroyable->AddComponent(std::stoi(result[1 + i]), {result[2 + i] == "1" ? true : false});
	};
	virtual void getPlayable(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(",{}"));
		_Playable->AddComponent(std::stoi(result[1]), {result[2] == "1" ? true : false});
		for (int i = 3; i < result.size() - 1; i += 3)
			_Playable->AddComponent(std::stoi(result[1 + i]), {result[2 + i] == "1" ? true : false});
	};
	virtual void getVisibile(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(",{}"));
		_IsVisible->AddComponent(std::stoi(result[1]), {result[2] == "1" ? true : false});
		for (int i = 3; i < result.size() - 1; i += 3)
			_IsVisible->AddComponent(std::stoi(result[1 + i]), {result[2 + i] == "1" ? true : false});
	};
	virtual void getSize(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(",{}"));
		_Size->AddComponent(std::stoi(result[1]), {std::stoi(result[2])});
		for (int i = 3; i < result.size() - 1; i += 3)
			_Size->AddComponent(std::stoi(result[1 + i]), {std::stoi(result[2 + i])});
	};

	virtual void getFirePower(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(",{}"));
		_FirePower->AddComponent(std::stoi(result[1]), {std::stoi(result[2])});
		for (int i = 3; i < result.size() - 1; i += 3)
			_FirePower->AddComponent(std::stoi(result[1 + i]), {std::stoi(result[2 + i])});
	};
	virtual void getSpeedBeforeMove(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(",{}"));
		_SpeedRemaingTimeBeforeMoveAgain->AddComponent(std::stoi(result[1]), {std::stoi(result[2]), std::chrono::system_clock::now(), std::stoi(result[4])});
		for (int i = 5; i < result.size() - 1; i += 5)
			_SpeedRemaingTimeBeforeMoveAgain->AddComponent(std::stoi(result[1 + i]), {std::stoi(result[2 + i]), std::chrono::system_clock::now(), std::stoi(result[4 + i])});
	};
	virtual void getMaxBomb(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(",{}"));
		_MaxBomb->AddComponent(std::stoi(result[1]), {std::stoi(result[2]), std::stoi(result[3])});
		for (int i = 4; i < result.size() - 1; i += 4)
			_MaxBomb->AddComponent(std::stoi(result[1 + i]), {std::stoi(result[2 + i]), std::stoi(result[3 + i])});
	};
	virtual void getBombOwnerShip(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(",{}"));
		_BombOwnerShip->AddComponent(std::stoi(result[1]), {std::stoi(result[2])});
		for (int i = 3; i < result.size() - 1; i += 3)
			_BombOwnerShip->AddComponent(std::stoi(result[1 + i]), {std::stoi(result[2 + i])});
	};
	virtual void getWallPass(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(",{}"));
		_WallPass->AddComponent(std::stoi(result[1]), {result[2] == "1" ? true : false});
		for (int i = 3; i < result.size() - 1; i += 3)
			_WallPass->AddComponent(std::stoi(result[1 + i]), {result[2 + i] == "1" ? true : false});
	};

	virtual void getTimeRemaining(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(",{}"));
		_TimeRemaing->AddComponent(std::stoi(result[1]), {std::stoi(result[2]), std::stoi(result[3])});
		for (int i = 4; i < result.size() - 1; i += 4)
			_TimeRemaing->AddComponent(std::stoi(result[1 + i]), {std::stoi(result[2 + i]), std::stoi(result[3 + i])});
	};
	virtual void getTexture(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(",{}"));
		_Texture->AddComponent(std::stoi(result[1]), {result[2]});
		for (int i = 3; i < result.size() - 1; i += 3)
			_Texture->AddComponent(std::stoi(result[1 + i]), {result[2 + i]});
	};
	virtual void getPath(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(",{}"));
		_Path->AddComponent(std::stoi(result[1]), {result[2]});
		for (int i = 3; i < result.size() - 1; i += 3)
			_Path->AddComponent(std::stoi(result[1 + i]), {result[2 + i]});
	};
	virtual void getShape(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(",{}"));
		_Shape->AddComponent(std::stoi(result[1]), static_cast<SCENE_TYPE>(std::stoi(result[2])));
		for (int i = 3; i < result.size() - 1; i += 3)
			_Shape->AddComponent(std::stoi(result[1 + i]), static_cast<SCENE_TYPE>(std::stoi(result[2 + i])));
	};

	virtual void getMapFirst(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(","));
		for (int i = 0; i < result.size(); i++)
			_map.first.push_back({result[i]});
	};
	virtual void getMapSecond(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(","));
		for (int i = 0; i < result.size(); i++)
			_map.second.push_back({result[i]});
	};
	virtual void getInput(std::string line)
	{
		std::vector<std::string> result;
		boost::split(result, line, boost::is_any_of(",{}"));
		for (int i = 0; i < result.size(); i++)
			_Input.push_back(static_cast<INPUT>(std::stoi(result[i]) ) );
	};

	void readData()
	{
		std::string line;
		std::ifstream fd("./../save/bomberman.save");

		if (!fd.is_open())
			exit(84);
		// EntityVecSPtr
		getline(fd, line); // 1
		getNumStr(line);
		getline(fd, line); // 1
		getNbrBot(line);
		getline(fd, line); // 1
		getNbrPlayer(line);
		getline(fd, line); // 2
		getPlayer(line);
		getline(fd, line); // 3
		getWall(line);
		getline(fd, line); // 4
		getBomb(line);
		getline(fd, line); // 5
		getPowerUp(line);
		getline(fd, line); // 6
		getExplosion(line);

		// StorageSPtr<dot<float>>
		getline(fd, line); // 7
		getPos(line);
		getline(fd, line); // 8
		getOldPos(line);

		// StorageSPtr
		getline(fd, line); // 9
		getDead(line);
		getline(fd, line); // 9
		getDestroyable(line);
		getline(fd, line); // 10
		getPlayable(line);
		getline(fd, line); // 11
		getVisibile(line);
		getline(fd, line); // 12
		getSize(line);

		getline(fd, line); // 13
		getFirePower(line);
		getline(fd, line); // 14
		getSpeedBeforeMove(line);
		getline(fd, line); // 15
		getMaxBomb(line);
		getline(fd, line); // 16
		getBombOwnerShip(line);
		getline(fd, line); // 17
		getWallPass(line);

		// StorageSPtr
		getline(fd, line); // 18
		getTimeRemaining(line);
		getline(fd, line); // 19
		getTexture(line);
		getline(fd, line); // 20
		getPath(line);
		getline(fd, line); // 21
		getShape(line);

		getline(fd, line); // 22
		getMapFirst(line);
		getline(fd, line); // 22b
		getMapSecond(line);
		getline(fd, line); // 23
		getInput(line);
	};

	virtual void writeData(void)
	{
		std::ofstream outfile("./../save/bomberman.save", std::ios::out | std::ios::trunc);
		outfile << _num << std::endl; // 1
		outfile << _nbrBot << std::endl; // 1
		outfile << _nbrPlayer << std::endl; // 1
		for (uint i = 0; i < _Player->size(); i++) {
			outfile << (*_Player)[i]._id;
			i < _Player->size() - 1 ? outfile << ',' : outfile << std::endl;
		} // 2
		for (uint i = 0; i < _Wall->size(); i++) {
			outfile << (*_Wall)[i]._id;
			i < _Wall->size() - 1 ? outfile << ',' : outfile << std::endl;
		} // 3
		for (uint i = 0; i < _Bomb->size(); i++) {
			outfile << (*_Bomb)[i]._id;
			i < _Bomb->size() - 1 ? outfile << ',' : outfile << std::endl;
		} // 4
		// outfile << 2 << std::endl;
		for (uint i = 0; i < _PowerUp->size(); i++) { // 5
			outfile << (*_PowerUp)[i]._id;
			i < _PowerUp->size() - 1 ? outfile << ',' : outfile << std::endl;
		}
		for (uint i = 0; i < _Explosion->size(); i++) {
			outfile << (*_Explosion)[i]._id;
			i < _Explosion->size() - 1 ? outfile << ',' : outfile << std::endl;
		} // 6

		for (auto it : _Position->_storage) {
			outfile << "{";
			outfile << it.first;
			outfile << ",";
			outfile << it.second.getX();
			outfile << ",";
			outfile << it.second.getY();
			outfile << ",";
			outfile << it.second.getZ();
			outfile << "}";
		} // 7
		outfile << std::endl;
		for (auto it : _OldPosition->_storage) {
			outfile << "{";
			outfile << it.first;
			outfile << ",";
			outfile << it.second.getX();
			outfile << ",";
			outfile << it.second.getY();
			outfile << ",";
			outfile << it.second.getZ();
			outfile << "}";
		} // 8
		outfile << std::endl;

		for (auto it : _Dead->_storage) {
			outfile << "{";
			outfile << it.first;
			outfile << ",";
			it.second ? outfile << "1" : outfile << "0";
			outfile << "}";
		}
		outfile << std::endl;
		for (auto it : _Destroyable->_storage) {
			outfile << "{";
			outfile << it.first;
			outfile << ",";
			it.second ? outfile << "1" : outfile << "0";
			outfile << "}";
		} // 9
		outfile << std::endl;
		for (auto it : _Playable->_storage) {
			outfile << "{";
			outfile << it.first;
			outfile << ",";
			it.second ? outfile << "1" : outfile << "0";
			outfile << "}";
		} // 10
		outfile << std::endl;
		for (auto it : _IsVisible->_storage) {
			outfile << "{";
			outfile << it.first;
			outfile << ",";
			it.second ? outfile << "1" : outfile << "0";
			outfile << "}";
		} // 11
		outfile << std::endl;
		for (auto it : _Size->_storage) {
			outfile << "{";
			outfile << it.first;
			outfile << ",";
			outfile << it.second;
			outfile << "}";
		} // 12
		outfile << std::endl;

		for (auto it : _FirePower->_storage) {
			outfile << "{";
			outfile << it.first;
			outfile << ",";
			outfile << it.second;
			outfile << "}";
		} // 13
		outfile << std::endl;
		for (auto it : _SpeedRemaingTimeBeforeMoveAgain->_storage) {
			outfile << "{";
			outfile << it.first;
			outfile << ",";
			outfile << std::get<0>(it.second);
			outfile << ",";
			outfile << 0;
			outfile << ",";
			outfile << std::get<2>(it.second);
			outfile << "}";
		} // 14
		outfile << std::endl;
		for (auto it : _MaxBomb->_storage) {
			outfile << "{";
			outfile << it.first;
			outfile << ",";
			outfile << it.second.first;
			outfile << ",";
			outfile << it.second.second;
			outfile << "}";
		} // 15
		outfile << std::endl;
		for (auto it : _BombOwnerShip->_storage) {
			outfile << "{";
			outfile << it.first;
			outfile << ",";
			outfile << it.second;
			outfile << "}";
		} // 16
		outfile << std::endl;
		for (auto it : _WallPass->_storage) {
			outfile << "{";
			outfile << it.first;
			outfile << ",";
			it.second ? outfile << "1" : outfile << "0";
			outfile << "}";
		} // 17
		outfile << std::endl;

		for (auto it : _TimeRemaing->_storage) {
			outfile << "{";
			outfile << it.first;
			outfile << ",";
			outfile << it.second.first;
			outfile << ",";
			outfile << it.second.second;
			outfile << "}";
		} // 18
		outfile << std::endl;
		for (auto it : _Texture->_storage) {
			outfile << "{";
			outfile << it.first;
			outfile << ",";
			outfile << it.second;
			outfile << "}";
		} // 19
		outfile << std::endl;
		for (auto it : _Path->_storage) {
			outfile << "{";
			outfile << it.first;
			outfile << ",";
			outfile << it.second;
			outfile << "}";
		} // 20
		outfile << std::endl;
		for (auto it : _Shape->_storage) {
			outfile << "{";
			outfile << it.first;
			outfile << ",";
			outfile << static_cast<int> (it.second);
			outfile << "}";
		} // 21
		outfile << std::endl;

		for (uint i = 0; i < _map.first.size(); i++) {
			outfile << _map.first[i];
			i < _map.first.size() - 1 ? outfile << "," : outfile << std::endl;
		} // 22
		for (uint i = 0; i < _map.second.size(); i++) {
			outfile << _map.second[i];
			i < _map.second.size() - 1 ? outfile << "," : outfile << std::endl;
		} // 22a
		for (uint i = 0; i < _Input.size(); i++) {
			outfile << static_cast<int> (_Input[i]);
			i < _Input.size() - 1 ? outfile << "," : outfile << std::endl;
		} // 23
	};

	virtual Object_t getObjectByNumber(int a) {
		Object_t obj {-1};

		for (uint i = 0; i < _Player->size(); ++i) {
			if ((*_Player)[i]._id == a) {
				obj._type = TYPE::MESH_SCENE;
				obj._Texture = _Texture->_storage[(*_Player)[i]._id];
				obj._path = _Path->_storage[(*_Player)[i]._id];
				obj._Position = _Position->_storage[(*_Player)[i]._id];
				obj._OldPosition = _OldPosition->_storage[(*_Player)[i]._id];
				obj._scene_type = SCENE_TYPE::NONE;
				obj.id = (*_Player)[i]._id;
				obj.size = -1;
				obj._IsVisible = _IsVisible->_storage[(*_Player)[i]._id];
				obj.x = std::get<2>(_SpeedRemaingTimeBeforeMoveAgain->_storage[(*_Player)[i]._id]);
				return obj;
			}
		}

		for (uint i = 0; i < _Wall->size(); ++i) {
			if ((*_Wall)[i]._id == a) {
				obj._type = TYPE::SCENE;
				obj._Texture = _Texture->_storage[(*_Wall)[i]._id];
				obj._path = _Path->_storage[(*_Wall)[i]._id];
                                obj._Position = _Position->_storage[(*_Wall)[i]._id];
				obj._OldPosition = _OldPosition->_storage[(*_Wall)[i]._id];
				obj.id = (*_Wall)[i]._id;
				obj.size = _Size->_storage[(*_Wall)[i]._id];
				obj._scene_type = SCENE_TYPE::CUBE;
				obj._IsVisible = _IsVisible->_storage[(*_Wall)[i]._id];
				return obj;
			}
		}

		for (uint i = 0; i < _Bomb->size(); ++i) {
			if ((*_Bomb)[i]._id == a) {
				obj._type = TYPE::MESH_SCENE;
				obj._Texture = _Texture->_storage[(*_Bomb)[i]._id];
				obj._path = _Path->_storage[(*_Bomb)[i]._id];
                                obj._Position = _Position->_storage[(*_Bomb)[i]._id];
				obj._OldPosition = _OldPosition->_storage[(*_Bomb)[i]._id];
				obj.id = (*_Bomb)[i]._id;
				obj.size = -1;
				obj._scene_type = SCENE_TYPE::NONE;
				obj._IsVisible = _IsVisible->_storage[(*_Bomb)[i]._id];
				return obj;
			}
		}

		for (uint i = 0; i < _Explosion->size(); ++i) {
			if ((*_Explosion)[i]._id == a) {
				obj._type = TYPE::SCENE;
				obj._Texture = _Texture->_storage[(*_Explosion)[i]._id];
				obj._path = _Path->_storage[(*_Explosion)[i]._id];
                                obj._Position = _Position->_storage[(*_Explosion)[i]._id];
				obj._OldPosition = _OldPosition->_storage[(*_Explosion)[i]._id];
				obj.id = (*_Explosion)[i]._id;
				obj.size = _Size->_storage[(*_Explosion)[i]._id];
				obj._scene_type = SCENE_TYPE::CUBE;
				obj._IsVisible = _IsVisible->_storage[(*_Explosion)[i]._id];
				return obj;
			}
		}

		for (uint i = 0; i < _PowerUp->size(); ++i) {
			if ((*_PowerUp)[i]._id == a) {
				obj._type = TYPE::SCENE;
				obj._Texture = _Texture->_storage[(*_PowerUp)[i]._id];
                                obj._Position = _Position->_storage[(*_PowerUp)[i]._id];
				obj._OldPosition = _OldPosition->_storage[(*_PowerUp)[i]._id];
				obj.id = (*_PowerUp)[i]._id;
				obj.size = _Size->_storage[(*_PowerUp)[i]._id];
				obj._scene_type = SCENE_TYPE::CUBE;
				obj._IsVisible = _IsVisible->_storage[(*_PowerUp)[i]._id];;
				return obj;
			}
		}
		return obj;
	};
	virtual std::vector<std::vector<Entity>> getEntity(void) {
		std::vector<std::vector<Entity>> v;

		v.push_back(*_Player);
		v.push_back(*_Wall);
		v.push_back(*_Bomb);
		v.push_back(*_PowerUp);
		v.push_back(*_Explosion);
		return v;
	}
	virtual void initGame(uint nbrPlayer, uint nbrBot, int) {}; //+player input config
	virtual uint getNum() { return _num; };
	virtual void Calcul() {};
	virtual void dump() {};
};

class BombermanSystem : public BombermanCore {
private:
	ThreadPool<std::vector<INPUT>> _System_pool;
	std::vector<std::unique_ptr<Isystem>> _Sys;

	// std::vector<std::thread> System_thread;
	// ExplosionCountDown S_Cleaner;
	// PopBuff S_BuffDrawer;

	Chrono c;
	std::thread chrono;

	std::vector<INPUT> v;
	bool tmp;
public:

	BombermanSystem (void) : _System_pool(5), chrono(std::bind(&Chrono::Run, std::ref(c))) {
		_Sys.push_back(std::move(std::unique_ptr<Isystem> (new ExplosionCountDown(_IsVisible, _TimeRemaing, c, _Explosion))));
		_Sys.push_back(std::move(std::unique_ptr<Isystem> (new CollidingSystem(_Player, _Position, _Wall, _Bomb, _IsVisible, _OldPosition, _WallPass, _Destroyable, _SpeedRemaingTimeBeforeMoveAgain, _Dead))));
		_Sys.push_back(std::move(std::unique_ptr<Isystem> (new PoseBomb(_Player, _Position, _IsVisible, _Bomb, _TimeRemaing, c, _FirePower, &_num, _Path, _OldPosition, _MaxBomb, _BombOwnerShip, _Dead))));
		_Sys.push_back(std::move(std::unique_ptr<Isystem> (new BombCountDown(_IsVisible, _Bomb, _TimeRemaing, c, _Position, _Explosion, _Wall, _Destroyable, _MaxBomb, _BombOwnerShip))));
		_Sys.push_back(std::move(std::unique_ptr<Isystem> (new CollidingSystemExplosion(_IsVisible, _Explosion, _Position, _Player, _Dead))));
		_Sys.push_back(std::move(std::unique_ptr<Isystem> (new PopBuff(_IsVisible, _Position, _Wall, _PowerUp))));
		_Sys.push_back(std::move(std::unique_ptr<Isystem> (new AddBuff(_PowerUp, _Player, _TypePowerUp, _FirePower, _MaxBomb, _Position, _IsVisible, _WallPass, _SpeedRemaingTimeBeforeMoveAgain))));
		std::cout << "BombermanSystem init" << '\n';
	};

	bool isBorder(uint, uint);
	virtual void initGame(uint nbrPlayer, uint nbrBot, int) override; //+player input key
	virtual void Calcul() {
		enum SYSTEM { EXPLCD, COLLSYS, POSBMB, BMBCD, COLLSYSEXL, POPBUFF, ADDBUFF};
		int j = _nbrPlayer;

		if (_Input[0] == INPUT::ACTION)
			writeData();
		if (_bot.empty()) {
			for (uint i = 0; i < _nbrBot; i++)
				_bot.push_back({i + _nbrBot, 5, (int)_Position->_storage[(*_Player)[i + _nbrBot]._id].getX(), (int)_Position->_storage[(*_Player)[i + _nbrBot]._id].getY(), _Player, _Wall, _Bomb, _PowerUp, _Explosion, _Position, _IsVisible, _TimeRemaing, _SpeedRemaingTimeBeforeMoveAgain, _Dead});
		}
		for (size_t i = 0; i < _nbrBot; i++, j++) {
			_bot[i].actualizeMap();
			_Input[j] = _bot[i].move();
		}
		_System_pool.enqueue(std::bind(&Isystem::update, std::ref(_Sys[COLLSYS]), _Input), _Input);
		_System_pool.enqueue(std::bind(&Isystem::update, std::ref(_Sys[COLLSYSEXL]), _Input), _Input);
		_System_pool.enqueue(std::bind(&Isystem::update, std::ref(_Sys[POSBMB]), _Input), _Input);
		_System_pool.enqueue(std::bind(&Isystem::update, std::ref(_Sys[BMBCD]), _Input), _Input);
		_System_pool.enqueue(std::bind(&Isystem::update, std::ref(_Sys[EXPLCD]), _Input), _Input);
		_System_pool.enqueue(std::bind(&Isystem::update, std::ref(_Sys[POPBUFF]), _Input), _Input);
		_Sys[ADDBUFF]->update(_Input);
	};
	virtual ~BombermanSystem () {
		chrono.detach();
	};
};

#endif
