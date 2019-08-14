#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

class SegTree
{
private:
    vi st, A;
    int n;
    int left (int p) { return p << 1; }
    int right (int p) { return (p << 1) + 1; }

    void build(int p, int L, int R)
    {
        if (L == R)
            st[p] = L;
        else
        {
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] >= A[p2]) ? p1 : p2;
        }
    }

    int rmq(int p, int L, int R, int i, int j)
    {
        if (j < L || i > R)
            return -1;
        if (i <= L && j >= R)
            return st[p];

        int p1 = rmq(left(p), L, (L + R) / 2, i, j);
        int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
        if (p1 == -1)
            return p2;
        if (p2 == -1)
            return p1;
        return A[p1] >= A[p2] ? p1 : p2;
    }
    
        
public:
    SegTree(const vi& _A)
    {
        A = _A;
        n = A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    int rmq(int i, int j)
    {
        return rmq(1, 0, n - 1, i, j);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    int n, q, l, r;
    while (cin >> n >> q, n)
    {
        vi A(n), P(n);
        cin >> P[0];
        A[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            cin >> P[i];
            A[i] = P[i] == P[i - 1] ? A[i - 1] + 1 : 1;
        }
        
        SegTree S(A);
        
        for (int i = 0; i < q; ++i)
        {
            cin >> l >> r; --l; --r;
            int s = S.rmq(l, r);
            int m = min(A[s], s - l + 1);
            m = max(m, A[S.rmq(s + 1, r)]);
            cout << m << '\n';
        }
    }
}
