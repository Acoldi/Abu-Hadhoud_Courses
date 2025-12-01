---
course:
  - "[[Hadhoud's Courses]]"
---

## 02/02
- I have benefitted from `isprime()` function
```c++
#include <iostream>

#include <string>

#include <math.h>

using namespace std;

  

enum enPrimeOrNot {prime = 1, NotPrime = 2};

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

enPrimeOrNot IsPrime(int Num)

{

    for (int i = 2; i <= Num / 2; i++)

    {

        if (Num % i == 0)

            return enPrimeOrNot::NotPrime;

    }

    return enPrimeOrNot::prime;

}

  

void PrintPrimeNumbersTo(int To)

{

    cout << "prime numbers from 1 to " << To << " are\n";

    for (int i = 1; i <= To; i++)

    {

        if (IsPrime(i) == enPrimeOrNot::prime)

            cout << i << endl;

    }

}

  

int main(void)

{

    PrintPrimeNumbersTo(ReadPositiveNum("Enter a number"));

}
```

## 02/03
- whenever You create a function, ask yourself if you are going to need it in the  future or not, so you can make it a generic function.
- <mark class="hltr-green">This can be generic function, so try make it as one. </mark>
###  My sol
```c++
#include <iostream>

#include <string>

#include <math.h>

using namespace std;

  
  

bool IsPerfectNumber(int Number)

{

    int Sum = 0;

    for (int i = 1; i < Number; i++)

    {

        if (Number % i == 0)

        {

            Sum += i;

        }

    }

    if (Sum == Number)

        return 1;

    else

        return 0;

}

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

void PrintResult()

{

    if (IsPerfectNumber(ReadPositiveNum("Enter a number")))

        cout << "PERFECT number\n";

    else

        cout << "IMPERFECT number\n";

}

  

int main(void)

{

    PrintResult();

}
```
### Had's sol
- Instead of an if statement like this
  ```c++
  if (Sum == Number)

        return 1;

    else

        return 0;
```
 He made it one line Like this `    return Sum == Number;`
- And he made the print result function accept a parameter so we can print it with the result.

## 02/04

### My sol
```c++
#include <iostream>

#include <string>

#include <math.h>

using namespace std;

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

bool IsPerfectNumber(int Number)

{

    int Sum = 0;

    for (int i = 1; i < Number; i++)

    {

        if (Number % i == 0)

        {

            Sum += i;

        }

    }

    return Sum == Number;

}

  

void PrintResult(int Number)

{

    for (int i = 1; i <= Number; i++)

    {

        if (IsPerfectNumber(i))

        {

            cout << i << endl;

        }

    }

}

  

int main(void)

{

    PrintResult(ReadPositiveNum("Enter a positive number"));

}
```
### Had's sol
- Almost exactly the same

## 02/05
- Here When I divided by 0, I didn't have an error, instead, the program is just running, don't know what happened11
  ```c++
  void PrintReversedNumber(int number)

{

    int Mod = 0;

    while (number > 0)

    {

        cout << number % 10 << endl;

        number /= Mod;

        Mod *= 10;

    }

}
```
- But does math solve all the world problems????? #question 
### My sol
```c++
#include <iostream>

#include <string>

#include <math.h>

using namespace std;

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

void PrintReversedNumber(int number)

{

    while (number > 0)

    {

        cout << number % 10 << endl;

        number /= 10;

    }

}

  

int main(void)

{

    PrintReversedNumber(ReadPositiveNum("Enter a number"));

}
```
### Had's sol
- Exactly as mine!!

## 02/06
### My sol
```c++
#include <iostream>

#include <string>

#include <math.h>

using namespace std;

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

int SumOfDigits(int Number)

{

    int Remainder = 0, Sum = 0;

    while (Number > 0)

    {

        Remainder = Number % 10;

        Sum += Remainder;

        Number /= 10;

    }

    return Sum;

}

  

int main(void)

{

    int num = ReadPositiveNum("Enter a positive number");

    cout << "The sum of the number "<< num  << " digits is " <<Of SumDigits(num);

}
```

### His sol is the same!!
## 02/07
- I can only concatenate strings with strings, not even a string with char.
### My sol
```c++
#include <iostream>

#include <string>

#include <math.h>

using namespace std;

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

int ReverseNumber(int Number)

{

    int Remainder = 0;

    string ReversedNumber = "";

    while (Number > 0)

    {

        Remainder = Number % 10;

        ReversedNumber = ReversedNumber + to_string(Remainder);

        Number /= 10;

    }

    cout << ReversedNumber << endl;

    return stoi(ReversedNumber);

}

  

int main(void)

{

    cout << ReverseNumber(ReadPositiveNum("Enter a positive number"));

}
```

