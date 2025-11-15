// TASK 1: constexpr Factorial Function
// Write a constexpr function called 'factorial' that calculates n!.
// Requirements:
// - Function signature: constexpr long long factorial(const int n)
// - Use iterative approach (loop)
// - Handle n = 0 and n = 1 (return 1)
// - Test with: factorial(5), factorial(7), factorial(0)
// - Create a constexpr variable storing factorial(6) and use it as array size
// - Print: "Array size determined at compile-time: [size]"

// TASK 2: consteval Prime Checker
// Write a consteval function called 'is_prime' that checks if a number is prime.
// Requirements:
// - Function signature: consteval bool is_prime(const int n)
// - Return true if n is prime, false otherwise
// - Numbers less than 2 are not prime
// - Test with compile-time constants: is_prime(2), is_prime(17), is_prime(20), is_prime(97)
// - Use if constexpr to conditionally compile different messages based on results
// - Try calling with a runtime variable and observe the compilation error

// TASK 3: Static Sum Accumulator with Query
// Write two functions: 'accumulate' adds a value to a running total, 'get_total' returns current total.
// Requirements:
// - Function signatures:
//   void accumulate(const int value)
//   int get_total()
// - accumulate() adds the value to a static variable
// - get_total() returns the current total without modifying it
// - Test by: accumulate(10), accumulate(25), get_total(), accumulate(-5), get_total()
// - Print the total after each get_total() call

// TASK 4: Function with Multiple Default Parameters for Formatting
// Write a function called 'format_price' that formats and prints a price.
// Requirements:
// - Function signature: void format_price(const double price,
//                                          const std::string currency = "USD",
//                                          const bool show_symbol = true,
//                                          const int decimal_places = 2)
// - Currency symbols: USD=$, EUR=€, GBP=£, JPY=¥
// - Format: "[symbol][price]" if show_symbol is true, "[price] [currency]" if false
// - Use std::fixed and std::setprecision for decimal places (include <iomanip>)
// - Test with:
//   - format_price(49.99) - all defaults
//   - format_price(29.50, "EUR") - custom currency
//   - format_price(99.95, "GBP", false) - no symbol
//   - format_price(1234.5, "JPY", true, 0) - zero decimals

// TASK 5: Array Sorting and Median
// Write three functions to work with integer arrays:
// Requirements:
// - void sort_array(int array[], const int length) - sorts array in ascending order
//   (implement bubble sort or selection sort)
// - double find_median(const int array[], const int length) - returns median value
//   (median is middle element if length is odd, average of two middle elements if even)
// - void print_array(const int array[], const int length) - prints array elements
// - Test with array: {45, 23, 67, 12, 89, 34, 56}
// - Print original array, sorted array, and median

// TASK 6: Vector Filtering and Transformation
// Write three functions that work with std::vector<int>:
// Requirements:
// - void keep_evens(std::vector<int> & vec) - removes all odd numbers
// - void multiply_by(std::vector<int> & vec, const int multiplier) - multiplies each element
// - int product_of_elements(const std::vector<int> & vec) - returns product of all elements
// - Test with vector: {3, 8, 15, 22, 9, 16, 5}
// - Print original vector
// - Keep only even numbers and print result
// - Multiply all elements by 3 and print result
// - Calculate and print product of final vector

// TASK 7: String Vector Search and Count
// Write three functions for working with std::vector<std::string>:
// Requirements:
// - int count_starting_with(const std::vector<std::string> & vec, const char letter)
//   - counts strings starting with specified letter (case-insensitive)
// - std::vector<std::string> filter_by_length(const std::vector<std::string> & vec, const int min_length)
//   - returns new vector containing only strings with length >= min_length
// - void print_with_length(const std::vector<std::string> & vec)
//   - prints each string with its length: "word (4 chars)"
// - Test with: {"apple", "Banana", "apricot", "Cherry", "avocado", "blueberry"}
// - Count strings starting with 'a' or 'A'
// - Filter strings with minimum length 6
// - Print all strings with their lengths

