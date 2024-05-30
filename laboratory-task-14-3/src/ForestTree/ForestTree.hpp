#ifndef FORESTTREE_HPP
#define FORESTTREE_HPP

#include "src/Tree/Tree.hpp"


class ForestTree : public Tree {
private:
    int32_t woodAmount;

public:
    ForestTree(std::string n, int32_t a, TreeType t, int32_t w) : Tree(n, a, t), woodAmount(w) {}

    void printInfo() const override {
        std::cout << "Forest Tree - Name: " << getName() << ", Age: " << getAge() << ", Wood Amount: " << woodAmount << std::endl;
    }
};

#endif //FORESTTREE_HPP
