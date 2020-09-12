#pragma once
#include <iostream>
#include <string>

using namespace std;

class LargeInt
{
private:
	int fityInt[50];
	int size;
	bool negative;
public:
	LargeInt();
	LargeInt(string input);
	LargeInt(const LargeInt& obj);
	LargeInt operator + (LargeInt right);
	LargeInt operator - (LargeInt right);
	LargeInt& operator = (LargeInt right);
	friend bool operator < (const LargeInt &left, const LargeInt &right);
	friend bool operator > (const LargeInt & left, const LargeInt & right);
	friend bool operator == (const LargeInt & left, const LargeInt & right);
	friend bool operator != (const LargeInt & left, const LargeInt & right);
	friend bool operator >= (const LargeInt & left, const LargeInt & right);
	friend bool operator <= (const LargeInt & left, const LargeInt & right);
	friend istream& operator >> (istream& in,  LargeInt &right);
	friend ostream& operator << (ostream& out, const LargeInt &right);
	~LargeInt();
};

