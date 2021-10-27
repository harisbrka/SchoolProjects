/*

Program7_Q6

Programmer: Brka, Haris

Course: CSC160-141 Computer Science I C++ Fall 2021

Submission Date: [9/22/2021]

Brief Description of this program. [This is a menu driven program which allows the user to select various options that change a random number that was generated at the start of the program.]

*/

//importing input/output library
#include <iostream>
//including for random number
#include <ctime>
#include <cstdlib>

//using standard namespace
using namespace std;

//declaring prototypes
int doubleTheNumber (int);
int reverseNumber (int);
int raisePower (int);
int sumTheNumber (int);
int doubleDigit (int);
int tripleDigit (int);
int getPower (int, int);
bool isPrime (int);
int menu ();

//main function entry-point
int main()
{
    //declaring variables
    int number;
    //generating random number and setting it equal to number variable
    srand(time(0));
    number=rand()% 90 + 10;
    //displaying random number to user
    cout << "The random number: " << number << endl;
    //do-while to repeat the menu options
    do
    {
        //switch statement calling menu function, and each case calls each of the functions needed to complete the specific options selected by the user
        switch (menu())
        {
            case 1: number=doubleTheNumber(number);
            break;
            case 2: number=reverseNumber(number);
            break;
            case 3: number=raisePower(number);
            break;
            case 4: number=sumTheNumber(number);
            break;
            case 5: number=doubleDigit (number);
            break;
            case 6: number=tripleDigit (number);
            break;
            case 7: return 0;
        }
        //if statement calling isPrime to determine if the number is prime each time
        if (isPrime(number))
        {
            cout << number << " is prime." << endl;
        }
        //else statement that displays when number isn't prime
        else
        {
            cout << number << " is not prime." << endl;
        }
        //if that adds ten to the number if it is less than ten
        if (number < 10)
        {
            number=number+10;
        }
    } while (true);
}
//defining doubleTheNumber function which doubles the random number
int doubleTheNumber(int number)
{
    number=number*2;
    return number;
}
//defining reverseNumber function which reverses the digits of the random number and returns reversed number
int reverseNumber (int number)
{
    //declaring variables
    int holder=0;
    while (number > 0)
    {
        holder = holder * 10 + number % 10;
        number=number/10;
    }
    return holder;
}
//defining raisePower function which allows the user to choose if they want to raise the number to the power of 2,3, or 4.
int raisePower (int number)
{
    //declaring variables
    int x;
    //prompting user to enter the power they want to raise their number to
    cout << "Raise your number to the power 2, 3, or 4: ";
    cin >> x;
    //while to validate
    while ( x < 2 || x > 4)
    {
        cout << "Please enter 2, 3, or 4: ";
        cin >> x;
    }
    //calling getPower function and having the function return the number raised to the selected power
    return getPower(number, x);

}
//defining sumTheNumber functions which separates the numbers and adds them all up
int sumTheNumber (int number)
{
    //declaring variables
    int sum=0;
    while (number > 0)
    {
        sum=sum+number%10;
        number=number/10;
    }
    //return the sum of the separated digits
    return sum;
}
//defining doubleDigit function which takes a two digit number and raises the first digit to the power of the second digit
int doubleDigit (int number)
{
    //declaring local variables
    int firstNumber,
        secondNumber;
    if (number < 100)
    {
        secondNumber=number%10;
        firstNumber=number/10;
        return getPower (firstNumber, secondNumber);
    }
    //return changed number
    return number;
}
//defining tripleDigit function which takes the first two digits and raises them to the power of the last digit only if the last digit is less than or equal 4
int tripleDigit (int number)
{
    //declaring local variables
    int firstNumber,
        secondNumber;
    if (number > 99)
    {
        firstNumber=number%10;
        if (firstNumber <=4)
        {
            secondNumber=number/10;
            return getPower (firstNumber, secondNumber);
        }
    }
    //return changed number
    return number;
}
//defining getPower which raises numbers to specified powers determined by the other functions
int getPower (int firstNumber, int secondNumber)
{
    //declaring local variable
    int value, i;
    if (secondNumber==0)
    {
        return 1;
    }
    else
    {
        value=firstNumber;
        for (i = 2; i <= secondNumber; i++)
        {
            value=value*firstNumber;
        }
        //return raised value
        return value;
    }
}
//defining isPrime which returns a true if number is prime and false if the number is not prime
bool isPrime (int number)
{
    //declaring local variable
    int i;
    for (i = 2; i < number; i++)
    {
        if (number % i == 0)
            return false;
        else
            return true;
    }
}
//defining menu function, which returns user input and displays the menu
int menu ()
{
    //declaring local variable
    int input=8;
    //while loop for menu
    while (input < 1 || input > 7)
    {
        //displaying menu for the menu driven program
        cout << endl;
        cout << " ------ Menu ------" << endl;
        cout << "1: Double the random number " << endl;
        cout << "2: Reverse the digits of the random number " << endl;
        cout << "3: Raise the random number to power 2, 3, or 4 " << endl;
        cout << "4: Sum the digits of the random number " << endl;
        cout << "5: If the random number is a two digit then raise the first digit to the power of the second digit " << endl;
        cout << "6: If the random number is a three digit and the last digit is less or equal to 4, then raise the first two digits to the power of the last digit  " << endl;
        cout << "7: End Program " << endl;
        cout << endl;
        cout << "Enter your choice (1-7): ";
        cin >> input;
        //error message for number not between 1 or 7
        if (input < 1 || input > 7)
        {
            cout << "ERROR PLEASE ENTER NUMBER (1-7)! ";
            cin >> input;
        }
    }
    //returns user input
    return input;
}
