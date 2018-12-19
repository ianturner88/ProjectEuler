#include<string>
#include<fstream>
#include<streambuf>
#include<iostream>
using namespace std;

void Compare_Size(string number_x, string current_sum);

int main(void)
{
	ifstream PE013_Input_File("PE013.txt");
	string number_x, current_sum = "", PE013_answer = "";
	int number_x_length, current_sum_length;

	while (getline(PE013_Input_File, number_x))
	{
		/*programs driving algorithm...
		numbers are fed in one at a time*/

		//ensures current sum is the larger variable
		Compare_Size(number_x, current_sum);
	}

	//system pause
	getchar();
}

void Calculate_Length_Two_Strings(string number_x, string current_sum, int number_x_length, 
	int current_sum_length)
{
	number_x_length = number_x.length();
	current_sum_length = current_sum.length();
}

void Compare_Size(string number_x, string current_sum)
{
	/*compares the size of the two strings*/

	if (number_x.length() > current_sum.length())
	{
		//need to ensure the second variable is always the larger number
		swap(current_sum, number_x);
	}
}