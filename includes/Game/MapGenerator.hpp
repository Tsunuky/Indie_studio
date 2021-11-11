/*
** EPITECH PROJECT, 2019
** C++Day01
** File description:
** MapGenerator.hpp
*/

#ifndef __MAP__GENERATOR__HPP__
#define __MAP__GENERATOR__HPP__

#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <math.h>

#define SIZE 20

struct value
{
        int x;
        int y;
        int value;
};

class MapGenerator {
private:
	const int key[21] = {0, 0, 0, 0, 1, 1, 1, 4, 2, 2, 3, 3, 3, 2, 1, 3, 2, 3, 1, 0, 0};
	int calcDistance(std::vector<value> &v, int i, int j)
	{
	        int tmp = 0;
	        float tmp1 = 0.0;
	        std::vector<float> q;

	        for (uint k = 0; k < v.size(); ++k) {
	                q.push_back( sqrt( pow((v[k].x-i), 2) + pow((v[k].y-j), 2)));
	        }
	        tmp1 = q[0];
	        for (uint k = 0; k < q.size(); ++k) {
	                if (q[k] < tmp1) {
	                        tmp = k;
	                        tmp1 = q[k];
	                }
	        }
	        return (v[tmp].value);
	}
public:
	MapGenerator () = default;
	virtual ~MapGenerator () = default;
	std::pair<std::vector<std::string>, std::vector<std::string>> generator(int seednbr, int typeNbr) {
		char map[SIZE+1][SIZE+1] = {0};
		char _buff[SIZE+1][SIZE+1] = {0};
		std::vector<value> v;
		std::pair<std::vector<std::string>, std::vector<std::string>> ret;
		int plopi = typeNbr;

		srand(time(NULL));
		if (typeNbr == 4)
			typeNbr =3;
		for (int i = 0; i < seednbr; i++)
			v.push_back({rand()%SIZE, rand()%SIZE, rand()%typeNbr+1});
		for (int i = 0; i < SIZE; ++i) {
			for (int j = 0; j < SIZE; ++j) {
				int rev = calcDistance(v, i, j);
				if (rev == 1)
					map[i][j] = ' ';
				else if (rev == 2)
					map[i][j] = '|';
				else
					map[i][j] = 'X';
			}
		}
		for (int i = 0; i < SIZE; ++i) {
			for (int j = 0; j < SIZE; ++j) {
				if (i == 0 || j == 0 || i == SIZE-1 || j == SIZE-1) {
					map[i][j] = 'X';
				}
			}
		}
		for (int i = 1; i < SIZE-1; ++i) {
			for (int j = 1; j < SIZE-1; ++j) {
				if (i == SIZE/4 || i == (int)(SIZE*0.7) || j == SIZE/4 || j == (int)(SIZE*0.7)) {
					map[i][j] = '|';
				}
			}
		}
		if (plopi == 4) {
			for (size_t i = 2; i < 16; i+=1) {
				for (size_t j = 2; j < 16; j+=1) {
					map[i][j] = '|';
				}
			}
			for (size_t i = 1; i < 19; i++) {
				for (size_t j = 1; j < 19; j++) {
					if ((i >= 1 && i <= 3) ||( j >= 1 && j <= 3) || (j >= 16 && j <= 19) || (i >= 16 && i <= 19))
						map[i][j] = ' ';
				}
			}
		}
		for (int i = 0; i < SIZE; ++i) {
			for (int j = 0; j < SIZE; ++j) {
				if (map[i][j] == '|')
					_buff[i][j] = key[rand()%17] + '0';
				else
					_buff[i][j] = '0';
			}
		}
		if (typeNbr == 2) {
			for (size_t i = 0; i < 20; i+=2) {
				for (size_t j = 0; j < 20; j+=2) {
					map[i][j] = 'X';
				}
			}
		}
		for (int i = 0; i < SIZE; ++i) {
			ret.first.push_back({map[i]});
			ret.second.push_back({_buff[i]});
		}
		return ret;
	};
};

#endif
