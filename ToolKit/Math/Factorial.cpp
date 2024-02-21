#include "exception"
#include "StatusCodes.h"
#include "ExceptionsProcessor.h"

using namespace std;
using namespace StatusCodes;

namespace Factorial
{
	Code Factorial_Recursion(unsigned long long int iNumber, unsigned long long int& iResult)
	{
		Code eCode = Code::SUCCESSFUL;
		iResult = 0;
		try
		{
			if (iNumber < 0) // error value
			{
				iResult = -1;
				eCode == Code::INVALID_ARGUMENT;
				return eCode;
			}
			if (iNumber == 0 || iNumber == 1)
			{
				iResult = 1;
				return eCode;
			}
			else
			{
				unsigned long long int iTmp;
				eCode = Factorial_Recursion(iNumber - 1, iTmp);
				if (eCode == Code::SUCCESSFUL)
				{
					iResult = iNumber * iTmp;
				}
				else
				{
					return eCode;
				}
			}
		}
		catch (exception clsException)
		{
			eCode = Code::SYSTEM;
			ExceptionsProcessor::PrintExceptionInfo(eCode, clsException);
		}
		return eCode;
	}

	Code Factorial_Loop(unsigned long long int iNumber, unsigned long long int& iResult)
	{
		Code eCode = Code::SUCCESSFUL;
		iResult = 0;
		try
		{
			if (iNumber < 0) // error value
			{
				iResult = -1;
				eCode == Code::INVALID_ARGUMENT;
				return eCode;
			}
			iResult = 1;
			for (int iIndex = 1; iIndex <= iNumber; ++iIndex) {
				iResult *= iIndex;
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