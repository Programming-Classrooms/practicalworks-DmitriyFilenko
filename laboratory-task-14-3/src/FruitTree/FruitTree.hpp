#ifndef FRUITTREE_HPP
#define FRUITTREE_HPP

#include "src/Tree/Tree.hpp"


class FruitTree : public Tree {
private:
    int32_t harvestWeight;
    int32_t storageDuration;

public:
    FruitTree(std::string n, int32_t a, TreeType t, int32_t weight, int32_t duration) : Tree(n, a, t), harvestWeight(weight), storageDuration(duration) {}

    void printInfo() const override {
        std::cout << "Fruit Tree - Name: " << getName() << ", Age: " << getAge() << ", Harvest Weight: " << harvestWeight << ", Storage Duration: " << storageDuration << std::endl;
    }
};

#endif //FRUITTREE_HPP
