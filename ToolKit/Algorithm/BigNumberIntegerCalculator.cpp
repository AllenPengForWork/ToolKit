#include <string>
#include <exception>
#include <StatusCodes.h>
#include <StringOperator.h>
#include <ExceptionsProcessor.h>
#include <BigNumberIntegerCalculator.h>

using namespace std;
using namespace StatusCodes;

namespace BigNumberIntegerCalculator
{
	Code Add(string strNum1, string strNum2, string& strResult)
	{
		Code eCode = Code::SUCCESSFUL;
		try
		{
			string strTemp = "";
			int iFirstNumIndex1 = 0;
			int iFirstNumIndex2 = 0;
			bool bIsNegativeNum1 = false;
			bool bIsNegativeNum2 = false;

			if (strNum1[0] == '-')
			{
				bIsNegativeNum1 = true;
				iFirstNumIndex1 = 1;
			}

			if (strNum2[0] == '-')
			{
				bIsNegativeNum2 = true;
				iFirstNumIndex2 = 1;
			}

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
					eCode = BigNumberIntegerCalculator::Subtract(strNum2, strNum1.substr(1, iIndex1), strTemp);
				}
				else
				{
					eCode = BigNumberIntegerCalculator::Subtract(strNum1.substr(1, iIndex1), strNum2, strTemp);
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
					eCode = BigNumberIntegerCalculator::Subtract(strNum2.substr(1, iIndex2), strNum1, strTemp);
				}
				else
				{
					eCode = BigNumberIntegerCalculator::Subtract(strNum1, strNum2.substr(1, iIndex2), strTemp);
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
			int iFirstNumIndex1 = 0;
			int iFirstNumIndex2 = 0;
			bool bIsNegativeNum1 = false;
			bool bIsNegativeNum2 = false;

			if (strNum1[0] == '-')
			{
				bIsNegativeNum1 = true;
				iFirstNumIndex1 = 1;
			}

			if (strNum2[0] == '-')
			{
				bIsNegativeNum2 = true;
				iFirstNumIndex2 = 1;
			}

			int iBorrow = 0;
			int iIndex1 = strNum1.size() - 1;
			int iIndex2 = strNum2.size() - 1;
			bool bSwitch = false;
			if (bIsNegativeNum1 && !bIsNegativeNum2) // (-) - (+)
			{
				eCode = BigNumberIntegerCalculator::Add(strNum1.substr(1, iIndex1), strNum2, strTemp);
				if (eCode != Code::SUCCESSFUL)
				{
					return eCode;
				}
			}
			else if (!bIsNegativeNum1 && bIsNegativeNum2) // (+) - (-)
			{
				eCode = BigNumberIntegerCalculator::Add(strNum1, strNum2.substr(1, iIndex2), strTemp);
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
			int iFirstNumIndex1 = 0;
			int iFirstNumIndex2 = 0;
			bool bIsNegativeNum1 = false;
			bool bIsNegativeNum2 = false;

			if (strNum1[0] == '-')
			{
				bIsNegativeNum1 = true;
				iFirstNumIndex1 = 1;
			}

			if (strNum2[0] == '-')
			{
				bIsNegativeNum2 = true;
				iFirstNumIndex2 = 1;
			}

			string strTemp((bIsNegativeNum1 ? iLength1 - 1 : iLength1) + (bIsNegativeNum2 ? iLength2 - 1 : iLength2), '0');
			for (int iIndex1 = iLength1 - 1; iIndex1 >= iFirstNumIndex1; --iIndex1)
			{
				int iCarry = 0;
				for (int iIndex2 = iLength2 - 1; iIndex2 >= iFirstNumIndex2; --iIndex2)
				{
					int iTempIndex = (bIsNegativeNum1 ? iIndex1 - 1 : iIndex1) + (bIsNegativeNum2 ? iIndex2 - 1 : iIndex2) + 1;
					int iSum = (strNum1[iIndex1] - '0') * (strNum2[iIndex2] - '0') + (strTemp[iTempIndex] - '0') + iCarry;
					strTemp[iTempIndex] = iSum % 10 + '0';
					iCarry = iSum / 10;
				}
				strTemp[bIsNegativeNum1 ? iIndex1 - 1 : iIndex1] += iCarry;
			}
			while (strTemp.size() > 1 && strTemp[0] == '0')
			{
				strTemp.erase(0, 1);
			}
			if ((bIsNegativeNum1 ^= bIsNegativeNum2) && strTemp != "0")
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

	Code Divide(string strNum1, string strNum2, string& strResult)
	{
		Code eCode = Code::SUCCESSFUL;
		try
		{
			string strTemp = "";
			int iFirstNumIndex1 = 0;
			int iFirstNumIndex2 = 0;
			string strABSNum1 = strNum1;
			string strABSNum2 = strNum2;
			bool bIsNegativeNum1 = false;
			bool bIsNegativeNum2 = false;

			if (strNum1[0] == '-')
			{
				bIsNegativeNum1 = true;
				iFirstNumIndex1 = 1;
				strABSNum1.erase(0, 1);
			}

			if (strNum2[0] == '-')
			{
				bIsNegativeNum2 = true;
				iFirstNumIndex2 = 1;
				strABSNum2.erase(0, 1);
			}
			if (strABSNum2 == "0")
			{
				strResult = "0";
				eCode = Code::UNABLE_DIVIDE_ZERO;
				return eCode;
			}
			int iLength1 = strNum1.size();
			int iLength2 = strNum2.size();
			int iExcludeSignNumLength1 = (bIsNegativeNum1 ? iLength1 - 1 : iLength1);
			int iExcludeSignNumLength2 = (bIsNegativeNum2 ? iLength2 - 1 : iLength2);
			if (iExcludeSignNumLength1 < iExcludeSignNumLength2 || (iExcludeSignNumLength1 == iExcludeSignNumLength2 && strABSNum1 < strABSNum2))
			{
				strResult = "0";
				return eCode;
			}
			
			string strDividend = strNum1.substr(bIsNegativeNum1 ? 1 : 0, iExcludeSignNumLength2);
			string strDivisor = bIsNegativeNum2 ? strNum2.substr(bIsNegativeNum2, iExcludeSignNumLength2) : strNum2;
			int iIndex = iExcludeSignNumLength2;
			bool bContinue;
			do
			{
				int iQuotient = 0;
				while (strDividend.size() > 0 && strDividend[0] == '0')
				{
					strDividend.erase(0, 1);
				}
				if (strDividend.size() >= iExcludeSignNumLength2)
				{
					bool bDivisible = false;
					do
					{
						int iDividendLength = strDividend.length();
						int iNum2Length = strDivisor.length();
						int iLength = iDividendLength > iNum2Length ? iDividendLength : iNum2Length;
						string strDividendTmp, strNum2Tmp;
						StringOperator::AddLeadingZeroes(strDividend, iLength, strDividendTmp);
						StringOperator::AddLeadingZeroes(strDivisor, iLength, strNum2Tmp);
						bDivisible = strDividendTmp >= strNum2Tmp;
						if (bDivisible)
						{
							eCode = Subtract(strDividend, strDivisor, strDividend);
							if (eCode != Code::SUCCESSFUL)
							{
								return eCode;
							}
							++iQuotient;
						}
					} while (bDivisible);
					strTemp += to_string(iQuotient);
				}
				bContinue = iIndex < iExcludeSignNumLength1;
 				if (bContinue)
				{
					strDividend += strNum1[iIndex];
					iIndex++;
				}
			} while (bContinue);
			while (strTemp.size() > 1 && strTemp[0] == '0')
			{
				strTemp.erase(0, 1);
			}
			if ((bIsNegativeNum1 ^= bIsNegativeNum2) && strTemp != "0")
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
}