//
// EPITECH PROJECT, 2019
// indie_studio_2018
// File description:
// class Graph functions
//

#include <boost/exception/diagnostic_information.hpp>
#include <unistd.h>
#include <vector>
#include <string>
#include <iostream>
#include <thread>

#include "Graph/Objects.hpp"
#include "Graph/Graph.hpp"
// #include "Core/LibContainer.hpp"

__attribute__((constructor))
void constructor(void){
}

extern "C" Igraph *getLib(void)
{
        Igraph *lib = new Irrlib();
        return lib;
}

extern "C" LibContainer *getContainer(Igraph *a)
{
	LibContainer *container = new LibContainerIrrlicht(a);
	return container;
}

__attribute__((destructor))
void destructor(void){
}


bool cmpf(float A, float B, float epsilon = 0.005f)
{
    return (fabs(A - B) < epsilon);
}

void Irrlib::createObj(std::shared_ptr<std::map<io::path, IAnimatedMesh*>> Mesh, std::shared_ptr<std::map<io::path, ITexture*>> Textures, TYPE type, int id, io::path path, io::path texture, dot<float> pos, bool visible)
{
        if (type == TYPE::MESH_SCENE) {
                vector3df dpos;

                dpos.X = pos.getX()*20;
                dpos.Z = pos.getY()*20;
                dpos.Y = pos.getZ()*20;
		// MeshScene plop(_smgr, _device, _driver, path, texture, dpos, visible);
                //std::shared_ptr <IObject> tmp = std::make_shared<MeshScene>(_smgr, _device, _driver, path, texture, dpos, visible);
                std::shared_ptr <IObject> tmp = std::make_shared<MeshScene>(Mesh, Textures, _smgr, _device, _driver, path, texture, dpos, visible);
                Objects.AddComponent(id, tmp);
        }
}

void Irrlib::createObj(TYPE type, std::shared_ptr<std::map<io::path, ITexture*>> Textures, int id, io::path path, dot<float> pos, int size, SCENE_TYPE sceneType, bool visible)
{
        if (type == TYPE::SCENE) {
                vector3df dpos;

                dpos.X = pos.getX()*20;
                dpos.Z = pos.getY()*20;
                dpos.Y = pos.getZ()*20;
                std::shared_ptr <IObject> tmp(new Scene(Textures, _smgr, _driver, path, dpos, size, sceneType, visible));
                Objects.AddComponent(id, tmp);
        }
}

void Irrlib::createObj(TYPE type, int id, dot<float> pos)
{
        if (type == TYPE::CAMERA) {
                vector3df dpos;

                dpos.X = pos.getX()*20;
                dpos.Z = pos.getY()*20;
                dpos.Y = pos.getZ()*20;
                std::shared_ptr<IObject> tmp(new Camera(_smgr, dpos));
                Objects.AddComponent(id, tmp);
        }
}

INPUT Irrlib::getKey(std::map<KEYS, INPUT> map)
{
        for (int i = 0; i <= static_cast<int>(EKEY_CODE::KEY_LWIN); i++)
        {
                if (_receiver.IsKeyDown(static_cast<EKEY_CODE>(i))) {
                        if (map.find(static_cast<KEYS>(i)) != map.end()) {
                                return map[static_cast<KEYS>(i)];;
                        }
                }
        }
        return INPUT::NO_INPUT;
}

std::vector<INPUT> Irrlib::getInput(std::vector<std::map<KEYS, INPUT>> keys_map)
{
        std::vector<INPUT> inputs;

        for (auto it : keys_map) { //map
                inputs.push_back(getKey(it));
        }
        return inputs;
}

void Irrlib::movePos(uint a, dot<float> pos, dot<float> oldPos, int step)
{
        if (dotTo3df(pos) != dotTo3df(oldPos) && Objects._storage[a]->isMoving() == false) {
                Objects._storage[a]->setMoving(true);
                if (Positions.Find(a) == Positions._storage.end()) {
                        Positions.AddComponent(a, dotTo3df(pos));
                        OldPositions.AddComponent(a, dotTo3df(oldPos));
                }
                else {
                        Positions._storage[a] = dotTo3df(pos);
                        OldPositions._storage[a] = dotTo3df(oldPos);
                }
                Objects._storage[a]->setAnimation(ANIMATION::RUN);
                getDirection(a, Positions._storage[a], OldPositions._storage[a]);
                Objects._storage[a]->setAnimationSpeed((5 * step) / 2);
        }
        if (Objects._storage[a]->isMoving()) {
                for (int i = 0; i < step; i++) {
                if (OldPositions._storage[a].X < Positions._storage[a].X)
                        OldPositions._storage[a].X += 1;
                if (OldPositions._storage[a].X > Positions._storage[a].X)
                        OldPositions._storage[a].X -= 1;
                if (OldPositions._storage[a].Y < Positions._storage[a].Y)
                        OldPositions._storage[a].Y += 1;
                if (OldPositions._storage[a].Y > Positions._storage[a].Y)
                        OldPositions._storage[a].Y -= 1;
                if (OldPositions._storage[a].Z < Positions._storage[a].Z)
                        OldPositions._storage[a].Z += 1;
                if (OldPositions._storage[a].Z > Positions._storage[a].Z)
                        OldPositions._storage[a].Z -= 1;
                Objects._storage[a]->setPosition(OldPositions._storage[a]);
                draw();
                if (Positions._storage[a] == OldPositions._storage[a]) {
                        Objects._storage[a]->setMoving(false);
                        Objects._storage[a]->setAnimation(ANIMATION::IDLE);
                        return;
                }
                }
        }
        else if (dotTo3df(pos) == dotTo3df(oldPos))
                Objects._storage[a]->setPosition(dotTo3df(pos));
        if (Positions._storage[a] == OldPositions._storage[a]) {
                Objects._storage[a]->setMoving(false);
                Objects._storage[a]->setAnimation(ANIMATION::IDLE);
        }
};

void Irrlib::move(uint a, dot<float> pos, dot<float> oldPos, int step) {
        static int cmp = 0;

        movePos(a, pos, oldPos, step);
};

void Irrlib::CreateBackground()
{
        std::vector<MeshScene*> Meshes;
        std::cout << "hello" << "\n";
        Meshes.push_back(new MeshScene(Mesh, Textures, _smgr, _device, _driver, "./media/goblin-sapper-animated-X.X", "",  {300, 3, 500}, true));
        Meshes[0]->setAnimation(ANIMATION::ATK1);
        Meshes.push_back(new MeshScene(Mesh, Textures, _smgr, _device, _driver, "./media/goblin-sapper-animated-X.X", "",  {270, 3, 500}, true));
        Meshes[1]->setAnimation(ANIMATION::ATK2);
        Meshes.push_back(new MeshScene(Mesh, Textures, _smgr, _device, _driver, "./media/yeti-monster-animated-X.X", "./media/yeti2.jpg",  {200, 3, 500}, true));
        Meshes[2]->setAnimation(ANIMATION::Y_IDLE);
        for (float x = 12; x > -15; x--) {
        for (float i = -1; i < 12; i++) {
                        new Scene(Textures, _smgr, _driver, "./media/grass2.bmp", {(i*60), -60, (x*60)}, 60, SCENE_TYPE::CUBE, true);
        }
        }
};
