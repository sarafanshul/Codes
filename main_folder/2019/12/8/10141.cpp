#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define vi vector<int>

int main()
{
	int n, p, cnt = 0;
	while (cin >> n >> p, n || p)
	{
		if (cnt)
			cout << '\n';
		cin.ignore();
		string s;
		string bName;
		int bAtt = 0, x;
		float bPrice = 0, y;
		for (int i = 0; i < n; ++i)
			getline(cin, s);
			
		for (int i = 0; i < p; ++i)
		{
			getline(cin, s);
			cin >> y >> x;
			cin.ignore();
			if (x > bAtt || (x == bAtt && y < bPrice))
			{
				bName = s;
				bAtt = x;
				bPrice = y;
			}
			for (int j = 0; j < x; ++j)
				getline(cin, s);			
		}
		cout << "RFP #" << ++cnt << "\n" << bName << "\n";
	}
	
	return 0;
}
