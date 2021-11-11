/*
** EPITECH PROJECT, 2019
** C++Day01
** File description:
** Graph.hpp
*/

#ifndef __GRAPH__HPP
#define __GRAPH__HPP

#include <memory>
#include <stdlib.h>

#include "Core/Dot.hpp"
#include "Core/Enums.hpp"
#include "Core/Events.hpp"
#include "Core/ECS.hpp"
#include "Graph/Obj.hpp"
#include <SFML/Audio.hpp>

class Igraph {
        public:
                virtual ~Igraph () = default;
                virtual void draw() = 0;
                virtual std::vector<INPUT> getInput(std::vector<std::map<KEYS, INPUT>> keys_map) = 0;
                virtual bool exist(uint a) = 0;
                virtual void EraseObj(uint a) = 0;
                virtual void ObjVisible(uint a, bool visible) = 0;
                virtual void createObj(Object_t) = 0;
                virtual void setPosition(uint a, dot<float>) = 0;
                virtual void setAnimation(uint a, ANIMATION animation) = 0;
                virtual bool IsAvailable(uint a) = 0;
                virtual std::vector<int> getEntity() = 0;
                virtual void move(uint a, dot<float> pos, dot<float> oldPos, int step) = 0;
};

class Irrlib : public Igraph {
        public:
                Irrlib() {
			_device = createDevice(video::EDT_OPENGL, dimension2d<u32>(1900, 1080), 32, false, false,false, &_receiver);
			_smgr = _device->getSceneManager();
			_driver = _device->getVideoDriver();
                        _env = _device->getGUIEnvironment();
                        Mesh = std::make_shared<std::map<io::path, IAnimatedMesh*>>();
                        Textures = std::make_shared<std::map<io::path, ITexture*>>();
                        CreateBackground();
                        music.play();
		};
        public:
                virtual void draw() {
			if (_device->run()) {
				_driver->beginScene(true, true, SColor(255,100,101,140));
                                _driver->draw2DImage(createTexture("media/Goblin-Town.jpg"), {0,0});
                                _smgr->drawAll();
				_driver->endScene();
			}
                };
                virtual std::vector<INPUT> getInput(std::vector<std::map<KEYS, INPUT>> keys_map);
                void createObj(Object_t obj) {
			if (obj._type == TYPE::MESH_SCENE) {
				createObj(Mesh, Textures, obj._type, obj.id, {obj._path.c_str()}, {obj._Texture.c_str()}, obj._Position, obj._IsVisible);
			} else if (obj._type == TYPE::CAMERA) {
				createObj(obj._type, obj.id, obj._Position);
			} else if (obj._type == TYPE::SCENE) {
				createObj(obj._type, Textures, obj.id, {obj._Texture.c_str()}, obj._Position, obj.size, obj._scene_type,obj._IsVisible);
			}
		};
                //Create a meshScene
                void createObj(std::shared_ptr<std::map<io::path, IAnimatedMesh*>> Mesh, std::shared_ptr<std::map<io::path, ITexture*>> Textures, TYPE type, int id, io::path path, io::path texture, dot<float> pos, bool visible);
                //Create a scene that is either a cube or a sphere
                void createObj(TYPE type, std::shared_ptr<std::map<io::path, ITexture*>> Textures, int id, io::path path, dot<float> pos, int size, SCENE_TYPE sceneType, bool visible);
                //Create a camera
                void createObj(TYPE type, int id, dot<float> pos);
                virtual void EraseObj(uint a) {
                        Objects.DeleteCompenent(a);
                };
                virtual void setPosition(uint a, dot<float> pos) {
                        vector3df dpos;

                        dpos.X = pos.getX()*20;
                        dpos.Z = pos.getY()*20;
                        dpos.Y = pos.getZ()*20;
                        Objects._storage[a]->setPosition(dpos);
                };
                virtual void ObjVisible(uint a, bool visible) {
                        Objects._storage[a]->setVisible(visible);
                };
                virtual void setAnimation(uint a, ANIMATION animation) {
                        Objects._storage[a]->setAnimation(animation);
                };
                virtual bool IsAvailable(uint a) {
                        if (Objects._storage[a])
                                return true;
                        return false;
                };
                virtual std::vector<int> getEntity() {
                        std::vector<int> tmp;

                        if (!_device->run()) {
                                tmp.push_back(-5);
                                return tmp;
                        }
                        for (auto it : Objects._storage)
                                tmp.push_back(it.first);
                        return tmp;
                };
                INPUT getKey(std::map<KEYS, INPUT> map);
                virtual void move(uint a, dot<float> pos, dot<float> oldPos, int step);
                void movePos(uint a, dot<float> pos,dot<float> oldPos, int step);
                vector3df dotTo3df(dot<float> pos) {
                        vector3df dpos;

                        dpos.X = pos.getX()*20;
                        dpos.Z = pos.getY()*20;
                        dpos.Y = pos.getZ()*20;
                        return dpos;
                };
                void getDirection(uint a, vector3df pos, vector3df oldpos) {
                        if (pos.X > oldpos.X) {
                                Objects._storage[a]->setRotation({0, 270, 0});
                        }
                        if (pos.X < oldpos.X) {
                                Objects._storage[a]->setRotation({0, 90, 0});
                        }
                        if (pos.Z > oldpos.Z) {
                                Objects._storage[a]->setRotation({0, 180, 0});
                        }
                        if (pos.Z < oldpos.Z) {
                                Objects._storage[a]->setRotation({0, 0, 0});
                        }
                };
                virtual bool exist(uint a) {
                        if (Objects.Find(a) != Objects._storage.end())
                                return true;
                        return false;
                };
                ITexture *createTexture(io::path path) {
                        if (!(*Textures).empty() && (*Textures).find(path) != (*Textures).end()) {
                                return (*Textures)[path];
                        }
                        (*Textures)[path] = _driver->getTexture(path);
                        return (*Textures)[path];
                };
                IrrlichtDevice *getDivice() { return _device; }
                IVideoDriver *getDriver() { return _driver; }
                IGUIEnvironment *getEnv() { return _env; }
                void CreateBackground();
        private:
		IrrlichtDevice* _device;
                ISceneManager* _smgr;
                IVideoDriver* _driver;
                MyEventReceiver _receiver;
                IGUIEnvironment *_env;
                bool _setBackground;
                sf::Music music;
        public:
                Storage<std::shared_ptr<IObject>> Objects;
                Storage<vector3df> Positions;
                Storage<vector3df> OldPositions;
                std::shared_ptr<std::map<io::path, IAnimatedMesh*>> Mesh;
                std::shared_ptr<std::map<io::path, ITexture*>> Textures;
};

class LibContainer {
public:
	virtual Igraph *getLib(void) = 0;
};

class LibContainerIrrlicht : public LibContainer {
public:
	Irrlib *_graphicLibrary;
public:
        LibContainerIrrlicht(Igraph *lib) {
                _graphicLibrary = (Irrlib *)lib;
        };
	virtual Igraph *getLib(void) {
		return (Igraph *)_graphicLibrary;
	};

	virtual ~LibContainerIrrlicht () = default;
};
#endif /* !LIBCONTAINER_HPP_ */
