#include "fstream"
#include "string"
#include "StatusCodes.h"
#include "vector"
#include "String.h"
#include "ExceptionsProcessor.h"

using namespace std;
using namespace StatusCodes;

namespace StringOperator
{
	Code Split(string strSourceString, string strSymbol, vector<string>& clsSubString)
	{
		Code eCode = Code::SUCCESSFUL;
		clsSubString.clear();
		try
		{
			int iCurrent = 0;
			int iNext;
			while (1)
			{
				iNext = strSourceString.find_first_of(strSymbol, iCurrent);
				if (iNext != iCurrent)
				{
					string strTmp = strSourceString.substr(iCurrent, iNext - iCurrent);
					if (strTmp.size() != 0)
						clsSubString.push_back(strTmp);
				}
				if (iNext == string::npos) break;
				iCurrent = iNext + 1;
			}
		}
		catch (exception clsException)
		{
			eCode = Code::SYSTEM;
			ExceptionsProcessor::PrintExceptionInfo(eCode, clsException);
		}
		return eCode;
	}

	Code AddLeadingZeroes(string strSourceString, unsigned int iLength, string& strOutputString)
	{
		Code eCode = Code::SUCCESSFUL;
		strOutputString = "";
		try
		{
			int iSourceStringLength = strSourceString.length();
			if (iSourceStringLength < iLength)
			{
				strOutputString = string(iLength - iSourceStringLength, '0') + strSourceString;
			}
			else
			{
				eCode = Code::USELESS_ARGUMENT;
				strOutputString = strSourceString;
				return eCode;
			}
		}
		catch (exception clsException)
		{
			eCode = Code::SYSTEM;
			ExceptionsProcessor::PrintExceptionInfo(eCode, clsException);
		}
		return eCode;
	}
}
