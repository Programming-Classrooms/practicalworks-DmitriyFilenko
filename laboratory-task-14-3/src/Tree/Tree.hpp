#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>


class Tree {
protected:
    std::string name;
    int32_t age;
    

public:

enum class TreeType {
        Leafy,
        Coniferous,
    } type;

    Tree(std::string n, int32_t a, TreeType t) : name(n), age(a), type(t) {}

    virtual void printInfo() const = 0;

    TreeType getType() const {
        return type;
    }

    std::string getName() const {
        return name;
    }

    int32_t getAge() const {
        return age;
    }
};

#endif //TREE_HPP
