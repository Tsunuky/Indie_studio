/*
** EPITECH PROJECT, 2019
** C++Day01
** File description:
** main.cpp
*/

#include <iostream>
#include <boost/exception/diagnostic_information.hpp>

#include "Core/IndieException.hpp"
#include "Graph/lib.hpp"


int main(int argc, char const *argv[])
{
        try {
		// music.setLoop(true);
		Initializor init;
                Mainenu menu(init.container());
		menu.run();
        } catch (std::exception err) {
                std::clog << boost::current_exception_diagnostic_information() << std::endl;
                return 84;
        } catch (...) {
                std::clog << boost::current_exception_diagnostic_information() << std::endl;
                return 84;
        }
        return 0;
}
