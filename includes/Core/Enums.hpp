/*
** EPITECH PROJECT, 2019
** C++Day01
** File description:
** Enums.hpp
*/

//Enum class pour les inputs
//struct Object_t servant dans le core du programme

#ifndef __ENUMS__HPP__
#define __ENUMS__HPP__

#include "Core/Dot.hpp"

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//Changement a prévoir
//Changement dans l'enum
//Changement dans Object_t (temporaire)
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

enum class INPUT {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        BOMB,
        ACTION,
        QUIT,
        NO_INPUT
};

enum class SCENE_TYPE {
        CUBE,
        SPHERE,
	NONE
};

enum class TYPE {
        MESH_SCENE,
        CAMERA,
        SCENE
};

enum class ANIMATION {
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
        DEATH2,
        Y_IDLE
};

struct Object_t
{
        int id;
	TYPE _type;
	std::string _path;
	std::string _Texture;
	dot<float> _Position;
	dot<float> _OldPosition;
	int size;
	SCENE_TYPE _scene_type;
	bool _IsVisible;
	float x;
};

enum class KEYS {
        NOKEY = 11,
        LB = 12,
        RB,
        CANCEL,
        MB,
        XB1,
        XB2,
        BACK,
        TAB,
        CLEAR,
        RETURN,
        SHIFT,
        CONTROL,
        MENU,
        PAUSE,
        CAPITAL,
        KANA,
        HANGUEL,
        HANGUL,
        JUNJA,
        FINAL,
        HANJA,
        KANJI,
        ESCAPE,
        CONVERT,
        NONCONVERT,
        ACCEPT,
        MODECHANGE,
        SPACE,
        PRIOR,
        NEXT,
        END,
        HOME,
        LEFT,
        UP,
        RIGHT,
        DOWN,
        SELECT,
        PRINT,
        EXECUT,
        SNAPSHOT,
        INSERT,
        DELETE,
        HELP,
        KEY0,
        KEY1,
        KEY2,
        KEY3,
        KEY4,
        KEY5,
        KEY6,
        KEY7,
        KEY8,
        KEY9,
        A,
        B,
        C,
        D,
        E,
        F,
        G,
        H,
        I,
        J,
        K,
        L,
        M,
        N,
        O,
        P,
        Q,
        R,
        S,
        T,
        U,
        V,
        W,
        X,
        Y,
        Z,
        ENDKEY
};
#endif
