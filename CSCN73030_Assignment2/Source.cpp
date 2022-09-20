#ifdef _DEBUG
    #define something
#else
    #define somethingelse
#endif // _DEBUG


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
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

    #ifdef _DEBUG
    cout << "Printing Student Data (First, Last):" << endl;
    for (int i = 0; i < studentVector.size(); i++) {
        cout << studentVector.at(i).first << ", " << studentVector.at(i).last << endl;
    }
    #endif // _DEBUG

    return 1;
}
