#include <iostream>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

int val[] = {0, 0, 0, 1, 1, 2, 3, 5, 11, 11, 11, 11, 11, 11, 11, 11, 11};
int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};
bool valid(int a, int b)
{
    return a >= 0 && b >= 0 && a < 4 && b < 4;
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    string S[4], word;
    for (int c = 1; c <= n; ++c)
    {
        for (int i = 0; i < 4; ++i)
            cin >> S[i];

        cin >> m;
        int res = 0;
        for (int i = 0; i < m; ++i)
        {
            cin >> word;
            bool flag = true;
            for (int j = 0; j < 16 && flag; ++j)
            {
                int u = j / 4, v = j % 4;
                if (S[u][v] == word[0])
                {
                    queue<tuple<int, int, int> > Q;
                    Q.emplace(u * 4 + v, 1, 1 << (u * 4 + v));
                    while (flag && !Q.empty())
                    {
                        int el, cnt, vis;
                        tie(el, cnt, vis) = Q.front(); Q.pop();
                        if (cnt == word.size())
                            flag = false, res += val[word.size()];
                        
                        for (int k = 0; k < 8; ++k)
                        {
                            int du = el / 4 + dx[k], dv = el % 4 + dy[k];
                            if (valid(du, dv) && word[cnt] == S[du][dv] && !(vis & (1 << (du * 4 + dv))))
                                Q.emplace(du * 4 + dv, cnt + 1, vis | (1 << (du * 4 + dv)));
                        }
                    }
                }                
            }
        }

        cout << "Score for Boggle game #" << c << ": " << res << '\n';
    }
}
