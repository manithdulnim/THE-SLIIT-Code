#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib> 
#include <ctime>
#include <vector>
#include <string>

using namespace std;

string letters[26];

void calculator () {

    int times;
    double num1, num2, num3, num4, result1, result2, result3;
    char operation1, operation2, operation3;

    cout << "=== Welcome to the CALCULATOR === " << endl;
    cout << "*** This calculator allows up to 4 numbers to be operated on ***" << endl;
    cout << "Enter the number of input times needed (2, 3, 4): ";
    cin >> times; // Getting the number of times needed

    if (times < 2 || times > 4) {
        cout << "Invalid number of inputs. Please enter 2, 3, or 4." << endl;
    }

    // Prompt the user for input
    cout << "Enter the first number: ";
    cin >> num1;  // Input the first number

    cout << "Enter the operation (+, -, *, /, %, l for log): ";
    cin >> operation1; 

    if (times >= 2) {
        cout << "Enter the second number: ";
        cin >> num2;  // Input the second number
    }
    
    if (times >= 3) {
        cout << "Enter the operation (+, -, *, /, %, l for log): ";
        cin >> operation2;

        cout << "Enter the third number: ";
        cin >> num3;  // Input the third number
    }
    
    if (times == 4) {
        cout << "Enter the operation (+, -, *, /, %, l for log): ";
        cin >> operation3;

        cout << "Enter the fourth number: ";
        cin >> num4;  // Input the fourth number
    }

    // Perform the first operation
    if (operation1 == '+') {
        result1 = num1 + num2;
    } else if (operation1 == '-') {
        result1 = num1 - num2;
    } else if (operation1 == '*') {
        result1 = num1 * num2;
    } else if (operation1 == '/') {
        if (num2 != 0) {
            result1 = num1 / num2;
        } else {
            cout << "Error: Division by zero is not allowed." << endl;
            return;
        }
    } else if (operation1 == '%') {
        if (static_cast<int>(num2) != 0) {
            result1 = static_cast<int>(num1) % static_cast<int>(num2);
        } else {
            cout << "Error: Division by zero is not allowed." << endl;
            return;
        }
    } else if (operation1 == 'l') {
        if (num1 > 0) {
            result1 = log(num1);
        } else {
            cout << "Error: Logarithm of a non-positive number is not allowed." << endl;
            return;
        }
    } else {
        cout << "Invalid operation entered!" << endl;
        return;
    }

    if (times == 2) {
        cout << "The result is: " << fixed << setprecision(3) << result1 << endl;
        return;
    }

    // Perform the second operation
    if (operation2 == '+') {
        result2 = result1 + num3;
    } else if (operation2 == '-') {
        result2 = result1 - num3;
    } else if (operation2 == '*') {
        result2 = result1 * num3;
    } else if (operation2 == '/') {
        if (num3 != 0) {
            result2 = result1 / num3;
        } else {
            cout << "Error: Division by zero is not allowed." << endl;
            return;
        }
    } else if (operation2 == '%') {
        if (static_cast<int>(num3) != 0) {
            result2 = static_cast<int>(result1) % static_cast<int>(num3);
        } else {
            cout << "Error: Division by zero is not allowed." << endl;
            return;
        }
    } else if (operation2 == 'l') {
        if (result1 > 0) {
            result2 = log(result1);
        } else {
            cout << "Error: Logarithm of a non-positive number is not allowed." << endl;
            return;
        }
    } else {
        cout << "Invalid operation entered!" << endl;
        return;
    }

    if (times == 3) {
        cout << "The result is: " << fixed << setprecision(3) << result2 << endl;
        return;
    }

    // Perform the third operation
    if (operation3 == '+') {
        result3 = result2 + num4;
    } else if (operation3 == '-') {
        result3 = result2 - num4;
    } else if (operation3 == '*') {
        result3 = result2 * num4;
    } else if (operation3 == '/') {
        if (num4 != 0) {
            result3 = result2 / num4;
        } else {
            cout << "Error: Division by zero is not allowed." << endl;
            return;
        }
    } else if (operation3 == '%') {
        if (static_cast<int>(num4) != 0) {
            result3 = static_cast<int>(result2) % static_cast<int>(num4);
        } else {
            cout << "Error: Division by zero is not allowed." << endl;
            return;
        }
    } else if (operation3 == 'l') {
        if (result2 > 0) {
            result3 = log(result2);
        } else {
            cout << "Error: Logarithm of a non-positive number is not allowed." << endl;
            return;
        }
    } else {
        cout << "Invalid operation entered!" << endl;
        return;
    }

    cout << "The result is: " << fixed << setprecision(3) << result3 << endl;
}

