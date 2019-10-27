#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;

void finalize(int i, vi& A, vi& P)
{
    if (P[i] != -1)
        finalize(P[i], A, P);

    cout << A[i] << '\n';
}

int main()
{
    int c;
    cin >> c;
    cin.ignore(2);
    while (c--)
    {
        string s;
        vi A;
        while (getline(cin, s), s != "")
        {
            A.push_back(stoi(s));
            if (cin.eof())
                break;
        }

        vi L, P(A.size()), Id(A.size());
        int lis = 0, lis_end;
        for (int i = 0; i < A.size(); ++i)
        {
            auto lb = lower_bound(L.begin(), L.end(), A[i]);
            int dist = distance(L.begin(), lb);

            if (lb == L.end())
                L.push_back(A[i]);
            else
                L[dist] = A[i];

            Id[dist] = i;
            P[i] = dist ? Id[dist - 1] : -1;

            if (dist >= lis)
                lis = dist, lis_end = i;
        }

        cout << "Max hits: " << lis + 1 << '\n';
        finalize(lis_end, A, P);
        if (c) cout << '\n';
    }
}
