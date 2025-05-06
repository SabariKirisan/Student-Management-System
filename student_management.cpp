#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Student 
{
public:
    int id;
    string name;
    float marks;

    Student() : id(0), name(""), marks(0.0f) {}

    Student(int id, const string& name, float marks) 
    {
        this->id = id;
        this->name = name;
        this->marks = marks;
    }
};

void addStudent(vector<Student>& students) 
{
    int id;
    string name;
    float marks;

    cout << "Enter Student ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Student Name: ";
    getline(cin, name);
    cout << "Enter Student Marks: ";
    cin >> marks;

    students.emplace_back(id, name, marks);
    cout << "Student added successfully!" << endl;
}

void viewStudents(const vector<Student>& students) 
{
    if (students.empty()) 
    {
        cout << "No students available!" << endl;
        return;
    }
    cout << "\nAll Students:\n";
    for (const auto& student : students) 
    {
        cout << "ID: " << student.id << ", Name: " << student.name << ", Marks: " << student.marks << endl;
    }
}

void searchStudent(const vector<Student>& students, int id) 
{
    bool found = false;
    for (const auto& student : students) 
    {
        if (student.id == id) 
        {
            cout << "Student Found: ID: " << student.id << ", Name: " << student.name << ", Marks: " << student.marks << endl;
            found = true;
            break;
        }
    }
    if (!found) 
    {
        cout << "Student with ID " << id << " not found!" << endl;
    }
}

void editStudent(vector<Student>& students) 
{
    int id;
    cout << "Enter Student ID to edit: ";
    cin >> id;

    for (auto& student : students) 
    {
        if (student.id == id) 
        {
            cout << "Editing Student: ID: " << student.id << ", Name: " << student.name << ", Marks: " << student.marks << endl;
            cout << "1. Edit Name\n";
            cout << "2. Edit Marks\n";
            cout << "3. Edit ID\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            cin.ignore();

            switch (choice) 
            {
                case 1:
                    cout << "Enter new name: ";
                    getline(cin, student.name);
                    cout << "Name updated successfully!" << endl;
                    break;
                case 2:
                    cout << "Enter new marks: ";
                    cin >> student.marks;
                    cout << "Marks updated successfully!" << endl;
                    break;
                case 3:
                    cout << "Enter new ID: ";
                    cin >> student.id;
                    cout << "ID updated successfully!" << endl;
                    break;
                default:
                    cout << "Invalid option!" << endl;
            }
            return;
        }
    }
    cout << "Student with ID " << id << " not found!" << endl;
}

void deleteStudent(vector<Student>& students)
{
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    for (auto it = students.begin(); it != students.end(); ++it)
    {
        if (it->id == id)
        {
            students.erase(it);
            cout << "Student with ID " << id << " deleted successfully!" << endl;
            return;
        }
    }

    cout << "Student with ID " << id << " not found!" << endl;
}

void saveToFile(const vector<Student>& students) 
{
    ofstream outFile("students.txt");
    for (const auto& student : students) 
    {
        outFile << student.id << "," << student.name << "," << student.marks << endl;
    }
    outFile.close();
    cout << "Student data saved to file successfully!" << endl;
}

void loadFromFile(vector<Student>& students) 
{
    ifstream inFile("students.txt");
    if (!inFile.is_open()) 
    {
        cout << "No existing student file found. Starting fresh." << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) 
    {
        int id;
        string name;
        float marks;
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);

        if (pos1 == string::npos || pos2 == string::npos)
            continue;

        id = stoi(line.substr(0, pos1));
        name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        marks = stof(line.substr(pos2 + 1));

        students.emplace_back(id, name, marks);
    }

    inFile.close();
    cout << "Student data loaded from file successfully!" << endl;
}

int main() 
{
    vector<Student> students;
    int choice;

    loadFromFile(students);

    while (true) {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Edit Student by ID\n";
        cout << "5. Delete Student by ID\n";
        cout << "6. Save and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                addStudent(students);
                break;
            case 2:
                viewStudents(students);
                break;
            case 3:
            {
                int id;
                cout << "Enter Student ID to search: ";
                cin >> id;
                searchStudent(students, id);
                break;
            }
            case 4:
                editStudent(students);
                break;
            case 5:
                deleteStudent(students);
                break;
            case 6:
                saveToFile(students);
                return 0;
            default:
                cout << "Invalid option. Please try again!" << endl;
        }
    }
}
