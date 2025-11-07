// TASK 1: constexpr Power Function
// Write a constexpr function called 'power' that calculates base^exponent.
// Requirements:
// - Function signature: constexpr long int power(const int base, const int exponent)
// - Use iterative approach (loop)
// - Handle exponent = 0 (return 1)
// - Test with: power(2, 10), power(5, 3), power(3, 0)
// - Declare an array with size power(2, 4) to verify compile-time evaluation

// TASK 2: consteval Fibonacci
// Write a consteval function called 'fibonacci' that returns the nth Fibonacci number.
// Requirements:
// - Function signature: consteval long int fibonacci(const int n)
// - Use recursive approach
// - Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21...
// - Test with compile-time constants: fibonacci(0), fibonacci(10), fibonacci(15)
// - Try calling it with a runtime variable and observe the compilation error

// TASK 3: Static Counter with Reset
// Write a function called 'counter' with a static variable that counts calls.
// Then write a second function called 'reset_counter' that resets the count to 0.
// Requirements:
// - Function signatures:
//   int counter()
//   void reset_counter()
// - counter() increments and returns the current count
// - Test by calling counter() 5 times, then reset_counter(), then counter() 3 more times
// - Print all returned values to verify the reset works

// TASK 4: Function with Multiple Default Parameters
// Write a function called 'print_grade' that prints student information.
// Requirements:
// - Function signature: void print_grade(const std::string name, const int score,
//                                        const std::string course = "Programming",
//                                        const std::string semester = "Fall 2025")
// - Print format: "[name] scored [score] in [course] ([semester])"
// - Test with:
//   - All 4 parameters provided
//   - Only name and score (use defaults for course and semester)
//   - Name, score, and course (use default for semester)

// TASK 5: Array Statistics Functions
// Write three functions to work with double arrays:
// Requirements:
// - double find_max(const double array[], const int length) - returns maximum value
// - double find_min(const double array[], const int length) - returns minimum value
// - double calculate_average(const double array[], const int length) - returns average
// - Test with an array: {23.5, 67.8, 12.3, 89.1, 45.6, 34.2}
// - Print all three statistics

// TASK 6: Vector Manipulation
// Write two functions that work with std::vector<int>:
// Requirements:
// - void remove_negatives(std::vector<int> & vec) - removes all negative numbers
// - int sum_elements(const std::vector<int> & vec) - returns sum of all elements
// - Test with vector: {10, -5, 20, -15, 30, -25, 40}
// - Print vector before and after removing negatives
// - Print sum before and after removing negatives
// Hint: To remove elements, create a new vector with only positive values,
//       then use vec = new_vector

// TASK 7: String Vector Operations
// Write two functions for working with std::vector<std::string>:
// Requirements:
// - void print_strings(const std::vector<std::string> & vec) - prints all strings
//   with their index: "0: first_string\n1: second_string\n..."
// - std::string find_longest(const std::vector<std::string> & vec) - returns the longest string
//   (if multiple strings have same max length, return the first one)
// - Test with: {"C++", "Python", "JavaScript", "Go", "Rust", "Assembly"}
// - Print all strings and identify the longest one

// TASK 8: Combined Challenge
// Create a program that:
// Requirements:
// - Declares a std::vector<double> to store temperatures
// - Write function: void add_temperature(std::vector<double> & temps, double temp)
// - Write function: void print_statistics(const std::vector<double> & temps) that prints:
//   - Number of readings
//   - Highest temperature
//   - Lowest temperature
//   - Average temperature
// - In main: Add at least 7 temperature readings (use push_back or your add_temperature function)
// - Call print_statistics to display the results
// - Test with temperatures like: {20.5, 22.3, 19.8, 23.1, 21.7, 18.9, 24.2}

// INSTRUCTIONS:
// - Implement each task in order
// - Test your functions in the main() function
// - Use std::cout for output
// - Add comments to explain your logic
// - Make sure your code compiles without errors

#include <iostream>
#include <string>
#include <vector>


// TODO: TASK 1 - Write your power function here

/** The function return power
 *  @return long int
 *  @param base
 *  @param exponent
 */
constexpr
long int power(const int base, const int exponent) {
    if (exponent == 0) { //
        return 1;
    } else {
        long int result = 1;

        for (int i = 1; i <= exponent; ++i) {
            result *= base;
        }

        return result;
    }
}


// TODO: TASK 2 - Write your fibonacci function here

/** Function to calculate the nth Fibonacci number using recursion
 *  @return nth Fibonacci number in type long int
 *  @param n
 */
