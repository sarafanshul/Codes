#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string src, target;

void swiss_cheese(string &a)
{
	cout << a[0];
	for (int i = 1; i < a.size(); ++i)
		cout << ' ' << a[i];
	cout << '\n';
}

void func(string state, string stack, string partial)
{
	if (partial != target.substr(0, partial.size()))
		return ;
	
	int cnt = count(state.begin(), state.end(), 'i');
		
	if (cnt < src.size())
		func(state + "i", stack + src[cnt], partial);
	if (stack.size() > 0)
		func(state + "o", stack.substr(0, stack.size() - 1), partial + stack[stack.size() - 1]);
	if (partial == target)
		swiss_cheese(state);
	return;
}

int main()
{	
	while (cin >> src >> target)
	{
		cout << "[\n";
		func("i", string(1, src[0]), "");		
		cout << "]\n";
	}
}
