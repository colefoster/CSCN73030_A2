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

void parse() {
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
}

int main()
{
    parse();
    return 1;
}
