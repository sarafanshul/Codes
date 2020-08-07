#include <algorithm> 
#include <iostream>
using namespace std;

int main()
{
    int n, m, A[10000];
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        cin >> m;
        sort(A, A + n);
        
        for (int s = m % 2 ? (m - 1) / 2 : m / 2; s >= 0; --s)
        {
            auto llb = lower_bound(A, A + n, s);
            auto rlb = lower_bound(llb + 1, A + n, m - s);
            if (llb != A + n && rlb != A + n && (*llb + *rlb == m))
            {
                cout << "Peter should buy books whose prices are " << *llb << " and " << *rlb << ".\n\n";
                break;
            }
        }
    }    
}
