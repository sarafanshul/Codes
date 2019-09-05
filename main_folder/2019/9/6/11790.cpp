#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

int main()
{
    int T, n;
    cin >> T;
    for (int no = 1; no <= T; ++no)
    {
        cin >> n;
        vi H(n), W(n), WI, WD;
        for (int i = 0; i < n; ++i)
            cin >> H[i];
        for (int i = 0; i < n; ++i)
            cin >> W[i];
        WD = WI = W;
        
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (H[i] > H[j] && WI[j] + W[i] > WI[i])
                    WI[i] = WI[j] + W[i];
                
                if (H[i] < H[j] && WD[j] + W[i] > WD[i])
                    WD[i] = WD[j] + W[i];
            }
        }

        int mi = *max_element(WI.begin(), WI.end());
        int md = *max_element(WD.begin(), WD.end());
        if (mi >= md)
            cout << "Case " << no << ". Increasing (" << mi << "). Decreasing (" << md << ").\n";
        else
            cout << "Case " << no << ". Decreasing (" << md << "). Increasing (" << mi << ").\n";
    }
}
