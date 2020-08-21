#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, cnt = 0;
	string s;
	
	while (cin >> s, s != "*")
	{
		if (s == "Hajj")
			cout << "Case " << ++cnt << ": Hajj-e-Akbar\n";
		else
			cout << "Case " << ++cnt << ": Hajj-e-Asghar\n";		
	}
	
	return 0;
}
