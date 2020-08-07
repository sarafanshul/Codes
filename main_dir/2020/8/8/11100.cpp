#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<int> vi;

int main()
{
    int n, A[1000000], tmp;
    while (cin >> n, n)
    {
        int max = 0;
        vi seen;
        memset(A, 0, sizeof(A));
        for (int i = 0; i < n; ++i)
        {
            cin >> tmp; tmp--;
            A[tmp]++;
            max = A[tmp] > max ? A[tmp] : max;
            if (A[tmp] == 1)
                seen.push_back(tmp);
        }
        
        vector<vector<int> > R(max);
        int it = 0;
        for (int i : seen)
            for (int j = 0; j < A[i]; ++j)
            {
                R[it].push_back(i + 1);
                it = (it + 1) % max;
            }

        cout << max << "\n";
        for (auto& V : R)
        {
            for (int i = 0; i < V.size(); ++i)
                cout << (i ? " " : "") << V[i];
            cout << "\n";
        }
        cout << "\n";
    }
}
