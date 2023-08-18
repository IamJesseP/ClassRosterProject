# C++ Class Roster Project

## Overview

This project has been developed in C++ to assist a university in migrating their existing student system to a new platform. The project facilitates the reading and manipulation of provided student data.

**Academics:**
* WGU Scripting and Programming - Applications


## Description

You've been tasked to implement a portion of the system based on provided requirements. An outline of these requirements is presented below, which includes the manipulation of data from the given `studentData` table. This table contains details like student ID, name, email, age, days to complete courses, and degree type.

Upon reading the data, the program creates student objects using the appropriate subclasses (based on degree type) and stores them in an array called `classRosterArray`. Outputs related to the data are printed to the console.

## Data Structure

Below is the `STUDENT DATA TABLE`:

| Student ID | First Name | Last Name | Email Address              | Age | Days in Course | Degree  |
|------------|------------|-----------|----------------------------|-----|----------------|---------|
| A1         | John       | Smith     | John1989@gmail.com         | 20  | 30, 35, 40     | SECURITY|
| A2         | Suzan      | Erickson  | Erickson_1990@gmail.com    | 19  | 50, 30, 40     | NETWORK |
| ...        | ...        | ...       | ...                        | ... | ...            | ...     |

For implementation, data should be input as:

```cpp
const string studentData[] = {
    "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY", 
    ...
};
```

**Note**: Ensure no third-party libraries are used. Submissions should be compressed into a single ZIP containing all necessary code files. Provide a screenshot or a PDF capture of the program's console run as proof of functionality.

Additionally, if any diagrams are included, they should be original (either hand-drawn or crafted via graphics software) and should not exceed 30 MB.

## Requirements & Guidelines

1. **Originality**: Make sure your work is original. Direct quotes or paraphrases should not exceed 30% of the entire submission and no more than 10% from a single source, even if correctly cited.
2. **Rubric**: Follow the provided rubric as it outlines the criteria for evaluating your work.

### Implementation:

#### A. Update Student Data

Modify the `studentData` table to include your personal details as the last item.

#### B. Project Structure

Create a C++ project with the following files:
- `degree.h`
- `student.h`, `student.cpp`
- `networkStudent.h`, `networkStudent.cpp`
- `securityStudent.h`, `securityStudent.cpp`
- `softwareStudent.h`, `softwareStudent.cpp`
- `roster.h`, `roster.cpp`

Ensure a total of 11 source code files.

#### C. Define Enumerated Data Type

In the `degree.h` file, define an enumerated data type `Degree` with the elements: `SECURITY`, `NETWORKING`, and `SOFTWARE`.

#### D. Student Class Structure

For the `Student` class:
- Define the base class in `student.h` and `student.cpp`.
- Include variables: student ID, name, email, age, array (days to complete courses), and degree types.
- Create accessor and mutator functions for all instance variables.
- Implement functions like constructors, `print()`, destructor, and `getDegreeProgram()`.

Three subclasses (`SecurityStudent`, `NetworkStudent`, and `SoftwareStudent`) should be created with the `getDegreeProgram()` function overridden.

#### E. Roster Class Structure

For the `Roster` class (`roster.cpp`):
- Create the `classRosterArray` to hold the data from `studentData` table.
- Populate `classRosterArray` with student objects.
- Implement functions like `add()`, `remove()`, `printAll()`, `printDaysInCourse()`, `printInvalidEmails()`, and `printByDegreeProgram()`.

#### F. Main Function

Add a `main()` function in `roster.cpp` for demonstrating the program functionality. The function should:
- Display course title, programming language, student ID, and name.
- Create an instance of `Roster` class and add each student to it.
- Convert provided pseudo code to functional code.
- Call destructor to release memory.

Refer to the detailed guide for a comprehensive understanding of the tasks.
