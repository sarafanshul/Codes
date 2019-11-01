#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

typedef queue<int> qi;
typedef vector<qi> vqi;

int main()
{
    int t, k, x, T[1000000] = {}, c = 1;
    while (cin >> t, t)
    {
        cout << "Scenario #" << c++ << "\n";
        for (int i = 0; i < t; ++i)
        {
            cin >> k;
            for (int j = 0; j < k; ++j)
                cin >> x, T[x] = i + 1;
        }

        vqi VQ(t);
        qi Q;
        string s;
        while (cin >> s, s != "STOP")
            if (s == "ENQUEUE")
            {
                cin >> x;
                int t = T[x] - 1;
                if (VQ[t].empty())
                    Q.push(t);

                VQ[t].push(x);
            }
            else
            {
                cout << VQ[Q.front()].front() << '\n';
                VQ[Q.front()].pop();
                if (VQ[Q.front()].empty())
                    Q.pop();
            }
        cout << '\n';       
    }
}
