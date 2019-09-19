// Program converts cryptocurrency to US Dollars and vice versa 
#include <iostream>
using namespace std;
int main()
{
    string cryptoType, USDOrCrypto;
    double currencyAmount, valueInUSD, valueInCrypto; 
    cout << "Program supports conversions for: " << endl;
    cout << "Bitcoin, Ethereum, XRP, and Zcash." << endl;
    cout << "Enter the name of the cryptocurrency you wish to convert:" << endl; 
    cin >> cryptoType;
    if (cryptoType != "Bitcoin" && cryptoType != "Ethereum" && cryptoType !=
    "XRP" && cryptoType != "Zcash")//Checks to see if input is valid
    {
        cout << "Error: invalid input." << endl;
        return 0;
    }
    cout << "Would you like to convert to USD? (Type \"Y\" for yes, else \"N\""
    << " to convert from USD to " << cryptoType << "):" << endl;
    cin >> USDOrCrypto; 
    if (USDOrCrypto != "Y" && USDOrCrypto != "N")//Checks to see if input is valid
    {
        cout << "Error: invalid input." << endl;
        return 0;
    }
    cout << "Enter the amount of currency you have:" << endl;
    cin >> currencyAmount;
    if (currencyAmount < 0) //Checks to see if input is negative
    {
	cout << "Error: can't convert negative number." << endl;
	return 0;
    }
    if (USDOrCrypto == "Y")//Converting to USD
    {
    	if (cryptoType ==  "Bitcoin") 
    	{
		valueInUSD = currencyAmount * 6530.84;//1 Bitcoin is worth $6530.84
    	}
    	else if (cryptoType == "Ethereum")
    	{
        	valueInUSD = currencyAmount * 232.06;//1 Ethereum is worth $232.06
   	} 
   	else if (cryptoType == "XRP")
   	{
		valueInUSD = currencyAmount * 0.302801;//1 XRP is worth $0.302801
	}
     	else 
   	{
		valueInUSD = currencyAmount * 132.74;//1 Zcash is worth $132.74
   	}
    	cout << currencyAmount << " " << cryptoType << " is worth $" << valueInUSD << "." << endl;
   	return 0;
    }
    if (USDOrCrypto == "N")
    {
	if (cryptoType == "Bitcoin")
        {
		valueInCrypto = currencyAmount/6530.84;//$6530.84 is worth 1 Bitcoin
	}
        if (cryptoType == "Ethereum")
	{
		valueInCrypto = currencyAmount/232.06;//$232.06 is worth 1 Ethereum
	}
	if (cryptoType == "XRP")
	{
		valueInCrypto = currencyAmount/0.302801;//$0.302801 is worth 1 XRP
	}
	else 
	{
		valueInCrypto = currencyAmount/132.74;//$132.74 is worth 1 Zcash
	}
	cout << "$" << currencyAmount << " is worth " << valueInCrypto << " " <<
        cryptoType << "." << endl;
	return 0;
    }
}
