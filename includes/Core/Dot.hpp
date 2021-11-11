/*
** EPITECH PROJECT, 2019
** C++Day01
** File description:
** Dot.hpp
*/

//class qui permet de hold des points de différents type
//jusqu'a une dimension de 3

#ifndef __DOT__HPP__
#define __DOT__HPP__

#include <stdlib.h>
#include <iostream>
#include <math.h>

template <typename T>
class dot {
private:
        T x_pos;
        T y_pos;
        T z_pos = 0;
public:
        dot () = default;
        dot (T x, T y, T z) : x_pos(x), y_pos(y), z_pos(z) {};
        dot (const dot &copy) : x_pos(copy.x_pos), y_pos(copy.y_pos), z_pos(copy.z_pos) {};

	dot (T x, T y) : x_pos(x), y_pos(y) {};

        void dump()
        {
                std::cout << "POSX : " << x_pos << "\n";
                std::cout << "POSY : " << y_pos << "\n";
                std::cout << "POSZ : " << z_pos << "\n\n";
        };

        dot &operator=(const dot& equal) {
                x_pos = equal.x_pos;
                y_pos = equal.y_pos;
                z_pos = equal.z_pos;
                return *this;
        };
	bool operator==(dot &equal) { return x_pos == equal.getX() && y_pos == equal.getY() && z_pos == equal.getZ(); }
        bool operator!=(dot &equal) { return x_pos != equal.getX() || y_pos != equal.getY() || z_pos != equal.getZ(); }
        void setX(T x) { x_pos = x; };
        void setY(T y) { y_pos = y; };
        void setZ(T z) { z_pos = z; };
        T getX() { return x_pos; };
        T getY() { return y_pos; };
        T getZ() { return z_pos; };
        void IncX(T x) { x_pos += x; };
        void IncY(T y) { y_pos += y; };
        void IncZ(T z) { z_pos += z; };
        virtual ~dot () = default;
};

#endif
