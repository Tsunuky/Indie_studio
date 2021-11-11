//
// EPITECH PROJECT, 2019
// indie_studio_2018
// File description:
// class for handling events
//

#ifndef __EVENT__HPP__
#define __EVENT__HPP__

#include <irrlicht.h>
#include "Core/Enums.hpp"

 using namespace irr;
 using namespace core;
 using namespace scene;
 using namespace video;
 using namespace io;
 using namespace gui;

 #include "Enums.hpp"

 class MyEventReceiver : public IEventReceiver
 {
 public:
     // This is the one method that we have to implement
     virtual bool OnEvent(const SEvent& event)
     {
         // Remember whether each key is down or up
         if (event.EventType == irr::EET_KEY_INPUT_EVENT)
             KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

         return false;
     }

     // This is used to check whether a key is being held down
     virtual bool IsKeyDown(EKEY_CODE keyCode) const
     {
         return KeyIsDown[keyCode];
     }

     MyEventReceiver()
     {
         for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
             KeyIsDown[i] = false;
     }

 private:
     // We use this array to store the current state of each key
     bool KeyIsDown[KEY_KEY_CODES_COUNT];
 };

#endif
