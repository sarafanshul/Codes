#include <iostream>
#include <string> 
using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        for (char c : s)
            cout << char(c - 7);
        cout << "\n";
    }
}
