#include <iostream>
#include <string>
#include <vector>
using namespace std;

string D = "NSEW", s;
int dx[] = { 0, -1, -1, 0 };
int dy[] = {-1,  0, -1, 0 };
int di[] = { 0,  0, 1, -1 };
int dj[] = { 1, -1, 0,  0 };

int main()
{
    int n, x, y;
    cin >> n;
    for (int cn = 1; cn <= n; ++cn)
    {
        vector<string> A(32, string(32, '.'));
        cin >> x >> y >> s;
        for (char c : s)
            for (int i = 0; i < 4; ++i)
                if (c == D[i])
                {
                    x += di[i];
                    y += dj[i];
                    A[y + dy[i]][x + dx[i]] = 'X';
                }

        cout << "Bitmap #" << cn << '\n';
        for (auto it = A.rbegin(); it != A.rend(); ++it)
            cout << *it << '\n';
        cout << "\n";
    }
}
