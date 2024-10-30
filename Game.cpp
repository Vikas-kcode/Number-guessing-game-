#include <iostream>

#include <string>

using namespace std;



struct Course {

    string name;

    char grade;

    int credits;

};

float calculateGradePoints(char grade) {

    switch (grade) {

        case 'A': return 4.0;

        case 'B': return 3.0;

        case 'C': return 2.0;

        case 'D': return 1.0;

        case 'F': return 0.0;

        default: return 0.0;

    }

}

float calculateCGPA(Course courses[], int numCourses) {

    float totalGradePoints = 0;

    int totalCredits = 0;



    for (int i = 0; i < numCourses; i++) {

        totalGradePoints += calculateGradePoints(courses[i].grade) * courses[i].credits;

        totalCredits += courses[i].credits;

    }



    return totalGradePoints / totalCredits;

}



int main() {

    int numCourses;

    cout << "Enter the number of courses: ";

    cin >> numCourses;



    Course courses[numCourses];



    for (int i = 0; i < numCourses; i++) {

        cout << "Enter course " << i + 1 << " name: ";

        cin >> courses[i].name;

        cout << "Enter course " << i + 1 << " grade (A/B/C/D/F): ";

        cin >> courses[i].grade;

        cout << "Enter course " << i + 1 << " credits: ";

        cin >> courses[i].credits;

    }



    cout << "\nCourse Grades:" << endl;

    for (int i = 0; i < numCourses; i++) {

        cout << courses[i].name << ": " << courses[i].grade << endl;

    }



    float totalCredits = 0;

    float totalGradePoints = 0;

    for (int i = 0; i < numCourses; i++) {

        totalCredits += courses[i].credits;

        totalGradePoints += calculateGradePoints(courses[i].grade) * courses[i].credits;

    }



    cout << "\nTotal Credits: " << totalCredits << endl;

    cout << "Total Grade Points: " << totalGradePoints << endl;

    cout << "GPA: " << totalGradePoints / totalCredits << endl;

    cout << "CGPA: " << calculateCGPA(courses, numCourses) << endl;



    return 0;

}
