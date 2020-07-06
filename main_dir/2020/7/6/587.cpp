#include <cctype>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double d = 1.0 / 1.41421356;
string dir[8] = {"N", "S", "E", "W", "NE", "NW", "SE", "SW"};
double dx[8] = {0,  0, 1, -1, d, -d,  d, -d};
double dy[8] = {1, -1, 0,  0, d,  d, -d, -d};

int main()
{
    cout << fixed << setprecision(3);
    string s; int C = 1;
    while (getline(cin, s), s != "END")
    {
        size_t x;
        double r1 = 0, r2 = 0;
        while (x = s.find_first_of(",."), x != string::npos)
        {
            string t = s.substr(0, x);
            s = s.substr(x + 1);
            int l = isalpha(t[t.size() - 2]) ? 2 : 1;            
            string d = t.substr(t.size() - l);
            int m = stoi(t.substr(0, t.size() - l));
            
            for (int i = 0; i < 8; ++i)
                if (d == dir[i])
                    r1 += m * dx[i], r2 += m * dy[i];
        }

        cout << "Map #" << C++ << '\n';
        cout << "The treasure is located at (" << r1 << ',' << r2 << ").\n";
        cout << "The distance to the treasure is " << hypot(r1, r2) << ".\n\n";
    }
}
