#include "iostream"
#include "fstream"
#include "string"
#include "exception"
#include "StatusCodes.h"
#include "ExceptionsProcessor.h"

using namespace std;
using namespace StatusCodes;

namespace File
{
	Code GetFileString(string strFilePath, string& strText)
	{
		Code eCode = Code::SUCCESSFUL;
		strText = "";
		try
		{
			ifstream clsIfStream(strFilePath);
			if (clsIfStream.is_open())
			{
				string strLine;
				while (getline(clsIfStream, strLine))
				{
					strText += strLine + "\r\n";
				}
				clsIfStream.close();
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