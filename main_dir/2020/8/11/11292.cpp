#include <iostream>
#include <algorithm> 
using namespace std;

int main()
{
    int d, n, D[20000], N[20000];
    while (cin >> d >> n, d || n)
    {
        for (int i = 0; i < d; ++i)
            cin >> D[i];
        for (int i = 0; i < n; ++i)
            cin >> N[i];

        sort(D, D + d);
        sort(N, N + n);
        int gold = 0, i = 0, j = 0;
        while (j < n && i < d)
        {            
            if (D[i] > N[j])
            {
                ++j;
                continue;
            }

            gold += N[j];
            ++i;
            ++j;
        }

        if (i == d)
            cout << gold << "\n";
        else
            cout << "Loowater is doomed!\n";
        
        
    }
}
