#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int LSOne(int a)
{
    return a & (-a);
}

class fentree
{
private:
    vi ft;
public:
    fentree(int n)
    {
        ft.assign(n + 1, 0);
    }

    int rsq(int a)
    {
        int res = 0;
        for (; a > 0; a -= LSOne(a))
            res += ft[a];
        return res;
    }
    
    int rsq(int a, int b)
    {
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }

    void adjust(int k, int v)
    {
        for (; k < ft.size(); k += LSOne(k))
            ft[k] += v;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    int n, l, r, cnt = 0;
    while (cin >> n, n)
    {
        if (cnt)
            cout << '\n';
        
        cout << "Case " << ++cnt << ":\n";
        vi A(n + 1);
        fentree F(n);
        for (int i = 1; i <= n; ++i)
            cin >> A[i], F.adjust(i, A[i]);

        string s;
        while (cin >> s, s != "END")
        {
            cin >> l >> r;
            if (s == "S")
                F.adjust(l, r - A[l]), A[l] = r;
            else
                cout << F.rsq(l, r) << '\n';                
        }
    } 
}
