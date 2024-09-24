#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

//struct of student data
struct STUDENT_DATA {
    string firstName;
    string lastName;
    STUDENT_DATA(const string& first, const string& last)
        : firstName(first), lastName(last) {}
};

//Create a struct STUDENT_DATA that contains the first and last names of the students. 
// Each line read from the input file contains a first/last name pair separated by a comma.
//Parse the data, create an object and push that object into a vector space.
vector<STUDENT_DATA> processStudents() {

    //create a vector
    vector<STUDENT_DATA> students;

    //open file
    ifstream inputFile("Resource_Files/StudentData.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening StudentData.txt file" << endl;
        return students;
    }

    //write the student data into the vectors
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string firstName, lastName;
        if (getline(ss, lastName, ',') && getline(ss, firstName)) {
            students.emplace_back(firstName, lastName);
        }
    }

    //close the file and return the vector of data
    inputFile.close();
    return students;
}

int main() {

    //create a vector to display
    vector<STUDENT_DATA> testStudents;


    testStudents = processStudents();

    //print out the student data
    /*cout << "Student Data:" << endl;
    for (const auto& student : testStudents) {

        cout << student.lastName << ", " << student.firstName << endl;

    }*/

    return 1;
}