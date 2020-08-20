#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
    int T, a, n;
    cin >> T;
    while (T--)
    {
        cin >> a >> n;
        int A[20];
        vii P(1001);
        P[0].second = true;
        for (int i = 0; i < n; ++i)
            cin >> A[i], P[A[i]] = ii(1 << i, true);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < P.size(); ++j)
                if (P[j].second && j + A[i] < P.size() &&
                    !P[j + A[i]].second && !((1 << i) & P[j].first))
                    P[j + A[i]] = ii(P[j + A[i]].first | (1 << i), true);

        cout << (P[a].second ? "YES\n" : "NO\n");
    }
}
