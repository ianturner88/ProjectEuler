#include<string>
#include<iostream>
using namespace std;

void Length_Calculator(int &n1, int &n2, int &n3, int &length_difference, string &fibonacci1, string &fibonacci2, string &fibonacci_next);
void Fibonacci_Generator(string &fibonacci1, string &fibonacci2, string &fibonacci_next);
void Fibonacci_Next(string &fibonacci_next);
void Add_LSB(string &fibonacci1, string &fibonacci2, string &fibonacci_next, int &length_difference, int &carry, int &n1, int &n2, int &sum);
void Add_MSB(string &fibonacci2, string &fibonacci_next, int &length_difference, int &n1, int &n2);
void Carry(string &fibonacci_next, int &carry);
void Reverse(string &fibonacci_next);

int main()
{
	string fibonacci1 = "1", fibonacci2 = "1", fibonacci_next = "2";
	int length_difference, carry = 0, count = 0, n1, n2, n3 = 1, sum = 0;
	
	while (n3 != 3)
	{
		Length_Calculator(n1, n2, n3, length_difference, fibonacci1, fibonacci2, fibonacci_next);
		Fibonacci_Generator(fibonacci1, fibonacci2, fibonacci_next);
		Fibonacci_Next(fibonacci_next);
		Add_LSB(fibonacci1, fibonacci2, fibonacci_next, length_difference, carry, n1, n2, sum);
		Add_MSB(fibonacci2, fibonacci_next, length_difference, n1, n2);
		Carry(fibonacci_next, carry);
		
		count++;
	}

	Reverse(fibonacci_next);
	
	cout << "The index number of the first fibonacci number with 1 000 digits is: " << count << endl << endl;

	cout << "The " << count << " fibonacci number is " << fibonacci_next;
}

void Length_Calculator(int &n1, int &n2, int &n3, int &length_difference, string &fibonacci1, string &fibonacci2, string &fibonacci_next)
{
	n1 = fibonacci1.length();
	n2 = fibonacci2.length();
	n3 = fibonacci_next.length();

	length_difference = n2 - n1;
}

void Fibonacci_Generator(string &fibonacci1, string &fibonacci2, string &fibonacci_next)
{
	/*Traditionally, Fnext = F1 + F2 is the first line*/

	fibonacci1 = fibonacci2;
	fibonacci2 = fibonacci_next;
}

void Fibonacci_Next(string &fibonacci_next)
{
	string replacement = "0";

	fibonacci_next = replacement;
}

void Add_LSB(string &fibonacci1, string &fibonacci2, string &fibonacci_next, int &length_difference, int &carry, int &n1, int &n2, int &sum)
{
	/*Add the least significant bits of both numbers*/

	if (n1 == n2)
	{
		for (int i = n1 - 1; i >= 0; i--)
		{
			int test1 = (fibonacci1[i] - '0');
			int test2 = (fibonacci2[i + length_difference] - '0');

			sum = (fibonacci1[i] - '0') + (fibonacci2[i + length_difference] - '0') + carry;

			fibonacci_next.push_back(sum % 10 + '0');

			carry = sum / 10;
		}
	}

	else
	{
		for (int i = n1 - 1; i >= 0; i--)
		{
			int test1 = (fibonacci1[i] - '0');
			int test2 = (fibonacci2[i + length_difference] - '0');

			sum = (fibonacci1[i] - '0') + (fibonacci2[i + length_difference] - '0') + carry;

			fibonacci_next.push_back(sum % 10 + '0');

			carry = sum / 10;
		}
	}
	
	fibonacci_next.erase(fibonacci_next.begin());
}

void Add_MSB(string &fibonacci2, string &fibonacci_next, int &length_difference, int &n1, int &n2)
{
	/*Add the most sigificant digits of n2, the larger number*/
	
	int remainder;
	
	for (int i = n2 - n1 - 1; i >= 0; i--)
	{
		remainder = (fibonacci2[i] - '0');
		
		fibonacci_next.push_back(remainder + '0');
	}
}

void Carry(string &fibonacci_next, int &carry)
{
	if (carry == 1)
	{
		fibonacci_next.push_back(carry + '0');
	}
}

void Reverse(string &fibonacci_next)
{
	reverse(fibonacci_next.begin(), fibonacci_next.end());
}