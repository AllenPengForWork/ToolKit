#include <string>
#include <exception>
#include <StatusCodes.h>
#include <ExceptionsProcessor.h>
#include <BigNumberCalculator.h>

using namespace std;
using namespace StatusCodes;

namespace BigNumberCalculator
{
	Code Add(string strNum1, string strNum2, string& strResult)
	{
		Code eCode = Code::SUCCESSFUL;
		try
		{
			string strTemp = "";
			int iFirstNum1 = 0;
			int iFirstNum2 = 0;
			int iFirstNumIndex1 = 0;
			int iFirstNumIndex2 = 0;
			bool bIsNegativeNum1 = false;
			bool bIsNegativeNum2 = false;

			if (strNum1[0] == '-')
			{
				bIsNegativeNum1 = true;
				iFirstNumIndex1 = 1;
			}
			iFirstNum1 = strNum1[iFirstNumIndex1] - '0';

			if (strNum2[0] == '-')
			{
				bIsNegativeNum2 = true;
				iFirstNumIndex2 = 1;
			}
			iFirstNum2 = strNum2[iFirstNumIndex2] - '0';

			int iCarry = 0;
			int iIndex1 = strNum1.size() - 1;
			int iIndex2 = strNum2.size() - 1;
			bool bSwitch = false;

			if (bIsNegativeNum1 && !bIsNegativeNum2) // (-) + (+)
			{
				if (iIndex1 <= iIndex2) // Actually, Num1 size is large than Num2.
				{
					bSwitch = true;
				}
				else if (iIndex1 > iIndex2) // Num1 size may be equal to Num2.
				{
					int iCompareIndex1 = iFirstNumIndex1;
					int iCompareIndex2 = iFirstNumIndex2;
					while (iCompareIndex1 <= iIndex1)
					{
						if (strNum1[iCompareIndex1] < strNum2[iCompareIndex2])
						{
							bSwitch = true;
							break;
						}
						else if (strNum1[iCompareIndex1] > strNum2[iCompareIndex2])
						{
							bSwitch = false;
							break;
						}
						else
						{
							++iCompareIndex1;
							++iCompareIndex2;
							continue;
						}
					}
				}
				if (bSwitch)
				{
					eCode = BigNumberCalculator::Subtract(strNum2, strNum1.substr(1, iIndex1), strTemp);
				}
				else
				{
					eCode = BigNumberCalculator::Subtract(strNum1.substr(1, iIndex1), strNum2, strTemp);
				}
				if (eCode != Code::SUCCESSFUL)
				{
					return eCode;
				}
			}
			else if (!bIsNegativeNum1 && bIsNegativeNum2) // (+) + (-)
			{
				if (iIndex1 >= iIndex2) // Actually, Num1 size is large than Num2.
				{
					bSwitch = false;
				}
				else if (iIndex1 < iIndex2) // Num1 size may be equal to Num2.
				{
					int iCompareIndex1 = iFirstNumIndex1;
					int iCompareIndex2 = iFirstNumIndex2;
					while (iCompareIndex1 <= iIndex1)
					{
						if (strNum1[iCompareIndex1] < strNum2[iCompareIndex2])
						{
							bSwitch = true;
							break;
						}
						else if (strNum1[iCompareIndex1] > strNum2[iCompareIndex2])
						{
							bSwitch = false;
							break;
						}
						else
						{
							++iCompareIndex1;
							++iCompareIndex2;
							continue;
						}
					}
				}
				if (bSwitch)
				{
					eCode = BigNumberCalculator::Subtract(strNum2.substr(1, iIndex2), strNum1, strTemp);
				}
				else
				{
					eCode = BigNumberCalculator::Subtract(strNum1, strNum2.substr(1, iIndex2), strTemp);
				}
				if (eCode != Code::SUCCESSFUL)
				{
					return eCode;
				}
			}
			else // (+) + (+) & (-) + (-)
			{
				while ((bIsNegativeNum1 ? iIndex1 > 0 : iIndex1 >= 0) ||
					(bIsNegativeNum2 ? iIndex2 > 0 : iIndex2 >= 0) ||
					iCarry > 0)
				{
					int iA = iIndex1 >= 0 ? strNum1[iIndex1--] - '0' : 0;
					int iB = iIndex2 >= 0 ? strNum2[iIndex2--] - '0' : 0;
					if (iA < 0) iA = 0;
					if (iB < 0) iB = 0;
					int iSum = iA + iB + iCarry;
					iCarry = iSum / 10;
					iSum %= 10;
					strTemp = to_string(iSum) + strTemp;
				}
			}
			if (((!bSwitch && bIsNegativeNum1 && bIsNegativeNum2) ||
				(!bSwitch && bIsNegativeNum1 && !bIsNegativeNum2) ||
				(bSwitch && !bIsNegativeNum1 && bIsNegativeNum2)) &&
				strTemp != "0")
			{
				strTemp = "-" + strTemp;
			}
			/*
			while (iIndex1 >= 0 || iIndex2 >= 0 || iCarry > 0)
			{
				int iA = iIndex1 >= 0 ? strNum1[iIndex1--] - '0' : 0;
				int iB = iIndex2 >= 0 ? strNum2[iIndex2--] - '0' : 0;
				int iSum = iA + iB + iCarry;
				iCarry = iSum / 10;
				iSum %= 10;
				strTemp = to_string(iSum) + strTemp;
			}
			*/
			strResult = strTemp;
		}
		catch (exception clsException)
		{
			eCode = Code::SYSTEM;
			ExceptionsProcessor::PrintExceptionInfo(eCode, clsException);
		}
		return eCode;
	}