### Had's sol
```c++
#include <iostream>

#include <string>

#include <math.h>

using namespace std;

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

int ReverseNumber(int Number)

{

    int Remainder = 0, ReversedNumber = 0;

    while (Number > 0)

    {

        Remainder = Number % 10;

        Number /= 10;

        ReversedNumber = ReversedNumber * 10 + Remainder;  // Here we added the digit directly instead of converting to string.

        // The digit must be added to the right (in the single order) so we must get the place for the single digit then add it,

        // we do that by multiplying in 10.

    }

    return ReversedNumber;

}

  

int main(void)

{

    cout << ReverseNumber(ReadPositiveNum("Enter a positive number"));

}
```
## 02/08
### My sol
```c++
#include <iostream>

#include <string>

#include <math.h>

using namespace std;

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

int FindDigitFrequency(int Digit, int Number)

{

    int Remainder = 0, Counter = 0;

    while (Number > 0)

    {

        Remainder = Number % 10;

        Number /= 10;

        if (Remainder == Digit)

            Counter += 1;

    }

    return Counter;

}

  

int main(void)

{

    cout << FindDigitFrequency(ReadPositiveNum("Enter The digit you want to find its frequency in that number"),

    ReadPositiveNum("Enter a number"));

}
```
### Had sol
```c++
#include <iostream>

#include <string>

#include <math.h>

using namespace std;

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

int FindDigitFrequency(int Digit, int Number)

{

    int Remainder = 0, Counter = 0;

    while (Number > 0)

    {

        Remainder = Number % 10;

        Number /= 10;

        if (Remainder == Digit)

            Counter += 1;

    }

    return Counter;

}

  

int main(void)

{

    int Number = ReadPositiveNum("Enter a number");

    int Digit = ReadPositiveNum("Digit to find it's Frequency");

    cout << "The frequency of " << Digit << " is " << FindDigitFrequency(Digit, Number);

}
```
## 02/09
- Well I couldn't solve it the same way he wanted us to solve.
### My sol
```c++
#include <iostream>

#include <string>

#include <math.h>

using namespace std;

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

int FindDigitFrequency(int Digit, int Number)

{

    int Remainder = 0, Counter = 0;

    while (Number > 0)

    {

        Remainder = Number % 10;

        Number /= 10;

        if (Remainder == Digit)

            Counter += 1;

    }

    return Counter;

}

  

void PrintAllFrequenciesOfAllDigits(int Number)

{

    int Remainder = 0;

    int NumberCopy = Number;

    while (Number > 0)

    {

        Remainder = Number % 10;

        Number /= 10;

        cout << "The Frequency of " << Remainder << " is " << FindDigitFrequency(Remainder, NumberCopy)

        << endl;

    }

}

  

int main(void)

{

    PrintAllFrequenciesOfAllDigits(ReadPositiveNum("Enter a number"));

}
```
### His sol
- Well there is only 9 digits in the decimal system.
- To filter out the digits (i) where there is no frequency, we use an if statement.
- #question  Is it normal to cast from int to short implicitly??
```c++
#include <iostream>

#include <string>

#include <math.h>

using namespace std;

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

int FindDigitFrequency(int Digit, int Number)

{

    int Remainder = 0, Counter = 0;

    while (Number > 0)

    {

        Remainder = Number % 10;

        Number /= 10;

        if (Remainder == Digit)

            Counter += 1;

    }

    return Counter;

}

  

void PrintAllFrequenciesOfAllDigits(int Number)

{

    int Remainder = 0, Frequency = 0;

    for (int i = 0; i < 10; i++)

    {

        Frequency = FindDigitFrequency(i, Number);

        if (Frequency > 0)

        {

            cout << "The frequency of " << i << " is " << Frequency << endl;

        }

    }

}

  

int main(void)

{

    PrintAllFrequenciesOfAllDigits(ReadPositiveNum("Enter a number"));

}
```
## 02/10
### My sol
```c++
#include <iostream>

#include <string>

#include <math.h>

using namespace std;

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

int ReverseNumber(int Number)

{

    int Remainder = 0, ReversedNumber = 0;

    while (Number > 0)

    {

        Remainder = Number % 10;

        Number /= 10;

        ReversedNumber = ReversedNumber * 10 + Remainder;  // Here we added the digit directly instead of converting to string.

        // The digit must be added to the right (in the single order) so we must get the place for the single digit then add it,

        // we do that by multiplying by 10.

    }

    return ReversedNumber;

}

  

void PrintNumberDigits(int Number)

{

    int Remainder = 0;

    // Find The last space of the mumber

    while (Number > 0)

    {

        Remainder = Number % 10;

        Number /= 10;

        cout << Remainder << endl;

    }

}

  

int main(void)

{

    PrintNumberDigits(ReverseNumber(ReadPositiveNum("Enter a number")));

}
```
### Had's sol
- Exactly the same.
## 02/11
- What's the purpose of strange numbers like palindrome and perfect,, ?? Can we use them to solve real life problems or what? #question 
- Now our pace in writing code is 10x.
### My sol
- It is the same but never as succinct as his
```c++
#include <iostream>

#include <string>

#include <math.h>

using namespace std;

  $8/8 $
 
int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

int ReverseNumber(int Number)

{

    int Remainder = 0, ReversedNumber = 0;

    while (Number > 0)

    {

        Remainder = Number % 10;

        Number /= 10;

        ReversedNumber = ReversedNumber * 10 + Remainder;  // Here we added the digit directly instead of converting to string.

        // The digit must be added to the right (in the single order) so we must get the place for the single digit then add it,

        // we do that by multiplying by 10.

    }
    return ReversedNumber;
}


bool IsPalindrome(int Number)

{

    int Reversed = ReverseNumber(Number);

    if (Reversed == Number)

    {

        return 1;

    }

    return 0;

}

  

int main(void)

{

    int Number = ReadPositiveNum("Enter a number");

    if (IsPalindrome(Number))

        cout << "The number " << Number << " is a palindrome number\n";

    else

        cout << "The number " << Number << " is not a palindrome number\n";

}
```

### His sol
```c++
#include <iostream>

#include <string>

#include <math.h>

using namespace std;

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

int ReverseNumber(int Number)

{

    int Remainder = 0, ReversedNumber = 0;

    while (Number > 0)

    {

        Remainder = Number % 10;

        Number /= 10;

        ReversedNumber = ReversedNumber * 10 + Remainder;  // Here we added the digit directly instead of converting to string.

        // The digit must be added to the right (in the single order) so we must get the place for the single digit then add it,

        // we do that by multiplying by 10.

    }

    return ReversedNumber;

}

  

bool IsPalindrome(int Number)

{

    return Number == ReverseNumber(Number);

}

  

int main(void)

{

    int Number = ReadPositiveNum("Enter a number");

    if (IsPalindrome(Number))

        cout << "The number " << Number << " is a palindrome number\n";

    else

        cout << "The number " << Number << " is not a palindrome number\n";

}
```
## 02/12
### My sol
```c++
int PrintInvertedPattern(int Number)

{

    for (int i = 0; i < Number; i++)

    {

        for (int j = Number; j > i; j--)

        {

            cout << Number  - i;

        }

        cout << endl;

    }

}
```
### His sol
- He used less arithmetic operations
```c++
int PrintInvertedPattern(int Number)

{

    for (int i = Number; i > 0; i--)

    {

        for (int j = 0; j < i; j++)

        {

            cout << i;

        }

        cout << endl;

    }

}
```
## 02/13
###  Our sol
```c++
void PrintNumberPattern(int Number)

{

    for (int i = 1; i <= Number; i++)

    {

        for (int j = 0; j < i; j++)

        {

            cout << i;

        }

        cout << endl;

    }

}
```
## 02/14
### My sol
```c++
void PrintInvertedLetterPattern(int Number)

{

    for (int i = Number - 1; i >= 0; i--)

    {

        for (int j = 0; j <= i; j++)

        {

            cout << char(i + 65);

        }

        cout << endl;

    }

}
```
### His sol
```c++
void PrintInvertedLetterPattern(int Number)

{

    for (int i = 64 + Number; i >= 65; i--) // i represents the letter.

    {

        for (int j = 0; j < Number - (Number + 64 - i); j++) // This tell us how many time we shouls print the current letter, we want to print those times decreasingly from the Number to 0

                                                             // so we want to decrement the number by 1

                                                             // so it is Number - (something gets incremented by 1) which is

                                                             // Number + 64 - i

                                                             // Where i is getting decremented by 1

                                                             // every iteration. The first iteration it is gonna be 64

                                                             // so we are going to print the letter the same number of Number

                                                             // the next one i is (64 + Number - 1) which leads to the

                                                             // Equation (Number + 64 - i) to get decremented by 1

                                                             // SO the iterations are gonne be less than the previous ones by 1

        {

            cout << char(i);

        }

        cout << endl;

    }

}
```
## 02/15
###  My sol
```c++
void PrintLetterPattern(int Number)

{

    for (int i = 65; i <= 64 + Number; i++)

    {

        for (int j = 0; j <= i - 65; j++)

        {

            cout << char(i);

        }

        cout << endl;

    }

}
```
###  His sol is the same
## 02/16
### My sol
```c++
void PrintAAAtoZZZ(void)

{

    for (int i = 65; i < 91; i++)

    {

        for (int j = 65; j < 91; j++)

        {

            for (int k = 65; k < 91; k++)

            {

                cout << char(i) << char(j) << char(k) << endl;

            }

        }

    }

}
```
### His sol is almost the same
## 02/17
- I cannot convert integer to string, I can convert it to char though.
### My sol after watching his
```c++
bool FindPassword(string Password)

{

    int counter = 0;

    string letters = "";

    for (int i = 65; i < 91; i++)

    {

        for (int j = 65; j < 91; j++)

        {

            for (int k = 65; k < 91; k++)

            {

                counter++;

                letters += char(i);

                letters += char(j);

                letters += char(k);

                cout << "Trial ["<< counter << "]: " << letters << endl;

                if (letters == Password)

                {

                    cout << "The password " << letters << " Found at trial " << counter << endl;

                    return 1;

                }

                letters = "";

            }

        }

    }

    return 0;

}
```
## 02/18
- #question Why did I need to pass the string by reference??
  I was convinced that it is passed by reference by default. 
