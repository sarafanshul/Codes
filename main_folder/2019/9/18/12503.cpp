#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, C[100], tmp, res = 0;
		memset(C, 0, 100 * sizeof(int));
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			string s;
			cin >> s;
			if (s == "RIGHT")
			{
				C[i] = 1;
				res++;
			}
			else if (s == "SAME")
			{
				cin >> s >> tmp;
				C[i] = C[--tmp];
				res += (C[i] == 1 ? 1 : -1);
			}
			else
				res--;
		}
		cout << res << "\n";
		
	}
	
	
	return 0;
}
