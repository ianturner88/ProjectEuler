#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> Sieve_Of_Eratosthenes();
bool Is_Pandigital(int input_number);

std::vector<int> prime_sieve;
const long long int upperlimit = 7654321;
bool prime[upperlimit] = { 0 };
unsigned long long int prime_number;

int main(void) {

	bool is_prime_pandigital = false;

	std::vector<int> prime_numbers_less_than_upperlimit = Sieve_Of_Eratosthenes();

	for (int i = prime_numbers_less_than_upperlimit.size(); (i > 0) && (is_prime_pandigital == false); i--)
	{
		int prime_pandigital = prime_numbers_less_than_upperlimit[i - 1];

		if (prime_pandigital = 7652413)
		{
			int test = 0;
		}

		if (Is_Pandigital(prime_pandigital) == true)
		{
			is_prime_pandigital = true;
			std::cout << "The largest pandigital prime is: " << prime_pandigital;
		}
	}

	getchar();
}

bool Is_Pandigital(int input_number)
{
	/*determines if a number is pandigital*/

	std::vector<int> temp;
	int single_digit;
	bool is_match = true;

	while (input_number > 0)
	{
		//identify the last digit 
		single_digit = input_number % 10;
		//store the last digit
		temp.push_back(single_digit);
		//shrink the input number so that the next 'last' digit may be found
		input_number /= 10;
	}

	//sort the numbers from descending to increasing
	std::sort(temp.begin(), temp.end());

	for (int i = 0; (i < temp.size()) && (is_match == true); i++)
	{
		//check if the i-th vector element equals i
		//example slot 3 should have a value of 3
		if ((i + 1) != temp[i])
		{
			//the number is not pandigital
			is_match = false;
		}
	}

	return is_match;
}


std::vector<int> Sieve_Of_Eratosthenes()
{
	/*returns a vector of all prime numbers less than the specified upperlimit*/
	for (int i = 2; i * i <= upperlimit; i++)
	{
		if (prime[i] == false)
			//the number is prime
		{
			for (unsigned long long int multiple = i * i; multiple <= upperlimit; multiple += i)
			{
				//mark all subsequent multiples as non-prime
				prime[multiple] = true;
			}
		}
	}

	for (unsigned long long int i = 0; i <= upperlimit; i++)
	{
		if (prime[i] == false)
			//extract all prime numbers into a new vector
		{
			prime_number = i;
			prime_sieve.push_back(prime_number);
		}
	}

	return prime_sieve;
}