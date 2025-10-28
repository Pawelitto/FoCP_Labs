#include <iostream>
#include <iomanip>

/*
===========================================
LABORATORY TASKS — FUNDAMENTALS OF C++
===========================================

Task 1 — Hello, You!
--------------------
Goal: Practice basic input/output and strings.

1. Ask the user to enter their name and age.
2. Store the input in variables (std::string and int).
3. Print a message:
      Hello, Alice! You are 20 years old.
4. (Optional) Print the size (in bytes) of both variables using sizeof().


Task 2 — Simple Math
--------------------
Goal: Practice arithmetic operations and formatted output.

1. Declare two variables 'a' and 'b' as double.
2. Assign them values or read them from the user.
3. Calculate and print:
      sum = a + b
      difference = a - b
      product = a * b
      quotient = a / b
4. Use std::setprecision(3) to format the results (3 decimal places).


Task 3 — Solve a Linear Equation
--------------------------------
Goal: Practice if-else conditions and logic.

1. The equation is: a * x + b = 0
2. Ask the user to input 'a' and 'b'.
3. If a == 0:
      - If b == 0 → print "Equation always true"
      - Else → print "No solution"
4. Otherwise compute:
      x = -b / a
   and print the result.


Task 4 — True or False
----------------------
Goal: Practice boolean variables and conditional statements.

1. Declare a bool variable 'lightOn'.
2. Ask the user to type 1 for "light on" or 0 for "light off".
3. If lightOn is true → print "The room is bright!"
   Else → print "It's dark in here."
4. Try assigning other values like -1 or 3 and observe what happens.

===========================================
End of Tasks
===========================================
*/

int main ()
{
      std::cout << "==== STARTING code of task 1 ====" << std::endl;

      std::string name;
      int age;

      std::cout << "Provide your name: ";
      std::cin >> name;

      std::cout << "Provide your age: ";
      std::cin >> age;

      std::cout << std::endl;

      std::cout << "Hello, " << name << "! You are " << age << " years old." << std::endl;

      std::cout << "Size of variable name: " << sizeof(name) << " size of variable age: " << sizeof(age) << std::endl;

      std::cout << std::endl;
      std::cout << "==== ENDING code of task 1 ====" << std::endl;;
      std::cout << "==== STARTING code of task 2 ====" << std::endl;

      double a, b;

      std::cout << "Pass numbers to math operations (separate them by space): ";

      std::cin >> a >> b;

      double sum = a + b;
      double difference = a - b;
      double product = a * b;
      double quotient = a / b;

      std::cout << "Results:" << std::endl;

      std::cout << "Sum: " << std::setprecision(3) << sum  << std::endl;
      std::cout << "Difference: " << std::setprecision(3) << difference <<  std::endl;
      std::cout << "Product: " << std::setprecision(3) << product << std::endl;
      std::cout << "Quotient: " << std::setprecision(3) << quotient << std::endl;

      std::cout << std::endl;
      std::cout << "==== ENDING code of task 2 ====" << std::endl;
      std::cout << "==== STARTING code of task 3 ====" << std::endl;
      std::cout << std::endl;

      double task3_a, task3_b;

      std::cout << "Enter the first number: ";
      std::cin >> task3_a;

      std::cout << "Enter the second number: ";
      std::cin >> task3_b;

      std::cout << std::endl;

      if (task3_a == 0) {
            if (task3_b == 0) {
                  std::cout << "Equation always true" << std::endl;
            } else {
                  std::cout << "No solution" << std::endl;
            }
      } else {
            double x = -task3_b / task3_a ;
            std::cout << x << std::endl;
      }

      std::cout << std::endl;
      std::cout << "==== ENDING code of task 3 ====" << std::endl;;
      std::cout << "==== STARTING code of task 4 ====" << std::endl;

      bool lightOn;

      std::cout << "Write 1 or 0 to 'light on' or 'light off': ";
      std::cin >> lightOn;

      if (lightOn == true) {
            std::cout << "Lighting on" << std::endl;
      } else {
            std::cout << "Lighting off" << std::endl;
      }

      std::cout << std::endl;
      std::cout << "==== ENDING code of task 4 ====";

      return 0;
}