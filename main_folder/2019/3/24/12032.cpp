#include <iostream>
#include <vector> 
using namespace std;

typedef vector<int> vi;

bool check (vi& A, int m)
{
    for (int i = 1; i < A.size(); ++i)
    {
        int diff = A[i] - A[i - 1];
        if (diff > m)
            return false;
        else if (diff == m)
            --m;        
    }

    return true;
}

int bs(vi& A, int low, int hi)
{
    if (low == hi)
        return hi;

    int m = (low + hi) / 2;
    
    if (check(A, m))
        return bs(A, low, m);
    else
        return bs(A, m + 1, hi);
}

int main()
{
    int T, n;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        cin >> n;
        vi A(n + 1);
        for (int j = 1; j <= n; ++j)
            cin >> A[j];

        cout << "Case " << i << ": " << bs(A, 0, 10000000) << "\n";
    }
}
