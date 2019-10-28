#include <iostream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	int N;
	string s;
	while (cin >> N, cin.ignore(), N)
	{
		int A[N]; //Target permutation
		while (getline(cin, s), s != "0")
		{
			int cnt = 0;
			istringstream iss(s);
			for (int i = 0; i < N; ++i)
				iss >> A[i];
			
			stack<int> S;
			for (int i = 1; i <= N; ++i)
			{
				S.push(i);
				while (!S.empty() && A[cnt] == S.top())
				{
					S.pop();
					++cnt;
				}
			}
			cout << (cnt == N ? "Yes\n" : "No\n");
		}
		cout << '\n';
	}
}
