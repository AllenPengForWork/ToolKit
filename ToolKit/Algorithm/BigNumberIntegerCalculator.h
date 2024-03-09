#pragma once
#include "StatusCodes.h"
#include <string>

using namespace std;
using namespace StatusCodes;

namespace BigNumberIntegerCalculator
{
	Code Add(string num1, string num2, string& strResult);
	Code Subtract(string num1, string num2, string& strResult);
	Code Multiply(string num1, string num2, string& strResult);
	Code Divide(string num1, string num2, string& strResult);
}