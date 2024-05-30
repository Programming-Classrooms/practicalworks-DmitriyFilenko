#include "function.hpp"

void readData(std::queue<BusRoute>& busRoutes, 
              const std::string path){
    std::ifstream fin(path);
    std::string delimiters{",./<>?:;'[ ]{}()"};
    std::string line;
    size_t cycleCount = 0;

    while(getline(fin,line)){ //Пока можем читать, читаем

    BusRoute testRoute;
    while (!line.empty()) // Пока строка не опустеет
    {
        std::string word;
        size_t size = 0;
        size_t beg = line.find_first_not_of(delimiters);
        size_t end = line.find_first_of(delimiters);
        if (beg > end){   //для исключения ошибки
        std::swap(beg,end);
        }
        size = end - beg;
        if (beg == end){ //для исправления считывания пробела
            size = 1;
        }
        word = line.substr(0, size);

        line.erase(0, size);
        bool wordHaveDelims = false;
        for (size_t i = 0; i < word.size(); ++i){
            if (word[i] == ' '){// ПЛАКИ ПЛАКИ НЕ НОРМАЛДАКИ  :(
                wordHaveDelims =true;
                break;
            }
}
    if (!wordHaveDelims) //для записи в объект класса
    {
            if (cycleCount == 0){
    testRoute.setRouteNumber(stoi(word));
            }

            if (cycleCount == 1){
	testRoute.setDriverName(word);
            }

            if (cycleCount == 2){
	testRoute.setBusNumber(stoi(word));
            }

            if (cycleCount == 3){
	testRoute.setBusMark(word);
            }
                 ++cycleCount;

         }
     }
busRoutes.push(testRoute); //запись
  cycleCount = 0;
  }
}
