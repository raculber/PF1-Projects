// Program endcodes/decodes messages using 2 different methods
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int shift, encodeOrDecode, classicalOrImproved;
	char message;
	cout << "Would you like to encode or decode your message?" <<
	" (Type 1 to encode, 2 to decode)" << endl;
	cin >> encodeOrDecode;
	if (encodeOrDecode != 1 && encodeOrDecode != 2)
	{
		cout << "Invalid input." << endl;
		return 0;
	}
	cout << "Would you like to use the classical or improved " <<
	"algorithm? (Type 1 to use the classical method, 2 to use " <<
	"the improved method)" << endl;
	cin >> classicalOrImproved;
	if (classicalOrImproved != 1 && classicalOrImproved != 2)
	{
		cout << "Invalid input." << endl;
		return 0;
	}
        cout << "Enter an integer shift value: " << endl;
        cin >> shift;
        if (shift < 1 || shift > 25)
        {
                cout << "Invalid shift value." << endl;
                return 0;
        }
	cout << "Enter the message you want to encode/decode: " << endl;
        cin.get(message);
        if (classicalOrImproved == 1)//Classical Caesar method
	{
		if (encodeOrDecode == 1)//Encodes the message
		{
			while (message != '.')
			{
				if (message != ' ' && message >= 'A' && message <= 'Z')//Checks if message is alphabetical
				{
					message = message - shift;
					if (message < 'A')//If message is shifted too far
					{
						message = message+26;
					}
				}
				if ((message >= 'A' && message <= 'Z') || message == ' ')
				{
				cout << message;
				}
				cin.get(message);
			}
			cout << endl;
		}
		else if (encodeOrDecode == 2)//Decodes the message
		{
			while (message != '.') 
			{
				if (message != ' ' && message >= 'A' && message <= 'Z')
				{
					message = message + shift;
					if  (message > 'Z')//If message is shifted too far
					{
						message = message - 26;
					}
				}
				if ((message >= 'A' && message <= 'Z') || message == ' ')
				{
				cout << message;
				}
				cin.get(message);
			}
			cout << endl;
		}
	}
	else if (classicalOrImproved == 2)//Improved method
	{
		if (encodeOrDecode == 1)
		{ 
			while (message != '.')
                        {
                                if (message != ' ' && message >= 'A' && message <= 'Z')
                                {
					message = message - shift;
                                        shift = shift % 25 + 1;//Changes shift value 
				        if (message < 'A')
                                        {
                                                message = message+26;
                                        }
                                }
				if ((message >= 'A' && message <= 'Z') || message == ' ')
				{
                                cout << message;
				}
                                cin.get(message);
                        }
                        cout << endl;
		}
		else if (encodeOrDecode == 2)
		{ 
			while (message != '.')
                        {
                                if (message != ' ' && message >= 'A' && message <= 'Z')
                                {
                                        message = message + shift;
					shift = shift % 25 + 1;
                                        if (message > 'Z')
                                        {
                                                message = message - 26;
                                        }
                                }
				if ((message >= 'A' && message <= 'Z') || message == ' ')
				{
                                cout << message;
				}
                                cin.get(message);
                        }
                        cout << endl;
		}
	}
	return 0;
}

