// Zoe Dauphinee, recitation 1, C++ basics

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


//
// Function prototypes for tasks 15-17
//

// Task 15. Function to display a vector of ints
void print_vector(const vector<int>& vector);

// Task 16. Function to modify the vector, using indices
void double_vector(vector<int>& vector);

// Task 17. Function to modify the vector, using a ranged for
void double_with_ranged_for(vector<int>& vector);


//
// main
//
int main() { // Yes, it has to have an int for the return type
    //
    // Output
    //

    // Task 1. Printing hello ...  No use of "using namespace"
    std::cout << "hello\n";


    // Task 2  Printing hello ...  Using "using namespace"
    cout << "hello\n";


    //
    // Types and variables
    //

    // Task 3  Displaying uninitialized variable
    int x;
    cout << x << endl;
    // prints a 1

    
    // Task 4 Use the sizeof function to see the size in bytes of
    //        different types on your machine.
    int y = 17;
    int z = 2000000017;
    double pie = 3.14159;
    cout << "size of y: " << sizeof(y) << endl;
    cout << "size of z: " << sizeof(z) << endl;
    cout << "size of pie: " << sizeof(pie) << endl;
    
    // Task 5  Attempt to assign the wrong type of thing to a variable
    //x = "felix";
    // ^compilation error


    //
    // Conditions
    //

    // Task 6  Testing for a range
    if (y >= 10 && y <= 20) { cout << "True" << endl; }
    else { cout << "False"; }


    //
    // Loops and files
    //

    // Task 7  Looping, printing values 10 to 20 inclusive

    // First with a for loop
    for (int num = 10; num < 21; ++num) {
        cout << num << ' ';
    }
    cout << endl;

    // Then with a while loop
    int num = 10;
    while (num < 21) {
        cout << num << ' ';
        ++num;
    }
    cout << endl;
    
    // Finally with a do-while loop
    int num2 = 10;
    do {
        cout << num2 << ' ';
        ++num2;
    }
    while (num2 < 21);
    cout << endl;


    // Task 8  Looping to successfully open a file, asking user for the name
    fstream ifs;
    string file_name;
    do {
        cout << "input a file name: ";
        cin >> file_name;
        ifs.open(file_name);
    }
    while (!ifs);

    // Task 9  Looping, reading file word by "word".
    string word;
    while (ifs >> word) {
        cout << word << endl;
    }
    ifs.close();

    // Task 10 Open a file of integers, read it in, and display the sum.
    fstream ints_file("integers.txt");
    if (!ints_file) {
        cerr << "failed to open integers.txt";
        exit(1);
    }
    int sum = 0;
    int integer;
    while (ints_file >> integer) {
        sum += integer;
    }
    cout << "sum: " << sum << endl;
    ints_file.close();

    // Taks 11 Open and read a file of integers and words. Display the sum.
    fstream mixed_file("mixed.txt");
    if (!mixed_file) {
        cerr << "failed to open mixed.txt";
        exit(1);
    }
    int sum2 = 0;
    int integer2;
    while (mixed_file >> integer2) {
        sum2 += integer2;
    }
    cout << "sum: " << sum2 << endl;


    //
    // Vectors
    //

    // Task 12 Filling a vector of ints
    vector<int> even_ints;
    for (int num = 10; num < 101; num +=2) {
        even_ints.push_back(num);
    }
    
    // Task 13 Displaying the vector THREE times
    //         a) using the indices,
    cout << "   Task 13.a: " << endl;
    for (size_t index = 0; index < even_ints.size(); ++index) {
        cout << even_ints[index] << ' ';
    }
    cout << endl;

    //         b) using a "ranged for"
    cout << "   Task 13.b: " << endl;
    for (int num : even_ints) {
        cout << num << ' ';
    }
    cout << endl;

    //         c) using indices again but backwards
    cout << "   Task 13.c: " << endl;
    for (size_t index = even_ints.size(); index > 0; --index) {
        cout << even_ints[index - 1] << ' ';
    }
    cout << endl;

    // Task 14. Initialize a vector with the primes less than 20. 
    cout << "   Task 14: " << endl;
    vector<int> primes{1, 2, 3, 5, 7, 11, 13, 17, 19};
    for (int num : primes) {
        cout << num << ' ';
    }
    cout << endl;


    //
    // Function calls
    //
    
    // Task 15  Function to print a vector
    cout << "   Task 15: " << endl;
    print_vector(primes);

    // Task 16  Function to double the values in a vector
    cout << "   Task 16: " << endl;
    double_vector(primes);
    print_vector(primes);

    // Task 17  Function to double the values in a vector, using a ranged for 
    cout << "   Task 17: " << endl;
    double_with_ranged_for(primes);
    print_vector(primes);
}


//
// Function definitions for tasks 15-17
//

// Task 15. Function to display a vector of ints
void print_vector(const vector<int>& vector) {
    for (size_t index = 0; index < vector.size(); ++index) {
        cout << vector[index] << ' ';
    }
    cout << endl;
}

// Task 16. Function to modify the vector, using indices
void double_vector(vector<int>& vector) {
    for (size_t index = 0; index < vector.size(); ++index) {
        vector[index] *= 2;
    }
}

// Task 17. Function to modify the vector, using a ranged for
void double_with_ranged_for(vector<int>& vector) {
    for (int& num : vector) {
        num *= 2;
    }
}