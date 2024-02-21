#include <string>
#include "exception"
#include "StatusCodes.h"
#include "ExceptionsProcessor.h"
using namespace StatusCodes;

namespace Sorting
{
	Code BubbleSort()
	{
		Code eCode = Code::SUCCESSFUL;
		try
		{
			
		}
		catch (exception clsException)
		{
			eCode = Code::SYSTEM;
			ExceptionsProcessor::PrintExceptionInfo(eCode, clsException);
		}
		return eCode;
	}
}