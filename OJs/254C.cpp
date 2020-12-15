#include<bits/stdc++.h>
using namespace std;
#define pi 3.14159265359
#define int long long
#define pii pair<int,int>
const int mod=1e9+7;

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};



int32_t  main()
{ 
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
 
  #ifdef ONLINE_JUDGE
  freopen("input.txt","rt",stdin);
  freopen("output.txt","wt",stdout);
  #endif

  string s1,s2;
  cin>>s1>>s2;
  vector<int>cnt1(26),cnt2(26),rm1(26),rm2(26);
	for(int i=0;i<s1.size();i++){
		cnt1[s1[i]-'A']++;
		cnt2[s2[i]-'A']++;
	}
	int ans=0;
	for(int i=0;i<26;i++){
		if(cnt1[i]>=cnt2[i]){
			ans+=cnt1[i]-cnt2[i];
			rm1[i]+=cnt1[i]-cnt2[i];
		} 
    else{
			rm2[i]=cnt2[i]-cnt1[i];
		}
	}
	cout<<ans<<"\n";
	for(int i=0;i<s1.size();i++){
		if(rm1[s1[i]-'A']>0){
			for(int j=0;j<26;j++){
				if(cnt2[j]&&(rm2[j]>0||j==s1[i]-'A')){
					cnt2[j]--;
					if(j!=s1[i]-'A'){
						rm2[j]--;
						rm1[s1[i]-'A']--;
					}
					s1[i]=j+'A';
					break;
				}
			}
		} 
    else{
			cnt2[s1[i]-'A']--;
		}
	}
cout<<s1;

}