### My sol
```c++
void Encrypt(short key, string &Text)

{

    int counter = 0;

    while (Text[counter] != '\0')

    {

        Text[counter] = Text[counter] - key;

        cout << Text[counter] << endl;

        counter++;

    }

}

  

void Decrypt(short key, string &Text)

{

    int counter = 0;

    while (Text[counter] != '\0')

    {

        Text[counter] += key;

        cout << Text[counter] << endl;

        counter++;

    }

}
```

### Had's sol || The same with minor differences
```c++
#include <iostream>

#include <string>

#include <math.h>

using namespace std;

  

string ReadString(string input)

{

    string St;

    cout << input; cin >> St;

    return St;

}

  

string Encrypt(short key, string Text)

{

    for (int i = 0; i <= Text.length(); i++)

    {

        Text[i] = Text[i] - key;

    }

    return Text;

}

  

string Decrypt(short key, string Text)

{

    for (int i = 0; i < Text.length(); i++)

    {

        Text[i] = Text[i] + key;

    }

    return Text;

}

  

int main(void)

{

    const short Key = 2;

    string name = ReadString("Enter your name to decrypt it: ");

    string encrypted = Encrypt(Key, name);

    string decrypted = Decrypt(Key, encrypted);

    cout << "your name after encription: " << encrypted << endl;

    cout << "your name after decription: " << decrypted << endl;

}
```
## 02/19 <mark class="hltr-red">Important</mark>
- Why didn't we just say `rand() % To + 1` instead of 
  `int randNum = rand() % (To - From + 1) + From;`??
- #question What's this `srand((unsigned) time(NULL));`?
### Code
```c++
#include <iostream>

#include <string>

#include <math.h>

#include <cstdlib>

#include <time.h>

using namespace std;

  
  

int randomNumber(int From, int To)

{

    int Number;

    Number = rand() % (To - From + 1) + From;

    return Number;

}

  

int main(void)

{

    srand((unsigned)time(NULL));

    cout << randomNumber(5 , 7);

}
```
## 02/20
- We are building libraries, so we can ease the programming process later on.
- When you make a function, think about how you can use it in the future, not just for the current problem. So you will maximize the reusability and get faster and more efficient.
  Always ask yourself, <mark class="hltr-green">can I generalize this function or not</mark>.
