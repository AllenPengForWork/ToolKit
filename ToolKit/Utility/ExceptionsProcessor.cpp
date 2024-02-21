#include "iostream"
#include "ExceptionsProcessor.h"

using namespace std;
using namespace StatusCodes;

namespace ExceptionsProcessor
{
	Code PrintExceptionInfo(Code eStatusCode, exception clsException)
	{
		Code eCode = Code::SUCCESSFUL;
		try
		{
			cerr << "Exception caught: " << clsException.what() << endl;
			cerr << "Code: " << eStatusCode << endl;
			cerr << "File: " << __FILE__ << endl;
			cerr << "Line: " << __LINE__ << endl;
		}
		catch (exception clsException)
		{
			eCode = Code::SYSTEM;
			cerr << "Exception caught: " << clsException.what() << endl;
			cerr << "Code: " << Code::SYSTEM << endl;
			cerr << "File: " << __FILE__ << endl;
			cerr << "Line: " << __LINE__ << endl;
		}
		return eCode;
	}
}
