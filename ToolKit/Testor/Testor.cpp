// Testor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <BigNumberCalculator.h>
#include <Factorial.h>

int main()
{
    std::cout << "Hello World!\n";
    unsigned long long int iTmp1;
    unsigned long long int iTmp2;
    unsigned long long int iTmp3;
    unsigned long long int iTmp4;
    unsigned long long int iTmp5;
    unsigned long long int iTmp6;
    unsigned long long int iTmp7;
    unsigned long long int iTmp8;
    unsigned long long int iTmp9;
    unsigned long long int iTmp10;
    Factorial::Factorial_Recursion(1, iTmp1);
    Factorial::Factorial_Recursion(2, iTmp2);
    Factorial::Factorial_Recursion(3, iTmp3);
    Factorial::Factorial_Recursion(4, iTmp4);
    Factorial::Factorial_Recursion(5, iTmp5);
    Factorial::Factorial_Recursion(6, iTmp6);
    Factorial::Factorial_Recursion(7, iTmp7);
    Factorial::Factorial_Recursion(8, iTmp8);
    Factorial::Factorial_Recursion(9, iTmp9);
    Factorial::Factorial_Recursion(10, iTmp10);
    string strAddResult;
    string strMultiplyResult;
    string strSubtractResult;
    string strDivideResult;
    BigNumberCalculator::Add("123", "321", strAddResult);
    BigNumberCalculator::Multiply("123", "321", strMultiplyResult);
    BigNumberCalculator::Subtract("123", "321", strSubtractResult);
    BigNumberCalculator::Divide("123", "321", strDivideResult);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