consteval
long int fibonacci(const int n) {
    if (n <= 1){
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}


// TODO: TASK 3 - Write your counter and reset_counter functions here

static int calls {0};

/** Function incrementing static variable to count how many times counter() was used
 *  @return number of times called function counter()
 */
int counter() {
    return calls++;
}

/** Function to reseting state how many times someone called function counter() */
void reset_counter() {
    calls = 0;
}


// TODO: TASK 4 - Write your print_grade function here

/** Function print data in specific format data
 * @param name
 * @param score
 * @param course
 * @param semester
 */
void print_grade(
    const std::string name,
    const int score,
    const std::string course = "Programming",
    const std::string semester = "Fall 2025") {
    std::cout << name << " scored " << score << " in " << course << " (" << semester << ")" << std::endl;
}


// TODO: TASK 5 - Write your array statistics functions here

/** Function finds the maximum value of array
 * @return maximum value
 * @param array
 * @param length
 */
double find_max(const double array[], const int length) {
    double highest = 0;
    for (int i = 0; i < length; ++i) {
        if (array[i] > highest) {
            highest = array[i];
        }
    }
    return highest;
}

/** Function finds the minimum value of array
 * @return minimum value
 * @param array
 * @param length
 */
double find_min(const double array[], const int length) {
    double lowest = array[0];

    for (int i = 1; i < length; i++) {
        if (array[i] < lowest) {
            lowest = array[i];
        }
    }

    return lowest;
}

/** Function calculating average of array
 * @return average
 * @param array
 * @param length
 */
double calculate_average(const double array[], const int length) {
    double average = 0;
    for (int i = 0; i < length; ++i) {
        average += array[i];
    }

    return average / length;
}


// TODO: TASK 6 - Write your vector manipulation functions here

/** Function removes all negative numbers
 * @param vec
 */
void remove_negatives(std::vector<int> & vec) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] < 0) {
            vec[i] = -vec[i];
        }
    }
}

/** Function returns sum of all elements
 * @param vec
 */
int sum_elements(const std::vector<int> & vec) {
    int sum = 0;
    for (int i = 0; i < vec.size(); ++i) {
        sum += vec[i];
    }
    return sum;
}

// TODO: TASK 7 - Write your string vector functions here


// TODO: TASK 8 - Write your temperature functions here


int main()
{
    std::cout << "=== FUNDAMENTALS OF COMPUTER PROGRAMMING - PRACTICE TASKS ===\n\n";

    // TODO: TASK 1 - Test power function
    std::cout << "TASK 1: constexpr Power Function\n";
    std::cout << "--------------------------------\n";
    std::cout << power(2, 10) << " | " << power(5, 3) << " | " << power(3, 0);
    std::cout << std::endl;

    long int power_array[power(2, 4)];

    std::cout << "\n";


    // TODO: TASK 2 - Test fibonacci function
    std::cout << "TASK 2: consteval Fibonacci\n";
    std::cout << "----------------------------\n";

    // No compilation errors because we use constants
    std::cout << fibonacci(0) << " | " << fibonacci(10) << " | " << fibonacci(15);

    // int number {4};
    // std::cout << fibonacci(number) << std::endl; // COMPILATION ERROR

    std::cout << std::endl;
    std::cout << "\n";


    // TODO: TASK 3 - Test counter functions
    std::cout << "TASK 3: Static Counter with Reset\n";
    std::cout << "----------------------------------\n";

    std::cout << counter() << " | " << counter() << " | " << counter() << " | " << counter()  << " | " << counter() << std::endl;
    std::cout << "Reseting calls." << std::endl;
    reset_counter();
    std::cout << "Counting again: " << std::endl;
    std::cout << counter() << " | " << counter() << " | " << counter() << std::endl;

    std::cout << "\n";

    // TODO: TASK 4 - Test print_grade function
    std::cout << "TASK 4: Function with Default Parameters\n";
    std::cout << "-----------------------------------------\n";

    print_grade("Lewis Hamliton", 44, "Programming", "Fall 2025");
    print_grade("Max Verstappen", 129);
    print_grade("Fernando Alonso", 56, "Programming");

    std::cout << std::endl;
    std::cout << "\n";

    // TODO: TASK 5 - Test array statistics
    std::cout << "TASK 5: Array Statistics\n";
    std::cout << "------------------------\n";

    double test[] {23.5, 67.8, 12.3, 89.1, 45.6, 34.2};
    std::cout << "Average: " << calculate_average(test, 5) << std::endl;
    std::cout << "Maximum value: " << find_max(test, 5) << std::endl;
    std::cout << "Minimum value: " << find_min(test, 5) << std::endl;

    std::cout << "\n";

    // TODO: TASK 6 - Test vector manipulation
    std::cout << "TASK 6: Vector Manipulation\n";
    std::cout << "---------------------------\n";



    std::cout << "\n";

    // TODO: TASK 7 - Test string vector operations
    std::cout << "TASK 7: String Vector Operations\n";
    std::cout << "---------------------------------\n";
    // Your code here
    std::cout << "\n";

    // TODO: TASK 8 - Test temperature statistics
    std::cout << "TASK 8: Temperature Statistics\n";
    std::cout << "------------------------------\n";
    // Your code here
    std::cout << "\n";

    return 0;
}