- <mark class="hltr-green">Always think in ==Divide and Conquer approach==</mark>.
###  My sol
```c++
#include <iostream>

#include <string>

#include <math.h>

#include <cstdlib>

#include <time.h>

using namespace std;

  

enum enCharType {SmallLetter=1, CapitalLetter, SpecialCharacter, Digit};

  

int RandomNumber(int From, int To)

{

    int N;

    N = rand() % (To - From + 1) + From;

    return N;

}

  

char GetRandomCharacters(enCharType Value)

{

    switch (Value)

    {

    case enCharType::CapitalLetter:

        return char(RandomNumber(65, 90));

    case enCharType::SmallLetter:

        return char(RandomNumber(97, 122));

    case enCharType::SpecialCharacter:

        return char(RandomNumber(33, 47));

    case enCharType::Digit:

        return char(RandomNumber(48, 57));

    }

}

  

string KeyGenerator()

{

    string Key = "";

    for (int i = 0; i < 4; i++)

    {

        for (int j = 0; j < 4; j++)

        {

            Key += GetRandomCharacters(enCharType::CapitalLetter);

        }

        if (Key.length() != 19)

        {

            Key += '_';

        }

    }

    return Key;

}

  

void PrintFiveKeys(void)

{

    for (int i = 1; i <= 4; i++)

    {

        cout << "Key [" << i << "] : " + KeyGenerator() << endl;

    }

}

  

int main(void)

{

    cout << endl;

    srand((unsigned) time(NULL));

    PrintFiveKeys();

}
```
### Had's sol
```c++
#include <iostream>

#include <string>

#include <math.h>

#include <cstdlib>

#include <time.h>

using namespace std;

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

enum enCharType {SmallLetter=1, CapitalLetter, SpecialCharacter, Digit};

  

int RandomNumber(int From, int To)

{

    int N;

    N = rand() % (To - From + 1) + From;

    return N;

}

  

char GetRandomCharacters(enCharType Type)

{

    switch (Type)

    {

    case enCharType::CapitalLetter:

        return char(RandomNumber(65, 90));

    case enCharType::SmallLetter:

        return char(RandomNumber(97, 122));

    case enCharType::SpecialCharacter:

        return char(RandomNumber(33, 47));

    case enCharType::Digit:

        return char(RandomNumber(48, 57));

    }

}

  

string GenerateWord(enCharType CharType, int Length)

{

    string Word;

    for (int i = 0; i < Length; i++)

    {

        Word += GetRandomCharacters(CharType);

    }

    return Word;

}

  

string GenerateKey(enCharType CharType, int LengthOfWord)

{

    string Key = "";

    Key += GenerateWord(CharType, LengthOfWord) + "_";

    Key += GenerateWord(CharType, LengthOfWord) + "_";

    Key += GenerateWord(CharType, LengthOfWord) + "_";

    Key += GenerateWord(CharType, LengthOfWord);

    return Key;

}

  

void GenerateKeys(int NumberOfKeys)

{

    for (int i = 0; i < NumberOfKeys; i++)

    {

        cout << "key [" << i << "] : " << GenerateKey(enCharType::CapitalLetter, 4) << endl;

    }

}

  

int main(void)

{

    cout << endl;

    srand((unsigned) time(NULL));

    GenerateKeys(ReadPositiveNum("Enter number of keys to generate"));    

}
```
## 02/21
```c++
#include <iostream>

#include <string>

#include <math.h>

#include <cstdlib>

#include <time.h>

using namespace std;

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

enum enCharType {SmallLetter=1, CapitalLetter, SpecialCharacter, Digit};

  

int RandomNumber(int From, int To)

{

    int N;

    N = rand() % (To - From + 1) + From;

    return N;

}

  

char GetRandomCharacters(enCharType Type)

{

    switch (Type)

    {

    case enCharType::CapitalLetter:

        return char(RandomNumber(65, 90));

    case enCharType::SmallLetter:

        return char(RandomNumber(97, 122));

    case enCharType::SpecialCharacter:

        return char(RandomNumber(33, 47));

    case enCharType::Digit:

        return char(RandomNumber(48, 57));

    }

}

  

string GenerateWord(enCharType CharType, int Length)

{

    string Word;

    for (int i = 0; i < Length; i++)

    {

        Word += GetRandomCharacters(CharType);

    }

    return Word;

}

  

string GenerateKey(enCharType CharType, int LengthOfWord)

{

    string Key = "";

    Key += GenerateWord(CharType, LengthOfWord) + "_";

    Key += GenerateWord(CharType, LengthOfWord) + "_";

    Key += GenerateWord(CharType, LengthOfWord) + "_";

    Key += GenerateWord(CharType, LengthOfWord);

    return Key;

}

  

void GenerateKeys(int NumberOfKeys)

{

    for (int i = 0; i < NumberOfKeys; i++)

    {

        cout << "key [" << i << "] : " << GenerateKey(enCharType::CapitalLetter, 4) << endl;

    }

}

  

int main(void)

{

    cout << endl;

    srand((unsigned) time(NULL));

    GenerateKeys(ReadPositiveNum("Enter number of keys to generate"));    

}
```
## 02/22
- Why hadhoud passes the length of the array with the array parameter??, I found it unnecessary!
### My sol
- Wherein I missed the opportunity to make very important generic functions like `read array()` and `print array`.
```c++
#include <iostream>

#include <string>

#include <math.h>

#include <cstdlib>

#include <time.h>

using namespace std;

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

void ReadArrayOfInt(int Length, int array[])

{

    for (int i = 0; i < Length; i++)

    {

        array[i] = ReadPositiveNum(("Element [" + to_string(i) + "]"));

    }

}

  

int FindFrequencyInArray(int Element, int Array[], int Length)

{

    int Frequency = 0;

    for (int i = 0; i < Length; i++)

    {

        if (Array[i] == Element)

        {

            Frequency++;

        }

    }

    return Frequency;

}

  

int main(void)

{

    int N = ReadPositiveNum("Number of elements you want to add");

    int array[N], Frequency;

    ReadArrayOfInt(N, array);

    int NumberTocheck = ReadPositiveNum("Enter the number you watn to check");

  

    Frequency = FindFrequencyInArray(NumberTocheck, array, N);

    cout << "Original array: ";

    for (int i = 0; i < N; i++)

    {

        cout << i << " ";

    } cout << endl;

    cout << NumberTocheck << " is repeated " << Frequency

        << " time(s) " << endl;

}
```
### Had's sol
```c++
#include <iostream>

#include <string>

#include <math.h>

#include <cstdlib>

#include <time.h>

using namespace std;

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

void ReadArrayOfInt(int &Length, int array[]) // Length is passed by reference because I want to change the value of

                                              // passed variable, hence I cannot (or am yet to learn) use the variable defined in a function from another funcion.

{

    Length = ReadPositiveNum("The number of elements you want to add");

    for (int i = 0; i < Length; i++)

    {

        array[i] = ReadPositiveNum(("Element [" + to_string(i) + "]"));

    }

}

  

void PrintArray(int Length, int array[])

{

    for (int i = 0; i < Length; i++)

    {

        cout << array[i] << " ";

    }

}

  

int TimesRepeated(int Element, int Array[], int Length)

{

    int Frequency = 0;

    for (int i = 0; i < Length; i++)

    {

        if (Array[i] == Element)

        {

            Frequency++;

        }

    }

    return Frequency;

}

  

int main(void)

{

    int N=1, array[N], Frequency; // after we read N in the read array function it chenged here, too. By the way this approach is better than hadhoud's approach.

    ReadArrayOfInt(N, array);

    int NumberTocheck = ReadPositiveNum("Enter the number you watn to check");

  

    Frequency = TimesRepeated(NumberTocheck, array, N);

    cout << "Original array: ";

    PrintArray(N, array); cout << endl;

    cout << NumberTocheck << " is repeated " << Frequency

        << " time(s) " << endl;

}
```
## 02/23
- This way doesn't work
```c++
int main(void)

{

    srand((unsigned)time(NULL));

    int Size = 1;

    int array[Size];

    GenerateRandomNumberArray(Size, array);

    PrintArray(Size, array);

}
```

- #question Why this didn't work??
### My sol and his
```c++
#include <iostream>

#include <string>

#include <math.h>

#include <cstdlib>

#include <time.h>

using namespace std;

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

int RandomNumber(int From, int To)

{

    int N;

    N = rand() % (To - From + 1) + From;

    return N;

}

  

void FillArrayWithRandomNumbers(int &Length, int array[])

{

    Length = ReadPositiveNum("Enter the array length");

  

    for (int i = 0; i < Length; i++)

    {

        array[i] = RandomNumber(0, 100);

    }

}

  

void PrintArray(int Length, int array[])

{

    for (int i = 0; i < Length; i++)

    {

        cout << array[i] << " ";

    }

}

  

int main(void)

{

    srand((unsigned)time(NULL));

    int Size = 1;

    int array[100];

    FillArrayWithRandomNumbers(Size, array);

    PrintArray(Size, array);

}
```


## 02/24
### Mine
- My sole is better than his, because I used '\\0' instead of passing the array length.
	- Noo it is not because I would be indexing values out of the array.
```c++
#include <iostream>

#include <string>

#include <math.h>

#include <cstdlib>

#include <time.h>

using namespace std;

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

int RandomNumber(int From, int To)

{

    int N;

    N = rand() % (To - From + 1) + From;

    return N;

}

  

void FillArrayWithRandomNumbers(int &Length, int array[])

{

    Length = ReadPositiveNum("Enter the array length");

  

    for (int i = 0; i < Length; i++)

    {

        array[i] = RandomNumber(0, 100);

    }

}

  

int Max(int arr[100])

{

    int Max = 0;

    for (int i = 0; arr[i] != '\0'; i++)

    {

        if (arr[i] > Max)

        {

            Max = arr[i];

        }

    }

    return Max;

}

  

void PrintArray(int Length, int array[])

{

    for (int i = 0; i < Length; i++)

    {

        cout << " " << array[i];

    }

}

  

int main(void)

{

    srand((unsigned)time(NULL));

    int Size = 1;

    int array[100];

    FillArrayWithRandomNumbers(Size, array);

    PrintArray(Size, array);

  

    cout << endl << "The maximum number is:  " << Max(array);

}
```
## 02/25
- The same but with...
```c++
int Min(int Length, int arr[100])

{

    int Min = arr[0];

    for (int i = 0; i < Length ; i++)

    {

        if (arr[i] < Min)

        {

            Min = arr[i];

        }

    }

    return Min;

}
```
## 02/26
plus
```c++
int SumArrayValue(int Length, int arr[100])

{

    int Sum = 0;

    for (int i = 0; i < Length; i++)

    {

        Sum += arr[i];

    }

    return Sum;

}
```
## 02/27
```c++
float AvgOfArray(int Length, int arr[])

{

    return (float) SumArrayValue(Length, arr) / Length;

}
```
## 02/28

