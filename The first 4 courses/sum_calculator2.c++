#include <iostream>
using namespace std;
int main(void)
{
    int Number1;
    cout << "First number: ";
    cin >> Number1;
    
    int Number2;
    cout << "second number: ";
    cin >> Number2;

    int Number3;
    cout << "Third number: ";
    cin >> Number3;

    std::cout << Number1 << "+" << std::endl;
    std::cout << Number2 << "+" << std::endl;
    std::cout << Number3 << std::endl;
    std::cout << "_________________________________________________________\n\n";
    std::cout << "Total = " << Number1 + Number2 + Number3 << std::endl;


}