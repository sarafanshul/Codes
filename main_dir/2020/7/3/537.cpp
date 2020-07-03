#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;
#define INF 1e9

int main()
{
    int t;
    string s;
    cin >> t;
    cin.ignore();
    cout << fixed << setprecision(2);
    for (int pr = 1; pr <= t; ++pr)
    {
        double P, U, I;
        P = U = I = INF;
        getline(cin, s);
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '=')
            {
                char let = s[i - 1];
                string val;
                int dots = 0;
                while (isdigit(s[i + 1]) || (dots < 1 && s[i + 1] == '.'))
                {
                    ++i;
                    val += s[i];
                    dots += s[i] == '.';
                }

                double mult = 1;
                if (s[i + 1] == 'm')
                    mult /= 1000;
                else if (s[i + 1] == 'k')
                    mult *= 1000;
                else if (s[i + 1] == 'M')
                    mult *= 1000000;

                if (mult != 1)
                    ++i;
                ++i; // 'A', 'W' or 'V'
                    
                if (let == 'U')
                    U = stod(val) * mult;
                else if (let == 'P')
                    P = stod(val) * mult;
                else if (let == 'I')
                    I = stod(val) * mult;                        
            }
        }

        cout << "Problem #" << pr << '\n';
        if (P == INF)
            cout << "P=" << U * I << "W\n\n";
        else if (U == INF)
            cout << "U=" << P / I << "V\n\n";
        else
            cout << "I=" << P / U << "A\n\n";
    }    
}