	Code Subtract(string strNum1, string strNum2, string& strResult)
	{
		Code eCode = Code::SUCCESSFUL;
		try
		{
			string strTemp = "";
			int iFirstNum1 = 0;
			int iFirstNum2 = 0;
			int iFirstNumIndex1 = 0;
			int iFirstNumIndex2 = 0;
			bool bIsNegativeNum1 = false;
			bool bIsNegativeNum2 = false;

			if (strNum1[0] == '-')
			{
				bIsNegativeNum1 = true;
				iFirstNumIndex1 = 1;
			}
			iFirstNum1 = strNum1[iFirstNumIndex1] - '0';

			if (strNum2[0] == '-')
			{
				bIsNegativeNum2 = true;
				iFirstNumIndex2 = 1;
			}
			iFirstNum2 = strNum2[iFirstNumIndex2] - '0';

			int iBorrow = 0;
			int iIndex1 = strNum1.size() - 1;
			int iIndex2 = strNum2.size() - 1;
			bool bSwitch = false;
			if (bIsNegativeNum1 && !bIsNegativeNum2) // (-) - (+)
			{
				eCode = BigNumberCalculator::Add(strNum1.substr(1, iIndex1), strNum2, strTemp);
				if (eCode != Code::SUCCESSFUL)
				{
					return eCode;
				}
			}
			else if (!bIsNegativeNum1 && bIsNegativeNum2) // (+) - (-)
			{
				eCode = BigNumberCalculator::Add(strNum1, strNum2.substr(1, iIndex2), strTemp);
				if (eCode != Code::SUCCESSFUL)
				{
					return eCode;
				}
			}
			else // (+) + (+) & (-) + (-)
			{
				if (iIndex1 == iIndex2)
				{
					int iCompareIndex1 = iFirstNumIndex1;
					int iCompareIndex2 = iFirstNumIndex2;
					while (iCompareIndex1 <= iIndex1)
					{
						if (strNum1[iCompareIndex1] < strNum2[iCompareIndex2])
						{
							bSwitch = true;
							break;
						}
						else if (strNum1[iCompareIndex1] > strNum2[iCompareIndex2])
						{
							bSwitch = false;
							break;
						}
						else
						{
							++iCompareIndex1;
							++iCompareIndex2;
							continue;
						}
					}
				}
				else if (iIndex1 > iIndex2)
				{
					bSwitch = false;
				}
				else if (iIndex1 < iIndex2)
				{
					bSwitch = true;
				}
				while ((bIsNegativeNum1 ? iIndex1 > 0 : iIndex1 >= 0) ||
					(bIsNegativeNum2 ? iIndex2 > 0 : iIndex2 >= 0))
				{
					int iA = iIndex1 >= 0 ? strNum1[iIndex1--] - '0' : 0;
					int iB = iIndex2 >= 0 ? strNum2[iIndex2--] - '0' : 0;
					if (iA < 0) iA = 0;
					if (iB < 0) iB = 0;
					int iDiff = (bSwitch ? (iB - iA) : (iA - iB)) - iBorrow;
					if (iDiff < 0)
					{
						iDiff += 10;
						iBorrow = 1;
					}
					else
					{
						iBorrow = 0;
					}
					strTemp = to_string(iDiff) + strTemp;
				}
			}

			while (strTemp.size() > 1 && strTemp[0] == '0')
			{
				strTemp.erase(0, 1);
			}
			if (((bSwitch && !bIsNegativeNum1 && !bIsNegativeNum2) ||
				(!bSwitch && bIsNegativeNum1 && !bIsNegativeNum2) ||
				(!bSwitch && bIsNegativeNum1 && bIsNegativeNum2)) &&
				strTemp != "0")
			{
				strTemp = "-" + strTemp;
			}
			if (iBorrow == 1)
			{
				strTemp = "-" + strTemp;
			}
			strResult = strTemp;
		}
		catch (exception clsException)
		{
			eCode = Code::SYSTEM;
			ExceptionsProcessor::PrintExceptionInfo(eCode, clsException);
		}
		return eCode;
	}

