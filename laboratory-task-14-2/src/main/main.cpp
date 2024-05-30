#include "src/session1student/session1student.hpp"
#include "src/session2student/session2student.hpp"


int main() {
    int32_t grades1[4] = {80, 75, 90, 85};
    int32_t grades11[4] = {56, 75, 45, 65};

    int32_t grades2[5] = {70, 65, 80, 75, 85};

    Session1Student student1("BEPKUT", 1, "7121", 12345, grades11);
    Session1Student student2("HarryPotter", 1, "7121", 123456, grades1);
    Session1Student student3("Soloway", 1, "7121", 1234567, grades1);
    Session1Student student4("MrCantik", 1, "7121", 12345678, grades11);

    Session2Student student5("Petya", 2, "7111", 5432231, grades11, grades2);
    Session2Student student6("Yura", 2, "7111", 54322721, grades11, grades2);
    Session2Student student7("Treadchik", 2, "7111", 54228321, grades1, grades2);


    std::cout << student1 << std::endl;
    std::cout << student2 << std::endl;
    std::cout << student3 << std::endl;
    std::cout << student4 << std::endl;
    std::cout << student5 << std::endl;
    std::cout << student6 << std::endl;
    std::cout << student7 << std::endl;



    std::cout << "Student 1 Average: " << student1.calculateAverage() << std::endl;
    std::cout << "Student 2 Average: " << student2.calculateAverage() << std::endl;

    return 0;
}
