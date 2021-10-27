/*

Program7_Q1

Programmer: Brka, Haris

Course: CSC160-141 Computer Science I C++ Fall 2021

Submission Date: [10/27/2021]

Brief Description of this program. [This program determines if user's triangle is isosceles, equilateral, scalene, or if the triangle has no shape.]

*/

//importing input/output library
#include <iostream>

//using standard namespace
using namespace std;

//defining enumeration type triangleType with values for each triangle type
enum triangleType {scalene, isosceles, equilateral, noTriangle};

//declaring prototype
triangleType triangleShape (float, float, float);

//main function entry-point
int main()
{
    //declaring variables for each side
    float side1,
          side2,
          side3;
    //declaring variable
    int hold;
    //prompting user to enter three sides to their triangle
    cout << "Please enter three sides of a triangle: ";
    //storing user input into variables for sides
    cin >> side1 >> side2 >> side3;
    //calling triangleShape function and setting it equal to hold variable
    hold=triangleShape(side1, side2, side3);
    //switch statement with cases for each outcomes for every triangle type
    switch (hold)
    {
        case 0: cout << "The triangle is Scalene." << endl;
        break;
        case 1: cout << "The triangle is Isosceles." << endl;
        break;
        case 2: cout <<  "The triangle is Equilateral." << endl;
        break;
        case 3: cout << "This triangle has no shape." << endl;
        break;
    }

    return 0;
}
//defining triangleType function
triangleType triangleShape (float side1, float side2, float side3)
{
    //declaring local variable
    triangleType triangle;
    //series of if-else if statements to determine if the triangle has no shape or is isosceles, equilateral, or scalene
    if (side1 > (side2+side3)|| side2 > (side1+side3)|| side3 > (side1+side2))
    {
        triangle=noTriangle;
    }
    else if ((side1==side2)&&(side2==side3)&&(side1==side3))
    {
        triangle=equilateral;
    }
    else if (side1!=side2&&side2!=side3&&side3!=side1)
    {
        triangle=scalene;
    }
    else
    {
        triangle=isosceles;
    }
    return triangle;
}
