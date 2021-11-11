//
// EPITECH PROJECT, 2019
// indie_studio_2018
// File description:
// clas obj
//

#ifndef _OBJ_
#define _OBJ_

#include <irrlicht.h>
#include <string>

#include "Core/Enums.hpp"
#include "Core/Dot.hpp"
#include "Core/IndieException.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class IObject
{
      public:
        virtual ~IObject() = default;
        virtual void setPosition(vector3df pos) = 0;
        virtual void setRotation(vector3df pos) = 0;
        virtual void setTexture(io::path path) = 0;
        virtual void setVisible(bool visible) = 0;
        virtual void setAnimation(ANIMATION animation) = 0;
        virtual void setAnimationSpeed(int speed) = 0;
        virtual bool isMoving() = 0;
        virtual void setMoving(bool moving) = 0;
        virtual ITexture *createTexture(io::path path) = 0;
};

class PrimaryObj: public IObject
{
public:
        ~PrimaryObj() = default;
        virtual void setPosition(vector3df pos) = 0;
        virtual void setRotation(vector3df pos) = 0;
        virtual void setTexture(io::path path) {};
        virtual void setVisible(bool visible) {};
        virtual void setAnimation(ANIMATION animation) {};
        virtual void setAnimationSpeed(int speed) {};
        virtual bool isMoving() {return false;};
        virtual void setMoving(bool moving) {};
        virtual ITexture *createTexture(io::path path) {
                if (!(*_Textures).empty() && (*_Textures).find(path) != (*_Textures).end()) {
                        return (*_Textures)[path];
                }
                (*_Textures)[path] = _driver->getTexture(path);
                return (*_Textures)[path];
        };
protected:
        std::shared_ptr<std::map<io::path, ITexture*>> _Textures;
        IVideoDriver *_driver;
};
#endif