// TASK 8: Grade Management System
// Create a comprehensive grade management program:
// Requirements:
// - Create struct: struct Student { std::string name; std::vector<double> grades; };
// - Write function: void add_grade(Student & student, const double grade)
//   - adds grade to student's grade vector
// - Write function: double calculate_gpa(const Student & student)
//   - returns average of all grades (GPA)
// - Write function: char get_letter_grade(const double gpa)
//   - returns: 'A' (>=90), 'B' (>=80), 'C' (>=70), 'D' (>=60), 'F' (<60)
// - Write function: void print_student_report(const Student & student)
//   - prints: name, all grades, GPA, letter grade
// - In main: Create 2-3 students, add multiple grades to each, print reports

// TASK 9: Vector Statistics with Outlier Detection
// Create advanced statistics functions:
// Requirements:
// - double calculate_std_deviation(const std::vector<double> & vec)
//   - calculates standard deviation: sqrt(sum((x - mean)^2) / n)
//   - use <cmath> for sqrt function
// - std::vector<double> remove_outliers(const std::vector<double> & vec, const double threshold)
//   - removes values more than threshold standard deviations from mean
//   - returns new vector with outliers removed
// - void print_detailed_stats(const std::vector<double> & vec)
//   - prints: count, min, max, mean, standard deviation
// - Test with: {12.5, 15.3, 14.8, 13.9, 45.2, 14.1, 15.7, 13.2, 90.5, 14.5}
// - Print stats for original data
// - Remove outliers (threshold = 2.0) and print stats again

// TASK 10: Combined Challenge - Inventory System
// Create a simple inventory management system:
// Requirements:
// - Create struct: struct Item { std::string name; int quantity; double price; };
// - Write function: void add_item(std::vector<Item> & inventory, const Item & item)
// - Write function: double calculate_total_value(const std::vector<Item> & inventory)
//   - returns sum of (quantity * price) for all items
// - Write function: Item find_most_expensive(const std::vector<Item> & inventory)
//   - returns item with highest price
// - Write function: void print_inventory(const std::vector<Item> & inventory)
//   - prints table: "Name | Quantity | Price | Value"
// - Write function: void restock(std::vector<Item> & inventory, const std::string & name, const int amount)
//   - finds item by name and increases its quantity
// - In main: Create inventory with 5+ items, demonstrate all functions


// INSTRUCTIONS:
// - Implement each task in order
// - Test your functions thoroughly in the main() function
// - Use std::cout for output and format output clearly
// - Add meaningful comments to explain your logic
// - Pay attention to const correctness and pass-by-reference vs pass-by-value
// - Make sure your code compiles without errors or warnings

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>

// TODO: TASK 1 - Write your factorial function here
constexpr
long long factorial(const int n) {
    if (n == 0 or n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
};

// TODO: TASK 2 - Write your is_prime function here
consteval
bool is_prime(int n, int i = 2)
{
    if (n < 2) {
        return false;
    }

    if (n == 2) {
        return true;
    }

    if (n % 2 == 0) {
        return false;
    }

    if (i * i > n) {
        return true;
    }
    if (n % i == 0) {
        return false;
    }

    return is_prime(n, i + 2);
}

// TODO: TASK 3 - Write your accumulate and get_total functions here
static int sum {0};

void accumulate(const int value) {
    sum += value;
}

int get_total() {
    return sum;
}


// TODO: TASK 4 - Write your format_price function here
void format_price(const double price,
    const std::string currency = "USD",
    const bool show_symbol = true,
    const int decimal_places = 2) {

    const std::vector<std::string> symbols {"$", "€","£", "¥"};
    const std::vector<std::string> currencies {"USD", "EUR","GBP", "JPY"};

    auto it = std::find(currencies.begin(), currencies.end(), currency);

    const int index = std::distance(currencies.begin(), it);

    std::cout << std::fixed << std::setprecision(decimal_places);

    if (show_symbol) {
        std::cout << symbols[index] << price << std::endl;
    } else {
        std::cout << price << " " << currencies[index] << std::endl;
    }
}


// TODO: TASK 5 - Write your array sorting and median functions here
void sort_array(int array[], const int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int buff = array[j];
                array[j] = array[j + 1];
                array[j + 1] = buff;
            }
        }
    }
}

double find_median(const int array[], const int length) {
    if (length == 0) {
        return 0.0;
    }

    if (length % 2 == 0) {
        return array[length / 2];
    } else {
        return (array[length / 2 - 1] + array[length / 2]) / 2.0;
    }
}

