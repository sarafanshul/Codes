#include <algorithm>
#include <iostream>
#include <numeric> 
#include <string>
#include <vector>
#include <tuple>
using namespace std;

typedef vector<string> vs;
typedef tuple<int, int, char> iic;

int dx[] = {-1,  0, 0, 1};
int dy[] = { 0, -1, 1, 0};
int c;
vs A(10);

void dfs(int i, int j, vs& V, char col)
{
    for (int k = 0; k < 4; ++k)
    {
        int ii = i + dx[k], jj = j + dy[k];
        if (ii >= 0 && jj >= 0 && ii < 10 && jj < 15 && !V[ii][jj] && A[ii][jj] == col)
            V[ii][jj] = 1, dfs(ii, jj, V, col), ++c;
    }
}

iic findmax()
{
    int best = 0, sol;
    char col;
    
    vs V(10, string(15, 0));
    for (int i = 0; i < 15; ++i)
        for (int j = 9; j >= 0; --j)
            if (!V[j][i] && A[j][i] != 'X')
            {
                c = 1;
                V[j][i] = 1;
                dfs(j, i, V, A[j][i]);
                if (c > best)
                    best = c, sol = j * 15 + i, col = A[j][i];
            }
    
    return make_tuple(sol, best, col);
}

void clear(int i, int j, char col)
{
    A[i][j] = 'X';
    for (int k = 0; k < 4; ++k)
    {
        int ii = i + dx[k], jj = j + dy[k];
        if (ii >= 0 && jj >= 0 && ii < 10 && jj < 15 && A[ii][jj] == col)
            clear(ii, jj, col);
    }
}

void fixcols()
{
    for (int i = 0; i < 15; ++i)
    {
        string s;
        for (int j = 0; j < 10; ++j)
            if (A[j][i] != 'X')
                s += A[j][i];

        for (int j = 0; j < s.size(); ++j)
            A[j + 10 - s.size()][i] = s[j];
        for (int j = 0; j < 10 - s.size(); ++j)
            A[j][i] = 'X';
    }
}

void fixrows()
{
    bool E[15];
    for (int i = 0; i < 15; ++i)
        E[i] = all_of(A.begin(), A.end(), [&](string& s){return s[i] == 'X';});
    
    for (int it = 0, i = 0; i < 15; ++i)
    {
        if (E[i])
            continue;

        for (int j = 0; j < 10; ++j)
            A[j][it] = A[j][i];
        ++it;
    }
    
    int e = accumulate(E, E + 15, 0);
    for (int i = 15 - e; i < 15; ++i)
        for (int j = 0; j < 10; ++j)
            A[j][i] = 'X';
}

int main()
{
    int n;
    cin >> n;
    for (int c = 1; c <= n; ++c)
    {
        cout << (c > 1 ? "\n" : "") << "Game " << c << ":\n\n";
        for (int i = 0; i < 10; ++i)
            cin >> A[i];

        int balls = 150, mov = 1, pts = 0;
        while (true)
        {
            int m, blocks; char col;
            tie(m, blocks, col) = findmax();
            if (blocks <= 1)
                break;

            clear(m / 15, m % 15, A[m / 15][m % 15]);
            fixcols(); fixrows();
            
            int new_pts = (blocks - 2) * (blocks - 2);
            pts += new_pts;
            balls -= blocks;
            cout << "Move " << mov++ << " at (" << 10 - m / 15 << "," << m % 15 + 1 << "): removed "
                 << blocks << " balls of color " << col << ", got " <<  new_pts << " points.\n";
        }

        if (!balls)
            pts += 1000;
        cout << "Final score: " << pts << ", with " << balls << " balls remaining.\n";
    }
}
