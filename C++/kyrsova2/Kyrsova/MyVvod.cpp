//MyVvod.cpp
#include "MyVvod.h"
int InputINT(int min, int max)//Error 1-3
{
	int value;
	string is;
	int i = 0;
	while (true)
	{
		try
		{
			getline(cin, is);
			bool flag_negative = false;
			for (char const& c : is)
			{
				if (i == 0 && c != '-' && !isdigit(c)) throw IntException("It's is not number", 1);
				if (!flag_negative && c == '-') flag_negative = true;
				else if (!isdigit(c)) throw IntException("It's is not number", 1);
		        i++;
			}
			value = stoi(is);
			if (value < min) throw IntException("Number is to slow", 2);
			if (value > max) throw IntException("Number is to big", 3);
			break;
		}
		catch (IntException& e)
		{
			cout << e.WhatINT();
			cout << "Try again" << endl;
		}
		catch (...) { cout << "Try again" << endl; }

	}

	return value;
}
string InputString()// 4-11
{
	string is;
	int i = 0;
	int ch_space = 0;
	while (true)
	{
		try
		{
			getline(cin, is);
			i = 0;
			for (char const& c : is)
			{
				if (i == 0 && (c == ' ' || c == '-')) throw StringException("You have space or '-' in the begin of word", 9); 
				if (c == ' ') { ch_space++; if (ch_space == 2) throw StringException("Don't use 2 space once", 10);}
				else if (c != ' ') ch_space = 0;
				if (c >= '0' && c <= '9') throw StringException("Number in the string", 5);
				if ((c >= 'à' && c <= 'ÿ') || (c >= 'À' && c <= 'ß')) throw StringException("Russian symbol", 4);
				if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && c != ' ' && c!= '-') throw StringException("Unknow's symbol", 8);
				i++;
			}
			if (is[is.length() - 1] == ' ' || is[is.length() - 1] == '-' ) throw StringException("You have space or '-' in the end of word", 11);
			if (i > 20) throw StringException("String to long", 6);
			break;
		}
		catch (StringException& e)
		{
			cout << e.WhatSTRING();
			cout << "Try again" << endl;
		}
		catch (...) { cout << "Try again" << endl;	}
	}

	return is;
}

string InputStringwithINT()
{
	string is;
	int i = 0;
	int ch_space = 0;
	while (true)
	{
		try
		{
			getline(cin, is);
			i = 0;
			for (char const& c : is)
			{
				if (i == 0 && (c == ' ' || c == '-')) throw StringException("You have space or '-' in the begin of word", 9);
				if (c == ' ') { ch_space++; if (ch_space == 2) throw StringException("Don't use 2 space once", 10); }
				else if (c != ' ') ch_space = 0;
				if ((c >= 'à' && c <= 'ÿ') || (c >= 'À' && c <= 'ß')) throw StringException("Russian symbol", 4);
				if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && c != ' ' && c != '-' && (c < '0' && c > '9')) throw StringException("Unknow's symbol", 8);
				i++;
			}
			if (is[is.length() - 1] == ' ' || is[is.length() - 1] == '-') throw StringException("You have space or '-' in the end of word", 11);
			if (i > 20) throw StringException("String to long", 6);
			if (i == 1) throw StringException("String to short", 7);
			break;
		}
		catch (StringException& e)
		{
			cout << e.WhatSTRING();
			cout << "Try again" << endl;
		}
		catch (...) { cout << "Try again" << endl; }
	}
	return is;
}

double InputDouble(int min, int max)//Error 12
{
	double value;
	string is;
	int i = 0;
	int ch_tochek = 0;
	while (true)
	{
		try
		{
			getline(cin, is);
			bool flag_negative = false;
			for (char const& c : is)
			{
				if (c == '.') ch_tochek++;
				if (ch_tochek > 1) { ch_tochek = 0; throw DoubleException("There are many '.'", 12);} 
				if (i == 0 && c != '-' && (!isdigit(c) && c != '.')) throw DoubleException("It's is not number", 1);
				if (!flag_negative && c == '-') flag_negative = true;
				else if (!isdigit(c) && c !='.') throw DoubleException("It's is not number", 1);
				i++;
			}
			locale::global(std::locale("C"));
			value = stod(is);
			if (value < min) throw DoubleException("Number is to slow", 2);
			if (value > max) throw DoubleException("Number is to big", 3);
			break;
		}
		catch (DoubleException& e)
		{
			cout << e.WhatDOUBLE();
			cout << "Try again" << endl;
		}
		catch (...) { cout << "Try again" << endl; }
	}

	return value;
}