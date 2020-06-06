#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int T, cnt = 0;
	cin >> T;
	while (T--)
	{
		int A[3];
		cin >> A[0] >> A[1] >> A[2];
		sort(A, A + 3);
		cout << "Case " << ++cnt << ": " << A[1] << endl;	
	}
	
	return 0;
}
