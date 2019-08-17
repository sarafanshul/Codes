#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector> 
using namespace std;

const int dy[] = {-1, 0,  0, 1};
const int dx[] = { 0, 1, -1, 0};

string G[30];
int x, y, p, s = 1800, t = 1801, R[1802][1802];;
vector<int> P;
vector<vector<int>> F;

bool legal(int a, int b)
{
    return a >= 0 && b >= 0 && a < x && b < y && G[a][b] != '~' && G[a][b] != '*';
}

void process(int a, int b, int w)
{
    R[a][b] = w;
    F[a].push_back(b);
    F[b].push_back(a);
}

bool ap()
{
    queue<int> Q;
    Q.push(s);
    P.assign(1802, -1);
    
    while (!Q.empty())
    {
        int top = Q.front(); Q.pop();
        if (top == t)
            return true;
        
        for (int i : F[top])
            if (P[i] == -1 && R[top][i])
                Q.push(i), P[i] = top;
    }

    return false;
}

int main()
{
    char c;
    while (cin >> x >> y >> p)
    {
        for (int i = 0; i < x; ++i)
            cin >> G[i];

        F.assign(1802, vector<int>());
        memset(R, 0, sizeof(R));
        for (int i = 0; i < x; ++i)
        {
            for (int j = 0; j < y; ++j)
            {
                if (G[i][j] == '*')
                {
                    process(s, 30 * i + j, 1);
                    for (int k = 0; k < 4; ++k)
                    {
                        int ky = i + dy[k], kx = j + dx[k];
                        if (legal(ky, kx))
                            process(30 * i + j, 30 * ky + kx, 1);
                    }
                }
                else if (G[i][j] == '.')
                {
                    process(30 * i + j, 900 + 30 * i + j, 1);
                    for (int k = 0; k < 4; ++k)
                    {
                        int ky = i + dy[k], kx = j + dx[k];
                        if (legal(ky, kx))
                            process(900 + 30 * i + j, 30 * ky + kx, 1);
                    }
                }
                else if (G[i][j] == '@' || G[i][j] == '#')
                {
                    if (G[i][j] == '#')
                        process(30 * i + j, t, p);
                    for (int k = 0; k < 4; ++k)
                    {
                        int ky = i + dy[k], kx = j + dx[k];
                        if (legal(ky, kx))
                            process(30 * i + j, 30 * ky + kx, 451);
                    }
                }
                else if (G[i][j] == '#')
                {

                    for (int k = 0; k < 4; ++k)
                    {
                        int ky = i + dy[k], kx = j + dx[k];
                        if (legal(ky, kx))
                            process(30 * i + j, 30 * ky + kx, 451);
                    }
                }                            
            }
        }

        int mf = 0;
        while (ap())
        {
            int aug = 451;
            for (int it = t; it != s; it = P[it])
                aug = min(aug, R[P[it]][it]);

            for (int it = t; it != s; it = P[it])
                R[P[it]][it] -= aug, R[it][P[it]] += aug;

            mf += aug;
        }

        cout << mf << "\n";
    }
}
