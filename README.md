# 🎓 CGPA Calculator System (C++)

## 📌 Overview

The **CGPA Calculator System** is a C++ console-based application designed to calculate a student's GPA and overall CGPA.

The project is implemented using **Object-Oriented Programming (OOP)** concepts and provides an easy-to-use menu system for managing multiple semesters and courses.

---

## ✨ Features

✅ Object-Oriented Design using Classes  
✅ Add multiple semesters  
✅ Add multiple courses per semester  
✅ Calculate Semester GPA  
✅ Calculate real cumulative CGPA  
✅ Letter grade validation  
✅ Credit hours validation  
✅ Display all semester details  
✅ Interactive menu system  
✅ Clean and organized code with comments  

---

## 🛠️ Technologies Used

- **Programming Language:** C++
- **Concepts:**
  - Classes & Objects
  - Encapsulation
  - Vectors
  - Functions
  - Loops
  - Conditional Statements

---

## 📂 Project Structure

```
CGPA-Calculator/
│
├── main.cpp        # Main source code
│
└── README.md       # Project documentation
```

---

# 🧠 Program Design

The project is divided into three main classes:

## 1️⃣ Course Class

Responsible for storing and managing course information:

- Course name
- Letter grade
- Credit hours
- Grade point calculation

Example:

```
Course:
- Mathematics
- Grade: A
- Credits: 3
```

---

## 2️⃣ Semester Class

Handles semester-related operations:

- Adding courses
- Calculating semester GPA
- Displaying semester information


Formula:

```
GPA = Total Grade Points / Total Credit Hours
```

---

## 3️⃣ Student Class

Manages all student semesters:

- Add new semester
- Display all semesters
- Calculate overall CGPA


CGPA Formula:

```
CGPA = Total Grade Points of All Semesters
       -------------------------------------
       Total Credit Hours of All Semesters
```

---

# 📋 Menu Options

When running the program:

```
==============================
       CGPA Calculator
==============================

1. Add New Semester

2. Display All Semesters

3. Calculate CGPA

4. Exit
```

---

# ▶️ How to Run

### Using g++ Compiler:

Compile:

```bash
g++ main.cpp -o CGPA
```

Run:

```bash
./CGPA
```

---

# 📊 Example Output

```
Course Name : Programming
Letter Grade : A
Credit Hours : 3


Semester GPA : 4.00


============================
Total Credits : 15
Total Points : 54.5
Real CGPA : 3.63
============================
```

---

# 🚀 Future Improvements

Possible improvements:

- Save student data using files
- Add student login system
- Add graphical user interface (GUI)
- Export CGPA report as PDF
- Support multiple students
- Database integration

---

# 👨‍💻 Author

**Ziad Hatem**

C++ | Embedded Systems Student

---

# 📄 License

This project is created for educational purposes.
