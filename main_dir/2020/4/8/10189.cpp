#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<string> vs;

int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};
int m, n, c = 0;

bool legal(int a, int b)
{
    return a >= 0 && b >= 0 && a < m && b < n;
}

int main()
{
    while (cin >> m >> n, m || n)
    {
        if (c)
            cout << '\n';
        
        vs A(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> A[i];
            replace(A[i].begin(), A[i].end(), '.', '0');
        }
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (A[i][j] == '*')
                    for (int k = 0; k < 8; ++k)
                        if (legal(i + dx[k], j + dy[k])
                            && A[i + dx[k]][j + dy[k]] != '*')
                            A[i + dx[k]][j + dy[k]]++;

        cout << "Field #" << ++c << ":\n";
        for (string& s : A)
            cout << s << '\n';
    }    
}
