#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;

int main()
{
    int s, d;
    while (cin >> s >> d)
    {
        d *= -1;
        int m = -1;
        for (int i = 0; i < (1 << 12); ++i)
        {
            int R[12];
            for (int k = 0; k < 12; ++k)
                R[k] = (1 << k) & i ? d : s;
            int A[12] = {};
            for (int k = 4; k < 12; ++k)
                for (int l = 0; l < 5; ++l)
                    A[k] += R[k - l];
            
            if (all_of(A + 4, A + 12, [](int a){ return a < 0; }))
                m = max(m, accumulate(R, R + 12, 0));
        }

        if (m > 0)
            cout << m << '\n';
        else
            cout << "Deficit\n";
    }
}
