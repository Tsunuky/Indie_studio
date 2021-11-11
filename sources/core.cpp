/*
** EPITECH PROJECT, 2019
** C++Day01
** File description:
** core.hpp
*/

#include "Core/Core.hpp"

void Core::launcher(int a, int b, int c, std::string path)
{
	// _GraphContainer->getLib()->createObj(TYPE::MESH_SCENE, 0, "sydney.md2", "sydney.bmp", {-4, 3, 3}, true);
	if (path != "./../save/bomberman.save")
		_gameLibrary->initGame(a, b, c+2);
	else
		_gameLibrary->readData();
	Object_t tmp = {0};
	tmp._type = TYPE::CAMERA;
	tmp._Position = {10.0, 10.0, 15.0};
	tmp.id = -1000;

	_GraphContainer->getLib()->createObj(tmp);
	_GraphContainer->getLib()->setPosition(-1000, {10, 10, 0});

	while (computeGame() != -1) {
		// sleep(1);
		_GraphContainer->getLib()->draw();
	};
}

int Core::computeGame(void)
{
	std::vector<std::map<KEYS, INPUT>> _KeyBoardConfig;
	_KeyBoardConfig.push_back({});
	_KeyBoardConfig[0].insert({KEYS::K, INPUT::LEFT});
	_KeyBoardConfig[0].insert({KEYS::M, INPUT::RIGHT});
	_KeyBoardConfig[0].insert({KEYS::O, INPUT::UP});
	_KeyBoardConfig[0].insert({KEYS::L, INPUT::DOWN});
	_KeyBoardConfig[0].insert({KEYS::I, INPUT::BOMB});
	_KeyBoardConfig[0].insert({KEYS::P, INPUT::ACTION});
	_KeyBoardConfig.push_back({});
	_KeyBoardConfig[1].insert({KEYS::S, INPUT::LEFT});
	_KeyBoardConfig[1].insert({KEYS::F, INPUT::RIGHT});
	_KeyBoardConfig[1].insert({KEYS::E, INPUT::UP});
	_KeyBoardConfig[1].insert({KEYS::D, INPUT::DOWN});
	_KeyBoardConfig[1].insert({KEYS::R, INPUT::BOMB});

	// if Server
	// 	getIMult -> getILoc
	// 	calc
	// else if client
	// 	getILoc
	// 	sendI
	// 	getInfo
	//
	// if !mult
	// 	getIloc
	// 	calc
        std::vector<INPUT> input = _GraphContainer->getLib()->getInput(_KeyBoardConfig);

	_gameLibrary->getInput(input);
        _gameLibrary->Calcul();
	return graphicalUpdate();
}



int Core::graphicalUpdate(void)
{
        dot<float> test1 {11, 13, 0};
        dot<float> test2 {12, 13, 0};
        static bool flag = false;
	//static bool plop = false;
	Object_t tmp;
	std::vector<std::vector<Entity>> EntityList = _gameLibrary->getEntity();
	std::vector<int> EntityListGraph;

	// static dot<float> plopq = {10, 0, 10};
	// plopq.setZ(plopq.getZ()+0.1);
	// std::cout << plopq.getZ() << '\n';
	// _GraphContainer->getLib()->setPosition(-1000, plopq);

	for (size_t i = 0; i < EntityList.size(); i++) {
		for (size_t j = 0; j < EntityList[i].size(); j++) {
			if (_GraphContainer->getLib()->exist(EntityList[i][j]._id) == false) {
				tmp = _gameLibrary->getObjectByNumber(EntityList[i][j]._id);
				_GraphContainer->getLib()->createObj(tmp);
			}
		}
	}

	for (size_t i = 0; i < EntityList.size(); i++) {
		for (size_t j = 0; j < EntityList[i].size(); j++) {
			tmp = _gameLibrary->getObjectByNumber(EntityList[i][j]._id);
			if (i == 0 && j < 4) {
				//_GraphContainer->getLib()->setPosition(EntityList[i][j]._id, tmp._Position);
				 _GraphContainer->getLib()->move(EntityList[i][j]._id, tmp._Position, _gameLibrary->getObjectByNumber(EntityList[i][j]._id)._OldPosition, _gameLibrary->getObjectByNumber(EntityList[i][j]._id).x);
			}
			_GraphContainer->getLib()->ObjVisible(EntityList[i][j]._id, tmp._IsVisible);
		}
	}

	EntityListGraph = _GraphContainer->getLib()->getEntity();

	if (EntityListGraph[0] == -5)
		return -1;
	for (size_t i = 0; i < EntityListGraph.size(); i++) {
		if (ExistGame(EntityListGraph[i]) == false)
			_GraphContainer->getLib()->EraseObj(EntityListGraph[i]);
	}
	return 0;
}
