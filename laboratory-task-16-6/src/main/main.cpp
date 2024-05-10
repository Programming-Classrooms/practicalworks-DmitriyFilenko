
#include "src/Train/Train.hpp"


int32_t main() {
    // Вектор для хранения информации о поездах
    std::vector<Train> trains;

    // Чтение данных из текстового файла
    const std::string filePath = "src/data/Trains.txt";
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла!" << std::endl;
        return 1;
    }

    int32_t number, travelTime;
    std::string destination, type, departureTime;

    // Считывание данных из файла и добавление в вектор
    while (file >> number >> destination >> type >> departureTime >> travelTime) {
        Train train(number, destination, type, departureTime, travelTime);
        trains.push_back(train);
    }
    file.close();

    // Сортировка поездов по времени отправления
    sort(trains.begin(), --trains.end(), compareDepartureTime);

    // Вывод информации обо всех поездах
    std::cout << "Информация обо всех поездах:" << std::endl;
    for (auto& train : trains) {
        train.printTrainInfo();
    }

    // Запрос временного диапазона для поиска
    std::string startTime, endTime;
    std::cout << "Введите начальное время (ЧЧ:ММ): ";
    std::cin >> startTime;
    std::cout << "Введите конечное время (ЧЧ:ММ): ";
    std::cin >> endTime;

    // Вывод информации о поездах из заданного временного диапазона
    std::cout << "Поезда в заданном временном диапазоне (" << startTime << " - " << endTime << "):" << std::endl;
    for ( auto& train : trains) {
        // Сравнение времени отправления поезда с заданным диапазоном
struct tm trainDepartureTimeStruct, startTimeStruct, endTimeStruct;
strptime(train.departureTime.c_str(), "%H:%M", &trainDepartureTimeStruct);

if (mktime(&trainDepartureTimeStruct) > mktime(&startTimeStruct) && mktime(&trainDepartureTimeStruct) < mktime(&endTimeStruct)) {
    train.printTrainInfo();
}
    }

    // Запрос пункта назначения для поиска
    std::string searchDestination;
    std::cout << "Введите пункт назначения для поиска: ";
    std::cin >> searchDestination;

bool isFound = false;
for ( auto& train : trains) {
        if (train.destination == searchDestination) {
            isFound = true;
            break;
        }
    }
    if (isFound){

    // Вывод информации о поездах с заданным пунктом назначения
    std::cout << "Поезда, направляющиеся в " << searchDestination << ":" << std::endl;
    for ( auto& train : trains) {
        if (train.destination == searchDestination) {
            train.printTrainInfo();
        }
    }

    // Вывод информации о скорых поездах с заданным пунктом назначения
    std::cout << "Скорые поезда, направляющиеся в " << searchDestination << ":" << std::endl;
    for ( auto& train : trains) {
        if (train.destination == searchDestination && train.type == "скорый") {
            train.printTrainInfo();
        }
    }
    }

    // Поиск самого быстрого поезда с заданным пунктом назначения
    Train fastestTrain(-1, "", "", "", 32000);
    for ( auto& train : trains) {
        if (train.destination == searchDestination && train.travelTime < fastestTrain.travelTime) {
            fastestTrain = train;
        }
    }

    if (fastestTrain.number != -1) {
        std::cout << "Самый быстрый поезд в " << searchDestination << " это:" << std::endl;
        fastestTrain.printTrainInfo();
    } else {
        std::cout << "Нет поездов в " << searchDestination << "." << std::endl;
    }

    return 0;
}
