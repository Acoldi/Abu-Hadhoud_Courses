#include <iostream>
#include <string>

int main(void)
{
	std::string myName = "Ali";
	short int Myage = 20;
	std::string MyCity = "Tokyo";
	unsigned short int MySalary = 5000;
	unsigned short int YearlySalary = MySalary * 12;
	char Gender = 'M';
	bool  Married = 1;
    std::string myCountry = "Japan";

	std::cout << "***********************" << std::endl;
	std::cout << "Name: " << myName << std::endl;
	std::cout << "Age: " << Myage << std::endl;
	std::cout << "City: " << MyCity << std::endl;
	std::cout << "country: " << myCountry << std::endl;
	std::cout << "Monthly Salary: " << MySalary << std::endl;
	std::cout << "Yearly Salary: " << YearlySalary << std::endl;
	std::cout << "Gender: " << Gender << std::endl;
	std::cout << "Married: " << Married << std::endl;
	std::cout << "***********************" << std::endl;
}