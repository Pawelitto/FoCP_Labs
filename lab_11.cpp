#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <deque>

/* TASK 1: Reverse Print Using Iterator */
void reverse_print(const std::vector<int>& vec)
{
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        std::cout << *it << "\n";
    }
}

/* TASK 2: Multiply All Elements */
void multiply_all(std::vector<int>& vec, int factor)
{
    std::for_each(vec.begin(), vec.end(), [factor](int& n) {
        n *= factor;
    });
}

/* TASK 3: Sort Strings by Length */
void sort_by_length(std::vector<std::string>& vec)
{
    std::sort(vec.begin(), vec.end(), [](const std::string& a, const std::string& b) {
        return a.length() < b.length();
    });
}

/* TASK 4: Find Maximum Value */
int find_maximum(const std::vector<int>& vec)
{
    if (vec.empty()) return 0;

    int max_val = vec[0];

    std::for_each(vec.begin(), vec.end(), [&max_val](int n) {
        if (n > max_val) {
            max_val = n;
        }
    });

    return max_val;
}

/* TASK 5: Calculate Average */
double calculate_average(const std::vector<double>& vec)
{
    if (vec.empty()) return 0.0;

    double sum = 0.0;

    std::for_each(vec.begin(), vec.end(), [&sum](double n) {
        sum += n;
    });

    return sum / vec.size();
}

/* TASK 6: Erase All Negative Numbers */
void erase_negatives(std::vector<int>& vec)
{
    for (auto it = vec.begin(); it != vec.end(); ) {
        if (*it < 0) {
            it = vec.erase(it);
        } else {
            ++it;
        }
    }
}

/* TASK 7: Merge Two Sorted Vectors */
void merge_sorted(std::vector<int>& first, const std::vector<int>& second)
{
    first.insert(first.end(), second.begin(), second.end());

    std::sort(first.begin(), first.end());
}

/* TASK 8: Count Strings Starting With Letter */
int count_starting_with(const std::vector<std::string>& vec, char letter)
{
    int count = 0;

    std::for_each(vec.begin(), vec.end(), [&count, letter](const std::string& s) {
        if (!s.empty() && s[0] == letter) {
            count++;
        }
    });

    return count;
}

/* MAIN FUNCTION - Test Your Solutions */
int main()
{
    std::cout << "--- Task 1: Reverse Print ---\n";

    std::vector<int> t1 = {1, 2, 3};
    reverse_print(t1);


    std::cout << "\n--- Task 2: Multiply All ---\n";

    std::vector<int> t2 = {1, 2, 3};
    multiply_all(t2, 5);
    for(int i : t2) std::cout << i << " ";
    std::cout << "\n";


    std::cout << "\n--- Task 3: Sort by Length ---\n";

    std::vector<std::string> t3 = {"apple", "dog", "elephant", "cat"};
    sort_by_length(t3);
    for(const auto& s : t3) std::cout << s << " ";
    std::cout << "\n";


    std::cout << "\n--- Task 4: Find Maximum ---\n";

    std::vector<int> t4 = {3, 7, 2, 9, 1};
    std::cout << "Max: " << find_maximum(t4) << "\n";


    std::cout << "\n--- Task 5: Calculate Average ---\n";

    std::vector<double> t5 = {2.0, 4.0, 6.0, 8.0};
    std::cout << "Avg: " << calculate_average(t5) << "\n";


    std::cout << "\n--- Task 6: Erase Negatives ---\n";

    std::vector<int> t6 = {1, -2, 3, -4, 5};
    erase_negatives(t6);
    for(int i : t6) std::cout << i << " ";
    std::cout << "\n";


    std::cout << "\n--- Task 7: Merge Sorted ---\n";
    std::vector<int> first = {1, 3, 5};

    std::vector<int> second = {2, 4, 6};
    merge_sorted(first, second);
    for(int i : first) std::cout << i << " ";
    std::cout << "\n";


    std::cout << "\n--- Task 8: Count Starting With 'a' ---\n";

    std::vector<std::string> t8 = {"apple", "ant", "bear", "Alice"};
    std::cout << "Count: " << count_starting_with(t8, 'a') << "\n";

    return 0;
}