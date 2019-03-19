#include <iostream>
#include <set>
using namespace std;

int main()
{
	int N[2];
	while (cin >> N[0] >> N[1], N[0] || N[1])
	{
		int tmp, cnt = 0;
		multiset<int> S;
		for (int k = 0; k < 2; ++k)
			for (int i = 0; i < N[k]; ++i)
			{
				cin >> tmp;
				S.insert(tmp);
			}
		for (int elem : S)
			if (S.count(elem) == 2)
				++cnt;
		cout << cnt / 2 << '\n';
	}
}
