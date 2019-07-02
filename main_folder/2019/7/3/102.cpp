#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		int A[9] = {};
		int B[6] = {};
		istringstream iss(s);
		for (int i = 0; i < 9; ++i)
			iss >> A[i];
				
		int a1 = A[1] + A[2], a2 = A[0] + A[1], a3 = A[0] + A[2];
		int b1 = A[4] + A[5], b2 = A[3] + A[4], b3 = A[3] + A[5];
		int c1 = A[7] + A[8], c2 = A[6] + A[7], c3 = A[6] + A[8];
		
		B[0] = a1 + b2 + c3; B[1] = a1 + b3 + c2;
		B[2] = a2 + b1 + c3; B[3] = a2 + b3 + c1;
		B[4] = a3 + b1 + c2; B[5] = a3 + b2 + c1;
		
		int m = *(min_element(B, B + 6));
		string S[6] = {"BCG ", "BGC ", "CBG ", "CGB ", "GBC ", "GCB "};
		
		for (int i = 0; i < 6; ++i)
			if (m == B[i])
			{	
				cout << S[i] << m << "\n";
				break;
			}
	}	
}
