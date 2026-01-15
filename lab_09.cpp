/** @file */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <array>
#include <utility>
#include <vector>

// Task 1: Create a struct called 'book' with fields for title, author, year of publication,
// and number of pages. Then create a vector of at least 3 books and print out the author
// of the second book in your collection.

// Task 2: Write a function that takes a vector of integers and returns a pair containing
// the sum and the average of all numbers. Test it with the vector {12, 45, 67, 23, 89, 34}.

std::pair<int, int> find_sum_avg(const std::vector<int> & numbers) {
    int sum = 0;
    int avg = 0;

    for (int num: numbers) {
        sum += num;
        avg += num;
    }

    avg /= numbers.size();

    return std::make_pair(sum, avg);
}

// Task 3: Create a std::array of 5 doubles representing temperatures in Celsius.
// Write code to find and display both the highest and lowest temperature from the array
// without using any additional functions.

// Task 4: Build a simple phone book using std::map where the key is a person's name
// and the value is their phone number. Add at least 4 entries, then write code to
// look up and display a specific person's number. Also print all entries in the phone book.

// Task 5: Define a struct called 'student' that contains name, student ID number,
// and a vector of grades. Create two students, add several grades to each,
// then calculate and print the average grade for both students.

struct Student {
    std::string name;
    int id;
    std::vector<double> grades;
};

// Task 6: Create a nested structure for a 'computer' that has fields for brand and model,
// plus a nested struct for 'processor' containing manufacturer, model, and speed in GHz.
// Initialize one computer object and print all its details.

struct Processor {
    std::string manufacturer;
    std::string model;
    double speedGHx;
};

struct Computer {
    std::string brand;
    std::string model;
    Processor cpu;
};

// Task 7: Use std::map to count how many times each character appears in the string
// "programming is fun and challenging". Display the results showing each character
// and its count, but skip spaces in your counting.

int main()
{
    // Write your solutions here

    // ==== Task 1 ====

    struct book {
        std::string title;
        std::string author;
        int year_of_publication;
        int pages_number;
    };

    std::vector<book> books = {
        {"Bez ściemy. Moja niesamowita dekada w Formule 1", "Günther Steiner", 2024, 200},
        {"Max Verstappen. Niepowstrzymany", "Mark", 2024, 300},
        {"Pięć królestw", "Brandon Mull", 2019, 300}
    };

    std::cout << "Athor second book: " << books[1].author << "\n";

    std::cout << "=====\n";
    // ==== Task 2 ====

    std::vector<int> numbers = {12, 45, 67, 23, 89, 34};

    const std::pair res = find_sum_avg(numbers);

    std::cout << "Sum: " << res.first << ", Average: " << res.second << "\n";

    std::cout << "=====\n";
    // ==== Task 3 ====

    std::array<double, 5> temperatures = {23.4, 22.7, 30.2, 18.9, 15.4};

    double highest_tem = temperatures.front();
    double lowest_tem = temperatures.front();

    for (double temp : temperatures) {
        if (temp > highest_tem) {
            highest_tem = temp;
        }
        if (temp < lowest_tem) {
            lowest_tem = temp;
        }
    }

    std::cout << "Highest temperature: " << highest_tem << "\n";
    std::cout << "Lowest temperature: " << lowest_tem << "\n";

    std::cout << "=====\n";
    // ==== Task 4 ====

    std::map<std::string, std::string> phoneBook;

    phoneBook["Max Verstappen"] = "555-0101";
    phoneBook["Lewis Hamilton"] = "513-4342";
    phoneBook["Fernando Alonso"] = "423-0434";
    phoneBook["Toto Wolff"] = "530-3261";

    std::string searchName = "Lewis Hamilton";

    std::cout << "=====\n";

    std::cout << "Search Results \n";

    if (phoneBook.find(searchName) != phoneBook.end()) {
        std::cout << searchName << "'s number is: " << phoneBook[searchName] << "\n";
    } else {
        std::cout << "Contact not found.\n";
    }

    std::cout << "=====\n";
    std::cout << " Full Phone Book: \n";
    for (const auto& entry : phoneBook) {
        std::cout << entry.first << " | Number" << entry.second << "\n";
    }

    std::cout << "=====\n";
    // ==== Task 5 ====

    Student s1;
    s1.name = "Charles Leclerc";
    s1.id = 1;
    s1.grades = {3.5, 2.0, 5.0, 3.5, 4.5, 4.0};

    Student s2;
    s2.name = "Fernando Alonso";
    s2.id = 2;
    s2.grades = {5.5, 4.0, 3.0, 2.5, 4.5, 5.0};

    double sum1 = 0;
    for (const auto& grade : s1.grades) {
        sum1 += grade;
    }
    double avg1 = sum1 / s1.grades.size();

    double sum2 = 0;
    for (const auto& grade : s2.grades) {
        sum2 += grade;
    }
    double avg2 = sum2 / s2.grades.size();

    std::cout << s1.name << " (ID: " << s1.id << ") Average: " << avg1 << "\n";
    std::cout << s2.name << " (ID: " << s2.id << ") Average: " << avg2 << "\n";

    std::cout << "=====\n";

    // ==== Task 6 ====

    Computer myPC;

    myPC.brand = "Apple";
    myPC.model = "Macbook Pro";

    myPC.cpu.manufacturer = "Apple";
    myPC.cpu.model = "M1 Pro";
    myPC.cpu.speedGHx = 3.22;

    std::cout << " Computer Spec:\n";
    std::cout << "Brand: " << myPC.brand << "\n";
    std::cout << "Model: " << myPC.model << "\n";

    std::cout << " Processor Spec:\n";
    std::cout << "Manufacturer: " << myPC.cpu.manufacturer << "\n";
    std::cout << "CPU Model: " << myPC.cpu.model << "\n";
    std::cout << "Speed: " << myPC.cpu.speedGHx << " GHz" << "\n";


    std::cout << "=====\n";

    // ==== Task 7 ====

    std::string text = "'Before you embark on a journey of revenge, dig two graves.' ― Confucius";

    std::map<char, int> charCounts;
    for (char c : text) {
        if (c == ' ') {
            continue;
        }
        charCounts[c]++;
    }

    std::cout << "Character Frequencies: " << std::endl;
    for (auto const& [character, cout] : charCounts) {
        std::cout << character << ": " << cout << "\n";
    }

    return 0;
}