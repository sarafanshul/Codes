#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const double r = 2.5;
int n;

struct pt
{
    double x, y;
    pt() {}
    pt(double x, double y) : x(x), y(y) {}
    friend istream& operator>>(istream& i, pt& p)
    {
        return i >> p.x >> p.y;
    }
} P[201];

double dot(pt& a, pt& b)
{
    return a.x * b.x + a.y * b.y;
}

inline double dsq(pt&a, pt& b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int cookie(int i, int j)
{
    pt M(.5 * (P[i].x + P[j].x), .5 * (P[i].y + P[j].y));
    pt U(P[j].x - M.x, P[j].y - M.y);
    U = pt(-U.y, U.x);

    if (r * r < dot(U, U))
        return 0;
    
    double lambda = sqrt(r * r / dot(U, U) - 1);
    U.x = U.x * lambda + M.x;
    U.y = U.y * lambda + M.y;

    int res = 0;
    for (int i = 0; i < n; ++i)
        if (dsq(U, P[i]) < r * r + 1e-8)
            ++res;
    
    return res;
}

int main()
{
    int T;
    cin >> T;
    cin.ignore(2);
    string s;
    while (T--)
    {
        n = 0;
        while (cin.peek() != '\n' && !cin.eof())
            cin >> P[n++], cin.ignore();

        int m = 1;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                m = max(m, max(cookie(i, j), cookie(j, i)));

        cout << m << '\n';
        if (T) cout << '\n';
        cin.ignore();
    }
}
