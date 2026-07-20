/*
===========================================================
            CGPA Calculator System
-----------------------------------------------------------
Author : Ziad Hatem
Language : C++
Description:
This program calculates the GPA/CGPA of a student
based on course grades and credit hours.
===========================================================
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

/*---------------------------------------------
   Structure to store information of one course
----------------------------------------------*/
struct Course
{
    string name;
    string letterGrade;
    int creditHours;
    double gradePoint;
};

/*---------------------------------------------
      Convert Letter Grade to Grade Point
----------------------------------------------*/
double getGradePoint(string grade)
{
    if (grade == "A+" || grade == "A")
        return 4.0;
    else if (grade == "A-")
        return 3.7;
    else if (grade == "B+")
        return 3.3;
    else if (grade == "B")
        return 3.0;
    else if (grade == "B-")
        return 2.7;
    else if (grade == "C+")
        return 2.3;
    else if (grade == "C")
        return 2.0;
    else if (grade == "C-")
        return 1.7;
    else if (grade == "D+")
        return 1.3;
    else if (grade == "D")
        return 1.0;
    else
        return 0.0; // F
}

/*---------------------------------------------
      Display All Entered Courses
----------------------------------------------*/
void displayCourses(const vector<Course>& courses)
{
    cout << "\n================ Course Details ================\n";

    cout << left
         << setw(20) << "Course"
         << setw(10) << "Grade"
         << setw(15) << "Credits"
         << setw(15) << "Points"
         << endl;

    cout << "------------------------------------------------------------\n";

    for (const Course& course : courses)
    {
        cout << left
             << setw(20) << course.name
             << setw(10) << course.letterGrade
             << setw(15) << course.creditHours
             << setw(15) << course.gradePoint
             << endl;
    }

    cout << "------------------------------------------------------------\n";
}

/*---------------------------------------------
                Main Program
----------------------------------------------*/
int main()
{
    vector<Course> courses;

    int numberOfCourses;

    cout << "=========================================\n";
    cout << "         CGPA Calculator System\n";
    cout << "=========================================\n\n";

    // Validate number of courses
    do
    {
        cout << "Enter Number of Courses: ";
        cin >> numberOfCourses;

        if (numberOfCourses <= 0)
            cout << "Invalid Number!\n\n";

    } while (numberOfCourses <= 0);

    double totalGradePoints = 0.0;
    int totalCredits = 0;

    // Input all courses
    for (int i = 0; i < numberOfCourses; i++)
    {
        Course course;

        cout << "\nCourse " << i + 1 << endl;

        cout << "Course Name: ";
        cin >> course.name;

        cout << "Letter Grade (A+,A,A-,B+,B,B-,C+,C,C-,D+,D,F): ";
        cin >> course.letterGrade;

        course.gradePoint = getGradePoint(course.letterGrade);

        do
        {
            cout << "Credit Hours: ";
            cin >> course.creditHours;

            if (course.creditHours <= 0)
                cout << "Invalid Credit Hours!\n";

        } while (course.creditHours <= 0);

        totalCredits += course.creditHours;
        totalGradePoints += course.gradePoint * course.creditHours;

        courses.push_back(course);
    }

    // Calculate GPA
    double gpa = totalGradePoints / totalCredits;

    // Display
    displayCourses(courses);

    cout << fixed << setprecision(2);

    cout << "\nTotal Credit Hours : " << totalCredits << endl;
    cout << "Total Grade Points : " << totalGradePoints << endl;
    cout << "Semester GPA       : " << gpa << endl;
    cout << "Overall CGPA       : " << gpa << endl;

    cout << "\nThank You!\n";

    return 0;
}
