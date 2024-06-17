#include "src/function/function.hpp"
#include "src/BusRoute/BusRoute.hpp"


int main() {
    try {
        const std::string filePath = "src/data/data.txt";
        std::queue<std::string> rawQueue = getTokens(filePath);
        std::queue<BusRoute> BusRouteQueue = writeRouteToClass(rawQueue);

        std::cout << "До сортировки:\n";
        printBusRouteQueue(BusRouteQueue);

        std::queue<BusRoute> SortedRouteQueueByBusNumber = sortingQueueByBusNumber(BusRouteQueue);

        std::cout << "\nПосле сортировки:\n";
        printBusRouteQueue(SortedRouteQueueByBusNumber);

		std::queue<BusRoute> SortedRouteQueueByRouteNumber = sortingQueueByRouteNumber(BusRouteQueue);

        std::cout << "\nПосле сортировки:\n";
        printBusRouteQueue(SortedRouteQueueByRouteNumber);

	    std::map<std::string, BusRoute> BusRouteMap;
		BusRouteMap = queueToMap(BusRouteQueue);
		printBusRouteMap(BusRouteMap);

		printUniqueBusRoutes(SortedRouteQueueByRouteNumber);
		printDriversByBusMark(SortedRouteQueueByBusNumber);
		replaceDriver(SortedRouteQueueByBusNumber, "Шумахер", "Гамильтон");
		printDriversByBusMark(SortedRouteQueueByBusNumber);
		std::cout << "\nКол-во уникальных марок автобусов: " << countUniqueBusMarks(SortedRouteQueueByBusNumber) << '\n';

        return 0;
    } catch (std::exception& e) {
        std::cerr << "Exception! " << e.what() << '\n';
        return 0;
    }
}
