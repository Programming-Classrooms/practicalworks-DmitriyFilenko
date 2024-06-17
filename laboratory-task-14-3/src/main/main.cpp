#include "src/TreeContainer/TreeContainer.hpp"
#include "src/FruitTree/FruitTree.hpp"
#include "src/ForestTree/ForestTree.hpp"
#include "src/Tree/Tree.hpp"


int32_t main() {
    TreeContainer container;
    std::ifstream inputFile("src/data/datafile.txt");

    if (inputFile.is_open()) {
        std::string name;
        int32_t age, woodAmount, harvestWeight, storageDuration;
        int32_t treeTypeInt;

        while (inputFile >> name) 
        {
            inputFile >> age >> treeTypeInt;
            Tree::TreeType treeType = static_cast<Tree::TreeType>(treeTypeInt);

            if (treeType == Tree::TreeType::Coniferous || treeType == Tree::TreeType::Leafy) {
                inputFile >> woodAmount;
                container.addTree(new ForestTree(name, age, treeType, woodAmount));
            } else {
                inputFile >> harvestWeight >> storageDuration;
                container.addTree(new FruitTree(name, age, treeType, harvestWeight, storageDuration));
            }
        }

        inputFile.close();
    }

    container.printAllTrees();
    std::cout << "Number of Leafy Trees: " << container.countTreesByType(Tree::TreeType::Leafy) << std::endl;
    std::cout << "Number of Coniferous Trees: " << container.countTreesByType(Tree::TreeType::Coniferous) << std::endl;
    std::cout << "Number of Forest Trees: " << container.countForestTrees() << std::endl;

    container.sortTreesByNameAndAge();
    container.printAllTrees();

    return 0;
}
