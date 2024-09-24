#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

#define PRE_RELEASE

//struct of student data
struct STUDENT_DATA {
    string firstName;
    string lastName;
    string email;
    STUDENT_DATA(const string& first, const string& last,
        const string& email = ""): firstName(first), lastName(last), email(email) {}
};

//Create a struct STUDENT_DATA that contains the first and last names of the students. 
// Each line read from the input file contains a first/last name pair separated by a comma.
//Parse the data, create an object and push that object into a vector space.
vector<STUDENT_DATA> processStudents() {

    //create a vector
    vector<STUDENT_DATA> students;

    //open normal data file
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

// Process normal data and emails when in pre release
vector<STUDENT_DATA> processStudentsEmail() {

    vector<STUDENT_DATA> students;

    //open email file
    ifstream inputFile("Resource_Files/StudentData_Emails.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening StudentData_Emails.txt file" << endl;
        return students;
    }

    //write the student data into the vectors include email
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string firstName, lastName, email;
        if (getline(ss, lastName, ',') && getline(ss, firstName, ',') && getline(ss, email)) {
            students.emplace_back(firstName, lastName, email);
        }
    }

    //close the file and return the vector of data
    inputFile.close();
    return students;
}

int main() {

    //create a vector to display
    vector<STUDENT_DATA> testStudents;

 //check for pre_release
#ifdef PRE_RELEASE
    cout << "Running pre-release version." << endl;
    testStudents = processStudentsEmail();

#else
    cout << "Running standard version." << endl;
    testStudents = processStudents();

#endif


//check for debug
#ifdef _DEBUG

    //print out the student data 
    cout << "[Student List:]" << endl;
    for (const STUDENT_DATA& student : testStudents) {

//check for pre_release
#ifdef PRE_RELEASE
        cout << student.lastName << ", " << student.firstName << ", " << student.email << endl;

#else
        cout << student.lastName << ", " << student.firstName << endl;

#endif

    }
#endif // DEBUG

    return 1;
}