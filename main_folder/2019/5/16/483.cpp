#include <iostream>
#include <string>
#include <sstream>
#include <algorithm> 
using namespace std;

int main()
{
    string s, t;
    while (getline(cin, s))
    {
        bool flag = false;
        istringstream iss(s);
        while (iss >> t)
        {
            cout << (flag ? " " : "");
            flag = true;
            reverse(t.begin(), t.end());
            cout << t;
        }
        cout << "\n";
    }
}
