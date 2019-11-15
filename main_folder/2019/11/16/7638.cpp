#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
#include <set>
using namespace std;

typedef vector<int> vi;

vi Primes, IsPrime;

void Sieve(int bound)
{
    IsPrime.assign(bound, 1);
    IsPrime[0] = IsPrime[1] = 0;

    for (int i = 2; i < bound; ++i)
    {
        if (IsPrime[i])
        {
            for (int j = i * i; j < bound; j += i)
                IsPrime[j] = 0;

            Primes.push_back(i);
        }
    }
}

struct UF
{
    vi r, p;
    UF(int n) : r(n, 0), p(n, 0)
    {
        iota(p.begin(), p.end(), 0);
    }
	
    int f(int x)
    {
        return (p[x] == x ? x : p[x] = f(p[x]));
    }
	
    void u(int i, int j)
    {
        int x = f(i), y = f(j);
        if (x == y)
            return;

        if (r[x] >= r[y])
        {
            p[y] = x;
            if (r[x] == r[y])
                r[x]++;
        }
        else
            p[x] = y;
    }

    bool s(int i, int j)
    {
        return f(i) == f(j);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    int T, N;
    cin >> T;
    Sieve(1005);
    for (int c = 1; c <= T; ++c)
    {
        cin >> N;
        vi A(N);
        int ones = 0;
        for (int i = 0; i < N; ++i)
            cin >> A[i], ones += A[i] == 1;

        UF uf(1000005);
        
        for (int i = 0; i < N; ++i)
        {
            int tmp = A[i];
            for (int j = 0; j < Primes.size() && Primes[j] * Primes[j] <= A[i]; ++j)
                if (tmp % Primes[j] == 0)
                {
                    while (tmp % Primes[j] == 0)
                        tmp /= Primes[j];
                    
                    uf.u(A[i], Primes[j]);
                }

            // At most 1 factor of A[i] is greater than sqrt(A[i]).
            if (tmp > 1)
                uf.u(tmp, A[i]);
        }

        set<int> res;
        for (int i = 0; i < N; ++i)
            if (A[i] > 1)
                res.insert(uf.f(A[i]));
        
        cout << "Case " << c << ": " << res.size() + ones  << '\n';
    }
}
    
