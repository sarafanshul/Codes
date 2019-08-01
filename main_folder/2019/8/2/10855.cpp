#include <iostream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

typedef vector<string> vs;
typedef tuple<int, int, int> iii;
int n, N;

void chkSubmat(const vs &A, const vs &a, int &r0)
{
	//Kandidati za Up-Left početak podmatrice
	stack<iii> S;
	for (int i = 0; i < N - n + 1; ++i)
	{
		int find = A[i].find(a[0]);
		while (find != string::npos)
		{
			if (find < N - n + 1)
				S.emplace(0, i, find);
			find = A[i].find(a[0], find + 1);
		} 
	}
	
	while(!S.empty())
	{
		int lev, row, col, i;
		tie(lev, row, col) = S.top();
		S.pop();
		for (i = lev + 1; i < n; ++i)
			if (!equal(A[row + i].begin() + col, A[row + i].begin() + col + n, a[i].begin()))
				break;
		if (i == n)
			++r0;
	}
}

void rot90(vs &M)
{
	vs R = M;
	for (int i = 0; i < M.size(); ++i)
		for (int j = 0; j < M.size(); ++j)
			M[j][n - i - 1] = R[i][j];
}

int main()
{
	while (cin >> N >> n, n && N)
	{
		int r0 = 0, r1 = 0, r2 = 0, r3 = 0;
		vs A(N, ""), a(n, "");
		for (int i = 0; i < N; ++i)
			cin >> A[i];
		for (int i = 0; i < n; ++i)
			cin >> a[i];
			
		chkSubmat(A, a, r0);
		rot90(a);
		chkSubmat(A, a, r1);
		rot90(a);
		chkSubmat(A, a, r2);
		rot90(a);
		chkSubmat(A, a, r3);
		
		cout << r0 << ' ' << r1 << ' ' << r2 << ' ' << r3 << "\n";
	}
}
