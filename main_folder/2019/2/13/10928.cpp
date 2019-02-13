#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, a;
		unsigned min = -1;
		cin >> n;
		cin.ignore();
		vector<vector<int> > P(n);
		
		for (int i = 0; i < n; ++i)
		{
			string s;
			getline(cin, s);
			istringstream iss(s);
			while (iss >> a)
				P[i].push_back(a);
			
			if (P[i].size() < min)
				min = P[i].size();
		}
		
		string res;
		for (int i = 0; i < P.size(); ++i)
			if (P[i].size() == min)
				res += to_string(i + 1) + " ";
		res.pop_back();
		cout << res << '\n';
	}
}
