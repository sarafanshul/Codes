#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi dx, dy;
int R, C, k_0;
bool valid(int d, int e)
{
    return d >= 0 && e >= 0 && d < R && e < C;
}

void dfs(vvi& A, int i, int j)
{
    for (int k = 0; k < k_0; ++k)
    {
        int d = i + dx[k], e = j + dy[k];
        if (valid(d, e) && A[d][e] == 0)
            A[d][e] = 1, dfs(A, d, e);
    }
}

int main()
{
    int T, M, N, w, a, b;
    cin >> T;
    for (int c = 1; c <= T; ++c)
    {
        cin >> R >> C >> M >> N >> w;
        vvi A(R, vi(C));
        for (int i = 0; i < w; ++i)
            cin >> a >> b, A[a][b] = -1;
        
        int d1[] = {-M, M, -N,  N, -N, N, -M,  M};
        int d2[] = {-N, N,  M, -M, -M, M,  N, -N};
        dx = vi(d1, d1 + 8); dy = vi(d2, d2 + 8);
        k_0 = (M == N || M * N == 0) ? 4 : 8;

        A[0][0] = 1;
        dfs(A, 0, 0);
        
        int odd = 0, even = 0;
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if (A[i][j] > 0)
                {
                    int cnt = 0;
                    for (int k = 0; k < k_0; ++k)
                    {
                        int d = i + dx[k], e = j + dy[k];
                        if (valid(d, e) && A[d][e] >= 0)
                            ++cnt;
                    }

                    ++(cnt % 2 ? odd : even);
                }
        
        cout << "Case " << c << ": " << even << ' ' << odd << '\n';
    }
}