## 02/29
- _In memory there are just Numbers (0s and 1s), Nothing else_.
- #question How did we implement the logic??
### My sol
```c++
void CopyPrimrNumbersOfArray(int Length, int &Length2, int arrSource[], int arrDestination[])

{

    Length2 = 0;

    for (int i = 0; i < Length; i++)

    {

        if (IsPrime(arrSource[i]) == enPrimeOrNot::prime)

        {

            Length2++;

            arrDestination[Length2 - 1] = arrSource[i];

        }

    }

}
```
### His Sol
- I think this is wrong, I am sure actually.
```c++
void CopyPrimrNumbersOfArray(int Length, int &Length2, int arrSource[], int arrDestination[])

{

    int counter = 0;

    for (int i = 0; i < Length; i++)

    {

        if (IsPrime(arrSource[i]) == enPrimeOrNot::prime)

        {

            arrDestination[counter] = arrSource[i];

            counter++;

        }

    }

    Length2 = --counter;

}
```
- The correct one
  ```c++
  void CopyPrimrNumbersOfArray(int Length, int &Length2, int arrSource[], int arrDestination[])

{

    int counter = 0;

    for (int i = 0; i < Length; i++)

    {

        if (IsPrime(arrSource[i]) == enPrimeOrNot::prime)

        {

            arrDestination[counter] = arrSource[i];

            counter++;

        }

    }

    Length2 = --counter;

}
```

## 02/30
### Our sol
```c++
#include <iostream>

#include <string>

#include <math.h>

#include <cstdlib>

#include <time.h>

using namespace std;

  

enum enPrimeOrNot {prime = 1, NotPrime = 2};

  

enPrimeOrNot IsPrime(int Num)

{

    for (int i = 2; i <= Num / 2; i++)

    {

        if (Num % i == 0)

            return enPrimeOrNot::NotPrime;

    }

    return enPrimeOrNot::prime;

}

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

int RandomNumber(int From, int To)

{

    int N;

    N = rand() % (To - From + 1) + From;

    return N;

}

  

void FillArrayWithRandomNumbers(int &Length, int array[])

{

    for (int i = 0; i < Length; i++)

    {

        array[i] = RandomNumber(0, 100);

    }

}

  

void SumArray(int Arr1[], int Arr2[], int arrDestination[], int Length)

{

    for (int i = 0; i < Length; i++)

    {

        arrDestination[i] = Arr1[i] + Arr2[i];

    }

}

  

void PrintArray(int Length, int array[])

{

    for (int i = 0; i < Length; i++)

    {

        cout << array[i] << " " ;

    }

}

  

int main(void)

{

    srand((unsigned) time(NULL));

    int Length;

    Length = ReadPositiveNum("\nEnter the array length");

  

    int Array[100];

  

    int Array2[100];

  

    int Array3[100];

  

    FillArrayWithRandomNumbers(Length, Array);

    FillArrayWithRandomNumbers(Length, Array2);

  

    cout << "\nArray 1: " << endl;

    PrintArray(Length, Array);

  

    cout << "\n\nArray 2: " << endl;

    PrintArray(Length, Array2);

  

    SumArray(Array, Array2, Array3, Length);

    cout << "\n\nSum of array 1 and array 2: " << endl;

    PrintArray(Length, Array3);

}
```
## 02/31
- I cannot name a variable the same name I used for a function, because that would cause confusion to the compiler.

### My sol, which is wrong

```c++
#include <iostream>

#include <string>

#include <math.h>

#include <cstdlib>

#include <time.h>

using namespace std;

  

enum enPrimeOrNot {prime = 1, NotPrime = 2};

  

enPrimeOrNot IsPrime(int Num)

{

    for (int i = 2; i <= Num / 2; i++)

    {

        if (Num % i == 0)

            return enPrimeOrNot::NotPrime;

    }

    return enPrimeOrNot::prime;

}

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

int RandomNumber(int From, int To)

{

    int N;

    N = rand() % (To - From + 1) + From;

    return N;

}

  

void FillArrayFrom1toN(int Length, int array[])

{

    for (int i = 0; i < Length; i++)

    {

        array[i] = i + 1;

    }

}

  

void ShuffleArray(int Length, int arrSource[], int arrDestination[])

{

    for (int i = 0; i < Length; i++)

    {

        int RandomN = RandomNumber(1 , Length);

        for (int j = 0; j < i; j++)

        {

            while (RandomN == arrSource[j])

            {

                RandomN = RandomNumber(1, Length);

            }

        }

        arrDestination[i] = RandomN;

    }

}

  

void PrintArray(int Length, int array[])

{

    for (int i = 0; i < Length; i++)

    {

        cout << array[i] << " " ;

    }

}

  

int main(void)

{

    srand((unsigned) time(NULL));

    int Length;

    Length = ReadPositiveNum("\nEnter the array length");

  

    int Array[100];

  

    int Array2[100];

  
  

    FillArrayFrom1toN(Length, Array);

    (Length, Array2);

  

    ShuffleArray(Length, Array, Array2);

  

    cout << "\nArray 1: " << endl;

    PrintArray(Length, Array);

  

    cout << "\n\nAfter Array 1 Being Shuffled: " << endl;

    PrintArray(Length, Array2);

  

}
```

