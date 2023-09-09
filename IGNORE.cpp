#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>
#include <regex>

using namespace std;
// My short term objective is to write this code - this one was written by ai from a python script i provided it
string getFormattedTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
    return buf;
}

bool isValidName(const string& name) {
    regex namePattern("^[A-Za-z]+$");
    return regex_match(name, namePattern);
}

class Student {
public:
    Student(const string& name, const string& familyname, float grade)
        : name(name), familyname(familyname), grade(grade) {
        code = rand() % 900000000 + 100000000;
        fullname = name + " " + familyname;
    }

    string studentInfo() const {
        return fullname + " ID: " + to_string(code) + " has the following grade " + to_string(grade) + "%";
    }

    string studentCode() const {
        return fullname + " has the following unique student identifier " + to_string(code);
    }

private:
    string name;
    string familyname;
    float grade;
    int code;
    string fullname;
};

class Subject {
public:
    Subject(const string& subjectName, int credit = 3)
        : subjectName(subjectName), credit(credit), subjectCode(subjectName.substr(0, 3)) {
    }

    void addStudent(const Student& student) {
        enrolledStudents.push_back(student);
    }

    string generateReport() const {
        string report = "Subject: " + subjectName + "\nCredits: " + to_string(credit) + "\nSubject Code: " + subjectCode + "-" + to_string(rand() % 9000 + 1000) + "\n";
        report += "Enrolled Students:\n";
        for (const Student& student : enrolledStudents) {
            report += student.studentInfo() + "\n";
        }
        return report;
    }

private:
    string subjectName;
    int credit;
    string subjectCode;
    vector<Student> enrolledStudents;
};

int main() {
    srand(static_cast<unsigned>(time(0)));
    
    cout << "          Welcome to the Student Report System    " << endl;
    cout << "          You logged in at " << getFormattedTime() << endl;

    cout << "           Type option for more actions     " << endl;
    string subjectInput;
    cout << "Please choose a subject from the following" << endl;
    cout << "-Math -Python -Java -English: ";
    cin >> subjectInput;

    vector<string> subjectList = {"math", "python", "java", "english"};
    bool validSubject = false;

    for (string& subject : subjectList) {
        if (subjectInput == subject) {
            validSubject = true;
            break;
        }
    }

    if (!validSubject) {
        cout << subjectInput << " not in the list, please choose a valid subject." << endl;
        return 1;
    }

    Subject subject(subjectInput);

    while (true) {
        string name;
        cout << "Please Enter student name: ";
        cin >> name;

        if (name != "option" && isValidName(name)) {
            string familyName;
            cout << "Please enter " << name << "'s family name: ";
            cin >> familyName;

            if (isValidName(familyName)) {
                float grade;
                cout << "Please Enter " << name << "'s grade: ";
                cin >> grade;

                if (grade > 0 && grade <= 100) {
                    Student newStudent(name, familyName, grade);
                    subject.addStudent(newStudent);
                    cout << newStudent.studentInfo() << " at " << subjectInput << endl;
                } else {
                    cout << "Grades should be between 0 and 100, enter the student name and try again" << endl;
                }
            } else {
                cout << "Invalid family name format. Please use only letters." << endl;
            }
        } else if (name == "option") {
            cout << "Please choose an action:" << endl;
            cout << "1- Display student's information" << endl;
            cout << "2- Display students' secret code" << endl;
            cout << "3- Display Student info (Enter unique ID)" << endl;
            cout << "4- Display Subject report" << endl;
            cout << "5- Exit Program" << endl;

            int choice;
            cout << "Choose the option: ";
            cin >> choice;

            if (choice == 1) {
                for (const Student& student : subject.generateReport()) {
                    cout << student.studentInfo() << endl;
                }
            } else if (choice == 2) {
                for (const Student& student : subject.generateReport()) {
                    cout << student.studentCode() << endl;
                    break;
                }
            } else if (choice == 3) {
                int studentCode;
                cout << "Enter student secret code: ";
                cin >> studentCode;

                bool found = false;
                for (const Student& student : subject.generateReport()) {
                    if (studentCode == student.getStudentCode()) {
                        cout << "The student name is " << student.getFullName() << " and they have the following grade " << student.getGrade() << "%" << endl;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Student with code " << studentCode << " not found." << endl;
                }
            } else if (choice == 4) {
                cout << subject.generateReport() << endl;
            } else if (choice == 5) {
                cout << "Exiting School grader ..." << endl;
                break;
            }
        }
    }

    return 0;
}
