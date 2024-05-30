#include "src/function/function.hpp"
#include "src/BusRoute/BusRoute.hpp"

int main()
{
	try{

	const std::string pathToFile{"src/data/data.txt"};
	std::queue<BusRoute> busRoutes;
	std::string line;
readData(busRoutes, pathToFile);

std::cout << "\nСписок различных маршрутов:\n";

	return 0;
	}
	catch(std::exception err){
		std::cout << err.what();
	}
}
