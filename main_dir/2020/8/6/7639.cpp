#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi A;
vvi S;

int f(int a, int b)
{
    int len = b - a + 1;
    if (len == 1)
        return A[a];

    if (S[len - 2][a] != -1)
        return S[len - 2][a];
    
    return S[len - 2][a] = f(a, b - 1) ^ f(a + 1, b);
}

int main()
{
    int T, n, q, a, b;
    cin >> T;
    for (int c = 1; c <= T; ++c)
    {
        cout << "Case " << c << ":\n";
        cin >> n;
        A.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        
        S.assign(n - 1, vi(n, -1));
        cin >> q;
        for (int i = 0; i < q && cin >> a >> b; ++i)
            cout << f(a, b) << '\n';
    }
}
