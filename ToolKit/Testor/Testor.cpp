// Testor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <BigNumberIntegerCalculator.h>
#include <Factorial.h>
#include <StringOperator.h>

string subtract(string num1, string num2) {
	string result = "";
	int borrow = 0;
	int i = num1.size() - 1;
	int j = num2.size() - 1;
	while (i >= 0 || j >= 0) {
		int a = i >= 0 ? num1[i--] - '0' : 0;
		int b = j >= 0 ? num2[j--] - '0' : 0;
		int diff = a - b - borrow;
		if (diff < 0) {
			diff += 10;
			borrow = 1;
		}
		else {
			borrow = 0;
		}
		result = to_string(diff) + result;
	}
	while (result.size() > 1 && result[0] == '0') {
		result.erase(0, 1);
	}
	return result;
}


string divide(string num1, string num2) {
	string result = "";
	int len1 = num1.size();
	int len2 = num2.size();
	if (len1 < len2 || (len1 == len2 && num1 < num2)) {
		return "0";
	}
	string dividend = num1.substr(0, len2);
	for (int i = len2; i <= len1; ++i) {
		int quotient = 0;
		while (dividend.size() > 0 && dividend[0] == '0') {
			dividend.erase(0, 1);
		}
		while (dividend.size() < len2 && i < len1) {
			dividend += num1[i++];
			result += "0";
		}
		if (dividend.size() >= len2) {
			while (dividend >= num2) {
				dividend = subtract(dividend, num2);
				++quotient;
			}
			result += to_string(quotient);
		}
	}
	while (result.size() > 1 && result[0] == '0') {
		result.erase(0, 1);
	}
	return result;
}


int main()
{
	//divide("1234", "321");

	string strDividend = "75";
	string strNum2 = "123";

	string strAddResult;
	string strMultiplyResult;
	string strSubtractResult;
	string strDivideResult;

	StringOperator::AddLeadingZeroes(strDividend, 3, strDividend);
	StringOperator::AddLeadingZeroes(strNum2, 3, strNum2);
	bool bBool = strDividend >= strNum2;

	BigNumberIntegerCalculator::Divide("123", "321", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("123", "-321", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("-123", "321", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("-123", "-321", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("123", "0", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("0", "321", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("-123", "0", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("0", "-321", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("321", "123", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("321", "-123", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("-321", "123", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("-321", "-123", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("123", "123", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("123", "-123", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("-123", "123", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("-123", "-123", strAddResult); cout << strAddResult << endl;

	BigNumberIntegerCalculator::Divide("1234", "321", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("1234", "-321", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("-1234", "321", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("-1234", "-321", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("1234", "0", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("0", "321", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("-1234", "0", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("0", "-321", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("321", "1234", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("321", "-1234", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("-321", "1234", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("-321", "-1234", strAddResult); cout << strAddResult << endl;

	BigNumberIntegerCalculator::Divide("123", "4321", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("123", "-4321", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("-123", "4321", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("-123", "-4321", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("123", "0", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("0", "4321", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("-123", "0", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("0", "-4321", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("4321", "123", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("4321", "-123", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("-4321", "123", strAddResult); cout << strAddResult << endl;
	BigNumberIntegerCalculator::Divide("-4321", "-123", strAddResult); cout << strAddResult << endl;
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
