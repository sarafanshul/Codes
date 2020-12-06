# # # def check(mask , modValue):
# # # 	pass

# # # def solve(length , mask , modValue , isequal):
# # # 	if length == 0:
# # # 		return check(mask , modValue)
# # # 	sol = 0
# # # 	if not isequal:
# # # 		for i in range(10):
# # # 			if i==0:
# # # 				sol += solve(length-1 , mask , (modValue*10+i)%2520 , 0)
# # # 			else:
# # # 			sol += solve(length-1 , mask|(1<<i) , (modValue*10+i)%2520 , 0)
# # # 		

# # dp = [[[0 for i in range(20)]for j in range(504)]for k in range(513)]
# # k = co = T = 0
# # r_vals = [0 for a in range(513)]
# # dp = [[[0 for i in range(20)]for j in range(504)]for k in range(513)]
# # mds = [0 for a in range(100000)]

# # def mod(x):
# # 	if mds[x] == -1:
# # 		return mds[x]=(x%504)
# # 	else:
# # 		return mds[x]

# # def check(mask , md , prev):
# # 	count = ch = 0
# # 	for i in range(9):
# # 		if (mask>>i) and 1 :
# # 			count += 1
# # 			if i == 4:
# # 				if prev: ch += 1
# # 			elif (md%(i+1) == 0):
# # 				ch += 1
# # 	if count >= k and ch >= k:
# # 		return 1
# # 	return 0



# #include<iostream>
# #include<string.h>
# #include<vector>
# using namespace std;
# long long int dp2[513][504][20];
# int k,co;
# int r_vals[513];
# short visit[513][504][20],T;
# int mds[100000];
# int mod(int x)
# {
# 	return mds[x]==-1?(mds[x]=(x%504)):mds[x];
# }
# int check(int mask,int md,int prev)
# {
# 	int coun=0,ch=0;
# 		for(int i=0;i<9;i++)
# 		{
# 			if((mask>>i)&1)
# 			{
# 				coun++;
# 				if(i==4)
# 				{
# 					if(prev)
# 					ch++;
# 				}
# 				else if(md%(i+1)==0)
# 				{
# 					ch++;
# 				}
# 			}
# 		}
# 		if(coun>=k&&ch>=k)
# 		{
# 			return 1;
# 		}
# 	return 0;
# }
# long long int lowvals(int mask,int md,int l)
# {
# 	co++;
# 	if(visit[mask][md][l]==T)
# 	{
# 		return dp2[mask][md][l];
# 	}
# 	long long int sol=0;
# 	int x=0;
# 	if(l!=0)
# 	{
# 		for(int i=0;i<=9;i++)
# 		{
# 		if(i==5||i==0)
# 		{
# 			x=1;
# 		}
# 		else x=0;
# 		if(i==0)
# 		sol+=lowvals(mask,mod(md*10+i),l-1);
# 		else sol+=lowvals(mask|(1<<(i-1)),mod(md*10+i),l-1);
# 		}
# 	}
# 	else
# 	{
# 		for(int i=0;i<=9;i++)
# 		{
# 		if(i==5||i==0)
# 		{
# 			x=1;
# 		}
# 		else x=0;
# 		if(i==0)
# 		sol+=check(mask,mod(md*10+i),x);
# 		else sol+=check(mask|(1<<(i-1)),mod(md*10+i),x);
# 	   }
# 	}
# 	visit[mask][md][l]=T;
# 	return dp2[mask][md][l]=sol;
# }
# int mos=1,x=0;
# long long int calc(int mask,int md,int l)
# {
# 	long long int sol=0;
# 	for(int j=l;j>=0;j--)	
# 	{
# 		for(int i=0;i<r_vals[j];i++)
# 		{
# 			if(j!=0)
# 			{if(i==5||i==0)
# 			{
# 				x=1;
# 			}
# 			else x=0;
# 			if(i==0)
# 			{
# 				sol+=lowvals(mask,mod(md*10+i),j-1);
# 			}
# 			else 
# 			{
# 				sol+=lowvals(mask|(1<<(i-1)),mod(md*10+i),j-1);
# 			}}
# 			else 
# 			{
# 				if(i==5||i==0)
# 			{
# 				x=1;
# 			}
# 			else x=0;
# 			if(i==0)
# 			{
# 				sol+=check(mask,mod(md*10+i),x);
# 			}
# 			else 
# 			{
# 				sol+=check(mask|(1<<(i-1)),mod(md*10+i),x);
# 			}
# 			}
# 		}
# 		if(r_vals[j]!=0)
# 		{
# 			mask|=(1<<(r_vals[j]-1));
# 		}
# 		md=mod(md*10+r_vals[j]);
# 	}
# 	return sol+check(mask,md,((r_vals[0]==5||r_vals[0]==0)?1:0));
# }
# int main()
# {
# 	int t,len=0;
# 	long long int r,l,x,x1,x2;
# 	scanf("%d",&t);
# 	memset(mds,-1,sizeof(mds));
# 	while(t--)
# 	{
# 	T=(short)t+2;
# 	int c=0;
# 	len=0;
# 	mos++;
# 	scanf("%lld %lld %d",&l,&r,&k);
# 	x=r;
# 	while(x)
# 	{
# 		r_vals[len++]=(x%10);
# 		x/=10;
# 	}
# 	x1=calc(0,0,len-1);
# 	x=l-1;
# 	mos++;
# 	len=0;
# 	while(x)
# 	{
# 		r_vals[len++]=(x%10);
# 		x/=10;
# 	}
# 	x2=calc(0,0,len-1);
# 	printf("%lld\n",x1-x2);
# }
# }    