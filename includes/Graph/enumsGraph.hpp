//
// EPITECH PROJECT, 2019
// indie_studio_2018
// File description:
// enums for graphical lib
//

#ifndef _ENUMGRAPH_
#define _ENUMGRAPH_

#include "Core/Dot.hpp"

/*#define IDLE setFrameLoop(0, 95);
#define RUN setFrameLoop(100, 122);
#define WALK_FORWARD setFrameLoop(125, 165);
#define WALK_BACK setFrameLoop(170, 210);
#define STRAFE_LEFT setFrameLoop(220, 250);
#define STRAFE_RIGHT setFrameLoop(260, 290);
#define JUMP setFrameLoop(300, 350);
#define ATK1 setFrameLoop(350, 390);
#define ATK2 setFrameLoop(390, 440);
#define HIT1 setFrameLoop(440, 450);
#define HIT2 setFrameLoop(450, 475);
#define HIT3 setFrameLoop(475, 500);
#define DEATH1 setFrameLoop(500, 550);
#define DEATH2 setFrameLoop(560, 680);*/

enum class ANIMATION3D {
        IDLE = 0,
        RUN,
        WALK_FORWARD,
        WALK_BACK,
        STRAFE_LEFT,
        STRAFE_RIGHT,
        JUMP,
        ATK1,
        ATK2,
        HIT1,
        HIT2,
        HIT3,
        DEATH1,
        DEATH2
};

/*enum class ANIMATION3D1 {
        IDLE = 0,
        RUN = 100,
        WALK_FORWARD = 125,
        WALK_BACK = 170,
        STRAFE_LEFT = 220,
        STRAFE_RIGHT = 260,
        JUMP = 300,
        ATK1 = 350,
        ATK2 = 390,
        HIT1 = 440,
        HIT2 = 450,
        HIT3 = 475,
        DEATH1 = 500,
        DEATH2 = 560
};

enum class ANIMATION3D2 {
        IDLE = 95,
        RUN = 122,
        WALK_FORWARD = 165,
        WALK_BACK = 210,
        STRAFE_LEFT = 250,
        STRAFE_RIGHT = 290,
        JUMP = 350,
        ATK1 = 390,
        ATK2 = 440,
        HIT1 = 450,
        HIT2 = 475,
        HIT3 = 500,
        DEATH1 = 550,
        DEATH2 = 680
};*/

#endif
