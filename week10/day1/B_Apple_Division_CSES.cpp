#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
ll choices(int i,int n,ll g1,ll g2,vector<int>&v){
    if(i==n){
        return abs(g1-g2);
    }
    ll choice1=choices(i+1,n,g1+v[i],g2,v);
    ll choice2=choices(i+1,n,g1,g2+v[i],v);
    return min(choice1,choice2);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    ll mn=LLONG_MAX;
    cout<<choices(0,n,0,0,v);
    return 0;
}
/*
this problem's constraint is n=20 
so we can naively make a solution using recursion without 
memoization!
here if i==n then we are at the end of the vector so return
difference between g1 & g2. 
both choice1 & choice2 will get their own differences. 
we'll just return the minimum difference among them. 
*/