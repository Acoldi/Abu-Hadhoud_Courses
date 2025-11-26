#pragma once
#include <iostream>
#include <string>

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
