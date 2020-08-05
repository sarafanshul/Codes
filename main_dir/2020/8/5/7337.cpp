#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string M[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
int len[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string D[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main()
{
    int n;
    cin >> n;
    string mon, day;
    while (n--)
    {
        cin >> mon >> day;
        int m = find(M, M + 12, mon) - M;
        int d = find(D, D + 7, day) - D;
        int c = 1, res = 0;
        while (d = d % 7, c++ <= len[m])
            res += d++ > 4;

        cout << res << '\n';
    }
}
