#include <cmath> 
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string s;
        getline(cin, s);
        float sf = sqrt(s.size());
        int si = sf;
        if (sf == si)
        {
            for (int i = 0; i < si; ++i)
                for (int j = 0; j < si; ++j)
                    cout << s[i + si * j];
            cout << '\n';
        }
        else
            cout << "INVALID\n";
    }
}
