//
// EPITECH PROJECT, 2019
// indie_studio_2018
// File description:
// objects classes
//

#ifndef _OBJECTS_
#define _OBJECTS_

#include "Graph/Obj.hpp"
#include "Graph/enumsGraph.hpp"

class MeshScene : public PrimaryObj
{
	public:
		MeshScene(std::shared_ptr<std::map<io::path, IAnimatedMesh*>> Mesh, std::shared_ptr<std::map<io::path, ITexture*>> Textures, ISceneManager* smgr, IrrlichtDevice* device, IVideoDriver* driver, io::path path, io::path texture, vector3df pos, bool visible) {
			_smgr = smgr;
			_device = device;
			_driver = driver;
                        _moving = false;
                        _Mesh = Mesh;
                        _Textures = Textures;

			_mesh = createMesh(path);
			if (!_mesh) {
				_device->drop();
				throw IndieException<CException::LibException>("Error MeshScene");
			}
			_node = _smgr->addAnimatedMeshSceneNode(_mesh);
			if (_node) {
				_node->setPosition(core::vector3df(pos));
				_node->setMaterialFlag(video::EMF_LIGHTING, false);
				if (path == "./media/Bomb.obj")
					_node->setScale({60,60,60});
                                /*if (path == "./media/Dynamite_obj.obj")
        				_node->setScale({0.2,0.2,0.2});
                                if (path == "./media/13642_Polo_Boots_v1_L2.obj")
                			_node->setScale({0.4,0.4,0.4});*/
				else {
					_node->setScale({10,10,10});
                                        setAnimation(ANIMATION::IDLE);
				}

				if (!texture.empty()) {
					_node->setMaterialTexture(0, createTexture(texture));
				}
				_node->setVisible(visible);
			}

			// if (_node) {
			// 	_node->setPosition(core::vector3df(pos));
			// 	if (path == "./media/Bomb.obj")
			// 		_node->setScale({60,60,60});
			// 	_node->setMaterialFlag(video::EMF_LIGHTING, false);
			// 	if (!texture.empty()) {
			// 		_node->setMD2Animation(scene::EMAT_RUN);
			// 		_node->setMaterialTexture(0, _driver->getTexture(texture));
			// 	}
			// 	// _node->setVisible(visible);
			// }
                };
                virtual ~MeshScene () {
			if (_node)
				_node->remove();
		};
        public:
                virtual void setPosition(vector3df pos) {
			_node->setPosition(pos);
                };
                virtual void setRotation(vector3df pos) {
                        _node->setRotation(pos);
                };
                virtual void setTexture(io::path path) override {
                        _node->setMaterialTexture(0, createTexture(path));
                };
                virtual void setVisible(bool visible) {
                        _node->setVisible(visible);
                };
                virtual void setAnimation(ANIMATION animation) {
                        std::vector<dot<int>> list = {
                                {0, 95},
                                {100, 122},
                                {125, 165},
                                {170, 210},
                                {220, 250},
                                {260, 290},
                                {300, 350},
                                {350, 390},
                                {390, 440},
                                {440, 450},
                                {450, 475},
                                {475, 500},
                                {500, 550},
                                {560, 680},
                                {0, 200}
                        };
                        dot<int> tmp = list[static_cast<int>(animation)];
                        _node->setFrameLoop(tmp.getX(), tmp.getY());
                };
                virtual bool isMoving() {
                        return _moving;
                };
                virtual void setMoving(bool moving) {
                        _moving = moving;
                };
                IAnimatedMesh *createMesh(io::path path) {
                        if (!(*_Mesh).empty() && (*_Mesh).find(path) != (*_Mesh).end()) {
                                return (*_Mesh)[path];
                        }
                        (*_Mesh)[path] = _smgr->getMesh(path);
                        return (*_Mesh)[path];
                };
                virtual void setAnimationSpeed(int speed){
                        _node->setAnimationSpeed(speed);
                };
        private:
                IAnimatedMesh* _mesh;
		ISceneManager *_smgr;
		IrrlichtDevice *_device;
                std::shared_ptr<std::map<io::path, IAnimatedMesh*>> _Mesh;
                bool _moving;
        public:
                IAnimatedMeshSceneNode *_node;
};

class Camera : public PrimaryObj
{
        public:
                //create a mesh with no texture
		// Camera(ISceneManager *smgr, vector3df pos) {
                Camera(ISceneManager *smgr, vector3df pos) {
                        _camera = smgr->addCameraSceneNode(NULL, pos, vector3df(0,0,0));
			_camera->bindTargetAndRotation(true);
			// _camera->setTarget( vector3d<f32>( -20, 0, -20 ) );
			_camera->setTarget({10,0,10});
                };
                virtual ~Camera () = default;
        public:
                virtual void setPosition(vector3df pos) {
			_camera->setTarget(pos);
                        // _camera->setRotation({10, 0, 0});
                };
                virtual void setRotation(vector3df pos) {
                        _camera->setRotation(pos);
                };
        private:
                ICameraSceneNode *_camera;
};

class Scene : public PrimaryObj
{
public:
	// Scene(ISceneManager *smgr, IVideoDriver *driver, io::path path, vector3df pos, int size, SCENE_TYPE type, bool visible) : _smgr(smgr), _driver(driver) {
        Scene(std::shared_ptr<std::map<io::path, ITexture*>> Textures, ISceneManager *smgr, IVideoDriver *driver, io::path path, vector3df pos, int size, SCENE_TYPE type, bool visible) {
		_smgr = smgr;
		_driver = driver;
                _Textures = Textures;

		if (type == SCENE_TYPE::CUBE)
			_node = _smgr->addCubeSceneNode(size);
		if (type == SCENE_TYPE::SPHERE)
			_node = _smgr->addSphereSceneNode(size);
                if (_node)
                {
                        _node->setPosition(pos);
                        _node->setMaterialTexture(0, createTexture(path));
                        _node->setMaterialFlag(video::EMF_LIGHTING, false);
                        _node->setVisible(visible);
                }
        };
        ~Scene() {
		if (_node)
			_node->remove();
	};
public:
        virtual void setPosition(vector3df pos) {
                _node->setPosition(pos);
        };
        virtual void setRotation(vector3df pos) {
                _node->setRotation(pos);
        };
        virtual void setTexture(io::path path) override {
                _node->setMaterialTexture(0, createTexture(path));
        };
        virtual void setVisible(bool visible) {
                _node->setVisible(visible);
        };
private:
        scene::ISceneNode * _node;
	ISceneManager *_smgr;
};

#endif
