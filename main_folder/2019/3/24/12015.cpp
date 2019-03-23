#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int T, cnt = 1;
	cin >> T;
	string s;
	while (T--)
	{
		int max = -1, R[11];
		vector<string> W(11);
		memset(R, 0, 11 * sizeof(int));
		for (int i = 0; i < 10; ++i)
		{
			cin >> W[i] >> R[i];
			if (R[i] > max)
				max = R[i];
		}
		cout << "Case #" << cnt++ << ":\n";
		for (int i = 0; i < 10; ++i)
			if (R[i] == max)
				cout << W[i] << "\n";
	}
	
	return 0;
}
