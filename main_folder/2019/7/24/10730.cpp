#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

typedef vector<int> vi;

bool isAntiArithmetic(vi A, vi S)
{
	for (int i = 0; i < A.size() - 2; ++i)
	{
		int d_min = ceil(-A[i] / 2.0);
		int d_max = floor((A.size() - 1 - A[i]) / 2.0);
		bool first = false, second = false;
		for (int d = d_min; d <= d_max; ++d)
			if (S[A[i] + d] > i && S[A[i] + 2 * d] > S[A[i] + d])
				return false;	
	}
	
	return true;
}

vector<int> sortIndices(std::vector<int>& A)
{
	vector<int> ind(A.size());
	iota(ind.begin(), ind.end(), 0);
	sort(ind.begin(), ind. end(), [&](int i, int j){return abs(A[i]) < abs(A[j]);});
	
	return ind;	
}

int main()
{
	char c;
	int n;
	while (cin >> n >> c, n)	
	{
		vi A(n);
		for (int i = 0; i < n; ++i)
			cin >> A[i];
			
		vi S = sortIndices(A);		
		cout << (isAntiArithmetic(A, S) ? "yes" : "no") << "\n";		
	}
}