### Had sol
- The idea is to use a swap function that swaps random elements of the array.
```c++
void ShuffleArrayElements(int Length, int arr[])
{

    for (int i = 0; i < Length; i++)

    {

        Swap(arr[RandomNumber(1, Length) - 1], arr[RandomNumber(1, Length) - 1]); // Here the swap function is doing all the work, where it

                                                                      // Randomly chooses 2 indexes to swap their values, In a loop from the first index to the last.

    }

}
```
## 02/32
### My sol
```c++
void ReverseArray(int Length, int arrSource[], int arrDestination[])
{
    for (int i = 0; i < Length; i++)
    }
        arrDestination[Length - i - 1] = arrSource[i];
    }
}
```
### Had sol
```c++
void ReverseArray(int Length, int arrSource[], int arrDestination[])

{

    for (int i = 0; i < Length; i++)

    {

        arrDestination[i] = arrSource[Length - 1 - i]; // The reason we subtract 1 from Length is because we don't end the index of the array at Length but At length - 1, because we started from 0.

    }

}
```
## 02/33
```c++
void GenerateKeysInArray(int Length, string Arr[])

{

    for (int i = 0; i < Length; i++)

    {

        Arr[i] = GenerateKey(enCharType::CapitalLetter, 4);

    }

}
```
## 02/34
```c++
#include <iostream>

#include <string>

#include <math.h>

#include <cstdlib>

#include <time.h>

  

using namespace std;

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

int RandomNumber(int From, int To)

{

    int N;

    N = rand() % (To - From + 1) + From;

    return N;

}

  

void FillArrayWithRandomNumbers(int &Length, int array[])

{

    for (int i = 0; i < Length; i++)

    {

        array[i] = RandomNumber(0, 100);

    }

}

  

int FindNumberInArray(int Number, int Length, int Arr[])

{

    for (int i = 0; i < Length; i++)

    {

        if (Arr[i] == Number)

        {

            return i;

        }

    }

    return -1;

}

  

void PrintArray(int Length, int array[])

{

    for (int i = 0; i < Length; i++)

    {

        cout << array[i] << " " ;

    }

}

  

int main(void)

{

    srand((unsigned) time(NULL));

    int Arr[100];

    int Length = ReadPositiveNum("Enter the array length");

  

    FillArrayWithRandomNumbers(Length, Arr);

    PrintArray(Length, Arr);

    cout << endl;

  

    short NumberIndex = FindNumberInArray(ReadPositiveNum("Enter The number you eant to find"), Length, Arr);

  
  

    if (NumberIndex == -1)

    {

        cout << "The number not found :-(\n";

    }

    else

    {

        cout << "The Number found at position: " << NumberIndex << endl;

        cout << "The Number found at order: " << NumberIndex + 1 << endl;

    }

}
```
## 02/35
```c++
#include <iostream>

#include <string>

#include <math.h>

#include <cstdlib>

#include <time.h>

  

using namespace std;

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

int RandomNumber(int From, int To)

{

    int N;

    N = rand() % (To - From + 1) + From;

    return N;

}

  

void FillArrayWithRandomNumbers(int &Length, int array[])

{

    for (int i = 0; i < Length; i++)

    {

        array[i] = RandomNumber(0, 100);

    }

}

  

bool IsFound(int Number, int Length, int Arr[])

{

    for (int i = 0; i < Length; i++)

    {

        if (Arr[i] == Number)

        {

            return 1;

        }

    }

    return 0;

}

  

void PrintArray(int Length, int array[])

{

    for (int i = 0; i < Length; i++)

    {

        cout << array[i] << " " ;

    }

}

  

int main(void)

{

    srand((unsigned) time(NULL));

    int Arr[100];

    int Length = ReadPositiveNum("Enter the array length");

  

    FillArrayWithRandomNumbers(Length, Arr);

    cout << "Array Elements\n";

  

    PrintArray(Length, Arr);

    cout << endl;

  

    int Number = ReadPositiveNum("the number you want to find");

  

    cout << "Number you are looking for: " << Number << endl;

  

    if (IsFound(Number, Length, Arr))

        cout << "Found\n";

    else

        cout << "Not Found\n";

}
```
## 02/36
### My sol
```c++
#include <iostream>

#include <string>

#include <math.h>

#include <cstdlib>

#include <time.h>

  

using namespace std;

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message; cin >> num;

    } while (num < 0);

    return num;

}

  

void PrintArray(int Length, int array[])

{

    for (int i = 0; i < Length; i++)

    {

        cout << array[i] << " " ;

    }

}

  

void AddElements(int &Length, int Arr[])

{

    int Check = 1;

    do

    {

        Arr[Length] = ReadPositiveNum("Enter the " + to_string(Length + 1) + "th element\n- ");

        Length++;

        Check = ReadPositiveNum("Do you want to add another element? (1/0)\n- ");

    }

    while (Check != 0);

  

}

  

int main(void)

{

    int Arr[100];

    int Length = 0;

  

    AddElements(Length, Arr);

    cout << "Array length: " << Length << endl;

    cout << "Array's elements: ";

    PrintArray(Length, Arr);

  

}
```
### Had Sol
```c++
void AddArrayElement(int number, int &Length, int Arr[])

{

    Arr[Length] = number;

    Length++;

}

  

void AddArrayElements(int &Length, int Arr[])

{

    int AddMore = true;

    do    // We don't have to add element here because, maybe we need to add just 1 element later on, it would be better if it is a function by itself.

    {

        AddArrayElement(ReadPositiveNum("Enter a number: "), Length, Arr);

        AddMore = ReadPositiveNum("Do you want to add another element? (1/0)\n- ");

    }

    while (AddMore);

  

}
```
## 02/37
- <mark class="hltr-red">I had to watch hadhoud's solution carefully at the first time</mark>
### My sol (Solved it without ArrLength2, and then solved it with arrlength2 while watching hadhoud solving it)  
```c++
#include <iostream>

#include <string>

#include <math.h>

#include <cstdlib>

#include <time.h>

using namespace std;

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

int RandomNumber(int From, int To)

{

    int N;

    N = rand() % (To - From + 1) + From;

    return N;

}

void FillArrayWithRandomNumbers(int &ArrLength, int array[])

{

    ArrLength = ReadPositiveNum("Enter the length of the array");

    for (int i = 0; i < ArrLength; i++)

    {

        array[i] = RandomNumber(0, 10);

    }

}

  

void AddArrayElement(int number, int &ArrLength, int Arr[])

{

    Arr[ArrLength] = number;

    ArrLength++;

}

  

void CopyArrayUsingAddArrayElement(int ArrLength, int &ArrayLength2, int Arr[], int ArrDestination[])

{

    for (int i = 0; i < ArrLength; i++)

        AddArrayElement(Arr[i], ArrayLength2, ArrDestination);

}

  

void PrintArray(int ArrLength, int array[])

{

    for (int i = 0; i < ArrLength; i++)

    {

        cout << array[i] << " " ;

    }

}

  
  

int main(void)

{

    int ArrLength = 0, Arr2Length = 0;

    srand((unsigned)time(NULL));

  

    int Array[100];

  

    int CArray[100];

  

    FillArrayWithRandomNumbers(ArrLength, Array);

  

    cout << "Array 1: " << endl;

    PrintArray(ArrLength, Array);

  

    CopyArrayUsingAddArrayElement(ArrLength, Arr2Length, Array, CArray);

  

    cout << "\nArray 2 (ArrDestination): " << endl;

    PrintArray(ArrLength, CArray);

}
```
## 02/38
```c++
void CopyOddArraysElementsToAnotherOne(int ArrLength, int &ArrayLength2, int Arr[], int ArrDestination[])

{

    for (int i = 0; i < ArrLength; i++)

    {    

        if (CheckNumberType(Arr[i]) == enOddOrNot::Odd)

        {

            AddArrayElement(Arr[i], ArrayLength2, ArrDestination);

        }

    }

}
```
## 02/39
```c++
#include <iostream>

#include <string>

#include <math.h>

#include <cstdlib>

#include <time.h>

using namespace std;

  

enum enPrimeOrNot {prime = 1, NotPrime = 2};

  

enPrimeOrNot IsPrime(int Num)

{

    for (int i = 2; i <= Num / 2; i++)

    {

        if (Num % i == 0)

            return enPrimeOrNot::NotPrime;

    }

    return enPrimeOrNot::prime;

}

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

int RandomNumber(int From, int To)

{

    int N;

    N = rand() % (To - From + 1) + From;

    return N;

}

  

void FillArrayWithRandomNumbers(int &ArrLength, int array[])

{

    ArrLength = ReadPositiveNum("Enter the length of the array");

    for (int i = 0; i < ArrLength; i++)

    {

        array[i] = RandomNumber(0, 100);

    }

}

  

void AddArrayElement(int number, int &ArrLength, int Arr[])

{

    Arr[ArrLength] = number;

    ArrLength++;

}

  

void CopyPrimeNumbersArraysToAnotherOne(int ArrLength, int &ArrayLength2, int Arr[], int ArrDestination[])

{

    for (int i = 0; i < ArrLength; i++)

    {    

        if (IsPrime(Arr[i]) == enPrimeOrNot::prime)

        {

            AddArrayElement(Arr[i], ArrayLength2, ArrDestination);

        }

    }

}

  

void PrintArray(int ArrLength, int array[])

{

    for (int i = 0; i < ArrLength; i++)

    {

        cout << array[i] << " " ;

    }

}

  
  

int main(void)

{

    int ArrLength = 0, Arr2Length = 0;

    srand((unsigned)time(NULL));

  

    int Array[100];

    FillArrayWithRandomNumbers(ArrLength, Array);

  

    int CArray[100];

    CopyPrimeNumbersArraysToAnotherOne(ArrLength, Arr2Length, Array, CArray);

  

    cout << "Array 1: " << endl;

    PrintArray(ArrLength, Array);

  

    cout << "\nArrDestination odd numbers: " << endl;

    PrintArray(Arr2Length, CArray);

}
```
## 02/40
### My sol.....>
- In which I forgot the isNumberInarray Function and came up with a distort solution that doesn't work all the time.
```c++
#include <iostream>

#include <string>

#include <math.h>

#include <cstdlib>

#include <time.h>

using namespace std;

  

int TimesRepeated(int Element, int Array[], int Length)

{

    int Frequency = 0;

    for (int i = 0; i < Length; i++)

    {

        if (Array[i] == Element)

        {

            Frequency++;

        }

    }

    return Frequency;

}

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message << ": "; cin >> num;

    } while (num <= 0);

    return num;

}

  

void AddElementsManually(int &ArrLength, int array[])

{

    ArrLength = 9;

    array[0] = 10;

    array[1] = 10;

    array[2] = 10;

    array[3] = 50;

    array[4] = 50;

    array[5] = 70;

    array[6] = 70;

    array[7] = 70;

    array[8] = 90;

}

  

void AddArrayElement(int number, int &ArrLength, int Arr[])

{

    Arr[ArrLength] = number;

    ArrLength++;

}

  

void CopyDistinctArrayNumbers(int ArrLength, int &ArrayLength2, int Arr[], int ArrDestination[])

{

    int timesRepeated = 0;

    for (int i = 0; i < ArrLength; i++)

    {  

        if (Arr[i] != Arr[i - 1])

            timesRepeated = 0;

  

        if (timesRepeated == 0)

        {

            cout << TimesRepeated(Arr[i], Arr, ArrLength);

            AddArrayElement(Arr[i], ArrayLength2, ArrDestination);

        }

  

        timesRepeated = TimesRepeated(Arr[i], Arr, ArrLength);

  

        if (timesRepeated > 1)

        {

            cout << Arr[i] << " Is repeated\n";

            continue;

        }

        timesRepeated = 0;

    }

}

  

void PrintArray(int ArrLength, int array[])

{

    for (int i = 0; i < ArrLength; i++)

    {

        cout << array[i] << " " ;

    }

}

  
  

int main(void)

{

    int ArrLength = 0, Arr2Length = 0;

    srand((unsigned)time(NULL));

  

    int Array[100];

    AddElementsManually(ArrLength, Array);

  

    int CArray[100];

    CopyDistinctArrayNumbers(ArrLength, Arr2Length, Array, CArray);

  

    cout << "Array 1: " << endl;

    PrintArray(ArrLength, Array);

  

    cout << "\nArray 2 distinct numbers: " << endl;

    PrintArray(Arr2Length, CArray);

}
```

