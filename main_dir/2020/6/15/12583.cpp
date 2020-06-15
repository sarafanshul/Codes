#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int t, n, k;
	string s;
	cin >> t;
	
	for (int c = 1; c <= t; c++)
	{
		cin >> n >> k >> s;
		vector<int> B('Z' - 'A' + 1, -1);	// The last position someone was seen on
		int res = 0;
		
		for (int i = 1; i < n; ++i)
		{
			B[s[i - 1] - 'A'] = i - 1;
			
			if (B[s[i] - 'A'] != -1 && i - B[s[i] - 'A'] <= k)
				++res;
		}
		
		cout << "Case " << c << ": " << res << "\n";
	}
}