void print_array(const int array[], const int length) {
    std::cout << "[";
    for (int i = 0; i < length; i++) {
        std::cout << array[i];
        if (i < length - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}


// TODO: TASK 6 - Write your vector filtering functions here
void keep_evens(std::vector<int> & vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] % 2 != 0) {
            vec.erase(vec.begin() + i);
            i--;
        }
    }
}

void multiply_by(std::vector<int> & vec, const int multiplier) {
    for (int i = 0; i < vec.size(); i++) {
        vec[i] *= multiplier;
    }
}

int product_of_elements(std::vector<int> & vec) {
    int result = 1;
    for (int i = 0; i < vec.size(); i++) {
        result *= vec[i];
    }
    return result;
}


// TODO: TASK 7 - Write your string vector search functions here
int count_starting_with(const std::vector<std::string> & vec, const char letter) {
    int result = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i][0] == letter) {
            result += 1;
        }
    }
    return result;
}

std::vector<std::string> filter_by_length(const std::vector<std::string> & vec, const int min_length) {
    std::vector<std::string> result;

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].length() >= min_length) {
            result.push_back(vec[i]);
        }
    }
    return result;
}

void print_with_length(const std::vector<std::string> & vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << "( " << vec[i].length() << " chars)" << "\n";
    }
}


// TODO: TASK 8 - Write your Student struct and grade management functions here
struct Student {
    std::string name;
    std::vector<double> grades;
};

void add_grade(Student & student, const double grade) {
    student.grades.push_back(grade);
}

double calculate_gpa(const Student & student) {
    if (student.grades.empty()) {
        return 0.0;
    }

    double sum = 0.0;
    for (double grade : student.grades) {
        sum += grade;
    }
    return sum / student.grades.size();
}

char get_letter_grade(const double gpa) {
    if (gpa >= 90) return 'A';
    if (gpa >= 80) return 'B';
    if (gpa >= 70) return 'C';
    if (gpa >= 60) return 'D';
    return 'F';
}

