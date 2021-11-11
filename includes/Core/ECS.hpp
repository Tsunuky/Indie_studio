//
// EPITECH PROJECT, 2019
// indie_studio_2018
// File description:
// class for ECS
//

#ifndef _GRAPH_
#define _GRAPH_

#include <vector>
#include <map>

struct Tags {
	unsigned int Position : 1;
	unsigned int PhysicalObj : 1;
	unsigned int Playable : 1;
	unsigned int Rotate : 1;
	unsigned int Timer : 1;
	unsigned int Drawable : 1;
};

class Entity {
public:
	Entity(uint id, Tags attribute) : _id(id), _attribute(attribute) {};
	~Entity() = default;
public:
	int _id;
	Tags _attribute = {0};
};

template <class Component>
class Storage {
public:
	Storage() = default;
	~Storage() = default;
public:
	void AddComponent(int ID, Component args) {
		_storage.emplace(ID, args);
	};
	void DeleteCompenent(int ID) {
		auto tmp = _storage.find(ID);
		if (tmp != _storage.end())
			_storage.erase(tmp);
	};
	auto Find(int ID) { return _storage.find(ID); }
public:
	std::map<int, Component> _storage;
};

#endif
