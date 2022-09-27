// StringDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    char cstring_1[] { 'K', 'e', 'v', 'i', 'n', '\0' };
    char cstring_2[] { "Kevin" };

    cout << sizeof(cstring_1) << endl;
    cout << sizeof(cstring_2);

    cout << endl << endl;

    cout << strlen(cstring_1) << endl;
    cout << strlen(cstring_2);
}

