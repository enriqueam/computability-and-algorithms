// C++ program to implement
// the above approach
#include <bits/stdc++.h>

#ifndef BIGINT_H
#define BIGINT_H

class BigInt {
	private:
		int level_;
		int counter_;
	public:
		std::string digits;
		//Constructors:
		BigInt(unsigned long long n = 0);
		BigInt(std::string &);
		BigInt(const char *);
		BigInt(BigInt &);

		//Helper Functions:
		friend void divide_by_2(BigInt &a);
		friend bool Null(const BigInt &);
		friend int Length(const BigInt &);
		int operator[](const int)const;

		/* * * * Operator Overloading * * * */

		//Direct assignment
		BigInt &operator=(const BigInt &);

		//Post/Pre - Incrementation
		BigInt &operator++();
		BigInt operator++(int temp);
		BigInt &operator--();
		BigInt operator--(int temp);

		//Addition and Subtraction
		friend BigInt &operator+=(BigInt &, const BigInt &);
		friend BigInt operator+(const BigInt &, const BigInt &);
		friend BigInt operator-(const BigInt &, const BigInt &);
		friend BigInt &operator-=(BigInt &, const BigInt &);

		//Comparison operators
		friend bool operator==(const BigInt &, const BigInt &);
		friend bool operator!=(const BigInt &, const BigInt &);

		friend bool operator>(const BigInt &, const BigInt &);
		friend bool operator>=(const BigInt &, const BigInt &);
		friend bool operator<(const BigInt &, const BigInt &);
		friend bool operator<=(const BigInt &, const BigInt &);

		//Multiplication and Division
		friend BigInt &operator*=(BigInt &, const BigInt &);
		friend BigInt operator*(const BigInt &, const BigInt &);
		friend BigInt &operator/=(BigInt &, const BigInt &);
		friend BigInt operator/(const BigInt &, const BigInt &);

		//Modulo
		friend BigInt operator%(const BigInt &, const BigInt &);
		friend BigInt &operator%=(BigInt &, const BigInt &);

		//Power Function
		friend BigInt &operator^=(BigInt &, const BigInt &);
		friend BigInt operator^(BigInt &, BigInt &);
		
		//Square Root Function
		friend BigInt sqrt(BigInt &a);

		//Read and Write
		friend std::ostream &operator<<(std::ostream &, const BigInt &);
		friend std::istream &operator>>(std::istream &, BigInt &);

		BigInt Karatsuba(const BigInt &a, const BigInt &b);
		void SetLevel(int level);
		int GetCounter();
};

#endif

