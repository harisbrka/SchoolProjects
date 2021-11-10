#include <iostream>
#include <iomanip>
#include <string>
#include <fstream> //for input/output files

using namespace std;

//global for array size
const int SIZE=20;

//struct studentType with all the necessary components
struct studentType
{
    //declaring struct components
    string studentFName,
           studentLName;
    int testScore;
    char grade;
}student[SIZE];

//function prototypes
int dataOfStudents (ifstream& inputFile, studentType student[]);
void openOutputFile (ofstream& outputFile, char filename[]);
bool openInputFile(ifstream& inputFile, char filename[]);
void findHighestScore(ofstream& outputFile, studentType student[], int x);
void displayData(ofstream& outputFile, studentType student[], int x);
void getStudentGrade(studentType student[], int x);

//main function entry-point
int main()
{
    //declare variables
    int x;
    bool holder;
    //creating the input and output files
    ifstream inputFile;
    ofstream outputFile;
    holder=openInputFile(inputFile, "school.txt");
    if (holder)
    {
        openOutputFile(outputFile, "schoolTwo.txt");

        //calling functions
        x = dataOfStudents(inputFile, student);
        getStudentGrade(student, x);
        displayData(outputFile, student, x);
        findHighestScore(outputFile, student, x);

        //close output file
        outputFile.close();
        //close input file
        inputFile.close();

    }

    return 0;
}
//defining the openInputFile function
bool openInputFile(ifstream& inputFile, char filename[])
{

    inputFile.open(filename);

    if (inputFile.fail())
    {
        cout << "File failed to open.";
        return false;
    }
    return true;
}
void openOutputFile (ofstream& outputFile, char filename [])
{
    outputFile.open(filename);
}
int dataOfStudents(ifstream& inputFile, studentType student[])
{
    int i=0;
    inputFile >> student[i].studentFName
              >> student[i].studentLName
              >>student[i].testScore;
    while (inputFile)
    {
        i++;
        inputFile >> student[i].studentFName
                  >> student[i].studentLName
                  >>student[i].testScore;
    }
    return i;
}
void getStudentGrade(studentType student[], int x)
{
    int i;
    for (i=0; i<x; i++)
        switch ((int)(student[i].testScore/10))
    {
        case 10:
        case 9: student[i].grade='A';
            break;
        case 8: student[i].grade='B';
            break;
        case 7: student[i].grade='C';
            break;
        case 6: student[i].grade='D';
            break;
        default: student[i].grade='F';
            break;
    }
}
 void displayData (ofstream& out, studentType student[], int x)
 {
     out << "Last Name, First Name, Score Grade";
     out << "----------------------------------";
     cout << "Last Name, First Name, Score Grade";
     cout << "----------------------------------";
     for (int i=0; i<x; i++)
     {
         out << setw(15) << left << student[i].studentLName << setw(15) <<student[i].studentFName;
         out << setw(5) << student[i].testScore << setw(3) << student[i].grade << endl;
         cout << setw(15) << left << student[i].studentLName << setw(15) <<student[i].studentFName;
         cout << setw(5) << student[i].testScore << setw(3) << student[i].grade << endl;
     }
 }
 void findHighestScore (ofstream& out, studentType student[], int x)
 {
     string firstName="",
            lastName="";
     int total=0,
         i;
     for (i=1; i<x; i++)
     {
         if (student[i].testScore > student[total].testScore)
         {
             total=i;
         }
     }
     out << "Highest Test Score: " << student[total].testScore << endl;
     out << "Students with highest test scores: " << endl;
     cout << "Highest Test Score: " << student[total].testScore << endl;
     cout << "Students with highest test scores: " << endl;
     for (i=0; i < x; i++)
     {
         if (student[i].testScore == student[total].testScore)
         {
             out << student[i].studentLName << "," << student[i].studentFName << endl;
             cout << student[i].studentLName << "," << student[i].studentFName << endl;
         }
     }
 }
