#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    while (cin >> s)
    {
        for (int i = s.size() / 2; i > 0; --i)
        {
            if (s.substr(0, i) == s.substr(i, i))
            {
                for (int j = s.size() % i, cnt = 0; cnt++ < 8; j = (j + 1) % i)
                    cout << s[j];
                cout << "...\n";
                break;
            }
        }
    }
}
