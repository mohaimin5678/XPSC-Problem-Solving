#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
#define neg cout<<"-1"<<ln
using namespace std;
void mohaimin(){
    int n,a,b;
    cin>>n>>a>>b;
    int x=n/2;
    int y=x+1;
    if(n==2){
        cout<<a<<" "<<b<<ln;
        return;
    }
    if(a<=x && b<=x){
        neg;
        return;
    }
    if(a>y || b<x || (a!=y && b==x) || (a==y && b!=x)){
        neg;
        return;
    }
    vector<int> mn;
    vector<int> mx;
    mn.push_back(a);
    mx.push_back(b);
    for(int i=n;i>x;i--){
        if(i!=b && i!=a) mn.push_back(i);
        if(mn.size()==x) break;
    }
    for(int i=1;i<=x;i++){
        if(i!=b && i!=a) mx.push_back(i);
        if(mx.size()==x) break;
    }

    for(auto z:mn) cout<<z<<" ";
    for(auto z:mx) cout<<z<<" ";
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