### Had sol
- From the function, find NumberInArray, we made another function that is `IsNumberInArray` And another function to check if it is added in the array, and if it is, we are not gonna add it again, if not we will add it only once.
```c++
#include <iostream>

#include <string>

#include <math.h>

#include <cstdlib>

#include <time.h>

using namespace std;

  

int FindNumberInArray(int Number, int Length, int Arr[])

{

    for (int i = 0; i < Length; i++)

    {

        if (Arr[i] == Number)

        {

            return Arr[i];

        }

    }

    return -1;

}

  

bool IsNumberInArray(int Number, int Arr[], int Length)

{

    return FindNumberInArray(Number, Length, Arr) != -1;

}

  

void AddElementsManually(int &ArrLength, int array[])

{

    ArrLength = 10;

    array[0] = 10;

    array[1] = 10;

    array[2] = 10;

    array[3] = 50;

    array[4] = 50;

    array[5] = 70;

    array[6] = 70;

    array[7] = 70;

    array[8] = 90;

    array[9] = 10;

}

  

void AddArrayElement(int number, int &ArrLength, int Arr[])

{

    Arr[ArrLength] = number;

    ArrLength++;

}

  

void CopyDistinctArrayNumbers(int ArrLength, int &ArrayLength2, int Arr[], int ArrDestination[])

{

    for (int i = 0; i < ArrLength; i++)

    {  

        if (!IsNumberInArray(Arr[i], ArrDestination, ArrayLength2))

        {

            AddArrayElement(Arr[i], ArrayLength2, ArrDestination);

        }

    }

}

  

void PrintArray(int ArrLength, int array[])

{

    for (int i = 0; i < ArrLength; i++)

    {

        cout << array[i] << " " ;

    }

}

  
  

int main(void)

{

    int ArrLength = 0, Arr2Length = 0;

  

    int Array[100];

    AddElementsManually(ArrLength, Array);

  

    int CArray[100];

    CopyDistinctArrayNumbers(ArrLength, Arr2Length, Array, CArray);

  

    cout << "Array 1: " << endl;

    PrintArray(ArrLength, Array);

  

    cout << "\nArray 2 distinct numbers: " << endl;

    PrintArray(Arr2Length, CArray);

}
```
## 02/41
### My sol
- I created a function called `isArrayCopy` That checks if 2 arrays have the same values or not. 
```c++
#include <iostream>

#include <string>

#include <math.h>

#include <cstdlib>

#include <time.h>

using namespace std;

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message; cin >> num;

    } while (num < 0);

    return num;

}

  

void AddArrayElement(int number, int &Length, int Arr[])

{

    Arr[Length] = number;

    Length++;

}

  

void AddArrayElements(int &Length, int Arr[])

{

    Length = 0;

    int AddMore = true;

    do    // We don't have to add element here because, maybe we need to add just 1 element later on, it would be better if it is a function by itself.

    {

        AddArrayElement(ReadPositiveNum("Enter a number: "), Length, Arr);

        AddMore = ReadPositiveNum("Do you want to add another element? (1/0)\n- ");

    }

    while (AddMore);

}

  

void PrintArray(int ArrLength, int array[])

{

    for (int i = 0; i < ArrLength; i++)

    {

        cout << array[i] << " " ;

    }

}

  

void ReverseArray(int Length, int arrSource[], int arrDestination[])

{

    for (int i = 0; i < Length; i++)

    {

        arrDestination[i] = arrSource[Length - 1 - i]; // The reason we subtract 1 from Length is because we don't end the index of the array at Length but At length - 1, because we started from 0.

    }

}

  

bool IsCopyArray(int Length, int Arr[], int copy[])

{

    for (int i = 0; i < Length; i++)

    {

        if (Arr[i] != copy[i])

        {

            return false;

        }

    }

    return true;

}

  

bool IsArrayPalindrome(int Length, int Array[], int ReversedArray[])

{

    if (IsCopyArray(Length, Array, ReversedArray))

        return true;

    return false;

}

  

int main(void)

{

    int ArrLength = 0;

  

    int Array[100];

    AddArrayElements(ArrLength, Array);

  

    int CArray[100];

    ReverseArray(ArrLength, Array, CArray);

    cout << "Array\n" << endl;

    PrintArray(ArrLength, Array);

  

    if (IsArrayPalindrome(ArrLength, Array, CArray))

        cout << "\nArray contains a palindrome number\n";

    else

        cout << "Array doesn't contain a palindrome number\n";

  

}
```
### His sol
- His sol doesn't contain the function that i created and he didn't even call the `reversearray` function.
```c++
bool IsArrayPalindrome(int Length, int Array[])

{

    for (int i = 0; i < Length; i++)

    {

        if (Array[0 + i] != Array[Length - 1 - i])

            return false;

    }

    return true;

}
```
## 02/42
### My sol
```c++
#include <iostream>

#include <string>

#include <math.h>

#include <cstdlib>

#include <time.h>

using namespace std;

  

int RandomNumber(int From, int To)

{

    int N;

    N = rand() % (To - From + 1) + From;

    return N;

}

  

enum enNumberType {Odd=1, Even};

  

enNumberType CheckNumberType(int number)

{

    int result = number % 2;

  

    if (result == 0)

    {

        return enNumberType::Even;  // it returns the corresponding number

    }

    else{

        return enNumberType::Odd;

    }

}

  

int ReadPositiveNum(string Message)

{

    int num;

    do

    {

        cout << Message;

        cin >> num;

    } while (num < 0);

    return num;

}

  

void FillArrayWithRandomNumbers(int &ArrLength, int array[])

{

    ArrLength = ReadPositiveNum("Enter the length of the array: ");

    for (int i = 0; i < ArrLength; i++)

    {

        array[i] = RandomNumber(0, 100);

    }

}

  

void PrintArray(int ArrLength, int array[])

{

    for (int i = 0; i < ArrLength; i++)

    {

        cout << array[i] << " " ;

    }

}

  

int CountOfOddNumbersInArray(int Length, int Arr[])

{

    int count = 0;

    for (int i = 0; i < Length; i++)

    {

        if (CheckNumberType(Arr[i]) == enNumberType::Odd)

            count++;

    }

    return count;

}

  

int main(void)

{

    int ArrLength = 0;

  

    int Array[100];

    FillArrayWithRandomNumbers(ArrLength, Array);

  

    cout << "The Array:\n";

    PrintArray(ArrLength, Array);

  

    cout << "The odd numbers count is " << CountOfOddNumbersInArray(ArrLength, Array) << endl;

  

}
```
### His sol
- Again, he solved it with just one function  **Maybe because he wanted to be an independent general function, a function that doesn't need to call other functions**.
```c++
int CountOfOddNumbersInArray(int Length, int Arr[])

{

    int count = 0;

    for (int i = 0; i < Length; i++)

    {

        if (Arr[i] % 2 != 0)

            count++;

    }

    return count;

}
```
- I don't always need to prioritize calling other functions, the priority is for generalizing as many functions as possible.
## 02/43

