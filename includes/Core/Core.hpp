/*
** EPITECH PROJECT, 2019
** C++Day01
** File description:
** Core.hpp
*/

//classe core du programme qui hold le jeu et la lib grapique
//Elle va etre en charge faire tourner le programme

#ifndef __CORE__HPP__
#define __CORE__HPP__

#include "Core/Initializor.hpp"

class Core {
private:
        Parsers _parser;
        //ptr holder pour la lib grapique
        //ptr holder pour la lib du jeu
        // std::unique_ptr<Igraph> _graphicLibrary;
	std::shared_ptr<LibContainer> _GraphContainer;
        std::unique_ptr<Igame> _gameLibrary;
	// void createObj(Object_t obj);
private:
	bool ExistGame(int value) {
		std::vector<std::vector<Entity>> EntityList = _gameLibrary->getEntity();

		for (size_t i = 0; i < EntityList.size(); i++) {
			for (size_t j = 0; j < EntityList[i].size(); j++) {
				if (EntityList[i][j]._id == value) {
					return true;
				}
			}
		}
		return false;
	}
public:
        Core(LibContainer *a, Igame *b) : _parser("./conf.ini"), _GraphContainer(a), _gameLibrary(b) {};
        virtual ~Core() {};
public:
        //launcher : lance le programme
        //computeGame : récupere les inputs et fait les Calcul grapique et du jeu
        //graphicalUpdate : appele par computeGame, va faire tout les opérations graphique
        void launcher(int, int, int, std::string);
        int computeGame(void);
        int graphicalUpdate(void);
};

#endif
