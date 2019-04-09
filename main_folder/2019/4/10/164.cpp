#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string s, t;
int ind;
int nw[21][21] = {};
int par[21][21] = {};

void print(int i, int j)
{
    if (par[i][j] == 1)
    {
        print(i, j - 1);
        cout << 'D' << s[j - 1] << (ind < 10 ? "0" : "") << ind;
    }
    else if (par[i][j] == 2)
    {
        print(i - 1, j - 1);
        if (nw[i][j] != nw[i - 1][j - 1])
            cout << 'C' << t[i - 1] << (ind < 10 ? "0" : "") << ind++;
        else
            ++ind;
    }
    else if (par[i][j] == 3)
    {
        print(i - 1, j);
        cout << 'I' << t[i - 1] << (ind < 10 ? "0" : "") << ind++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> s >> t, s != "#")
    {
        memset(nw, 0, sizeof(nw));
        memset(par, 0, sizeof(par));
        for (int i = 1; i <= s.size(); ++i)
            nw[0][i] = i, par[0][i] = 1;
        for (int i = 1; i <= t.size(); ++i)
            nw[i][0] = i, par[i][0] = 3;

        for (int i = 1; i <= t.size(); ++i)
        {
            for (int j = 1; j <= s.size(); ++j)
            {
                int a = nw[i - 1][j - 1], b = nw[i - 1][j], c = nw[i][j - 1];
                if (a <= min(b, c))
                {
                    nw[i][j] = a + (t[i - 1] != s[j - 1]);
                    par[i][j] = 2;
                }
                else if (b <= c)
                {
                    nw[i][j] = b + 1;
                    par[i][j] = 3;
                }
                else
                {
                    nw[i][j] = c + 1;
                    par[i][j] = 1;
                }
            }
        }
        
        ind = 1;
        print(t.size(), s.size());
        cout << "E\n";
    }
}
