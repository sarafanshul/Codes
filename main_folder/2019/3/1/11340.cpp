#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int p, l;
		double res = 0;
		//Paid charachters
		cin >> p;
		int P[256], a;
		memset(P, 0, sizeof(P));
		unsigned char y;
				
		for (int i = 0; i < p; ++i)
		{
			cin >> y >> a;
			P[int(y)] = a;
		}
			
		cin >> l;
		cin.ignore();
		
		//Article
		for (int i = 0; i < l; ++i)
		{
			unsigned char c;
			while ( c = cin.get(), c != '\n')
				res += P[int(c)];				
		}		
			
		printf("%.2f$\n", res / 100);		
	}
}
