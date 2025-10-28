#include <iostream>
#include <iomanip>
#include <cmath>

// --------------------------------------------------------------
// TASK 1: Numerical Precision and Type Casting
// --------------------------------------------------------------
// 1. Print the value of 0.1 with default precision and with setprecision(30).
// 2. Print results of integer division and floating-point division of two numbers (e.g., 7 and 3).
// 3. Explain the difference in output and why it happens.
// 4. Demonstrate casting int to double before division.


// --------------------------------------------------------------
// TASK 2: Conditional Statements and Operators
// --------------------------------------------------------------
// 1. Ask the user for an integer number.
// 2. Check whether the number is even or odd using modulo (%).
// 3. Use the ternary operator to compute the absolute value of the number (without using std::abs).
// 4. Print both results (even/odd and absolute value).


// --------------------------------------------------------------
// TASK 3: Loops and Increment Operators
// --------------------------------------------------------------
// 1. Using a while loop, print numbers from 5 down to 1.
// 2. Using a do-while loop, print numbers from 1 to 5.
// 3. Using a for loop, print even numbers from 0 to 10.
// 4. In each loop, demonstrate difference between pre-increment (++i) and post-increment (i++).


// --------------------------------------------------------------
// TASK 4: Working with Loops
// --------------------------------------------------------------
// 1. Write a program that sums numbers from 1 to 100 using a for loop.
// 2. Write a while loop that reads numbers from the user until the user enters 0.
//    For each number, print whether it is positive or negative.
// 3. Write a for loop that prints the first 10 squares (1, 4, 9, ...).
// 4. Use nested loops to print a simple rectangle made of '*' characters
//    (for example, 4 rows and 6 columns).

int main()
{
      std::cout << "TASK 1 OUTPUT:" << std::endl;
      std::cout << "0.1: " << 0.1 << std::endl;
      std::cout << "0.1 with setprecision(30): " << std::setprecision(30) << 0.1 << std::endl;

      std::cout << std::endl;

      std::cout << "Integer division: 7 by 3" << int (7) / 3 << std::endl;
      std::cout << "Floating point division: 7 by 3" << double (7) / 3 << std::endl;

      std::cout << std::endl;

      std::cout << "Diffrence in output is because Integer(int) is number without comma and double can have numbers behind comma because this type has floating point number" << std::endl;

      std::cout << std::endl << std::endl;


      std::cout << "TASK 2 OUTPUT:" << std::endl;
      int userInputInt;

      std::cout << "Enter an integer: ";
      std::cin >> userInputInt;

      std::cout << std::endl;

      if (userInputInt % 2 == 0) {
            std::cout << userInputInt << " is even and absolute value is: " << ((userInputInt < 0) ? -userInputInt : userInputInt ) << std::endl;
      } else {
            std::cout << userInputInt << " is odd absolute value is: " << ((userInputInt < 0) ? -userInputInt : userInputInt ) << std::endl;
      }

      std::cout << std::endl << std::endl;


      std::cout << "TASK 3 OUTPUT:" << std::endl;

      std::cout << "post-increment loop" << std::endl;
      int a = 5;
      while (a > 0) {
            std::cout << a-- << " ";
      }

      std::cout << std::endl;

      int y = 1;
      do {
            std::cout << y++ << " ";
      } while (y < 6);

      std::cout << std::endl;

      for (int i = 0; i <= 10; i++) {
            if (i % 2 == 0) {
                  std::cout << i << " ";
            }
      }

      std::cout << std::endl << std::endl;
      std::cout << "pre-increment loop" << std::endl;

      int post_a = 6;
      while (post_a > 1) {
            std::cout << --post_a << " ";
      }

      std::cout << std::endl;

      int post_y = 0;
      do {
            std::cout << ++post_y << " ";
      } while (post_y < 5);

      std::cout << std::endl;

      for (int i = 0; i <= 10; ++i) {
            if (i % 2 == 0) {
                  std::cout << i << " ";
            }
      }

      std::cout << "Conclusion: if we decided to use pre-incrementation we have to make sure that data is presented at right time in loop we have to keep in mind that loop can work in eg. 1 but 1 will be showed in next iteration" << std::endl;

      std::cout << std::endl << std::endl;

      std::cout << "TASK 4 OUTPUT:" << std::endl;

      double sum;

      for (int i = 1; i <= 100; i++) {
            sum += i;
      }

      std::cout << "Sumed numbers from 1 to 100 is: " << sum << std::endl;
      std::cout << std::endl;

      double x;
      while (true) {
            std::cout << "Enter number: ";
            std::cin >> x;
            if (x == 0) {
                  break;
            } else {
                  if ( x > 0) {
                        std::cout << x << " is positive" << std::endl;
                  } else {
                        std::cout << x << " is negative" << std::endl;
                  }
            }
      };

      std::cout << std::endl;

      for (int i = 1; i <= 10; i++) {
            std::cout << std::pow(i, 2) << " ";
      }

      std::cout << std::endl;

      for (int i = 0; i <= 3; i++) {
            for (int j = 0; j <= 5; j++) {
                  std::cout << "*";
            }

            std::cout << std::endl;
      }

      return 0;
}