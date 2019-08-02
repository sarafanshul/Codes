#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n, k;
	while (cin >> n, n != 0)
	{
		bool flag = true;
		cin >> k;
		vector<string> C(n);
		for (int i = 0; i < n; ++i)
			cin >> C[i];
		
		for (int i = 0; i < k; ++i)
		{
			string name;
			int nrC, req, cnt = 0;
			cin >> nrC >> req;
			while (nrC--)
			{
				cin >> name;
				for (string s : C)
					if (name == s)
						cnt++;
			}
			if (cnt < req)
				flag = false;
		}
		if (flag)
			cout << "yes\n";
		else
			cout << "no\n";
		
		
	}
	
	
	return 0;
}
