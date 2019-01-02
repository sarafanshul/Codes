#include <iostream>
using namespace std;

typedef unsigned long long ull;

const int M = 5478;
int A[M * M];
int B[M];

int f(ull i)
{
    if (i < M * M && A[i])
        return A[i];

    int ret = 1 + (i % 2 ? f(3 * i + 1) : f(i / 2));
    
    if (i < M * M)
        return A[i] = ret;

    return ret;
}

int g(int a, int b)
{
    int i = a / M, j = b / M, r = 0;
    for (int k = a; k < min(b, i * M + M); ++k)
        r = max(r, A[k]);
    
    for (int k = max(a, j * M); k < b + 1 ; ++k)
        r = max(r, A[k]);
    
    for (int k = i + 1; k < j; ++k)
        r = max(r, B[k]);

    return r;
}

int main()
{
    A[1] = 1;
    for (int i = 2; i < 1000000; ++i)
        f(i);

    for (int k = 0; k < M; ++k)
        for (int i = 0; i < M; ++i)
            B[k] = max(B[k], A[k * M + i]);

    int a, b;
    while (cin >> a >> b)        
        cout << a << ' ' << b << ' ' << g(min(a, b), max(a, b)) << '\n';
}
