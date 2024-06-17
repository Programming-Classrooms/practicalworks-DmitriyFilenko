#include "../LinkedList/LinkedList.hpp"
#include "../Fraction/Fraction.hpp"
#include "../MyMatrix/MyMatrix.hpp"


int main() {
    try {
        // Create some Fraction objects
        Fraction f1(3, 4);
        Fraction f2(1, 2);
        Fraction f3;

        // Perform some arithmetic operations
        f3 = f1 + f2;
        std::cout << "Addition: " << f1 << " + " << f2 << " = " << f3 << std::endl;

        f3 = f1 - f2;
        std::cout << "Subtraction: " << f1 << " - " << f2 << " = " << f3 << std::endl;

        f3 = f1 * f2;
        std::cout << "Multiplication: " << f1 << " * " << f2 << " = " << f3 << std::endl;

        f3 = f1 / f2;
        std::cout << "Division: " << f1 << " / " << f2 << " = " << f3 << std::endl;

        // Comparison operations
        std::cout << f1 << " == " << f2 << " : " << (f1 == f2) << std::endl;
        std::cout << f1 << " > " << f2 << " : " << (f1 > f2) << std::endl;
        std::cout << f1 << " < " << f2 << " : " << (f1 < f2) << std::endl;

        // Unary operators
        std::cout << "Unary Minus of " << f1 << " : " << (-f1) << std::endl;

        // Increment and Decrement
        std::cout << "Increment Prefix: " << ++f1 << std::endl;
        std::cout << "Increment Postfix: " << f1++ << std::endl;
        std::cout << "Decrement Prefix: " << --f1 << std::endl;
        std::cout << "Decrement Postfix: " << f1-- << std::endl;

        // Input and Output
        std::cout << "Enter a fraction in the format (numerator/denominator): ";
        std::cin >> f3;
        std::cout << "You entered: " << f3 << std::endl;



        MyMatrix mat1(3); // Create a 3x3 matrix initialized with zeros
        std::cout << "Matrix 1:\n";
        mat1.print();

        MyMatrix mat2(3, 3); // Create a 3x3 matrix initialized with zeros
        std::cout << "Matrix 2:\n";
        mat2.print();

        // Set elements of mat1
        mat1.setElement(5, 0, 0);
        mat1.setElement(7, 1, 1);
        mat1.setElement(3, 2, 2);
        std::cout << "Matrix 1 after setting elements:\n";
        mat1.print();

        // Set elements of mat2
        mat2.setElement(1, 0, 0);
        mat2.setElement(2, 0, 1);
        mat2.setElement(3, 0, 2);
        mat2.setElement(4, 1, 0);
        mat2.setElement(5, 1, 1);
        mat2.setElement(6, 1, 2);
        mat2.setElement(7, 2, 0);
        mat2.setElement(8, 2, 1);
        mat2.setElement(9, 2, 2);
        std::cout << "Matrix 2 after setting elements:\n";
        mat2.print();

        // Perform some operations
        MyMatrix mat3 = mat1 + mat2;
        std::cout << "Matrix 1 + Matrix 2:\n";
        mat3.print();

        MyMatrix mat4 = mat1 - mat2;
        std::cout << "Matrix 1 - Matrix 2:\n";
        mat4.print();

        MyMatrix mat5 = mat1 * mat2;
        std::cout << "Matrix 1 * Matrix 2:\n";
        mat5.print();

        // Scalar operations
       // MyMatrix mat6 = mat1 * 3; // Multiply by scalar
       // std::cout << "Matrix 1 multiplied by 3:\n";
       // mat6.print();

        MyMatrix mat7 = mat2 / 2; // Divide by scalar
        std::cout << "Matrix 2 divided by 2:\n";
        mat7.print();

        // Equality check
        std::cout << "Are Matrix 1 and Matrix 2 equal? " << (mat1 == mat2) << std::endl;
        std::cin >> mat1;
        std::cout << mat1;


          LinkedList list;

    // Add some values to the list
    list.addValue(5);
    list.addValue(10);
    list.addValue(3);
    list.addValue(8);

    // Display the original list
    std::cout << "Original List: ";
    list.print();

    // Create a copy of the list using the copy constructor
    LinkedList copyList(list);

    // Display the copied list
    std::cout << "Copied List: ";
    copyList.print();
list.clear();


    // Insert a new value in the sorted order
    list.insertSorted(6);
    list.insertSorted(3);
    list.insertSorted(5);
    list.insertSorted(9);
    // Display the list after insertion
  
    list.print();

    // Pop a value from the list
    int poppedValue = list.popValue();
    std::cout << "Popped value: " << poppedValue << '\n';

    // Display the list after popping a value
    std::cout << "List after popping a value: ";
    list.print();

    } catch(const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
