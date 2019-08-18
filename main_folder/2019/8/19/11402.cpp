#include <iostream>
#include <string> 
#include <vector>
using namespace std;

typedef vector<int> vi;
#define FLP 1 // flip
#define SET 2 // set
#define CLR 3 // clear

class segtree
{
    string A;
    vi st, S;
    int n;
public:
    segtree(string& A) : A(A), n(A.size())
    {
        st.assign(4 * n, 0);
        S.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    int rsq(int i, int j)
    {
        return rsq(1, 0, n - 1, i, j);
    }

    void update(int i, int j, int v)
    {
        update(1, 0, n - 1, i, j, v);
    }
    
private:
    int left(int a) { return 2 * a; }
    int right(int a) { return 2 * a + 1; }
    
    void build(int p, int L, int R)
    {
        if (L == R)
            st[p] = A[L] == '1';
        else
        {
            int M = (L + R) / 2;
            build(left(p), L, M);
            build(right(p), M + 1, R);
            st[p] = st[left(p)] + st[right(p)];
        }
    }

    int rsq(int p, int L, int R, int i, int j)
    {
        if (j < L || R < i) return 0;
        apply(p, L, R);

        if (i <= L && R <= j) return st[p];
        int M = (L + R) / 2;
        int l = rsq(left(p), L, M, i, j);
        int r = rsq(right(p), M + 1, R, i, j);
        return l + r;
    }

    void update(int p, int L, int R, int i, int j, int v)
    {
        apply(p, L, R);
        if (j < L || R < i) return;

        if (i <= L && R <= j)
        {
          adjust(p, v);
          apply(p, L, R);
          return;
        }

        int M = (L + R) / 2;
        update(left(p), L, M, i, j, v);
        update(right(p), M + 1, R, i, j, v);
        st[p] = st[left(p)] + st[right(p)];
    }

    void adjust(int p, int v)
    {
        if (v == SET || v == CLR)
            S[p] = v;
        else if (v == FLP)
            S[p] += (S[p] % 2) ? -1 : 1;
    }
   
    void apply(int p, int L, int R)
    {// Lazy propagation
        if (!S[p]) return;
        int len = R - L + 1;
        if (S[p] == SET)
            st[p] = len;
        else if (S[p] == CLR)
            st[p] = 0;
        else if (S[p] == FLP)
            st[p] = len - st[p];

        if (L < R)
        {
            adjust(left(p), S[p]);
            adjust(right(p), S[p]);                
        }
        S[p] = 0;
    }
};


int main()
{
    ios::sync_with_stdio(false);
    int T, m, k, q, a, b;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cout << "Case " << t << ":\n";
        cin >> m;
        string s, r;
        for (int i = 0; i < m; ++i)
        {
            cin >> k >> r;
            while (k--)
                s += r;
        }
        segtree seg(s);
        
        cin >> q;
        char c;
        int Q = 1;
        for (int i = 0; i < q; ++i)
        {
            cin >> c >> a >> b;
            if (c == 'I')
               seg.update(a, b, 1);
            else if (c == 'F')
                seg.update(a, b, 2);
            else if (c == 'E')
                seg.update(a, b, 3);
            else if (c == 'S')
                cout << 'Q' << Q++ << ": " << seg.rsq(a, b) << '\n';
        }
    }
}
