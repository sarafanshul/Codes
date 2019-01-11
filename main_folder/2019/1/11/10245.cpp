#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

struct pt
{
    double x, y;
    pt(){};
    pt(double x, double y) : x(x), y(y) {};
    bool operator<(const pt& rhs) const {return y < rhs.y;};
};

int main()
{
    int n;
    double x, y;
    cout << setprecision(4);
    while (cin >> n, n)
    {
	set<pt> box;
	vector<pt> A(n);
	for (int i = 0; i < n; ++i)
	    cin >> A[i].x >> A[i].y;
    
	sort(A.begin(), A.end(), [](pt a, pt b){return a.x < b.x;});
	double r = INT_MAX;
	int left = 0;
	box.insert(A[0]);
	for (int i = 1; i < n; ++i)
	{
	    while (left < i && A[left].x < A[i].x - r)
		box.erase(A[left++]);
	    
	    pt b(A[i].x - r, A[i].y - r);
	    for (auto it = box.lower_bound(b); it != box.end() && it->y <= A[i].y + r; ++it)
		r = min(r, hypot(it->x - A[i].x, it->y - A[i].y));

	    box.insert(A[i]);
	}

	if (r < 10000)
	    cout << fixed << r << "\n";
	else
	    cout << "INFINITY\n";
    }
}