/*
** EPITECH PROJECT, 2019
** C++Day01
** File description:
** DynamicLoader.hpp
*/

#ifndef __DYNLOADER__HPP__
#define __DYNLOADER__HPP__

#include <dlfcn.h>
#include <string>
#include <vector>


template <typename T>
class  DLLoader {
        std::vector<void *> handle;
	T *(*fctPtr)(void);
        T *(*fctPtrL)(Igraph *);
        std::string libPath;
public:
        DLLoader() = default;
        virtual ~DLLoader() {
                unload();
        };
public:
        void unload(void) {
                for (uint i = 0; i < handle.size(); i++) {
                        if (handle[i])
                                dlclose(handle[i]);
                }
        }

        void load(const std::string &str) {
                libPath = str;
                handle.push_back(dlopen(libPath.c_str(), RTLD_GLOBAL | RTLD_LAZY));
                if (handle[handle.size()-1] == NULL) {
                        printf("%s\n", dlerror());
                        throw std::invalid_argument("Lib doesn't exist");
                }
        };

        T *getInstance(std::string lib_name) {
                T *tmp;
                char *str;

                *(void **)(&fctPtr) = dlsym(handle[handle.size()-1], lib_name.c_str());
                if ((str = dlerror()) != NULL)
                        throw std::runtime_error(dlerror());
                return fctPtr();
        };

	T *getInstance(std::string lib_name, Igraph *a) {
                T *tmp;
                char *str;

                *(void **)(&fctPtrL) = dlsym(handle[handle.size()-1], lib_name.c_str());
                if ((str = dlerror()) != NULL)
                        throw std::runtime_error(dlerror());
                return fctPtrL(a);
        };
};

#endif
