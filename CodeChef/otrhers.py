# # ENCODING
# #include<bits/stdc++.h>
# using namespace std;
# long long ans,xr,a[100005],sz,coeff,temp,sum[100005],diff;
# long long j;
# vector<long long >  v[1999999];

# int main(){

# 	ios_base::sync_with_stdio(false);
# 	cin.tie(NULL);

# 	for(long long i=2;i<=100001;i++){
# 		sum[i]=sum[i-1]+ (long long)(((i-1)*i)/2);
# 	}

# 	set<long long > st;
# 	set <long long > :: iterator itr; 

# 	int t;
# 	cin>>t;
# 	while(t--){

# 		st.clear();
# 		ans=0;
# 		diff=0;
# 		int n;
# 		cin>>n;

# 		for(long long i=0;i<n;i++){
# 			cin>>a[i];

# 			if(i==0){
# 				xr=a[0];
# 				// continue;
# 			}else if(i==1){
# 				xr=a[0]^a[1];
# 				v[a[0]].push_back(1);
# 				v[xr].push_back(2);
# 			}else if(i>1){
# 				xr=xr^a[i];
# 				if(v[xr].size()==0){
# 					v[xr].push_back(i+1);	
# 				}else{
# 					v[xr].push_back(i-v[xr][0]);
# 					v[xr][0]=i+1;
# 				}
# 			}
# 			// cout<<xr<<" ";
# 			if(xr==0){
# 				ans+=i;
# 			}

# 			st.insert(xr);
# 		}
# 		// cout<<"**"<<ans<<endl;
# 		for (itr = st.begin(); itr != st.end(); itr++){ 
# 			xr=*itr;	

# 			if(v[xr].size()<=1){
# 				v[xr].clear();
# 				continue;
# 			}

# 			// cout<<xr<<" -- ";
# 			// ans=0;

# 			if((v[xr].size()-1)%2==0){

# 				j=1;
# 				sz=(v[xr].size()-1);
# 				temp=(long long)sz/2;
# 				coeff=sz;
# 				diff=sz-2;
# 				while(temp--){
# 					ans+=coeff*v[xr][j];
# 					coeff+=diff;
# 					diff-=2;
# 					j++;
# 				}

# 				temp=(long long )sz/2;
# 				diff=2;
# 				while(temp--){
# 					ans+=coeff*v[xr][j];
# 					coeff-=diff;
# 					diff+=2;
# 					j++;
# 				}

# 			}else{
# 				j=1;
# 				sz=(v[xr].size()-1);
# 				temp=(long long )sz/2;
# 				coeff=sz;
# 				diff=sz-2;
# 				while(temp--){
# 					ans+=coeff*v[xr][j];
# 					coeff+=diff;
# 					diff-=2;
# 					j++;
# 				}

# 				ans+=coeff*v[xr][j];
# 				j++;
# 				coeff--;

# 				temp=(long long)sz/2;
# 				diff=3;
# 				while(temp--){
# 					ans+=coeff*v[xr][j];
# 					coeff-=diff;
# 					diff+=2;
# 					j++;
# 				}
# 			}	

# 			ans+=sum[v[xr].size()-1];	
# 			v[xr].clear();

# 		}
# 		st.clear();
# 		cout<<ans<<endl;
# 	}
# 	return 0;
# }


# # # ZOMCAV TLE
# t = int(input())
# for _ in range(t):
#     n = int(input())
#     C = list(map(int, input().split()))
#     H = list(map(int, input().split()))
#     # radiation_levels = [0] * n
#     memo = []
#     for i in range(n):
#         underflow = overflow = 0
#         ones = 2 * C[i] + 1
#         left_zeroes = 0
#         right_zeroes = 0
#         if C[i] > i:
#             underflow = C[i] - i
#         else:
#             left_zeroes = i - C[i]
#         if C[i] > n - i - 1:
#             overflow = C[i] - (n - i - 1)
#         else:
#             right_zeroes = (n - i - 1) - C[i]
#         ones = ones - (underflow + overflow)
#         # temp = [0] * left_zeroes + [1] * ones + [0] * right_zeroes
#         temp = [left_zeroes, ones, right_zeroes]
#         memo.append(temp)
#         # for j in range(n):
#         #     radiation_levels[j] += temp[j]
#     x = [0] * n
#     for each in memo:
#         temp = [0] * each[0] + [1] * each[1] + [0] * each[2]

#     radiation_levels = [sum(i) for i in zip(*memo)]
#     # print(radiation_levels)
#     radiation_levels.sort()
#     H.sort()
#     if H == radiation_levels:
#         print('YES')
#     else:
#         print('NO')






# # # concept of ks1
# t = int(input())
# for _ in range(t):
#     n = int(input())
#     A = list(map(int, input().split()))
#     i = 0
#     j = 1
#     k = 1
#     t = 0
#     for x in range(n-1):
#         lhs = A[i:j-1]
#         rhs = A[j:k]


#     print(t)