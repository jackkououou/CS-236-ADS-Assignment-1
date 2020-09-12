#include "LargeInt.h"
#include <string>
using namespace std;

LargeInt::LargeInt()
{
	for (int i = 0; i < 50; i++)
	{
		fityInt[i] = 0;
	}
	size = 0;
	negative = false;
}

LargeInt::LargeInt(string input)
{
	int inputSize = input.length();
	for (int i = 0; i < 50; i++)
	{
		fityInt[i] = 0;
	}
	if (input[0] == '-')
	{
		if (inputSize > 51)
			this->size = 0;

		else
		{
			negative = true;
			size = inputSize - 1;
			for (int i = 0; i < size; i++)
			{
				fityInt[i] = input[size  - i] - '0';
			}
		}
	
	}
	else
	{
		if (inputSize > 50)
			this->size = 0;

		else
		{
			negative = false;
			size = inputSize;
			for (int i = 0; i < size; i++)
			{
				fityInt[i] = input[size -1 - i] - '0';
			}
		}

	}
}

LargeInt::LargeInt(const LargeInt & obj)
{
	this->size = obj.size;
	this->negative = obj.negative;
	
	for (int i = 0; i < 50; i++)
		this->fityInt[i] = 0;

	for (int i = 0; i < size; i++)
		this->fityInt[i] = obj.fityInt[i];
}

LargeInt LargeInt::operator+(LargeInt right)
{
	LargeInt Result = *this, Temp;
	int carry = 0;

	//Checking if numbers have the same sign; Simple add

	//Addition + (+) + || - (+) -
	if (this->negative == right.negative)
	{
		for (int i = 0; i < Result.size || i < right.size; i++)
		{
			//adding
			Result.fityInt[i] = Result.fityInt[i] + right.fityInt[i];

			//checking to see what the value of the tens digit is and upping the carry value for each I DONT really think the result can ever be higher than 19
			if (Result.fityInt[i] > 9)
			{
				
				Result.fityInt[i] = Result.fityInt[i] - 10;
				if (i < 49)
				{
					Result.fityInt[i + 1]++;
					if (i == Result.size - 1)
						Result.size++;
				}
			}
		}
	}
	//Addition + (+) -
	else if (!(this->negative) && right.negative)
	{
		Temp = right;
		Temp.negative = false;

		Result = *this - Temp;
	}
	//Addition - (+) +
	else if (this->negative && !(right.negative))
	{
		Temp = *this;
		Result = right - Temp;
	}
	//Resizing Result
	for (int i = 0; i < 50; i++)
	{
		if (Result.fityInt[i] != 0)
			Result.size = i + 1;
	}

	return Result;
}

LargeInt LargeInt::operator-(LargeInt right)
{
	LargeInt Result;
	bool carry = 0;
	
	//Subtract + (-) +
	if (!(this->negative) && !(right.negative))
	{
		if (*this > right)
		{
			Result = *this;
			for (int i = 0; i < 50; i++)
			{
				Result.fityInt[i] = Result.fityInt[i] - carry - right.fityInt[i];
				if (Result.fityInt[i] < 0)
				{
					carry = true;
					Result.fityInt[i] = Result.fityInt[i] + 10;
				}
				else
					carry = false;
			}
		}
		else if (*this < right)
		{
			Result = right;
			Result.negative = true;
			for (int i = 0; i < 50; i++)
			{
				Result.fityInt[i] = right.fityInt[i] - this->fityInt[i] - carry ;
				if (Result.fityInt[i] < 0)
				{
					carry = true;
					Result.fityInt[i] = Result.fityInt[i] + 10;
				}
				else
					carry = false;
			}
		}
	}
	//Subtract - (-) -
	else if (this->negative && right.negative)
	{
		if (*this > right)
		{
			Result = right;
			Result.negative = false;
			for (int i = 0; i < 50; i++)
			{
				Result.fityInt[i] = Result.fityInt[i] - carry - this->fityInt[i];
				if (Result.fityInt[i] < 0)
				{
					carry = true;
					Result.fityInt[i] = Result.fityInt[i] + 10;
				}
				else
					carry = false;
			}
		}
		else if (*this < right)
		{
			Result = *this;
			for (int i = 0; i < 50; i++)
			{
				Result.fityInt[i] = Result.fityInt[i] - carry - right.fityInt[i];
				if (Result.fityInt[i] < 0)
				{
					carry = true;
					Result.fityInt[i] = Result.fityInt[i] + 10;
				}
				else
					carry = false;
			}
		}
		
	}
	//Subtract - (-) + || + (-) -
	else if ((this->negative && !(right.negative)) || (!(this->negative) && right.negative))
	{
		Result = *this;
		for (int i = 0; i < Result.size || i < right.size; i++)
		{
			//adding
			Result.fityInt[i] = Result.fityInt[i] + right.fityInt[i];

			//checking to see what the value of the tens digit is and upping the carry value for each I DONT really think the result can ever be higher than 19
			if (Result.fityInt[i] > 9)
			{

				Result.fityInt[i] = Result.fityInt[i] - 10;
				if (i < 49)
				{
					Result.fityInt[i + 1]++;
					if (i == Result.size - 1)
						Result.size++;
				}
			}
		}
	}
	//Resizing Result
	for (int i = 0; i < 50; i++)
	{
		if (Result.fityInt[i] != 0)
			Result.size = i + 1;
	}
	return Result;
}

