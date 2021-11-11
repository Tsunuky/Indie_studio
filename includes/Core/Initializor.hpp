/*
** EPITECH PROJECT, 2019
** C++Day01
** File description:
** Initializor.hpp
*/

//Le but de cette classe est d'initialiser n'importe quelle variable qui
//a besoin de l'etre avant des appele

//Pour l'instant elle sert a creér des ptr pour pouvoir init les unique_ptr
//lors de la forward declaration

#ifndef __INITIALIZOR__HPP__
#define __INITIALIZOR__HPP__

#include "Core/Parsers.hpp"
#include "Graph/Graph.hpp"
#include "Game/Game.hpp"
#include "Core/DynamicLoader.hpp"

class Initializor {
public:
        Parsers _parser;
        //Initializor(1) default ctor
        //~Initializor(1) default dtor
        Initializor () : _parser("./conf.ini") {};
        virtual ~Initializor () = default;
        //Game : Load a game and return a ptr of it
        //Lib : Load a lib and return a ptr of it
        // Igame *Game();
	// Igraph *Lib();
        // LibContainer *container();
	DLLoader<Igame> loaderGame;
	DLLoader<Igraph> loaderLib;
	DLLoader<LibContainer> loaderContainer;

Igame *Game(void)
{
        loaderGame.load(_parser.getPartParser("Core")._section["game"]);
        return loaderGame.getInstance("getLib");
}

Igraph *Lib(void)
{
        loaderLib.load(_parser.getPartParser("Core")._section["lib"]);
        return loaderLib.getInstance("getLib");
}

LibContainer *container(void)
{
        loaderContainer.load(_parser.getPartParser("Core")._section["lib"]);
        return loaderContainer.getInstance("getContainer", Lib());
}

};

#endif
