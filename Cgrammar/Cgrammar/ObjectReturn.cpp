// source from http://www.bogotobogo.com/cplusplus/object_returning.php

/* Function could return
A reference to an object
A constant reference to an object
An object.
A Constant object
*/


#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <cstddef>
#include <iterator>
using namespace std;

class Kevin
{
private:
	double real;
	double imag;

public:
	Kevin() {}
	Kevin(double r, double i) : real(r), imag(i) {}
	Kevin operator + (const Kevin & k) const
	{
		return Kevin(real + k.real, imag + k.imag);
	}

	Kevin & operator += (const Kevin &k)
	{
		real = k.real;
		imag = k.imag;
		return *this;
	}
	friend ostream& operator<< (ostream& os, const Kevin &k);
	double getSize() const
	{
		return sqrt(real* real + imag * imag);
	}

};

ostream & operator<<(ostream & os, const Kevin & k)
{
	os << "( " << k.real << "  -  " << k.imag << ") ";
	return os;
}


// Maximum is just function name....
const Kevin & Maximum(const Kevin &k1, const Kevin &k2)
{
	if (k1.getSize() > k2.getSize())
	{
		return k1;
	}
	else
	{
		return k2;
	}
}

class A
{
public:
	A() = delete;
	float a;
	string b;
	int c;
};


std::vector<uint8_t> readFile(const char* filename)
{
	// open the file:
	std::ifstream file(filename, std::ios::binary);

	// Stop eating new lines in binary mode!!!
	file.unsetf(std::ios::skipws);

	// get its size:
	std::streampos fileSize;

	file.seekg(0, std::ios::end);
	fileSize = file.tellg();
	file.seekg(0, std::ios::beg);

	// reserve capacity
	std::vector<uint8_t> vec;
	vec.reserve(fileSize);

	// read the data:
	vec.insert(vec.begin(),
		std::istream_iterator<uint8_t>(file),
		std::istream_iterator<uint8_t>());

	return vec;
}




int main()
{
	Kevin k1(10, 20);
	Kevin k2(5, 40);
	cout << " k1 is " << k1 << endl;
	cout << " k2 is " << k2 << endl;
	// Checking which
	Kevin kFind = Maximum(k1, k2);
	cout << "Which one " << kFind << endl;
	
	Kevin k3(10, 10);
	Kevin k4, k5;
	k5 = k4 = k3;

	A consA{ 30.3, "kevin", 4 };
	A consB{};
	

	system("pause");
}