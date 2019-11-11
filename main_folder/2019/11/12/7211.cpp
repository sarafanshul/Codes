#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    int n, a;
    while (cin >> n)
    {
        cin.ignore();
        int r = 0;
        string s; getline(cin, s);
        istringstream iss(s);
        while (iss >> a)
            r += a == n;

        cout << r << endl;           
    }
}
