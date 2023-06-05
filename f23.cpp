#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string roll_number;
    string name;
    string division;
    string address;
};

void addStudentInfo() {
    Student student;

    cout << "Enter the roll number: ";
    cin >> student.roll_number;
    cout << "Enter the name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter the division: ";
    getline(cin, student.division);
    cout << "Enter the address: ";
    getline(cin, student.address);

    ofstream file("student_info.txt", ios::app);
    if (file.is_open()) {
        file << student.roll_number << "," << student.name << "," << student.division << "," << student.address << endl;
        file.close();
        cout << "Student information added successfully." << endl;
    } else {
        cout << "Unable to open the file." << endl;
    }
}

void searchStudent() {
    string roll_number;
    cout << "Enter the roll number of the student to search: ";
    cin >> roll_number;

    ifstream file("student_info.txt");
    if (file.is_open()) {
        string line;
        bool found = false;

        while (getline(file, line)) {
            size_t pos = line.find(",");
            string current_roll_number = line.substr(0, pos);
            if (current_roll_number == roll_number) {
                found = true;
                cout << "Student information:" << endl;
                cout << line << endl;
                break;
            }
        }

        if (!found) {
            cout << "Student not found." << endl;
        }

        file.close();
    } else {
        cout << "Unable to open the file." << endl;
    }
}

void deleteStudentInfo() {
    string roll_number;
    cout << "Enter the roll number of the student to delete: ";
    cin >> roll_number;

    ifstream file("student_info.txt");
    ofstream temp("temp.txt");

    bool found = false;
    if (file.is_open() && temp.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t pos = line.find(",");
            string current_roll_number = line.substr(0, pos);
            if (current_roll_number != roll_number) {
                temp << line << endl;
            } else {
                found = true;
            }
        }
        file.close();
        temp.close();

        remove("student_info.txt");
        rename("temp.txt", "student_info.txt");

        if (found) {
            cout << "Student information deleted successfully." << endl;
        } else {
            cout << "Student not found." << endl;
        }
    } else {
        cout << "Unable to open the file." << endl;
    }
}

void displayStudentInfo() {
    string roll_number;
    cout << "Enter the roll number of the student to display: ";
    cin >> roll_number;

    ifstream file("student_info.txt");
    if (file.is_open()) {
        string line;
        bool found = false;
        while (getline(file, line)) {
            size_t pos = line.find(",");
            string current_roll_number = line.substr(0, pos);
            if (current_roll_number == roll_number) {
                cout << "Student information:" << endl;
                cout << line << endl;
                found = true;
                break;
            }
        }
        file.close();

        if (!found) {
            cout << "Student not found." << endl;
        }
    } else {
        cout << "Unable to open the file." << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "1. Add student information" << endl;
        cout << "2. Delete student information" << endl;
        cout << "3. Display student information" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudentInfo();
                break;
            case 2:
                deleteStudentInfo();
                break;
            case 3:
                displayStudentInfo();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }
}
