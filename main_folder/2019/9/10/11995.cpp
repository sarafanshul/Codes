#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		stack<int> S;
		queue<int> Q;
		priority_queue<int> PQ;
		bool isS = 1, isQ = 1, isPQ = 1;
		
		for (int i = 0; i < n; ++i)
		{
			int op, el;
			cin >> op >> el;
			if (op == 1)
			{
				S.push(el);
				Q.push(el);
				PQ.push(el);
			}
			else
			{
				if (isS && !S.empty() && S.top() == el)
					S.pop();
				else
					isS = 0;
				if (isQ && !Q.empty() && Q.front() == el)
					Q.pop();
				else
					isQ = 0;
				if (isPQ && !PQ.empty() && PQ.top() == el)
					PQ.pop();
				else 
					isPQ = 0;
			}
		}
			
		if (isS + isQ + isPQ > 1)
			cout << "not sure\n";
		else if (isS)
			cout << "stack\n";
		else if (isQ)
			cout << "queue\n";
		else if (isPQ)
			cout << "priority queue\n";
		else
			cout << "impossible\n";	
	}
}
