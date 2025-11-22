#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>

// TASK 1: Function Overloading - Absolute Value
// Write three overloaded functions called 'absolute' that return absolute values.
// Requirements:
// - int absolute(const int value) - returns absolute value of integer
// - double absolute(const double value) - returns absolute value of double
// - void absolute(std::vector<int> & vec) - converts all elements to absolute values in-place
// - Test all three versions with different inputs
// - For vector version, print before and after
// - Test with: absolute(-42), absolute(-3.14), absolute(vector{-5, 10, -15, 20})

int absolute(const int value) {
    if (value < 0) {
        return value * -1;
    }
    return value;
};

double absolute(const double value) {
    if (value < 0) {
        return value * -1.0;
    }
    return value;
};

void absolute(std::vector<int> & vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] < 0) {
            vec[i] *= -1;
        }
    }
};


// TASK 2: File Writing - Student Records
// Write a function that writes student records to a file.
// Requirements:
// - Function signature: bool write_students(const std::string & filename,
//                                           const std::vector<std::string> & names,
//                                           const std::vector<int> & scores)
// - Each line format: "Name: [name], Score: [score]"
// - Return true if successful, false if vectors have different sizes or file fails
// - Test with at least 5 students
// - Print success/failure message and verify file contents

bool write_students(const std::string & filename,
                    const std::vector<std::string> & names,
                    const std::vector<int> & scores) {

    if (names.size() != scores.size()) {
        return false;
    }

    std::ofstream file(filename);

    if (!file.is_open()) {
        return false;
    }

    for (size_t i = 0; i < names.size(); i++) {
        file << "Name: " << names[i] << ", Score: " << scores[i] << "\n";
    }

    return true;
}

// TASK 3: File Reading - Number Statistics
// Write functions to read numbers from a file and analyze them.
// Requirements:
// - std::vector<double> read_numbers(const std::string & filename)
//   - reads all numbers from file (one per line or space-separated)
//   - returns vector of numbers
// - int count_positive(const std::vector<double> & numbers)
//   - counts how many numbers are positive
// - int count_negative(const std::vector<double> & numbers)
//   - counts how many numbers are negative
// - First create a file with numbers, then read and analyze it
// - Print: total count, positive count, negative count, zero count

std::vector<double> read_numbers(const std::string & filename) {
    std::ifstream input (filename);
    std::vector<double> numbers;

    for (std::string line; std::getline(input, line);) {
        std::istringstream iss(line);
        double number;
        iss >> number;
        numbers.push_back(number);
    }
    return numbers;
}

int count_positive(const std::vector<double> & numbers) {
    int positive = 0;
    for (double const number : numbers) {
        if (number > 0) {
            positive++;
        }
    }
    return positive;
}

int count_negative(const std::vector<double> & numbers) {
    int negative = 0;
    for (double const number : numbers) {
        if (number < 0) {
            negative++;
        }
    }
    return negative;
}

int count_zero(const std::vector<double> & numbers) {
    int zero = 0;
    for (double const number : numbers) {
        if (number == 0) {
            zero++;
        }
    }
    return zero;
}

// TASK 4: Reference Parameters - Sort Three Values
// Write functions that work with references to sort and manipulate values.
// Requirements:
// - void sort_three(int & a, int & b, int & c) - sorts three integers in ascending order
//   (a will be smallest, c will be largest)
// - void increment_all(int & a, int & b, int & c, const int value) - adds value to all three
// - void make_equal(int & a, int & b, int & c) - sets all three to their average
// - Test with three variables initialized to: 45, 12, 33
// - Show values after each function call

void sort_three(int & a, int & b, int & c) {
    if (a > b) std::swap(a, b);
    if (b > c) std::swap(b, c);
    if (a > b) std::swap(a, b);
}

void increment_all(int & a, int & b, int & c, const int value) {
    a += value;
    b += value;
    c += value;
}

void make_equal(int & a, int & b, int & c) {
    int avg = (a + b + c) / 3;
    a = b = c = avg;
}

