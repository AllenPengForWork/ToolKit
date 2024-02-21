#pragma once
#include "StatusCodes.h"
#include <exception>

using namespace std;
using namespace StatusCodes;

namespace ExceptionsProcessor
{
	Code PrintExceptionInfo(Code eCode, exception clsException);
}