void numberGuessingGame() {
    // Initialize random seed
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    const int maxAttempts = 7; // Limit the number of attempts

    cout << "====Welcome to the Number Guessing Game!=====" << endl;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "You have " << maxAttempts << " attempts to guess the correct number." << endl;

    // Game loop
    while (attempts < maxAttempts) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        // Check if the guess is correct
        if (guess == secretNumber) {
            cout << "Congratulations! You guessed the correct number " << secretNumber << " in " << attempts << " attempts!" << endl;
            return;
        }
        // Provide hints for incorrect guesses
        else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Too high! Try again." << endl;
        }

        // Check if the player has used all attempts
        if (attempts == maxAttempts) {
            cout << "Sorry! You've used all " << maxAttempts << " attempts. The correct number was " << secretNumber << "." << endl;
        }
    }
}

void initializeLetters() {
    letters[0] =  "      *      \n"
                  "     * *     \n"
                  "    *   *    \n"
                  "   *******   \n"
                  "  *       *  \n"
                  " *         * \n"
                  "*           *\n";

    letters[1] =  "******   \n"
                  "*     *  \n"
                  "******   \n"
                  "*     *  \n"
                  "*     *  \n"
                  "******   \n";

    letters[2] =  "  *****  \n"
                  " *       \n"
                  "*        \n"
                  "*        \n"
                  " *       \n"
                  "  *****  \n";

    letters[3] =  "*****    \n"
                  "*    *   \n"
                  "*     *  \n"
                  "*     *  \n"
                  "*    *   \n"
                  "*****    \n";

    letters[4] =  "*******\n"
                  "*      \n"
                  "****** \n"
                  "*      \n"
                  "*      \n"
                  "*******\n";

    letters[5] =  "*******\n"
                  "*      \n"
                  "****** \n"
                  "*      \n"
                  "*      \n"
                  "*      \n";

    letters[6] =  "  *****  \n"
                  " *       \n"
                  "*        \n"
                  "*   **** \n"
                  " *     * \n"
                  "  *****  \n";

    letters[7] =  "*     * \n"
                  "*     * \n"
                  "******* \n"
                  "*     * \n"
                  "*     * \n"
                  "*     * \n";

    letters[8] =  "*******\n"
                  "   *   \n"
                  "   *   \n"
                  "   *   \n"
                  "   *   \n"
                  "*******\n";

    letters[9] =  "*******\n"
                  "     * \n"
                  "     * \n"
                  "     * \n"
                  "*    * \n"
                  " ****  \n";

    letters[10] = "*    *  \n"
                  "*  *    \n"
                  "***     \n"
                  "*  *    \n"
                  "*    *  \n";

    letters[11] = "*       \n"
                  "*       \n"
                  "*       \n"
                  "*       \n"
                  "*       \n"
                  "******* \n";

    letters[12] =  "*     * \n"
                  "**   ** \n"
                  "* * * * \n"
                  "*  *  * \n"
                  "*     * \n"
                  "*     * \n";

    letters[13] =  "*     * \n"
                  "**    * \n"
                  "* *   * \n"
                  "*  *  * \n"
                  "*   * * \n"
                  "*    ** \n";

    letters[14] =  "  *****  \n"
                  " *     * \n"
                  "*       *\n"
                  "*       *\n"
                  " *     * \n"
                  "  *****  \n";

    letters[15] =  "******   \n"
                  "*     *  \n"
                  "******   \n"
                  "*        \n"
                  "*        \n"
                  "*        \n";

    letters[16] =  "  *****  \n"
                  " *     * \n"
                  "*       *\n"
                  "*    *  *\n"
                  " *    ** \n"
                  "  ***** *\n";

    letters[17] =  "******   \n"
                  "*     *  \n"
                  "******   \n"
                  "*  *     \n"
                  "*   *    \n"
                  "*    *   \n";

    letters[18] =  "  *****  \n"
                  " *       \n"
                  "  *****  \n"
                  "       * \n"
                  " *     * \n"
                  "  *****  \n";

    letters[19] =  "*******\n"
                  "   *   \n"
                  "   *   \n"
                  "   *   \n"
                  "   *   \n"
                  "   *   \n";

    letters[20] =  "*     * \n"
                  "*     * \n"
                  "*     * \n"
                  "*     * \n"
                  " *   *  \n"
                  "  ***   \n";

    letters[21] =  "*     * \n"
                  "*     * \n"
                  " *   *  \n"
                  " *   *  \n"
                  "  * *   \n"
                  "   *    \n";

    letters[22] =  "*     * \n"
                  "*     * \n"
                  "*  *  * \n"
                  "* * * * \n"
                  "**   ** \n"
                  "*     * \n";

    letters[23] =  "*     * \n"
                  " *   *  \n"
                  "  * *   \n"
                  "   *    \n"
                  "  * *   \n"
                  " *   *  \n"
                  "*     * \n";

    letters[24] =  "*     * \n"
                  " *   *  \n"
                  "  * *   \n"
                  "   *    \n"
                  "   *    \n"
                  "   *    \n";

    letters[25] =  "*******\n"
                  "     * \n"
                  "    *  \n"
                  "   *   \n"
                  "  *    \n"
                  "*******\n";
}

