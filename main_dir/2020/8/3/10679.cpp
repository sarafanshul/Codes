#include <iostream>
#include <string>
using namespace std;

#define MAX_N 100001
string T, P;
int b[MAX_N], n, m;

void kmpPreprocess()
{
    int i = 0, j = -1;
    b[0] = -1;
    while (i < m)
    {
        while (j >= 0 && P[i] != P[j])
            j = b[j];
        ++i; ++j;
        b[i] = j;
    }
}

bool kmpSearch()
{
    int i = 0, j = 0;
    while (i < n)
    {
        while (j >= 0 && T[i] != P[j])
            j = b[j];
        ++i; ++j;
        if (j == m)
            return true;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    int t, Q;
    cin >> t;
    while (t--)
    {
        cin >> T;
        n = T.size();
        cin >> Q;
        for (int i = 0; i < Q; ++i)
        {
            cin >> P;
            kmpPreprocess();
            m = P.size();

            if (kmpSearch())
                cout << "y\n";
            else
                cout << "n\n";
        }
    }
}
