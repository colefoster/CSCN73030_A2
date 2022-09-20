//#define _PRERELEASE

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
#ifdef _PRERELEASE
    cout << "Application is running in Pre-Release mode" << endl;

    struct STUDENT_DATA {
        string last;
        string first;
        string email;
    }tempStudent;
    
    vector<STUDENT_DATA> studentVector;

    ifstream studentEmailFile("StudentData_Emails.txt");
    ifstream studentDataFile("StudentData.txt");
    if (studentDataFile.is_open() && studentEmailFile.is_open())
    {
        string name;
        string email;
        while (getline(studentDataFile, name) && getline(studentEmailFile, email))
        {
            tempStudent.last = name.substr(0, name.find(","));
            tempStudent.first = name.substr(name.find(",") + 1, name.length());
            tempStudent.email = email;
            studentVector.push_back(tempStudent);
        }
    }
#else
    cout << "Application is running in Standard mode" << endl;

    struct STUDENT_DATA {
        string last;
        string first;
    }tempStudent;

    vector<STUDENT_DATA> studentVector;

    ifstream studentDataFile("StudentData.txt");
    if (studentDataFile.is_open())
    {
        string line;
        while (getline(studentDataFile, line))
        {
            tempStudent.last = line.substr(0, line.find(","));
            tempStudent.first = line.substr(line.find(",") + 1, line.length());
            studentVector.push_back(tempStudent);
        }
    }
#endif
    

    #ifdef _DEBUG
        #ifdef _PRERELEASE
        cout << "Printing Student Data (First, Last - Email):" << endl;
        for (int i = 0; i < studentVector.size(); i++) {
            cout << studentVector.at(i).first << ", " << studentVector.at(i).last << " - " << studentVector.at(i).email << endl;
        }
        #else
        cout << "Printing Student Data (First, Last):" << endl;
        for (int i = 0; i < studentVector.size(); i++) {
            cout << studentVector.at(i).first << ", " << studentVector.at(i).last << endl;
        }
        #endif
    #endif // _DEBUG

    

    return 1;
}
