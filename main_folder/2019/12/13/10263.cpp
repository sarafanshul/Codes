#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

#define eps 1e9

struct point
{
    double x, y;
} P[10000];

double dist(point A, point B)
{
    return hypot(A.x - B.x, A.y - B.y);
}

double dot(point A, point B)
{
    return A.x * B.x + A.y * B.y;
}

double normsq(point A)
{
    return dot(A, A);
}

double distance(point S, point A, point B, point& res)
{
    point M = S;
    M.x -= A.x; M.y -= A.y;
    B.x -= A.x; B.y -= A.y;
    double lambda = dot(M, B) / normsq(B);
    if (lambda < 0)
    {
        res = A;
        return dist(S, A);
    }
    if (lambda > 1)
    {
        res.x = B.x + A.x;
        res.y = B.y + A.y;
        return dist(M, B);
    }

    res.x = lambda * B.x + A.x;
    res.y = lambda * B.y + A.y;
    return dist(res, S);
}

int main()
{
    int n;
    point M;
    cout << fixed << setprecision(4);
    while (cin >> M.x >> M.y >> n)
    {
        for (int i = 0; i < n + 1; ++i)
            cin >> P[i].x >> P[i].y;

        // Procesuirati na inputu
        point res;
        double m = 1e9;
        for (int i = 0; i < n; ++i)
        {
            point pr;
            double a = distance(M, P[i], P[i + 1], pr);
            if (a < m)
                m = a, res = pr;
        }

        cout << res.x << '\n' << res.y << '\n';
    }
}
