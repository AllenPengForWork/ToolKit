#include "string"
#include "StatusCodes.h"

using namespace std;
using namespace StatusCodes;

namespace File
{
	Code GetFileString(string strFilePath, string& strText);
}