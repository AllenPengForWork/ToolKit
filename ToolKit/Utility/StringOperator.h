#pragma once
#include "string"
#include "StatusCodes.h"
#include "vector"

using namespace std;
using namespace StatusCodes;

namespace StringOperator
{
	Code Split(string strSourceString, string strSymbol, vector<string>& clsSubString);
	Code AddLeadingZeroes(string strSourceString, unsigned int iLength, string& strOutputString);
}