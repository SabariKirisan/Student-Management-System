# Student Management System

## Overview
This is a console-based **Student Management System** built in **C++**. The system allows you to manage student records with the following features:

- **Add new students**: Enter a student's ID, name, and marks.
- **View student records**: Display all students currently stored in the system.
- **Search by ID**: Find a student by their unique ID.
- **Edit student details**: Modify a student's ID, name, or marks.
- **Delete a student**: Remove a student from the records.
- **Save and load student data**: Persist student information to a file (`students.txt`) and load it back when the program starts.

## Features
- **Add Student**: Enter a student's ID, name, and marks.
- **View Students**: See all students stored in the system.
- **Search Student by ID**: Search for students using their unique ID.
- **Edit Student**: Update student information such as name, ID, or marks.
- **Delete Student**: Remove a student from the system.
- **Save Data**: Save all student records to a file so they can be loaded later.
- **Load Data**: Automatically load student records when the program starts.

## Example Usage

1. **Adding a student:**
   - Enter student ID: `1`
   - Enter student Name: `John Doe`
   - Enter student Marks: `85.5`

2. **Viewing all students:**
   - Displays all students in the system with their ID, name, and marks.

3. **Searching by ID:**
   - Enter student ID: `1`
   - Displays the student's details if found.

4. **Editing student details:**
   - Choose which detail (Name, Marks, or ID) to modify and update accordingly.

5. **Deleting a student:**
   - Remove a student by their ID from the system.

## File Storage Format
- The system saves student data in a plain text file (`students.txt`) with the following format:
- Each student's information is saved on a new line.

## Conclusion
This system helps manage student records with options to add, view, search, edit, delete, and save data efficiently. It is a simple and effective way to handle student information in a C++ console application.
