// Testor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <BigNumberCalculator.h>
#include <Factorial.h>

int main()
{
    std::cout << "Hello World!\n";
    string strAddResult;
    string strMultiplyResult;
    string strSubtractResult;
    string strDivideResult;

    BigNumberCalculator::Add("123", "321", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("123", "-321", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("-123", "321", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("-123", "-321", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("123", "0", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("0", "321", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("-123", "0", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("0", "-321", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("321", "123", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("321", "-123", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("-321", "123", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("-321", "-123", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("123", "123", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("123", "-123", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("-123", "123", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("-123", "-123", strAddResult); cout << strAddResult << endl;

    BigNumberCalculator::Add("1234", "321", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("1234", "-321", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("-1234", "321", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("-1234", "-321", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("1234", "0", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("0", "321", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("-1234", "0", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("0", "-321", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("321", "1234", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("321", "-1234", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("-321", "1234", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("-321", "-1234", strAddResult); cout << strAddResult << endl;

    BigNumberCalculator::Add("123", "4321", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("123", "-4321", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("-123", "4321", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("-123", "-4321", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("123", "0", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("0", "4321", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("-123", "0", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("0", "-4321", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("4321", "123", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("4321", "-123", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("-4321", "123", strAddResult); cout << strAddResult << endl;
    BigNumberCalculator::Add("-4321", "-123", strAddResult); cout << strAddResult << endl;
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