LargeInt & LargeInt::operator=(LargeInt right)
{
	this->size = right.size;
	this->negative = right.negative;
	for (int i = 0; i < size; i++)
	{
		this->fityInt[i] = right.fityInt[i];
	}
	return *this;// TODO: insert return statement here
}


bool operator<(const LargeInt & left, const LargeInt & right)
{
	if (!(left.negative) && right.negative)
		return false;
	else if (!(left.negative) && !(right.negative))
	{
		if (left.size > right.size)
			return false;
		else if (left.size < right.size)
			return true;
		else
		{
			for (int i = left.size - 1; i > 0; i--)
			{
				if (left.fityInt[i] > right.fityInt[i])
					return false;
				else if (left.fityInt[i] < right.fityInt[i])
					return true;
			}
		}
	}
	else if (left.negative && right.negative)
	{
		if (left.size > right.size)
			return true;
		else if (left.size < right.size)
			return false;
		else
		{
			for (int i = left.size - 1; i > 0; i--)
			{
				if (left.fityInt[i] > right.fityInt[i])
					return true;
				else if (left.fityInt[i] < right.fityInt[i])
					return false;
			}
		}
	}
	else if (left.negative && !(right.negative))
		return true;
	return false;
}
bool operator>(const LargeInt & left, const LargeInt & right)
{
	if (!(left.negative) && right.negative)
		return true;
	else if (!(left.negative) && !(right.negative))
	{
		if (left.size > right.size)
			return true;
		else if (left.size < right.size)
			return false;
		else
		{
			for (int i = left.size - 1; i > 0; i--)
			{
				if (left.fityInt[i] > right.fityInt[i])
					return true;
				else if (left.fityInt[i] < right.fityInt[i])
					return false;
			}
		}
	}
	else if (left.negative && right.negative)
	{
		if (left.size > right.size)
			return false;
		else if (left.size < right.size)
			return true;
		else
		{
			for (int i = left.size - 1; i > 0; i--)
			{
				if (left.fityInt[i] > right.fityInt[i])
					return false;
				else if (left.fityInt[i] < right.fityInt[i])
					return true;
			}
		}
	}
	else if (left.negative && !(right.negative))
		return false;
	return false;
}
bool operator==(const LargeInt & left, const LargeInt & right)
{
	bool sentinel = true;
	if (left.negative != right.negative)
		return false;
	if (left.size != right.size)
		return false;
	else
	{
		for (int i = left.size - 1; i >= 0; i--)
		{
			if (left.fityInt[i] != right.fityInt[i])
				sentinel = false;
		}
		return sentinel;
	}
}
bool operator!=(const LargeInt & left, const LargeInt & right)
{
	bool sentinel = false;
	if (left.negative != right.negative)
		return true;
	if (left.size != right.size)
		return true;
	else
	{
		for (int i = left.size - 1; i >= 0; i--)
		{
			if (left.fityInt[i] != right.fityInt[i])
				sentinel = true;
		}
		return sentinel;
	}
}
bool operator>=(const LargeInt & left, const LargeInt & right)
{
	bool sentinel = false;
	if (left > right)
		sentinel = true;
	else if (left == right)
		sentinel = true;
	return sentinel;
}
bool operator<=(const LargeInt & left, const LargeInt & right)
{
	bool sentinel = false;
	if (left < right)
		sentinel = true;
	else if (left == right)
		sentinel = true;
	return sentinel;
}
LargeInt::~LargeInt()
{
	/*for (int i = 0; i < 50; i++)
		this->fityInt[i] = NULL;
	this->negative = NULL;
	this->size = NULL;
	delete this->fityInt;
	delete this;*/
}

istream & operator >> (istream & in, LargeInt &right)
{
	string temp;
	string zero = "0";
	in >> temp;
	if (temp.length() <= 50)
	{
		right = temp;

		return in;
	}
	else
	{
		cout << "This number has more than 50 digits. Number is set to 0." << endl;
		right = zero;
		right.size = 0;

		return in;
	}
}
ostream & operator << (ostream & out, const LargeInt &right)
{
	
	if (right.size == 0)
	{
		out << '0';
		return out;
	}
	if (right.negative)
	{
		out << '-';
	}
	for (int i = right.size - 1; i > -1; i--)
	{
		out << right.fityInt[i];
	}
	
	return out;
}