void print_student_report(const Student & student) {
    std::cout << "\n=== STUDENT REPORT ===" << std::endl;
    std::cout << "Name: " << student.name << std::endl;

    std::cout << "Grades: ";
    for (size_t i = 0; i < student.grades.size(); i++) {
        std::cout << student.grades[i];
        if (i < student.grades.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    double gpa = calculate_gpa(student);
    char letter_grade = get_letter_grade(gpa);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "GPA: " << gpa << std::endl;
    std::cout << "Letter Grade: " << letter_grade << std::endl;
    std::cout << "======================\n" << std::endl;
}


// TODO: TASK 9 - Write your advanced statistics functions here
double calculate_mean(const std::vector<double> & vec) {
    if (vec.empty()) return 0.0;
    double sum = 0.0;
    for (double num : vec) {
        sum += num;
    }
    return sum / vec.size();
}

double calculate_std_deviation(const std::vector<double> & vec) {
    if (vec.empty()) return 0.0;
    double mean = calculate_mean(vec);
    double sum_squared_diff = 0.0;
    for (double num : vec) {
        sum_squared_diff += (num - mean) * (num - mean);
    }
    return std::sqrt(sum_squared_diff / vec.size());
}

std::vector<double> remove_outliers(const std::vector<double> & vec, const double threshold) {
    std::vector<double> result;
    if (vec.empty()) return result;

    double mean = calculate_mean(vec);
    double std_dev = calculate_std_deviation(vec);

    for (double num : vec) {
        if (std::abs(num - mean) <= threshold * std_dev) {
            result.push_back(num);
        }
    }
    return result;
}

void print_detailed_stats(const std::vector<double> & vec) {
    if (vec.empty()) {
        std::cout << "Vector is empty" << std::endl;
        return;
    }

    double min_val = *std::min_element(vec.begin(), vec.end());
    double max_val = *std::max_element(vec.begin(), vec.end());
    double mean = calculate_mean(vec);
    double std_dev = calculate_std_deviation(vec);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Count: " << vec.size() << std::endl;
    std::cout << "Min: " << min_val << std::endl;
    std::cout << "Max: " << max_val << std::endl;
    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Standard Deviation: " << std_dev << std::endl;
}


// TODO: TASK 10 - Write your Item struct and inventory functions here
struct Item {
    std::string name;
    int quantity;
    double price;
};

void add_item(std::vector<Item> & inventory, const Item & item) {
    inventory.push_back(item);
}

double calculate_total_value(const std::vector<Item> & inventory) {
    double total = 0.0;
    for (const Item & item : inventory) {
        total += item.quantity * item.price;
    }
    return total;
}

Item find_most_expensive(const std::vector<Item> & inventory) {
    if (inventory.empty()) {
        return {"", 0, 0.0};
    }

    Item most_expensive = inventory[0];
    for (const Item & item : inventory) {
        if (item.price > most_expensive.price) {
            most_expensive = item;
        }
    }
    return most_expensive;
}

void print_inventory(const std::vector<Item> & inventory) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Name | Quantity | Price | Value" << std::endl;
    std::cout << "--------------------------------" << std::endl;

    for (const Item & item : inventory) {
        double value = item.quantity * item.price;
        std::cout << item.name << " | " << item.quantity
                  << " | $" << item.price << " | $" << value << std::endl;
    }
}

void restock(std::vector<Item> & inventory, const std::string & name, const int amount) {
    for (Item & item : inventory) {
        if (item.name == name) {
            item.quantity += amount;
            return;
        }
    }
    std::cout << "Item '" << name << "' not found in inventory." << std::endl;
}

int main()
{
    std::cout << "=== FUNDAMENTALS OF COMPUTER PROGRAMMING - LABORATORY 6 ===\n\n";

    // TODO: TASK 1 - Test factorial function
    std::cout << "TASK 1: constexpr Factorial Function\n";
    std::cout << "-------------------------------------\n";

    std::cout << "Factorial(5): " << factorial(5) << " Factorial(7): " << factorial(7) << " Factorial(0): " << factorial(0) << "\n";

    constexpr long size = factorial(6);
    int array [size];

    std::cout << "Array size determined at compile-time: " << size << "\n";

    std::cout << "\n";

    // TODO: TASK 2 - Test is_prime function
    std::cout << "TASK 2: consteval Prime Checker\n";
    std::cout << "--------------------------------\n";

    std::cout << "Is Prime(2): " << is_prime(2) << " Is Prime(17): " << is_prime(17);
    std::cout << " Is Prime(20): " << is_prime(20) << " Is Prime(97): " << is_prime(97) <<  "\n";

    constexpr bool p1 = is_prime(7);

    // Error while compilation
    // int x = 17;
    // bool p2 = is_prime(x);

    std::cout << "\n";

    // TODO: TASK 3 - Test accumulate functions
    std::cout << "TASK 3: Static Sum Accumulator\n";
    std::cout << "-------------------------------\n";

    accumulate(10);
    accumulate(25);

    std::cout << get_total() << "\n";

    accumulate(-5);

    std::cout << get_total() << "\n";


    std::cout << "\n";

    // TODO: TASK 4 - Test format_price function
    std::cout << "TASK 4: Price Formatting with Defaults\n";
    std::cout << "---------------------------------------\n";

    format_price(49.99);
    format_price(29.50, "EUR");
    format_price(99.95, "GBP", false);
    format_price(1234.5, "JPY", true, 0);

    std::cout << "\n";

    // TODO: TASK 5 - Test array sorting and median
    std::cout << "TASK 5: Array Sorting and Median\n";
    std::cout << "---------------------------------\n";

    const int SIZE = 7;
    int array_2[SIZE] = {45, 23, 67, 12, 89, 34, 56};

    std::cout << "Original array: ";
    print_array(array_2, SIZE);

    sort_array(array_2, SIZE);

    std::cout << "Sorted array: ";
    print_array(array_2, SIZE);

    double median = find_median(array_2, SIZE);
    std::cout << "Median: " << median << "\n";


    std::cout << "\n";

    // TODO: TASK 6 - Test vector filtering
    std::cout << "TASK 6: Vector Filtering and Transformation\n";
    std::cout << "--------------------------------------------\n";

    std::vector<int> vector_task_6 {3, 8, 15, 22, 9, 16, 5};

    std::cout << "[ ";
    for (int i = 0; i < vector_task_6.size(); i++) {
        std::cout << vector_task_6[i] << " ";
    }
    std::cout << "]" << "\n";

    keep_evens(vector_task_6);

    std::cout << "Only even numbers: [ ";
    for (int i = 0; i < vector_task_6.size(); i++) {
        std::cout << vector_task_6[i] << " ";
    }
    std::cout << "]" << "\n";

    multiply_by(vector_task_6, 3);

    std::cout << "Multiplied numbers: [ ";
    for (int i = 0; i < vector_task_6.size(); i++) {
        std::cout << vector_task_6[i] << " ";
    }
    std::cout << "]" << "\n";

    std::cout << "Product of final vector: " << product_of_elements(vector_task_6) << "\n";

    std::cout << "\n";

    // TODO: TASK 7 - Test string vector search
    std::cout << "TASK 7: String Vector Search and Count\n";
    std::cout << "---------------------------------------\n";

    std::vector<std::string> fruits {"apple", "Banana", "apricot", "Cherry", "avocado", "blueberry"};

    print_with_length(fruits);

    const std::vector<std::string> filtered_fruits = filter_by_length(fruits, 6);

    std::cout << "\n" <<  "Filtered fruits: " << "\n";
    for (int i = 0; i < filtered_fruits.size(); i++) {
        std::cout << filtered_fruits[i] << "\n";
    }

    std::cout << "\n" << "Fruits that starts with 'a': " << count_starting_with(fruits, 'a') << "\n";

    std::cout << "\n";

    // TODO: TASK 8 - Test grade management
    std::cout << "TASK 8: Grade Management System\n";
    std::cout << "--------------------------------\n";

    Student student1 = {"John Smith", {}};
    Student student2 = {"Emily Johnson", {}};
    Student student3 = {"Michael Brown", {}};

    add_grade(student1, 85.5);
    add_grade(student1, 92.0);
    add_grade(student1, 78.5);
    add_grade(student1, 88.0);

    add_grade(student2, 75.0);
    add_grade(student2, 82.5);
    add_grade(student2, 79.0);
    add_grade(student2, 91.5);
    add_grade(student2, 68.0);

    add_grade(student3, 95.0);
    add_grade(student3, 89.5);
    add_grade(student3, 93.0);
    add_grade(student3, 87.5);

    print_student_report(student1);
    print_student_report(student2);
    print_student_report(student3);

    std::cout << "\n";

    // TODO: TASK 9 - Test statistics with outliers
    std::cout << "TASK 9: Statistics with Outlier Detection\n";
    std::cout << "------------------------------------------\n";

    std::vector<double> data = {12.5, 15.3, 14.8, 13.9, 45.2, 14.1, 15.7, 13.2, 90.5, 14.5};

    std::cout << "Original data statistics: " << "\n";
    print_detailed_stats(data);

    std::vector<double> filtered_data = remove_outliers(data, 2.0);

    std::cout << "\nFiltered data (outliers removed)" << "\n";
    print_detailed_stats(filtered_data);

    std::cout << "\n";

    // TODO: TASK 10 - Test inventory system
    std::cout << "TASK 10: Inventory Management System\n";
    std::cout << "-------------------------------------\n";

    std::vector<Item> inventory;

    add_item(inventory, {"Laptop", 5, 999.99});
    add_item(inventory, {"Mouse", 20, 25.50});
    add_item(inventory, {"Keyboard", 15, 75.00});
    add_item(inventory, {"Monitor", 8, 299.99});
    add_item(inventory, {"Headphones", 12, 149.99});

    std::cout << "\nCurrent inventory:" << "\n";
    print_inventory(inventory);

    std::cout << "\nTotal inventory value: $" << calculate_total_value(inventory) << "\n";

    Item expensive = find_most_expensive(inventory);
    std::cout << "Most expensive item: " << expensive.name << " ($" << expensive.price << ")" << "\n";

    std::cout << "\nRestocking monitors by 3 units..." << "\n";
    restock(inventory, "Monitor", 3);

    std::cout << "\nInventory after restocking:" << "\n";
    print_inventory(inventory);

    std::cout << "\nNew total inventory value: $" << calculate_total_value(inventory) << "\n";

    std::cout << "\n";

    std::cout << "=== ALL TASKS COMPLETED ===\n";
    return 0;
}