void printLetter(char letter) {
    // Convert the input letter to uppercase and ensure it's a valid letter
    if (letter >= 'A' && letter <= 'Z') {
        int index = letter - 'A';  // Calculate index (A = 0, B = 1, ...)
        cout << letters[index] << endl;  // Print the ASCII art for the letter
    } else {
        cout << "Invalid input. Please enter a capital letter between A-Z.\n";
    }
}

void processEmployeeData() {
    // Structure to store employee data
    struct Employee {
        int empNo;
        string empName;
        int pos;
        int sales;
        double netSalary;
    };

    // Vector to store all employees
    vector<Employee> employees; 

    while (true) {
        int empNo, pos, sales, salary = 0;
        double commi = 0.0, netSalary = 0.0;
        string empName;

        // Prompt for employee number
        cout << "Enter Employee No (Enter -1 to exit): E_";
        cin >> empNo;
        if (empNo == -1) {
            cout << "Exiting data entry...\n" << endl;
            break; // Exit the loop if sentinel value is entered
        }

        // Prompt for other details
        cout << "Enter Employee Name: ";
        cin.ignore(); // Clear input buffer
        getline(cin, empName);
        cout << "Enter Position (1 or 2): ";
        cin >> pos;

        // Validate position
        if (pos != 1 && pos != 2) {
            cout << "ERROR: Invalid position! Try again.\n" << endl;
            continue;
        }

        cout << "Enter number of Sales: ";
        cin >> sales;

        // Validate sales
        if (sales < 0) {
            cout << "ERROR: Invalid sales count! Try again.\n" << endl;
            continue;
        }

        // Find basic salary based on position
        salary = (pos == 1) ? 25000 : 50000;

        // Calculate commission based on sales
        if (sales >= 6000) {
            commi = sales * (120.0 / 100);
        } else if (sales >= 4000) {
            commi = sales * (115.0 / 100);
        } else if (sales >= 3000) {
            commi = sales * (110.0 / 100);
        } else {
            commi = sales * (105.0 / 100);
        }

        // Calculate net salary
        netSalary = salary + commi;

        // Store employee data in vector
        employees.push_back({empNo, empName, pos, sales, netSalary});

        // Print the entered details incrementally
        cout << "\nCurrent Entry:" << endl;
        cout << fixed << setprecision(2);
        cout << "Employee No: E_" << empNo << endl;
        cout << "Employee Name: " << empName << endl;
        cout << "Position: " << pos << endl;
        cout << "Sales: " << sales << endl;
        cout << "Net Salary: " << netSalary << endl;
        cout << "=========================\n" << endl;
    }

    // Print all entered details after exiting the loop
    if (!employees.empty()) {
        cout << "Summary of All Entered Employees:\n";
        cout << "=============================================\n";
        cout << "Emp No\tName\t\tPosition\tSales\tNet Salary\n";
        cout << "=============================================\n";
        for (const auto &emp : employees) {
            cout << "E_" << emp.empNo << "\t" << emp.empName << "\t\t" << emp.pos
                 << "\t\t" << emp.sales << "\t" << fixed << setprecision(2)
                 << emp.netSalary << endl;
        }
        cout << "=============================================\n";
    } else {
        cout << "No employee data was entered.\n";
    }
}

