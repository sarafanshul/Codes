#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;

int main()
{
	int N;
	cin >> N;
	cin.ignore(2);
	cout.precision(4);
	while (N--)
	{
		float cnt = 0;
		string s;
		map<string, int> M;
		while (getline(cin, s), s != "")
		{
			M[s]++;
			++cnt;
		}
			
		for (auto& tree : M)
			cout << fixed << tree.first << ' ' << tree.second / cnt * 100 << '\n';
		if (N > 0)
			cout << '\n';
	}
}