	Code Multiply(string strNum1, string strNum2, string& strResult)
	{
		Code eCode = Code::SUCCESSFUL;
		try
		{
			int iLength1 = strNum1.size();
			int iLength2 = strNum2.size();
			string strTemp(iLength1 + iLength2, '0');
			for (int iIndex1 = iLength1 - 1; iIndex1 >= 0; --iIndex1)
			{
				int iCarry = 0;
				for (int iIndex2 = iLength2 - 1; iIndex2 >= 0; --iIndex2)
				{
					int iSum = (strNum1[iIndex1] - '0') * (strNum2[iIndex2] - '0') + (strTemp[iIndex1 + iIndex2 + 1] - '0') + iCarry;
					strTemp[iIndex1 + iIndex2 + 1] = iSum % 10 + '0';
					iCarry = iSum / 10;
				}
				strTemp[iIndex1] += iCarry;
			}
			while (strTemp.size() > 1 && strTemp[0] == '0')
			{
				strTemp.erase(0, 1);
			}
			strResult = strTemp;
		}
		catch (exception clsException)
		{
			eCode = Code::SYSTEM;
			ExceptionsProcessor::PrintExceptionInfo(eCode, clsException);
		}
		return eCode;
	}

	Code Divide(string strNum1, string strNum2, string& strResult)
	{
		Code eCode = Code::SUCCESSFUL;
		try
		{
			string strTemp = "";
			int iLength1 = strNum1.size();
			int iLength2 = strNum2.size();
			if (iLength1 < iLength2 || (iLength1 == iLength2 && strNum1 < strNum2))
			{
				strResult = "0";
				return eCode;
			}
			string strDividend = strNum1.substr(0, iLength2);
			for (int i = iLength2; i <= iLength1; ++i)
			{
				int iQuotient = 0;
				while (strDividend.size() > 0 && strDividend[0] == '0')
				{
					strDividend.erase(0, 1);
				}
				while (strDividend.size() < iLength2 && i < iLength1)
				{
					strDividend += strNum1[i++];
					strTemp += "0";
				}
				if (strDividend.size() >= iLength2)
				{
					while (strDividend >= strNum2)
					{
						eCode = Subtract(strDividend, strNum2, strDividend);
						if (eCode != Code::SUCCESSFUL)
						{
							return eCode;
						}
						++iQuotient;
					}
					strTemp += to_string(iQuotient);
				}
			}
			while (strTemp.size() > 1 && strTemp[0] == '0')
			{
				strTemp.erase(0, 1);
			}
			strResult = strTemp;
		}
		catch (exception clsException)
		{
			eCode = Code::SYSTEM;
			ExceptionsProcessor::PrintExceptionInfo(eCode, clsException);
		}
		return eCode;
	}
}