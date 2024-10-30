#include <iostream>
#include <cstring> // for C-string operations

using namespace std;

class Month {
private:
    int monthNo;  // 1 for January, 2 for February, ..., 12 for December

    // Helper function to convert month number to 3-letter month abbreviation
    const char* getMonthName() const {
        const char* monthNames[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                                     "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        if (monthNo >= 1 && monthNo <= 12)
            return monthNames[monthNo - 1];
        else
            return "Invalid";
    }

    // Helper function to convert 3-letter month name to month number
    int getMonthNumber(const char* monthName) const {
        const char* monthNames[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                                     "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        for (int i = 0; i < 12; ++i) {
            if (strncmp(monthName, monthNames[i], 3) == 0) {
                return i + 1;  // monthNo is 1-based
            }
        }
        return -1;  // Return -1 if not a valid month
    }

public:
    // Default constructor - Initializes to January
    Month() : monthNo(1) {}

    // Constructor to set the month using the first 3 letters of the month as arguments
    Month(const char* monthName) {
        monthNo = getMonthNumber(monthName);
        if (monthNo == -1) {
            cout << "Invalid month name provided. Defaulting to January." << endl;
            monthNo = 1; // Default to January if invalid input
        }
    }

    // Constructor to set the month using an integer value (1 for Jan, ..., 12 for Dec)
    Month(int monthValue) {
        if (monthValue >= 1 && monthValue <= 12) {
            monthNo = monthValue;
        } else {
            cout << "Invalid month number provided. Defaulting to January." << endl;
            monthNo = 1; // Default to January if invalid input
        }
    }

    // Input function that sets month from the first 3 letters of month name
    void inputFromMonthName() {
        char monthName[4]; // Buffer for month abbreviation (3 letters + null terminator)
        cout << "Enter the first 3 letters of the month name: ";
        cin >> monthName;
        monthNo = getMonthNumber(monthName);
        if (monthNo == -1) {
            cout << "Invalid month name. Defaulting to January." << endl;
            monthNo = 1; // Default to January if invalid input
        }
    }

    // Input function that sets month from an int value (1 for Jan, ..., 12 for Dec)
    void inputFromInt() {
        int monthValue;
        cout << "Enter the month number (1 for January, ..., 12 for December): ";
        cin >> monthValue;
        if (monthValue >= 1 && monthValue <= 12) {
            monthNo = monthValue;
        } else {
            cout << "Invalid month number. Defaulting to January." << endl;
            monthNo = 1;
        }
    }

    // Output function that outputs the month as the first 3 letters (C-string)
    void outputAsMonthName() const {
        cout << "Month: " << getMonthName() << endl;
    }

    // Output function that outputs the month as a number (1 for Jan, ..., 12 for Dec)
    void outputAsInt() const {
        cout << "Month number: " << monthNo << endl;
    }

    // Member function that returns the next month as a value of type Month
    Month nextMonth() const {
        if (monthNo == 12) {
            return Month(1);  // If December, wrap around to January
        } else {
            return Month(monthNo + 1);
        }
    }
};

// Test program
int main() {
    // Test default constructor
    Month m1;
    m1.outputAsMonthName(); // Should output January
    m1.outputAsInt();       // Should output 1

    // Test constructor with first 3 letters
    Month m2("Feb");
    m2.outputAsMonthName(); // Should output February
    m2.outputAsInt();       // Should output 2

    // Test constructor with integer value
    Month m3(5);
    m3.outputAsMonthName(); // Should output May
    m3.outputAsInt();       // Should output 5

    // Test input from month name
    Month m4;
    m4.inputFromMonthName(); // User inputs a valid month abbreviation
    m4.outputAsMonthName();
    m4.outputAsInt();

    // Test input from integer value
    Month m5;
    m5.inputFromInt(); // User inputs a valid month number
    m5.outputAsMonthName();
    m5.outputAsInt();

    // Test next month function
    Month next = m5.nextMonth();
    cout << "Next month: ";
    next.outputAsMonthName();
    next.outputAsInt();

    return 0;
}
