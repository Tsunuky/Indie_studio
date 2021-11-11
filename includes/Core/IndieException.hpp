/*
** EPITECH PROJECT, 2019
** C++Day01
** File description:
** IndieException.hpp
*/

//Custom exception pour l'indie
//IndieException hérite de std::exception pour une portabilité
//Toute les types d'erreur lié a l'indie doivent héréité de IndieException

//CoreException Regroupe toute les exception possible dans le core

#ifndef __INDIE_EXCPTION__HPP__
#define __INDIE_EXCPTION__HPP__

#include <exception>
#include <string>

enum class CException {
        CoreException,
        ParsingException,
        LibException,
        GameException,
        MeshException
};

template <enum CException> class IndieException : public std::exception{
private:
        std::string _errorMess;
public:
        IndieException (const std::string &mess) : _errorMess(mess) {};
        virtual ~IndieException() = default;
        virtual const char *what() const noexcept override {return _errorMess.c_str();};
};

#endif
