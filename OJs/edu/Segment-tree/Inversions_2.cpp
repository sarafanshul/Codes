#include<bits/stdc++.h>
#define ll long long
using namespace std;
int tree[400001],n;
void build(int l,int r,int node)
{
    if(l==r)
    {
        tree[node]=1;
        return;
    }
    if(l>r)
        return;
    int m=(l+r)/2;
    build(l,m,2*node+1);
    build(m+1,r,2*node+2);
    tree[node]=tree[2*node+1]+tree[2*node+2];
}
void update(int l,int r,int node,int x)
{
    if(l==r)
    {
        tree[node]=0;
        return;
    }
    if(l>r)
        return;
    int m=(l+r)/2;
    if(x<=m)
        update(l,m,2*node+1,x);
    else
        update(m+1,r,2*node+2,x);
    tree[node]=tree[2*node+1]+tree[2*node+2];
}
int query(int l,int r,int node,int k)
{
    if(l==r)
    {
        if(tree[node]==k)
        return l;
        else return n;
    }
    int m=(l+r)/2;
    if(tree[2*node+1]>=k)
        return query(l,m,2*node+1,k);
    else return query(m+1,r,2*node+2,k-tree[2*node+1]);
}
int main()
{
    // ll n;
    cin>>n;
    int a[n],ans[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    build(0,n-1,0);
    for(int i=n-1;i>=0;i--)
    {
        int q=query(0,n-1,0,tree[0]-a[i]);
        // cout<<q;
        ans[i]=q+1;
        update(0,n-1,0,max(q,0));
    }
    for(int i=0;i<n;i++)
    cout<<ans[i]<<' ';
}