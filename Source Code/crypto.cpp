#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<random>
#include<ctime>

using namespace std;

int functionnumber = 11; //upto where random number generate

int main();

string Takedatainput();
string Biasdata(vector<int> keys,string data);
vector<int> Biaskeys(vector<int> keys,int inputlength);
string Decrypt(string encrypteddata, vector<int> biasedkeys);
vector<int> Takekeyin(int inputlength);
string TakeEncrypteddata();
int biaskeylimit();

string::iterator it;

int main()
{
	string data;
	int inputlength=0;
	int choice;
	int loop = 1;
	int h;
	while (loop == 1)
	{
		cout << "\nDo you want to encrypt(1) or decrypt(2) :\n" << endl;
		cin >> choice;
		cin.ignore();
		if (choice == 1)
		{
			data = Takedatainput();

			for (inputlength = 0, it = data.begin();it != data.end();it++)
			{
				inputlength++;
			}


			vector<int> keys = Randomkeysgen(inputlength);
			//for (vector<int>::iterator it = keys.begin();it != keys.end();it++)
			//{
			//	cout << *it<<",";
			//}
			//cout << endl;


			string encrypteddata = Biasdata(keys, data); //encrypted message

			vector<int> genkey;
			genkey = Biaskeys(keys, inputlength); //biasedkey


			cout << endl;
			cout << "Now Encrypted Data is : ";
			cout << encrypteddata;
			cout << endl;
			cout << "Biased Keys : ";
			for (vector<int>::iterator it = genkey.begin();it != genkey.end();it++)
			{
				cout << *it << ":";
			}
			cout << endl << endl;
		}
		else {
			
			string s = TakeEncrypteddata();
				cout << "\nEnter the Hash key:\n";

				for (inputlength = 0, it = s.begin();it != s.end();it++)
				{
					inputlength++;
				}

				h= 0;
				for (int i = 0;i < inputlength;i++)
				{
					h++;
					for (int j = 0;j <= i;j++)
					{
						h++;
					}
				}

				vector<int> k = Takekeyin(h);

				cout << endl << "Decrypting (Please Wait) (Fake Timer using For loop)" << endl;
				for (int i = 0;i < 1000000000;i++);
				cout << "Decrypted Message is : " << Decrypt(s, k) << endl;
		}

		cout << "\nDo you want another encryption or decryption to true or false\n";
		cin >> loop;
		cin.ignore();
	}
	
	system("pause");

    return 0;
}


string TakeEncrypteddata()
{
	cout << endl << "Enter The Encrypted Data :" << endl;
	string s;
	//cin.ignore();
	getline(cin, s);
	//cin.ignore();

	return s;
}

vector<int> Takekeyin(int inputlength)
{
	vector<int> v;
	int f;
	//cin.ignore();

	for (int i = 0;i <= inputlength;i++)
	{
		cin >> f;
		v.push_back(f);
	}
	cin.ignore();
	return v;
}

string Takedatainput()
{
	string data;

	cout << "\nEnter the data to be encrypted "<<endl;
	getline(cin, data);

	return data;
}

string Biasdata(vector<int> keys,string data)
{
	//bias the data
	vector<int>::iterator keyselected;
	for (it = data.begin(), keyselected = keys.begin();it != data.end();it++, keyselected++)
	{
		switch (*keyselected)
		{
		case 1: 
			*it += 1;
			break;
		case 2:
			*it -= 1;
			break;
		case 3:
			*it += 2;
			break;
		case 4:
			*it -= 2;
			break;
		case 5:
			*it += 3;
			break;
		case 6:
			*it -= 3;
			break;
		case 7:
			*it += 4;
			break;
		case 8:
			*it -= 4;
			break;
		case 9:
			*it += 5;
			break;
		case 10:
			*it -= 5;
			break;
		case 11:
			*it += 6;
			break;
		}
	}

	return data;

	return 0;
}


vector<int> Biaskeys(vector<int> keys,int inputlength)
{
	vector<int> genkey;
	vector<int> newnum;
	vector<int>::iterator it3;
	vector<int>::iterator it4;
	int noisenum;
	
	int limit = biaskeylimit();

	if (limit >= 0)
	{
		genkey.push_back(limit);
	}
	else {
		cout << "Invalid input";
		exit(0);
	}

	for (it3 = keys.begin(),noisenum = 1;it3 != keys.end();it3++,noisenum++)
	{
		if (noisenum > limit&&limit!=0)
		{
			noisenum = limit;
		}

		genkey.push_back(*it3);
		newnum = Randomkeysgen(inputlength); /*This will return a random integer. Configured with External Library if you wanted to understand mail me Kartik and Rahul*/
		it4 = newnum.begin();
		for (int j = 0;j < noisenum;j++)
		{
			genkey.push_back(*it4);
			it4++;
		}
	}

	return genkey;
}

int biaskeylimit()
{
	int limit;
	cout << endl << "Enter the limit for the key (0 or unlimited) - limit decides the complexity of the hash key :" << endl;
	cin >> limit;
	cin.ignore();
	return limit;
}

	string Decrypt(string encrypteddata,vector<int> biasedkeys)
	{
		vector<int>::iterator keyselected;
		string data = encrypteddata;
		vector<int> keys = biasedkeys;
		int noiserem = 1;
		int limit = 0;
		for (it = data.begin(), keyselected = keys.begin(),noiserem=1;it != data.end();it++, keyselected++,noiserem++)
		{
			if (keyselected == keys.begin())
			{
				limit = *keyselected;
				//cout << "limit" << limit;
				keyselected++;
			}
			if (noiserem > limit&&limit!=0)
			{
				noiserem = limit;
			}
			
				switch (*keyselected)
				{/*Collection of function to bias and unbias data */
				case 1:
					*it -= 1;
					break;
				case 2:
					*it += 1;
					break;
				case 3:
					*it -= 2;
					break;
				case 4:
					*it += 2;
					break;
				case 5:
					*it -= 3;
					break;
				case 6:
					*it += 3;
					break;
				case 7:
					*it -= 4;
					break;
				case 8:
					*it += 4;
					break;
				case 9:
					*it -= 5;
					break;
				case 10:
					*it += 5;
					break;
				case 11:
					*it -= 6;
					break;
				}
				for (int i = 0;i < noiserem;i++)
				{
					keyselected++;
				}
			
			
		}

		return data;
	}
