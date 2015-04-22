#include <iostream>
#include <fstream>
#include <cstddef>
#include <ios>

using namespace std;

int main()
{
    int k;
    k = 0<<2;
    cout << k << endl;
    k = ~0<<2;
    cout << k << endl;
    k = ~(~0<<2);
    cout << k << endl;

    const int MAX_SIZE = 100;
    char name[MAX_SIZE];
    cout << "Input file name" << endl;
    cin.getline(name,MAX_SIZE);

    fstream filestream(name, ios::in | ios::binary);
    if (!filestream)
    {
        cout << "Can not open the file!" << endl;
        return 1;
    } else cout << "File is opened!" << endl;
    char ch;
    while(filestream.get(ch)) cout << ch;

    cout << endl;

     long number = 0;
    long maxNumber = 0;
    long firstNumber;
    filestream >> firstNumber;
    maxNumber = firstNumber;
    int currentPos = 0;

    cout << "FirstNumber" << firstNumber<< endl;
    filestream.seekg(0);

    int i = 0;
    while (filestream.eof())
    {
        cout << i++ << " In while()" << endl;
        filestream >> number;
        cout << number << endl;
        if (number > maxNumber)
        {
            maxNumber = number;
            currentPos = filestream.tellg();
            cout << "New max: " << maxNumber << endl;
        }

    }

    cout << "Position before clear()" << currentPos << endl;

    filestream.seekg(0, ios::beg);
    currentPos = filestream.tellg();

    cout << "Position after clear()" << currentPos << endl;







    return 0;
}