void dateFinder () {

    int date;

    cout << "=== Welcome to the date finder ===";
    cout << "=== This will show the relevant day in the week date you enter ===";
    cout << "Enter the date (1-7) : ";
    cin >> date;

    switch (date) {
        case 1: 
            cout << "The first day is Monday";
            break;
        case 2: 
            cout << "The second day is Tuesday";
            break;
        case 3: 
            cout << "The third day is Wednesday";
            break;
        case 4: 
            cout << "The fourth day is Thursday";
            break;
        case 5: 
            cout << "The fifth day is Friday";
            break;
        case 6: 
            cout << "The sixth day is Saturday";
            break;
        case 7: 
            cout << "The seventh day is Sunday";
            break;
        case 8: 
            cout << "The eightth day is ........" << endl;
            cout << "ARE YOU SERIOUS? There are no 8 days in a week... " << endl;
            cout << "Idiot!" << endl;
            cout << "" << endl;
            break;
    }
}

void numCounter () {
    int n, num;
    vector<int> evenNumbers, oddNumbers, squareNumbers;

    // Lambda function to check if a number is a perfect square
    auto isSquare = [](int num) {
        int root = sqrt(num);
        return (root * root == num);
    };

    cout << "Enter the count of numbers you want to input: ";
    cin >> n;

    // Read n numbers from user
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> num;

        // Sort into even or odd
        if (num % 2 == 0) {
            evenNumbers.push_back(num);
        } else {
            oddNumbers.push_back(num);
        }

        // Check if it's a square number using the lambda function
        if (isSquare(num)) {
            squareNumbers.push_back(num);
        }
    }

    // Display the results
    cout << "\nEven numbers: ";
    for (int even : evenNumbers) {
        cout << even << " ";
    }

    cout << "\nOdd numbers: ";
    for (int odd : oddNumbers) {
        cout << odd << " ";
    }

    cout << "\nSquare numbers: ";
    for (int square : squareNumbers) {
        cout << square << " ";
    }    
}

