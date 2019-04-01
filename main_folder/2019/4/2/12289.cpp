#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		if (s.size() == 3)
		{
			int cnt = (s[0] == 'o') + (s[1] == 'n') + (s[2] == 'e');
			cout << ( cnt >= 2 ? "1\n" : "2\n" );
		}
		else
			cout << '3' << "\n";
	}
	
	return 0;
}