```c++
int CountOfEvenNumbersInArray(int Length, int Arr[])

{

    int count = 0;

    for (int i = 0; i < Length; i++)

    {

        if (Arr[i] % 2 == 0)

            count++;

    }

    return count;

}
```
## 02/44
```c++
int CountOfPositiveNumbersInArray(int Length, int Arr[])

{

    int count = 0;

    for (int i = 0; i < Length; i++)

    {

        if (Arr[i] >= 0)

            count++;

    }

    return count;

}
```
## 02/45
```c++
int CountOfPositiveNumbersInArray(int Length, int Arr[])

{

    int count = 0;

    for (int i = 0; i < Length; i++)

    {

        if (Arr[i] < 0)

            count++;

    }

    return count;

}
```
## 02/46
```c++
float Abs(float Number)

{

    if (Number > 0)

        return Number;    

    else

        return Number*= -1;

}
```
## 02/47
- Didn't think about it much so I did not solve it on my own.
### His sol
```
#include <iostream>

#include <string>

#include <math.h>

#include <cstdlib>

#include <time.h>

using namespace std;

  

float GetFractionPart(float Number)

{

    return Number - int(Number);

}

  

int MyRound(float Number)

{

    int IntPart = int(Number);

    cout << "Int part is " << IntPart << endl;

    float Fraction = GetFractionPart(Number);

  

    cout << "The fraction is " << Fraction << endl;

  

    if (abs(Fraction) >= .5)

    {

        if (Number < 0)

            return --IntPart;

        else{

            return IntPart += 1;

        }

    }

    return IntPart;

}

  

float ReadNum(string Message)

{

    float num;

    cout << Message;

    cin >> num;

    return num;

}

  

int main(void)

{

    float Number = ReadNum("Enter a number: ");

  

    cout << "My round result: " << MyRound(Number) << endl;

    cout << "c++ round result: " << round(Number);

  

}
```
## 02/48
```c++
int MyFloor(float Number)

{

    int IntPart = int(Number);

    if (Number > 0)

        return IntPart;

    else

        return --IntPart;

}
```
## 02/49
```c++
float GetFractionPart(float Number)

{

    return Number - int(Number);

}

  

int Myceil(float Number)

{

    if (GetFractionPart(Number) > 0)

    {

        int IntPart = int(Number);

        if (Number > 0)

            return ++IntPart;

        else

            return IntPart;

    }

    return Number;

}
```
## 02/50
#question I don't understand this [[Maths]] ![[Pasted image 20240316130728.png]] 
