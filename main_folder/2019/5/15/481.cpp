#include <algorithm> 
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

typedef vector<int> vi;

void finalize(int elem, vi& A, vi& P)
{
    if (P[elem] != -1)
        finalize(P[elem], A, P);

    cout << A[elem] << '\n';
}

int main()
{
    int a, lis = 0, lis_end = 0;
    vi A;
    while (cin >> a)
        A.push_back(a);
    vi P(A.size(), -1), Id(A.size(), -1), LIS;

    for (int i = 0; i < A.size(); ++i)
    {
        auto lb = lower_bound(LIS.begin(), LIS.end(), A[i]);
        int dist = distance(LIS.begin(), lb);

        if (lb == LIS.end())
            LIS.push_back(A[i]);
        else
            LIS[dist] = A[i];
        
        Id[dist] = i;
        P[i] = dist > 0 ? Id[dist - 1] : -1;

        if (dist >= lis)
            lis = dist, lis_end = i;
    }
    
    cout << lis + 1 << "\n-\n";
    finalize(lis_end, A, P);
}
