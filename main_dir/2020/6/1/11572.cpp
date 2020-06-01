#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		map<int, int> Left;
		int s, border = 0, max = 0;
		cin >> s;
		for (int i = 1; i <= s; ++i)
		{
			int tmp;
			cin >> tmp;
			border = std::max(border, Left[tmp] + 1); //Now: Left[tmp] == 0
			Left[tmp] = i;			
			if (i - border + 1 > max)
				max = i + 1 - border;
		}
		cout << max << '\n';
	}
}
