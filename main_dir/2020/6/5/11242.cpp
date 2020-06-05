#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int f, r;
	while (cin >> f >> r, f)
	{
		int A[10], it = 0;
		double R[100], tmp;
		for (int i = 0; i < f; ++i)
			cin >> A[i];
			
		for (int i = 0; i < r; ++i)
		{
			cin >> tmp;
			for (int j = 0; j < f; ++j)
				R[it++] = tmp / A[j];
		}
		
		sort(R, R + r * f);
		double max = 0;
		for (int i = 1; i < r * f; ++i)
			if (R[i] / R[i - 1] > max)
				max = R[i] / R[i - 1];
				
		printf("%.2f\n", max);			
	}
}
