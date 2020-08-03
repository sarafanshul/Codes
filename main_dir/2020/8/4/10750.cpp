#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct point
{
    double x, y;
    point(){}
    point(double x, double y) : x(x), y(y) {};
    bool operator<(const point& P) const { return y < P.y; }
};

vector<point> P;
bool cmpx(point& a, point& b) { return a.x < b.x;}

void ClosestPoints()
{
    set<point> box;
    sort(P.begin(), P.end(), cmpx);
    double best = 1e9;
    box.insert(P[0]);
    int left = 0;
    point R;
    
    for (int i = 1; i < P.size(); ++i)
    {
        while (left < i && P[i].x - P[left].x > best)
            box.erase(P[left++]);
        point B(P[i].x - best, P[i].y - best);

        for (auto it = box.lower_bound(B); it != box.end() && P[i].y + best >= it->y; ++it)
        {
            double d = hypot(P[i].y - it->y, P[i].x - it->x);
            if (d < best)
                best = d, R = P[i];
        }
        
        box.insert(P[i]);
    }

    cout << R.x << ' ' << R.y << '\n';
}

int main()
{
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        P.assign(n, point());
        for (int i = 0; i < n; ++i)
            cin >> P[i].x >> P[i].y;

        ClosestPoints();
    }
    
}
