#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
const int maxN=2e5+9;
int v[maxN],t[4*maxN];
void build(int n,int b,int e){
    if(b==e){
        t[n]=v[b];
        return;
    }
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    build(l,b,mid);
    build(r,mid+1,e);
    t[n]=(t[l] & t[r]);
}
int query(int n,int b,int e,int i,int j){     //O(logN)
    if(e<i || b>j){   //"out of" segment
        return 2147483647;      //highest all on bit value
    }
    if(b>=i && e<=j){   //"inside" segment
        return t[n];
    }
    //"intersect" segment
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    return (query(l,b,mid,i,j) & query(r,mid+1,e,i,j)); 
}
void mohaimin(){
    int n,q;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>v[i];
    build(1,1,n);
    cin>>q;
    while(q--){
        int l,k;
        cin>>l>>k;
        int st=l,end=n,ans=-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(query(1,1,n,l,mid)>=k){
                ans=mid;
                st=mid+1;
            }
            else end=mid-1;
        }
        cout<<ans<<" ";
    }
    cout<<ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        mohaimin();
    }
}
/*
A simple fact also:- sequential & operation will either keep
the answer equal/low. It will never get up. The further we move
to the right, the lower the values will become.

intially we'll build the node-tree
then for q queries, we'll get a starting point & value
we have to maximize the ending point for which we'd get >=value
so what we did?
we used a binary search. 
we took st=l & end=n, then mid=st+(end-st)/2;
if(query(st,mid)>=value) that means we can go further so st=mid+1
                        also the ans will be saved
else we need to check for lesser range so end=mid-1

after doing the binary search we'll just print the ans. 

so complexity is= O(Q * log(N)^2);
*/