void theBanker () {
    int choice;
    double principal, rate, time, amount, interest;
    
    cout << "Welcome to the Banker Program!" << endl;
    cout << "Select an option:\n";
    cout << "1. Fixed Deposit Interest Calculation\n";
    cout << "2. Loan Interest Calculation\n";
    cout << "3. Compound Interest Calculation\n";
    cout << "4. Exit\n";
    cout << "Selection : ";
    
    cin >> choice;

    // Lambda for calculating simple interest
    auto calculateSimpleInterest = [](double principal, double rate, double time) {
        return (principal * rate * time) / 100;
    };
    
    // Lambda for calculating compound interest
    auto calculateCompoundInterest = [](double principal, double rate, double time) {
        return principal * pow((1 + rate / 100), time) - principal;
    };

    switch (choice) {
        case 1: // Fixed Deposit Interest Calculation
            cout << "Enter the Fixed Deposit Amount: ";
            cin >> principal;
            cout << "Enter the Annual Interest Rate (in %): ";
            cin >> rate;
            cout << "Enter the Time Period (in years): ";
            cin >> time;

            interest = calculateSimpleInterest(principal, rate, time);
            amount = principal + interest;
            
            cout << fixed << setprecision(2);
            cout << "\nFixed Deposit Interest: " << interest << endl;
            cout << "Total Amount after " << time << " years: " << amount << endl;
            cout << "================" << endl;
            cout << " " << endl;
            break;
        
        case 2: // Loan Interest Calculation
            cout << "Enter the Loan Amount: ";
            cin >> principal;
            cout << "Enter the Annual Interest Rate (in %): ";
            cin >> rate;
            cout << "Enter the Time Period (in years): ";
            cin >> time;

            interest = calculateSimpleInterest(principal, rate, time);
            amount = principal + interest;
            
            cout << fixed << setprecision(2);
            cout << "\nLoan Interest: " << interest << endl;
            cout << "Total Repayment Amount after " << time << " years: " << amount << endl;
            cout << "================" << endl;
            cout << " " << endl;
            break;

        case 3: // Compound Interest Calculation
            cout << "Enter the Principal Amount: ";
            cin >> principal;
            cout << "Enter the Annual Interest Rate (in %): ";
            cin >> rate;
            cout << "Enter the Time Period (in years): ";
            cin >> time;

            interest = calculateCompoundInterest(principal, rate, time);
            amount = principal + interest;

            cout << fixed << setprecision(2);
            cout << "\nCompound Interest: " << interest << endl;
            cout << "Total Amount after " << time << " years: " << amount << endl;
            cout << "================" << endl;
            cout << " " << endl;
            break;

        case 4: // Exit
            cout << "Thank you for using the Banker Program!" << endl;
            cout << "================" << endl;
            cout << " " << endl;
            return;

        default:
            cout << "Invalid choice! Please try again." << endl;
            cout << "================" << endl;
            cout << " " << endl;
    }
}

void null2 () {

}

void null1 () {

}

int main() {

    char Selection;

do {
    cout << "Enter 'C' === for the calculator or" << endl;
    cout << "Enter 'G' === for the mini game " << endl;
    cout << "Enter 'A' === for ACSII Letter art" << endl;
    cout << "Enter 'D' === for the Date finder " << endl;
    cout << "Enter 'E' === for Employee salary calculator" << endl;
    cout << "Enter 'N' === for the number counter and sorter" << endl; 
    cout << "Enter 'B' === for the Banker" << endl;
    cout << "Enter 'R' === for Dice ROLL" << endl;
    cout << "Enter 'M' === for Movie Database" << endl;
    cout << "Enter 'X' === to END THE PROGRAM" << endl;
    cout << "" << endl;
    cout << "Selection ===> ";
    cin >> Selection;

    if (Selection == 'c' || Selection == 'C') {
        // Call the calculator
        calculator ();

    } else  if (Selection == 'g' || Selection == 'G') {
        // Call the number guessing game
        numberGuessingGame();

    } else  if (Selection == 'a' || Selection == 'A') {
        // Call the ACSII art game initialization
        initializeLetters();

            char letter;
            cout << "=== Welcome to the ASCII Art Letter Generator! ===" << endl;
            cout << "Enter a capital English letter (A-Z): ";
            cin >> letter;
        // Call the letter art
        printLetter(letter);

    } else  if (Selection == 'd' || Selection == 'D') {
        // Call the date finder
        dateFinder ();

    } else  if (Selection == 'e' || Selection == 'E') {
        // Call the Employee Salary Calculator
        processEmployeeData ();

    } else  if (Selection== 'n' || Selection == 'N') {
        // Call the number counter
        numCounter ();

    } else  if (Selection == 'b' || Selection == 'B') {
        // Call the banker
        theBanker ();

    } else  if (Selection== 'n' || Selection == 'N') {
        // Call the dice roll 
        null2 ();

    } else  if (Selection == 'b' || Selection == 'B') {
        // Call the movie database
        null1 ();

    } else  if (Selection == 'x' || Selection == 'X') {
        cout << "==== Thank you for using this program ====" << endl;
        cout << " " << endl;
        cout << "      == created by Manith Dulnim == \n";
        cout << "  " << endl;
        cout << " " << endl;
        break;

    } else {
        cout << "Invalid selection!" << endl;
    }
} while (true); 

    return 0;
}
