#include <iostream>
#include <functional>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int main()
{
	map<int, int> Ins;
	string s;
	int a, b, q, cnt = 0;
	while (cin >> s, s != "#")
	{
		cin >> a >> b;
		Ins[a] = b;
	}
	
	cin >> q;
	priority_queue<ii, vector<ii>, greater<ii> > PQ;	
	for (ii elem : Ins)
		PQ.emplace(elem.second, elem.first);

	while (cnt++ < q)
	{
		int time, id;
		tie(time, id) = PQ.top();
		cout << id << '\n';
		PQ.pop();
		PQ.emplace(time + Ins[id], id);
	}
}
