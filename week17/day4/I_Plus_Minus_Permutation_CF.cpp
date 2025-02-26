#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
ll lcm(ll a,ll b){
    ll res=(a/__gcd(a,b))*1LL*b;
    return res;
}
void mohaimin(){
    ll n,x,y;
    cin>>n>>x>>y;
    ll com=lcm(x,y);
    x=n/x;
    y=n/y;
    com=n/com;  //taking how many times x & y can have same index
    x-=com;     //remove common from x
    y-=com;     //remove common from y
    //removing 1 to x-1 sum from it to take all large value from x to n
    ll larger=(n*x)-(x*(x-1))/2;   

    //calculating 1 to y sum for minimum values 
    ll smaller=(y*(y+1))/2;       

    cout<<larger-smaller<<ln;   //maximizing the answer
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