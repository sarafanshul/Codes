#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	while (n--)
	{
		int M = 0, F = 0;
		string s;		
		getline(cin, s);
		for (char c : s)
			if (c == 'F')
				F++;
			else if (c == 'M')
				M++;
		if (s.size() > 2 && M == F)
			cout << "LOOP\n";
		else
			cout << "NO LOOP\n";
	}
	
	
	return 0;
}