// TASK 5: String Stream Processing
// Write functions that use std::stringstream for string manipulation.
// Requirements:
// - std::vector<int> parse_integers(const std::string & text)
//   - extracts all integers from a string (use stringstream)
//   - example: "The year 2024 has 366 days" -> {2024, 366}
// - std::string join_strings(const std::vector<std::string> & words, const std::string & delimiter)
//   - joins vector of strings with delimiter between them
//   - example: {"Hello", "World", "!"} with ", " -> "Hello, World, !"
// - int count_tokens(const std::string & text)
//   - counts space-separated tokens using stringstream
// - Test with various strings and print results

std::vector<int> parse_integers(const std::string & text) {
    std::vector<int> numbers;
    std::stringstream ss(text);
    std::string token;

    while (ss >> token) {
        std::stringstream ts(token);
        int value;

        if (ts >> value) {
            numbers.push_back(value);
        }
    }

    return numbers;
}

std::string join_strings(const std::vector<std::string> & words, const std::string & delimiter) {
    std::stringstream ss;

    for (size_t i = 0; i < words.size(); i++) {
        ss << words[i];
        if (i + 1 < words.size()) {
            ss << delimiter;
        }
    }

    return ss.str();
}

int count_tokens(const std::string & text) {
    std::stringstream ss(text);
    std::string token;
    int count = 0;

    while (ss >> token) {
        count++;
    }

    return count;
}

// TASK 6: Recursive Array Operations
// Write recursive functions to work with arrays.
// Requirements:
// - int array_sum_recursive(const int array[], const int length, const int index = 0)
//   - recursively calculates sum of array elements
//   - base case: index >= length returns 0
// - int find_max_recursive(const int array[], const int length, const int index = 0)
//   - recursively finds maximum value in array
//   - base case: index == length-1 returns array[index]
//   - hint: return max of current element and max of rest
// - Test with array: {34, 67, 12, 89, 45, 23, 78}
// - Compare with iterative results to verify correctness

int array_sum_recursive(const int array[], const int length, const int index = 0) {
    if (index >= length) {
        return 0;
    }
    return array[index] + array_sum_recursive(array, length, index + 1);
}

int find_max_recursive(const int array[], const int length, const int index = 0) {
    if (index == length - 1) {
        return array[index];
    }

    int rest_max = find_max_recursive(array, length, index + 1);
    return std::max(array[index], rest_max);
}

// TASK 7: Multi-File Data Processing
// Create a program that processes multiple data files.
// Requirements:
// - Create struct: struct DataSummary {
//     std::string filename;
//     int line_count;
//     int word_count;
//     int char_count;
//   };
// - Write function: DataSummary analyze_file(const std::string & filename)
//   - counts lines, words (space-separated), and characters in file
//   - returns DataSummary with all statistics
// - Write function: void print_summary(const DataSummary & summary)
//   - prints all statistics in readable format
// - Write function: void compare_files(const std::string & file1, const std::string & file2)
//   - analyzes both files and prints which has more lines/words/chars
// - Create 2-3 test files with different content and analyze them

struct DataSummary {
    std::string filename;
    int line_count;
    int word_count;
    int char_count;
};

DataSummary analyze_file(const std::string & filename) {
    std::ifstream file(filename);
    DataSummary summary{filename, 0, 0, 0};

    if (!file.is_open()) {
        std::cerr << "ERROR: Cannot open file: " << filename << "\n";
        return summary;
    }

    std::string line;
    while (std::getline(file, line)) {
        summary.line_count++;

        summary.char_count += line.size();

        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            summary.word_count++;
        }
    }

    return summary;
}

void print_summary(const DataSummary & summary) {
    std::cout << "File: " << summary.filename << "\n";
    std::cout << "Lines: " << summary.line_count << "\n";
    std::cout << "Words: " << summary.word_count << "\n";
    std::cout << "Characters: " << summary.char_count << "\n\n";
}

void compare_files(const std::string & file1, const std::string & file2) {
    DataSummary s1 = analyze_file(file1);
    DataSummary s2 = analyze_file(file2);

    std::cout << "Comparing files:\n";
    std::cout << "- " << file1 << "\n";
    std::cout << "- " << file2 << "\n\n";

    std::cout << "More lines:  "
        << ((s1.line_count > s2.line_count) ? file1 : file2) << "\n";

    std::cout << "More words:  "
        << ((s1.word_count > s2.word_count) ? file1 : file2) << "\n";

    std::cout << "More chars:  "
        << ((s1.char_count > s2.char_count) ? file1 : file2) << "\n\n";
}



