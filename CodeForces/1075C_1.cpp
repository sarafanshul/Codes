#include <bits/stdc++.h>
using namespace std;
 
#define N 100010
int n, m, q;
int a[N], b[N];
 
 
int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; ++i) scanf("%d", a + i);
		sort(a + 1, a + 1 + n);
		q = 0;
		for (int i = 1, x1, x2, y; i <= m; ++i)
		{
			scanf("%d%d%d", &x1, &x2, &y);
			if (x1 == 1) b[++q] = x2;
		}
		sort(b + 1, b + 1 + q);
		int res = q;  
		int pos = 0;
		a[n + 1] = (int)1e9; 
		for (int i = 0; i <= n; ++i)
		{
			while (pos < q && b[pos + 1] < a[i + 1]) ++pos;
			res = min(res, i + q - pos);
		}
		printf("%d\n", res);
	}
	return 0;
}
