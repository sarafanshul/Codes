
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<cmath>
#include<cstring>
#define FF first
#define SS second
#define ll long long
#define pb push_back
#define pm make_pair
using namespace std;
typedef pair<int,int> PII;
const int MAX = 2e5 + 5;
struct Node {
	int x,y,s;
	Node(int x=0,int y=0,int s=0):x(x),y(y),s(s){}
};
char s[11][11];
int nx[8] = {0,1,1,1,0,-1,-1,-1};
int ny[8] = {1,1,0,-1,-1,-1,0,1},maxsize;
bool bfs(int stx,int sty) {
	queue<Node> q;
	q.push(Node(stx,sty,0));
	while(q.size()) {
		Node cur = q.front();q.pop();
		if(s[max(1,cur.x-cur.s-1)][cur.y] != 'S') 
			q.push(Node(cur.x,cur.y,cur.s+1));
		if(cur.s >= 8) return 1;
		for(int i = 0; i<8; i++) {
			int tx = cur.x + nx[i],ty = cur.y + ny[i];
			if(s[max(1,tx-cur.s-1)][ty] == 'S' || s[max(1,tx-cur.s)][ty] == 'S') continue;
			if(tx < 1 || tx > 8 || ty < 1 || ty > 8) continue;
			q.push(Node(tx,ty,cur.s+1));
		}
	}return 0;
}
int main()
{
	for(int i = 1; i<=8; i++) scanf("%s",s[i]+1); 
	if(bfs(8,1) == 1) puts("WIN");
	else puts("LOSE");
//	printf("%d\n",maxsize);
	return 0 ;
}