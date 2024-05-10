
#include "../function/function.hpp"


int32_t main()
{
    try{
    srand(time(NULL));
    std::vector<int32_t> numbers;
    int32_t num;

    std::cout << "Enter numbers (enter a non-integer to stop):" << std::endl;
    while (std::cin >> num) {
        numbers.push_back(num);
    }
if (numbers.size() == 0) {
throw std::runtime_error("No numbers entered");
}
    // вывод элементов вектора
    std::cout << "Numbers stored in the numbers:" << std::endl;
    for (int32_t n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // вывод суммы вектора
    std::cout << "Sum is: " << std::accumulate(numbers.begin(), numbers.end(), 0) << std::endl;
    int32_t compareNumber = 0;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // пропускаем все до символа новой строки
    std::cout << "Enter number to compare: " << std::endl;
    std::cin >> compareNumber;
    std::cout << "Amount of numbers equal to " << compareNumber << ": " 
        << std::count(numbers.begin(), numbers.end(), compareNumber) << std::endl;
    std::cout << "Enter number to compare: " << std::endl;
    std::cin >> compareNumber;
    std::cout << "Amount of numbers more than " << compareNumber << ": " 
        << std::count_if(numbers.begin(), numbers.end(), [compareNumber](int32_t i) { return i > compareNumber; }) << std::endl;

    int32_t middle = std::accumulate(numbers.begin(), numbers.end(), 0) / numbers.size();
    std::cout << "Middle number: " << middle << std::endl;
    std::replace_if(numbers.begin(), numbers.end(), [](int32_t i) { return i == 0; }, middle);
    std::cout << "Replaced numbers:" << std::endl;
    for (int32_t n : numbers) {
    std::cout << n << " ";
    }
    std::cout << std::endl;

    int32_t leftPos;
    int32_t rightPos;
    std::cout << "Enter leftPos border: " << std::endl;
    std::cin >> leftPos;
    std::cout << "Enter rightPos border: " << std::endl;
    std::cin >> rightPos;

    if (leftPos < 0 || rightPos > numbers.size()) 
    {
        std::cerr << "Invalid range" << std::endl;
        return 1;
    }   

    if (leftPos > rightPos) {
        std::swap(leftPos, rightPos);
    }
    std::vector <int32_t> numbersInRange;

    std::copy_if(numbers.begin() + leftPos, numbers.begin() + rightPos + 1, std::back_inserter(numbersInRange), [](int32_t i) { return true; });

    std::cout << "Numbers in range: " << std::endl;
    for (int32_t n : numbersInRange) {
        std::cout << n << " ";
    }
    int32_t sumInRange = std::accumulate(numbersInRange.begin(), numbersInRange.end(), 0);
    std::cout << "\nSum in range: " << sumInRange << std::endl;
    std::transform(numbers.begin(), numbers.end(), numbers.begin(), [sumInRange](int32_t i) { return i + sumInRange; });
    std::cout << "Transformed numbers:" << std::endl;
    for (int32_t n : numbers) {
     std::cout << n << " ";
    }

    int32_t minValue = numbers[0];
    int32_t maxValue = numbers[0];
    
    for (int32_t num : numbers) {
        if (num < minValue) {
            minValue = num;
        }
        if (num > maxValue) {
            maxValue = num;
        }
    }
    
    for (int32_t& num : numbers) {
        if (std::abs(num) % 2 == 0) {
            num = maxValue - minValue;
        }
    }
    std::cout << "\nModified numbers:" << std::endl;
    for (int32_t num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "Unique numbers:" << std::endl;

    std::set<int32_t> uniqueValues;
    
    for (int32_t num : numbers) {
        if (uniqueValues.find(std::abs(num)) == uniqueValues.end()) {
            uniqueValues.insert(std::abs(num));
            std::cout << num << " ";
        }
    }
    std::cout << std::endl;
    //task 3

    std::vector <std::string> words;
    std::string word;
    std::ifstream fin("src/data/something.txt");
    while (fin >> word) {
        words.push_back(word);
    }
    fin.close();
    for (std::string& word : words) {
     std::cout << word << " ";
    }
    std::cout << std::endl;

    std::sort(words.begin(), words.end());
    for (std::string& word : words) {
     std::cout << word << " ";
    }
    std::cout << std::endl;
    //вывод элементов на заданную букву
    char letter;
    std::cout << "Enter letter: " << std::endl;
    std::cin >> letter;
    for (std::string& word : words) {
        if (word[0] == letter) {
            std::cout << word << " ";
        }
    }
    std::cout << std::endl;

    //Удаление элементов начинающихся на заданную букву
    words.erase(std::remove_if(words.begin(), words.end(), [letter](std::string& word) {
        return word[0] == letter;
    }));
    for (std::string& word : words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    //task 4
    std::vector< std::vector <int32_t> > matrix;
    int32_t rows, cols;
    std::cout << "Enter rows and cols: " << std::endl;
    std::cin >> rows >> cols;
    if (rows <= 0 || cols <= 0) {
        throw std::runtime_error("Invalid rows or cols");
    }
    for (size_t i = 0; i < rows; ++i) {
        std::vector<int32_t> row;
        for (int32_t j = 0; j < cols; ++j) {
            int32_t num;
            num = rand() % 100;
            row.push_back(num);
        }
        matrix.push_back(row);
    }

    std::cout << "randomly generated matrix:" << std::endl;
    print(matrix, rows, cols);

    //вызов функции удаления максимального элемента матрицы
    deleteMaxElement(matrix, rows, cols);

//упорядочить строки матрицы по возрастанию сумм элементов строк (без
//использования алгоритма sort)

   sortWithoutSorting(matrix, rows, cols);

    std::cout << "sorted matrix without max element:" << std::endl;
    print(matrix, rows, cols);

return 0;

    }
    catch(std::exception err){
        std::cerr << "OOPS! Exception: " << err.what() <<std::endl;
        return 0;
    }
}
