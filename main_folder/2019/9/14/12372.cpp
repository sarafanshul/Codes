#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, cnt = 0;
	cin >> N;
	while (N--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if(a < 21 && b < 21 && c < 21)
			cout << "Case " << ++cnt << ": good\n";
		else
			cout << "Case " << ++cnt << ": bad\n";
	}
	
	return 0;
}
