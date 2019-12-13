#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main()
{
	int N;
	while (cin >> N)
	{
		vi W(1 << N);
		vi P(1 << N);
		for (int i = 0; i < (1 << N); ++i)
			cin >> W[i];
		
		for (int i = 0; i < (1 << N); ++i)
			for (int j = 0; j < N; ++j)
				P[i] += W[i ^ (1 << j)];
		
		int max = 0;	
		for (int i = 0; i < (1 << N); ++i)
			for (int j = 0; j < N; ++j)
				if (P[i] + P[i ^ (1 << j)] > max)
					max = P[i] + P[i ^ (1 << j)];
		cout << max << '\n';
	}
}
