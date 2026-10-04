#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// ========================================
// Student Class
// ========================================
class Student {
public:
    int id;
    string name;
    string course;
    float marks;
};

// ========================================
// Save Students to File
// ========================================
void saveStudents(const vector<Student>& students) {

    ofstream file("students.txt");

    for (int i = 0; i < students.size(); i++) {

        file << students[i].id << endl;
        file << students[i].name << endl;
        file << students[i].course << endl;
        file << students[i].marks << endl;
    }

    file.close();
}

// ========================================
// Load Students from File
// ========================================
void loadStudents(vector<Student>& students) {

    ifstream file("students.txt");

    Student s;

    while (file >> s.id) {

        file.ignore();

        getline(file, s.name);
        getline(file, s.course);

        file >> s.marks;

        students.push_back(s);
    }

    file.close();
}

// ========================================
// Main Function
// ========================================
int main() {

    vector<Student> students;

    // Load previously saved students
    loadStudents(students);

    int choice;

    while (true) {

        // ========================================
        // Menu
        // ========================================
        cout << "\n====================================\n";
        cout << "      STUDENT MANAGEMENT SYSTEM\n";
        cout << "====================================\n";

        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        // ========================================
        // Switch Case
        // ========================================
        switch (choice) {

        // ========================================
        // 1. Add Student
        // ========================================
        case 1: {

            Student s;

            cout << "\nEnter Student ID: ";
            cin >> s.id;

            cin.ignore();

            cout << "Enter Student Name: ";
            getline(cin, s.name);

            cout << "Enter Course: ";
            getline(cin, s.course);

            cout << "Enter Marks: ";
            cin >> s.marks;

            students.push_back(s);

            // Save data to file
            saveStudents(students);

            cout << "\nStudent added successfully!\n";

            break;
        }

        // ========================================
        // 2. View Students
        // ========================================
        case 2: {

            if (students.empty()) {

                cout << "\nNo students found!\n";
            }
            else {

                cout << "\n========== STUDENT LIST ==========\n";

                for (int i = 0; i < students.size(); i++) {

                    cout << "\nStudent " << i + 1 << endl;

                    cout << "ID     : "
                         << students[i].id << endl;

                    cout << "Name   : "
                         << students[i].name << endl;

                    cout << "Course : "
                         << students[i].course << endl;

                    cout << "Marks  : "
                         << students[i].marks << endl;

                    cout << "----------------------------------\n";
                }
            }

            break;
        }

        // ========================================
        // 3. Search Student
        // ========================================
        case 3: {

            int searchId;
            bool found = false;

            cout << "\nEnter Student ID to search: ";
            cin >> searchId;

            for (int i = 0; i < students.size(); i++) {

                if (students[i].id == searchId) {

                    cout << "\n========== STUDENT FOUND ==========\n";

                    cout << "ID     : "
                         << students[i].id << endl;

                    cout << "Name   : "
                         << students[i].name << endl;

                    cout << "Course : "
                         << students[i].course << endl;

                    cout << "Marks  : "
                         << students[i].marks << endl;

                    found = true;

                    break;
                }
            }

            if (!found) {

                cout << "\nStudent not found!\n";
            }

            break;
        }

        // ========================================
        // 4. Update Student
        // ========================================
        case 4: {

            int updateId;
            bool found = false;

            cout << "\nEnter Student ID to update: ";
            cin >> updateId;

            for (int i = 0; i < students.size(); i++) {

                if (students[i].id == updateId) {

                    cin.ignore();

                    cout << "Enter New Name: ";
                    getline(cin, students[i].name);

                    cout << "Enter New Course: ";
                    getline(cin, students[i].course);

                    cout << "Enter New Marks: ";
                    cin >> students[i].marks;

                    // Save updated data
                    saveStudents(students);

                    cout << "\nStudent updated successfully!\n";

                    found = true;

                    break;
                }
            }

            if (!found) {

                cout << "\nStudent not found!\n";
            }

            break;
        }

        // ========================================
        // 5. Delete Student
        // ========================================
        case 5: {

            int deleteId;
            bool found = false;

            cout << "\nEnter Student ID to delete: ";
            cin >> deleteId;

            for (int i = 0; i < students.size(); i++) {

                if (students[i].id == deleteId) {

                    students.erase(students.begin() + i);

                    // Save updated data
                    saveStudents(students);

                    cout << "\nStudent deleted successfully!\n";

                    found = true;

                    break;
                }
            }

            if (!found) {

                cout << "\nStudent not found!\n";
            }

            break;
        }

        // ========================================
        // 6. Exit
        // ========================================
        case 6:

            cout << "\nThank you for using Student Management System!\n";

            return 0;

        // ========================================
        // Invalid Choice
        // ========================================
        default:

            cout << "\nInvalid choice! Please try again.\n";
        }
    }

    return 0;
}