/*

-> Set s1= "aaaa...aaaaaaa" (ie. 200 times 'a').
-> For i such that (1≤i≤n) set si+1:=si and then flip (ai+1)-th character of si+1 (ie. if it was 'a' put 'b' otherwise 'a').
	So for each i:

	-> si and si+1 will have exactly ai common characters from the prefix.
	-> The (ai+1)-th character of si+1 is different than (ai+1)-th character of si (this character always exists since 0≤ai≤50 and each string has length exactly 200).
Therefore the LCP is ai as desired.
*/

#include <bits/stdc++.h>
using namespace std;

void check(){
	int n ,u;
	cin >> n;

	string s(200, 'a');
    cout << s << "\n";

    for(int i = 0; i < n ; ++i){
    	cin >> u;
    	s[u] = s[u] == 'a' ? 'b' : 'a';
    	cout << s <<"\n";
    }

}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		check();
	}
	return 0;
}