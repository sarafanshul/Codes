#include <algorithm> 
#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int T, n, p, q, m;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> n >> p >> q;
        ++p; ++q;
        map<int, int> M;
        
        for (int i = 0; i < p; ++i)
        {
            cin >> m;
            M[m] = i;            
        }

        int A[250 * 250 + 1], it = 0;
        for (int i = 0; i < q; ++i)
        {
            cin >> m;
            if (M.find(m) != M.end())
                A[it++] = M[m];
        }
        
        int LIS[250 * 250 + 1] = {}, lis = 0;
        for (int i = 0; i < it; ++i)
        {
            int lb = lower_bound(LIS, LIS + lis, A[i]) - LIS;
            LIS[lb] = A[i];
            if (lb + 1 > lis)
                ++lis;
        }
        
        cout << "Case " << t << ": " << lis << '\n';
    }
}
