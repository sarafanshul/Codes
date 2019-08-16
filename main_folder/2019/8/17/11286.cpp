#include <iostream>
#include <algorithm>
#include <array>
#include <map>
using namespace std;

int main()
{
	int N;
	while (cin >> N, N)
	{
		int max = 0, cnt = 0;
		map<array<int, 5>, int> M;
		for (int i = 0; i < N; ++i)
		{
			array<int, 5> A;
			for (int j = 0; j < 5; ++j)
				cin >> A[j];
			sort(A.begin(), A.end());
			M[A]++;	
			if (M[A] > max)		
				max = M[A];
		}
		for (auto& elem : M)
			if (elem.second == max)
				cnt += elem.second;

		cout << cnt << '\n';
				
	}
}
