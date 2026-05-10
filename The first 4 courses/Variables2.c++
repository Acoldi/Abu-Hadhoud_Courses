#include <iostream>
#include <string>

int main(void)
{
    // Define all your variables at first.
	std::string myName;
    std::cout << "Name: ";
    std::cin >> myName;
	int Myage;
    std::cout << "Age: ";
    std::cin >> Myage;

	std::string MyCity;
    std::cout << "City: ";
    std::cin >> MyCity;

    std::string myCountry;
    std::cout << "Country: ";
    std::cin >> myCountry;

	int MySalary;
    std::cout << "Salary: ";
    std::cin >> MySalary;

	int YearlySalary = MySalary * 12;

	char Gender;
    std::cout << "Your gender M/F: ";
    std::cin >> Gender;
	
    bool  isMarried ;
    std::cout << "Are you married? 1/0\n";
    std::cin >> isMarried;

	std::cout << "***********************" << std::endl;
	std::cout << "Name: " << myName << std::endl;
	std::cout << "Age: " << Myage << std::endl;
	std::cout << "City: " << MyCity << std::endl;
	std::cout << "country: " << myCountry << std::endl;
	std::cout << "Monthly Salary: " << MySalary << std::endl;
	std::cout << "Yearly Salary: " << YearlySalary << std::endl;
	std::cout << "Gender: " << Gender << std::endl;
	std::cout << "Married: " << isMarried << std::endl;
	std::cout << "***********************" << std::endl;
}