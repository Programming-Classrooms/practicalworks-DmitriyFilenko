#ifndef TREECONTAINER_HPP
#define TREECONTAINER_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

#include "src/Tree/Tree.hpp"


class TreeContainer {
private:
    std::vector<Tree*> trees;

public:
    void addTree(Tree* tree) {
        trees.push_back(tree);
    }

    void printAllTrees() {
        for (const auto& tree : trees) {
            tree->printInfo();
        }
    }

    int32_t countTreesByType(Tree::TreeType type) {
        return std::count_if(trees.begin(), trees.end(), [type](Tree* tree) {
            return tree->getType() == type;
        });
    }

    int32_t countForestTrees() {
        return countTreesByType(Tree::TreeType::Coniferous) + countTreesByType(Tree::TreeType::Leafy);
    }

    void sortTreesByNameAndAge() {
        std::sort(trees.begin(), trees.end(), [](Tree* tree1, Tree* tree2) {
            if (tree1->getName() != tree2->getName()) {
                return tree1->getName() < tree2->getName();
            } else {
                return tree1->getAge() > tree2->getAge();
            }
        });
    }
};

#endif //TREECONTAINER_HPP
