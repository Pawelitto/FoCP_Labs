#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

/* TASK 1: Apply Operation Using Function Pointer
   Write a function that takes two doubles and a pointer to a function,
   then applies that function to the two numbers and returns the result.
   The function should work with add, subtract, and multiply functions.

   Example: apply_operation(10.0, 5.0, add) should return 15.0
*/

double add_1(const double x, const double y) {
    return x + y;
};

double sub_1(const double x, const double y) {
    return x - y;
}

double mul_1(const double x, const double y) {
    return x * y;
}

double apply_operation(double a, double b, double (*op)(const double, const double)) {
    return op(a, b);
}

/* TASK 2: Array of Function Pointers
   Write a function that creates an array of function pointers (add, subtract, multiply)
   and applies all three operations to two given numbers. Store the results in a
   vector and return it.

   Example: all_operations(8.0, 2.0) should return {10.0, 6.0, 16.0}
*/
std::vector<double> all_operations(double a, double b) {
    double (*operations[])(const double, const double) = {add_1, sub_1, mul_1};

    std::vector<double> results;

    for (int i = 0; i < 3; i++) {
        results.push_back(operations[i](a, b));
    };

    return results;
}


/* TASK 3: Transform Array Using Function Pointer
   Write a function that takes a pointer to the beginning of an array,
   a pointer past the last element, and a function pointer that transforms
   each double value. Apply the transformation to all elements.

   Example: transform_array with a function that doubles values:
            {1.0, 2.0, 3.0} becomes {2.0, 4.0, 6.0}
*/

double multiply_by_2(const double x) {
    return x * 2;
}

void transform_array(double* begin, double* past_the_last,
                     double (*transform_func)(double)) {

    while (begin < past_the_last) {
        *begin = transform_func(*begin);
        begin++;
    }
}


/* TASK 4: Custom Operation with Lambda
   Write a function that takes two integers and performs a custom operation
   using std::function and a lambda. The lambda should calculate:
   (a * b) + (a - b)

   Example: custom_calc(5, 3) should return 5*3 + 5-3 = 15 + 2 = 17
*/
int custom_calc(int a, int b) {

    std::function<int(int, int)> operation = [](int a, int b) {
        return (a * b) + (a - b);
    };

    return operation(a, b);
}


/* TASK 5: Filter Array Using Pointer Arithmetic
   Write a function that takes a pointer to an array of doubles, its size,
   and a threshold value. Count how many elements are greater than the threshold
   using pointer arithmetic (no array indexing with []).

   Example: count_above_threshold({1.5, 3.7, 2.1, 4.9}, 4, 2.5) should return 2
*/
int count_above_threshold(double* arr, int size, double threshold) {
    int count = 0;

    double* end = arr + size;

    while (arr < end) {
        if (*arr > threshold) {
            count++;
        }
        arr++;
    }

    return count;
}


/* TASK 6: Typedef for Function Pointer
   Create a typedef for a function pointer that takes two doubles and returns a double.
   Then write a function that accepts this typedef as a parameter and applies it
   to calculate the result of: operation(a, b) * 2

   Example: Using add function: double_operation(4.0, 6.0, add) should return 20.0
*/
typedef double operation_func(double, double);

double double_operation(double a, double b, operation_func op) {
    return op(a, b) * 2;
}

/* TASK 7: Find Maximum Using Custom Comparator
   Write a function that finds the maximum value in an array of doubles
   using pointer arithmetic and a comparison function pointer. The comparison
   function should return true if first argument is greater than second.

   Example: find_max_with_compare({2.5, 7.1, 3.9, 5.2}, 4, greater_than)
            should return 7.1
*/
double find_max_with_compare(double* arr, int size,
                             bool (*compare)(double, double)) {
    double max = arr[0];

    for (int i = 1; i < size; i++) {
        if (compare(arr[i], max)) {
            max = arr[i];
        }
    }

    return max;
}


/* HELPER FUNCTIONS - Implement these as well */

// Helper for TASK 1, 2, 6
double add(const double l, const double p) {
    return l + p;
}

double subtract(const double l, const double p) {
    return l - p;
}

double multiply(const double l, const double p) {
    return l * p;
}

// Helper for TASK 7
bool greater_than(double a, double b) {
    return a > b;
}


/* MAIN FUNCTION - Test Your Solutions */
int main() {
    // Test TASK 1
    std::cout << "TASK 1: Apply Operation\n";

    std::cout << "Sum (5, 10): " << apply_operation(5, 10, add) << "\n";
    std::cout << "Sub (8, 7): " << apply_operation(8, 7, subtract) << "\n";
    std::cout << "Multiply (4, 8): " << apply_operation(4, 8, multiply) << "\n";

    // Test TASK 2
    std::cout << "\nTASK 2: All Operations\n";

    auto result = all_operations(8.0, 2.0);

    std::cout << "All operations: " << "\n";
    for_each(result.begin(), result.end(), [](double& x) {
        std::cout << x << "\n";
    });

    // Test TASK 3
    std::cout << "\nTASK 3: Transform Array\n";

    double numbers_3[] = {1.0, 2.0, 3.0};
    int n_3_size = 3;

    transform_array(numbers_3, numbers_3 + n_3_size, multiply_by_2);

    for (double& x : numbers_3) {
        std::cout << x << "\n";
    }

    // Test TASK 4
    std::cout << "\nTASK 4: Custom Calculation\n";

    std::cout << "Result (5, 3): " << custom_calc(5, 3) << "\n";

    // Test TASK 5
    std::cout << "\nTASK 5: Count Above Threshold\n";

    double data_5[] = {1.5, 3.7, 2.1, 4.9};
    int n_5_size = 4;

    std::cout << "Above Threshold (2.5): " << count_above_threshold(data_5, n_5_size, 2.5) << "\n";

    // Test TASK 6
    std::cout << "\nTASK 6: Double Operation\n";

    std::cout << "Result for function and double (4.0, 6.0) is: " << double_operation(4.0, 6.0, add) << "\n";

    // Test TASK 7
    std::cout << "\nTASK 7: Find Maximum\n";
    // find_max_with_compare({2.5, 7.1, 3.9, 5.2}, 4, greater_than)
    //             should return 7.1

    double data_7[] = {2.5, 7.1, 3.9, 5.2};
    int n_7_size = 4;

    double result_7 = find_max_with_compare(data_7, n_7_size, greater_than);

    std::cout << "Max value in {2.5, 7.1, 3.9, 5.2} is: " << result_7 << "\n";

    return 0;
}