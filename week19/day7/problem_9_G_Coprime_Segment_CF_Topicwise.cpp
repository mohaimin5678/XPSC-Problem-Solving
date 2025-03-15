#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
const int maxN=1e5+9;
ll a[maxN], t[4*maxN];
void build(int n,int b,int e){          //O(N)
    if(b==e){
        t[n]=a[b];      //saving a[e]/a[b] on the leaf node
        return;         
    }
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    build(l,b,mid);
    build(r,mid+1,e);
    t[n]=__gcd(t[l],t[r]);
}
ll query(int n,int b,int e,int i,int j){     //O(logN)
    if(e<i || b>j){   //"out of" segment
        return 0; 
    }
    if(b>=i && e<=j){   //"inside" segment
        return t[n];    
    }
    //"intersect" segment
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    return __gcd(query(l,b,mid,i,j),query(r,mid+1,e,i,j));
}
void mohaimin(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    int l=1,r=1,ans=INT_MAX;

    while(r<=n){
        // cout<<a[l]<<" "<<a[r]<<" "<<query(1,1,n,l,r)<<ln;
        if(query(1,1,n,l,r)==1LL){
            // cout<<"IN"<<ln;
            while(l<=r && query(1,1,n,l,r)==1){
                ans=min(ans,(r-l+1));
                l++;
            }
        }
        r++;
    }
    if(ans==INT_MAX) cout<<-1<<" ";
    else cout<<ans<<" ";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    t=1;
    while(t--){
        mohaimin();
    }
}
/*
initially I thought about binary search on answer but it wasn't 
correct. Then after analyzing the problem, 2 pointers sliding window 
made much more sense. since after the moment we'll hit gcd==1 the next
all right sided value will give 1. so we'll start to shift l towards
r until l==r & each time we'll use the query function to find the
gcd of this segment. if its still 1 then saving the min range & reduce
the range more. This is how segment tree & 2 pointers sliding window
worked together. 

silly mistake was: I did the code but didn't take the N as input & 
also I didn't call build function initially! :) 
*/