#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

/* TASK 1: Print Vector Using Iterator
   
   Write a function that prints all elements of a vector using an iterator.
   Use the iterator in a for loop (not range-based for).
   Each element should be printed on a new line.
   
   Example output for vector {1, 2, 3}:
   1
   2
   3
*/
void print_vector_with_iterator(const std::vector<int>& vec)
{
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << "\n";
    }
}


/* TASK 2: Fill Vector with Sequential Numbers
   
   Write a function that fills a vector with sequential numbers starting 
   from a given value. Use std::iota from <numeric> header.
   
   Example: fill_sequential(vec, 10) should fill vec with 10, 11, 12, ...
*/
void fill_sequential(std::vector<int>& vec, int start_value)
{
    std::iota(vec.begin(), vec.end(), start_value);
}


/* TASK 3: Sort Vector in Descending Order
   
   Write a function that sorts a vector of doubles in descending order
   (from largest to smallest). Use std::sort with a lambda function.
   
   Example: {1.5, 3.2, 2.1} should become {3.2, 2.1, 1.5}
*/
void sort_descending(std::vector<double>& vec)
{
    std::sort(vec.begin(), vec.end(), [](double a, double b) {
        return a > b;
    });
}


/* TASK 4: Count Elements Greater Than Value
   
   Write a function that counts how many elements in a vector are greater
   than a given threshold. Use std::for_each with a lambda function and
   a captured variable to count.
   
   Example: count_greater_than({1, 5, 3, 7, 2}, 3) should return 2
*/
int count_greater_than(const std::vector<int>& vec, int threshold)
{
    int count = 0;

    std::for_each(vec.begin(), vec.end(), [threshold, &count](int element) {
        if (element > threshold) {
            count++;
        }
    });

    return count;
}


/* TASK 5: Calculate Sum Using Lambda
   
   Write a function that calculates the sum of all elements in a vector
   using std::for_each with a lambda function. Capture the sum variable
   by reference.
   
   Example: calculate_sum({1, 2, 3, 4}) should return 10
*/
double calculate_sum(const std::vector<double>& vec)
{
    double sum = 0.0;

    std::for_each(vec.begin(), vec.end(), [&sum](double val) {
        sum += val;
    });

    return sum;
}


/* TASK 6: Find String by Length
   
   Write a function that finds and returns the first string in a vector
   that has exactly the specified length. Use iterators and a loop.
   Return empty string if not found.
   
   Example: find_by_length({"cat", "dog", "elephant"}, 3) returns "cat"
*/
std::string find_by_length(const std::vector<std::string>& vec, int length)
{
    for (std::vector<std::string>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        if (it->length() == length) {
            return *it;
        }
    }

    return "";
}


/* TASK 7: Insert Elements in Middle
   
   Write a function that inserts all elements from one vector into the
   middle of another vector. Use vector::insert with iterators.
   
   Example: insert_in_middle({1, 2, 3, 4}, {10, 20}) 
            should result in {1, 2, 10, 20, 3, 4}
*/
void insert_in_middle(std::vector<int>& target, const std::vector<int>& source)
{
    auto middle_pos = target.begin() + (target.size() / 2);

    target.insert(middle_pos, source.begin(), source.end());
}


/* TASK 8: Filter Even Numbers
   
   Write a function that creates and returns a new vector containing only
   the even numbers from the input vector. Use std::for_each with a lambda
   function.
   
   Example: filter_even({1, 2, 3, 4, 5, 6}) should return {2, 4, 6}
*/
std::vector<int> filter_even(const std::vector<int>& vec)
{
    std::vector<int> result;

    std::for_each(vec.begin(), vec.end(), [&result](int element) {
        if (element % 2 == 0) {
            result.push_back(element);
        }
    });

    return result;
}


/* MAIN FUNCTION - Test Your Solutions */

int main() {
    std::cout << "Task 1 \n";

    std::vector<int> v1 = {1, 2, 3};
    print_vector_with_iterator(v1);


    std::cout << "Task 2 \n";

    std::vector<int> v2(5);
    fill_sequential(v2, 10);
    for (int x : v2) std::cout << x << " ";
    std::cout << std::endl;

    std::cout << "Task 3 \n";

    std::vector<double> v3 = {1.5, 3.2, 2.1};
    sort_descending(v3);
    for (double x : v3) std::cout << x << " ";

    std::cout << "\nTask 4 \n";

    std::vector<int> v4 = {1, 5, 3, 7, 2};
    int count = count_greater_than(v4, 3);
    std::cout << "Elements in {1, 5, 3, 7, 2} > 3: " << count;

    std::cout << "\nTask 5 \n";

    std::vector<double> v5 = {1.5, 3.2, 2.1, 5.6};
    double sum = calculate_sum(v5);
    std::cout << "Sum of {1.5, 3.2, 2.1, 5.6} : " << sum;

    std::cout << "\nTask 6 \n";

    std::vector<std::string> v6 = {"cat", "dog", "elephant"};
    std::string found = find_by_length(v6, 8);
    std::cout << "First string with lengh 8: " << found;

    std::cout << "\n Task 7 \n";

    std::vector<int> target = {1, 2, 3, 4};
    std::vector<int> source = {10, 20};
    insert_in_middle(target, source);
    std::cout << "Insert {10, 20} into middle of {1, 2, 3, 4}: ";
    for (int x : target) std::cout << x << " ";

    std::cout << "\n Task 8 \n";
    std::vector<int> v8 = {1, 2, 3, 4, 5, 6};
    std::vector<int> evens = filter_even(v8);
    for (int x : evens) std::cout << x << " ";

    return 0;
}