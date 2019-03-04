#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

int main()
{
    int T, n, A[2000];
    cin >> T;
    while (T--)
    {
        cin >> n;
        if (n == 0)
        {
            cout << "0\n";
            continue;
        }
        
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        reverse(A, A + n);
        int lis = 0, lds = 0;
        vi LIS(n, 1), LDS(n, 1);
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (A[i] > A[j] && LIS[i] < LIS[j] + 1)
                    ++LIS[i];

        for (int i = 1; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (A[i] < A[j] && LDS[i] < LDS[j] + 1)
                    ++LDS[i];
        
        for (int i = 0; i < n; ++i)
            LIS[i] += LDS[i] - 1;
        cout << *max_element(LIS.begin(), LIS.end()) << endl;
    }
}
