 
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
 
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long;
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s ,a = "AB" ,b = "BA";
	cin >> s;
	int n = s.size();
	bool f1 = false  ,f2 = false;
	for (int i = 0; i < n ; ++i){
		if (a.compare(s.substr(i ,2)) == 0 ){
			for(int j = i+2; j < n ; ++j){
				if (b.compare(s.substr(j ,2)) == 0 ){
					f1 = true;
					break;
				}
			}
			break;
		}
	}
	for (int i = 0; i < n ; ++i){
		if (b.compare(s.substr(i ,2)) == 0 ){
			for(int j = i+2; j < n ; ++j){
				if (a.compare(s.substr(j ,2)) == 0 ){
					f2 = true;
					break;
				}
			}
			break;
		}
	}
 
	if (f1 || f2) cout << "YES";
	else  cout << "NO";
	return 0;
}
