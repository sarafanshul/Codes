#include <iostream>
using namespace std;

int n, m, A[1000];

bool check(int x)
{
    int c_sum = 0, cnt = 1;
    for (int i = 0; i < n; ++i)
        if (c_sum + A[i] <= x)
            c_sum += A[i];
        else
            c_sum = A[i], ++cnt;

    return cnt <= m;
}

int bs(int a, int b)
{
    if (a == b)
        return a;
    
    int m = (a + b) / 2;
    if (check(m))
        return bs(a, m);
    else
        return bs(m + 1, b);

    return -1;
}

int main()
{
    while (cin >> n >> m)
    {
        int sum = 0, start = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> A[i];
            sum += A[i];
            if (A[i] > start)
                start = A[i];
        }

        cout << bs(start, sum) << "\n";
    }
}
