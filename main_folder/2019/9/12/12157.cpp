#include <iostream>
using namespace std;

int main()
{
	int T, cnt = 0;
	cin >> T;
	while (T--)
	{
		int N, MVD = 0, J = 0;
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			int a;
			cin >> a;
			MVD += (a / 30 + 1) * 10;
			J += (a / 60 + 1) * 15;
		}
		cout << "Case " << ++cnt << ": ";
		if (MVD < J)
			cout << "Mile " << MVD << "\n";
		else if (J < MVD)
			cout << "Juice " << J << "\n";		
		else
			cout << "Mile Juice " << J << "\n";
	}
		
	return 0;
}
