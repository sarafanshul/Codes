#include <algorithm>
#include <iostream>
#include <tuple>
using namespace std;

typedef unsigned long long ull;

const int M = 10000000;
int A[M];

int f(ull i)
{
    if (i < M && A[i])
        return A[i];

    int ret = 1 + (i % 2 ? f(3 * i + 1) : f(i / 2));
    
    if (i < M)
        return A[i] = ret;

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    A[1] = 1;
    for (int i = 2; i < M; ++i)
        f(i);
    A[1] = 4;

    int a, b, c, d;
    while (cin >> c >> d, c + d)
    {
        tie(a, b) = minmax(c, d);
        
        int x, w = 0;
        for (int i = a; i <= b; ++i)
            if (A[i] > w)
                w = A[i], x = i;
        
        cout << "Between " << a << " and " << b << ", " << x
             << " generates the longest sequence of " << --w << " values.\n";
    }
}
