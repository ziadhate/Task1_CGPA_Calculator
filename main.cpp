/*
===========================================================
                Advanced CGPA Calculator System
-----------------------------------------------------------
Author : Ziad Hatem
Language : C++

Description:
This program calculates GPA and CGPA for multiple semesters.
It uses Object Oriented Programming (Classes).

Features:
- Multiple semesters support
- Real CGPA calculation
- Grade validation
- Menu based system
===========================================================
*/


#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;


/*
===========================================================
                    Course Class
===========================================================
*/
class Course
{
private:

    string courseName;
    string letterGrade;
    int creditHours;
    double gradePoint;


    // Convert Letter Grade into Grade Point
    double calculateGradePoint(string grade)
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
            return -1;
    }


    // Check if grade is valid
    bool isValidGrade(string grade)
    {
        vector<string> validGrades =
        {
            "A+","A","A-",
            "B+","B","B-",
            "C+","C","C-",
            "D+","D","F"
        };


        for(string g : validGrades)
        {
            if(g == grade)
                return true;
        }

        return false;
    }


public:


    /*
        Constructor
    */
    Course()
    {
        gradePoint = 0;
        creditHours = 0;
    }



    /*
        Input Course Data
    */
    void inputCourse()
    {

        cout << "\nCourse Name : ";
        cin >> courseName;


        // Validate Letter Grade
        do
        {
            cout << "Letter Grade : ";
            cin >> letterGrade;


            if(!isValidGrade(letterGrade))
            {
                cout << "Invalid Grade! Try Again.\n";
            }


        }while(!isValidGrade(letterGrade));



        gradePoint = calculateGradePoint(letterGrade);



        // Validate Credit Hours
        do
        {

            cout << "Credit Hours : ";
            cin >> creditHours;


            if(creditHours <=0)
                cout<<"Invalid Credit Hours!\n";


        }while(creditHours<=0);

    }




    double getTotalPoints()
    {
        return gradePoint * creditHours;
    }



    int getCredits()
    {
        return creditHours;
    }



    void display()
    {

        cout << left
        << setw(20)<<courseName
        << setw(10)<<letterGrade
        << setw(10)<<creditHours
        << setw(10)<<gradePoint
        <<endl;

    }

};





/*
===========================================================
                    Semester Class
===========================================================
*/

class Semester
{

private:

    vector<Course> courses;

    int semesterNumber;


public:


    Semester(int num)
    {
        semesterNumber=num;
    }



    void addCourses()
    {

        int number;


        cout<<"\nEnter Number of Courses : ";
        cin>>number;


        for(int i=0;i<number;i++)
        {

            cout<<"\nCourse "<<i+1<<endl;


            Course c;

            c.inputCourse();


            courses.push_back(c);

        }

    }





    double calculateGPA()
    {

        double totalPoints=0;

        int totalCredits=0;



        for(Course c:courses)
        {

            totalPoints += c.getTotalPoints();

            totalCredits += c.getCredits();

        }


        return totalPoints / totalCredits;

    }





    double getTotalPoints()
    {

        double total=0;


        for(Course c:courses)
        {
            total += c.getTotalPoints();
        }


        return total;

    }





    int getTotalCredits()
    {

        int total=0;


        for(Course c:courses)
        {
            total+=c.getCredits();
        }


        return total;

    }





    void displaySemester()
    {

        cout<<"\n====================================\n";

        cout<<"Semester "<<semesterNumber<<endl;


        cout<<"====================================\n";


        cout<<left
        <<setw(20)<<"Course"
        <<setw(10)<<"Grade"
        <<setw(10)<<"Credit"
        <<setw(10)<<"Point"
        <<endl;



        for(Course c:courses)
        {
            c.display();
        }



        cout<<"\nSemester GPA : "
        <<fixed<<setprecision(2)
        <<calculateGPA()
        <<endl;


    }



};





/*
===========================================================
                    Student Class
===========================================================
*/

class Student
{

private:

    vector<Semester> semesters;



public:


    void addSemester()
    {

        int semesterNumber =
        semesters.size()+1;


        Semester s(semesterNumber);


        s.addCourses();


        semesters.push_back(s);


    }




    void displayAll()
    {

        if(semesters.empty())
        {
            cout<<"No Data Available!\n";
            return;
        }



        for(Semester s:semesters)
        {
            s.displaySemester();
        }

    }





    void calculateCGPA()
    {


        if(semesters.empty())
        {
            cout<<"No Semesters Found!\n";
            return;
        }



        double totalPoints=0;

        int totalCredits=0;



        for(Semester s:semesters)
        {

            totalPoints += s.getTotalPoints();


            totalCredits += s.getTotalCredits();

        }



        double cgpa =
        totalPoints / totalCredits;



        cout<<"\n============================\n";

        cout<<"Total Credits : "
        <<totalCredits<<endl;


        cout<<"Total Points : "
        <<totalPoints<<endl;



        cout<<"Real CGPA : "
        <<fixed<<setprecision(2)
        <<cgpa<<endl;


        cout<<"============================\n";


    }



};






/*
===========================================================
                    Main Function
===========================================================
*/

int main()
{

    Student student;


    int choice;



    do
    {

        cout<<"\n\n==============================\n";
        cout<<"       CGPA Calculator\n";
        cout<<"==============================\n";


        cout<<"1. Add New Semester\n";

        cout<<"2. Display All Semesters\n";

        cout<<"3. Calculate CGPA\n";

        cout<<"4. Exit\n";


        cout<<"\nChoose : ";
        cin>>choice;



        switch(choice)
        {

        case 1:

            student.addSemester();

            break;



        case 2:

            student.displayAll();

            break;



        case 3:

            student.calculateCGPA();

            break;



        case 4:

            cout<<"Good Bye!\n";

            break;



        default:

            cout<<"Invalid Choice!\n";

        }



    }while(choice!=4);



    return 0;

}
