#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		bool flag = true;
		int w, a, b;
		cin >> w >> a >> b; 
		int diff = a - b;
		for (int j = 1; j < w; ++j)
		{
			cin >> a >> b;
			if (a - b != diff)
				flag = false;
			
		}
		if (flag)
			cout << "yes\n";
		else
			cout << "no\n";
			
		if (T != 0)
			cout << "\n";
		
	}
	
	return 0;
}
