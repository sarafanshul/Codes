#include <iostream>
using namespace std;

int main()
{
    int n, a;
    while (cin >> n, n)
    {
        int best = 0, cs = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a;
            cs += a;
            best = max(best, cs);  
            
            cs = max(cs, 0);
        }

        if (best > 0)
            cout << "The maximum winning streak is " << best << ".\n";
        else
            cout << "Losing streak.\n";
        
    }
}