int main()
{
    std::cout << "====== TASK 1 ======" << "\n";


    std::cout << absolute(-42) << "\n";
    std::cout << absolute(-3.14) << "\n";

    std::vector<int> numbers {-5, 10, -15, 20};
    std::cout << "Vector before: ";
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n";

    absolute(numbers);

    std::cout << "Vector after: ";
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }


    std::cout << "\n\n" << "====== TASK 2 ======" << "\n";


    std::vector<std::string> names = {
        "Lewis Hamilton",
        "Max Verstappen",
        "Fernando Alonso",
        "Gabriel Bortoleto",
        "Piotr Skowyrski"
    };

    std::vector<int> scores = {85, 92, 78, 65, 88};

    if (write_students("../data/lab07/task2.txt", names, scores)) {
        std::cout << "Write students data to file successfully.";
    } else {
        std::cout << "Write students data to file failed.";
    }


    std::cout << "\n\n" << "====== TASK 3 ======" << "\n";


    const std::vector<double> res = read_numbers("../data/lab07/task3.txt");

    for (double const number : res) {
        std::cout << number << " ";
    }

    std::cout << "\n\nPositive numbers in file/vector: " << count_positive(res) << "\n";
    std::cout << "Negative numbers in file/vector: " << count_negative(res) << "\n";
    std::cout << "Zero in file/vector: " << count_zero(res) << "\n";


    std::cout << "\n\n" << "====== TASK 4 ======" << "\n";


    int a = 45, b = 12, c = 33;

    std::cout << "Initial values: a=" << a << " b=" << b << " c=" << c << "\n";

    sort_three(a, b, c);
    std::cout << "After sort_three: a=" << a << " b=" << b << " c=" << c << "\n";

    increment_all(a, b, c, 10);
    std::cout << "After increment_all(+10): a=" << a << " b=" << b << " c=" << c << "\n";

    make_equal(a, b, c);
    std::cout << "After make_equal: a=" << a << " b=" << b << " c=" << c << "\n";


    std::cout << "\n\n" << "====== TASK 5 ======" << "\n";


    std::string text = "The year 2024 has 366 days";
    auto nums = parse_integers(text);

    std::cout << "Parsed integers: ";
    for (int n : nums) std::cout << n << " ";
    std::cout << "\n";

    std::vector<std::string> words = {"Hello", "World", "!"};
    std::cout << "Joined: "
              << join_strings(words, ", ")
              << "\n";

    std::string text2 = "One two three four";
    std::cout << "Token count: " << count_tokens(text2) << "\n";


    std::cout << "\n\n" << "====== TASK 6 ======" << "\n";


    const int data[] = {34, 67, 12, 89, 45, 23, 78};
    const int length = sizeof(data) / sizeof(data[0]);

    int sum_rec = array_sum_recursive(data, length);
    int max_rec = find_max_recursive(data, length);

    int sum_it = 0;
    int max_it = data[0];

    for (int i = 0; i < length; i++) {
        sum_it += data[i];
        if (data[i] > max_it) {
            max_it = data[i];
        }
    }

    std::cout << "Recursive sum: " << sum_rec << "\n";
    std::cout << "Iterative sum: " << sum_it << "\n\n";

    std::cout << "Recursive max: " << max_rec << "\n";
    std::cout << "Iterative max: " << max_it << "\n";

    std::cout << "\n\n" << "====== TASK 7 ======" << "\n";

    DataSummary s1 = analyze_file("../data/lab07/task7_1.txt");
    DataSummary s2 = analyze_file("../data/lab07/task7_2.txt");
    DataSummary s3 = analyze_file("../data/lab07/task7_3.txt");

    print_summary(s1);
    print_summary(s2);
    print_summary(s3);

    compare_files("../data/lab07/task7_1.txt", "../data/lab07/task7_2.txt");


    return 0;
}