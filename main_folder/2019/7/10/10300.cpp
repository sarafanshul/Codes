#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		int f, sum = 0;
		cin >> f;
		for (int i = 0; i < f; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			sum += a * c;			
		}
		cout << sum << "\n";		
	}
	return 0;
}
