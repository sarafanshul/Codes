#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, t, res;
	while (cin >> N, N >= 0)
	{
		double down_pay, loan, brm, ret;
		cin >> down_pay >> loan >> t;
		int ToN[t];
		double P[t];
		brm = down_pay + loan;
		ret = loan / N;
		
		for (int i = 0; i < t; ++i)
			cin >> ToN[i] >> P[i];
		
		int k = 0;				//Iterator po ToN[] i P[]
		for (int i = 0; i <= N; ++i)
		{
			if (k + 1 < t && i == ToN[k + 1])
				++k;
			brm *= 1.0 - P[k];
			if (brm > loan - ret * i)
			{
				cout << i << " month" << (i != 1 ? "s\n" : "\n");
				break;
			}
		}
			
	}
	
	return 0;
}
