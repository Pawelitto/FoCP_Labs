#include <iostream>
#include <cmath>

// ---------------------------------------------------------
// TASK 1: Dice Simulation with switch statement
//
// Write a program that:
//  - Asks the user to enter a number between 1 and 6.
//  - Uses a switch statement to print that many stars (*).
//  - If the number is outside the range, print "Invalid input".
//
// Example:
//   Input: 4
//   Output: ****
//
// Hint: use "break" after each case.
// ---------------------------------------------------------


// ---------------------------------------------------------
// TASK 2: Array Initialization and Printing
//
// Create an integer array of size 10.
//  - Initialize the array so that each element equals its index * 2.
//  - Print the array in one line, separated by spaces.
//
// Example output:
//   0 2 4 6 8 10 12 14 16 18
//
// Hint: use a for loop and array indexing.
// ---------------------------------------------------------


// ---------------------------------------------------------
// TASK 3: Average of Numbers
//
// Create an array of 5 doubles.
//  - Ask the user to enter 5 numbers.
//  - Compute and print the average value.
//
// Example:
//   Input: 5 10 15 20 25
//   Output: Average = 15
//
// Hint: Use a variable to store the running sum.
// ---------------------------------------------------------


// ---------------------------------------------------------
// TASK 4: Reverse an Array
//
// Using an integer array of size 6 (with values 1 to 6):
//  - Reverse the order of the elements (in-place).
//  - Print the array before and after reversing.
//
// Example:
//   Before: 1 2 3 4 5 6
//   After:  6 5 4 3 2 1
//
// Hint: use a while loop and swap elements.
// ---------------------------------------------------------


// ---------------------------------------------------------
// TASK 5: 2D Array – Spiral Filling
//
// Create a 2D array with 4 rows and 4 columns.
// Fill it with numbers 0, 1, 2, ... in a spiral order
// (from the outside towards the center).
//
// Example (4x4):
//   0   1   2   3
//  11  12  13   4
//  10  15  14   5
//   9   8   7   6
//
// Hint:
//   - Use variables for top, bottom, left, right boundaries.
//   - Decrease the boundaries as you fill the array.
// ---------------------------------------------------------

int main()
{
    // TASK 1


    std::cout << "===== TASK 1 =====" << std::endl << std::endl;

    int user_number;

    std::cout << "Enter number between 1 and 6: ";
    std::cin >> user_number;

    if (user_number < 1 || user_number > 6) {
        std::cout << "Invalid input.";
    } else {
        switch (user_number) {
            case 1: std::cout << "*" << std::endl; break;
            case 2: std::cout << "**" << std::endl; break;
            case 3: std::cout << "***" << std::endl; break;
            case 4: std::cout << "****" << std::endl; break;
            case 5: std::cout << "*****" << std::endl; break;
            case 6: std::cout << "******" << std::endl; break;

            default: std::cout << "???"; break;
        }
    }

    std::cout << std::endl;

    std::cout << "==================" << std::endl << std::endl;


    // TASK 2


    std::cout << "===== TASK 2 =====" << std::endl << std::endl;

    const int SIZE_ARRAY_EVEN {10};
    int array_even [SIZE_ARRAY_EVEN];

    for (int i = 0; i < SIZE_ARRAY_EVEN; i++) {
        array_even[i] = i * 2;
    }

    for (int i = 0; i < SIZE_ARRAY_EVEN; i++) {
        std::cout << array_even[i] << " ";
    }

    std::cout << std::endl << std::endl << "==================" << std::endl << std::endl;


    // TASK 3


    std::cout << "===== TASK 2 =====" << std::endl << std::endl;

    const int SIZE_ARRAY_DOUBLES {5};

    double array_double [SIZE_ARRAY_DOUBLES];

    double average_sum;
    double input_number;
    for (int i = 0; i < SIZE_ARRAY_DOUBLES; i++) {
        std::cin >> input_number;
        array_double[i] = input_number;
        average_sum += input_number;
    }

    average_sum /= SIZE_ARRAY_DOUBLES;
    std::cout << std::endl << "Average: " << average_sum << std::endl;

    std::cout << std::endl << "==================" << std::endl << std::endl;


    // TASK 4


    std::cout << "===== TASK 3 =====" << std::endl << std::endl;

    const int SIZE {6};
    int array [SIZE] {1, 2, 3, 4, 5, 6};

    int left_side = 0;
    int right_side = SIZE - 1;

    std::cout << "Array before swapping: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << array[i] << " ";
    }

    while (left_side <= right_side) {
        int tmp = array[left_side];
        array[left_side] = array[right_side];
        array[right_side] = tmp;
        left_side++;
        right_side--;
    }

    std::cout << std::endl;

    std::cout << "Array after swapping: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl << std::endl << "==================" << std::endl << std::endl;


    // TASK 5


    std::cout << "===== TASK 5 =====" << std::endl << std::endl;

    const int ROWS = 4;
    const int COLS = 4;
    int spiral_array[ROWS][COLS];

    int top = 0;
    int left = 0;
    int bottom = ROWS - 1;
    int right = COLS - 1;

    int value = 0;

    while (top <= bottom && left <= right) {
        for (int col = left; col <= right; col++) {
            spiral_array[top][col] = value++;
        }
        top++;

        for (int row = top; row <= bottom; row++) {
            spiral_array[row][right] = value++;
        }
        right--;

        if (top <= bottom) {
            for (int col = right; col >= left; col--) {
                spiral_array[bottom][col] = value++;
            }
            bottom--;
        }

        if (left <= right) {
            for (int row = bottom; row >= top; row--) {
                spiral_array[row][left] = value++;
            }
            left++;
        }
    }

    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            std::cout << spiral_array[row][col] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << "==================" << std::endl << std::endl;

    return 0;
}