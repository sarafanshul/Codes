#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<long> vl;

int main()
{
	long median, tmp;
	vl A;	
	while (cin >> tmp)
	{
		A.push_back(tmp);
		if (A.size() % 2)
		{
			nth_element(A.begin(), A.begin() + A.size() / 2,  A.end());
			median = A[A.size() / 2];
			cout << median << '\n';
		}
		else
		{
			nth_element(A.begin(), A.begin() + A.size() / 2 - (tmp > median ? 0 : 1), A.end());
			cout << (median + A[A.size() / 2 - (tmp > median ? 0 : 1)]) / 2 << '\n';
		}
	}	
}
