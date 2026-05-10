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
