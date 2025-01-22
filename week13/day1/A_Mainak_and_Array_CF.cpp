#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    if(n==1){
        cout<<0<<ln;
        return;
    }
    int mx=0;
    //check all subtraction result of all other elements-first
    for(int i=1;i<n;i++){       
        mx=max(mx,v[i]-v[0]);
    }
    //check all subtraction result of last-all other elements
    for(int i=0;i<n-1;i++){
        mx=max(mx,v[n-1]-v[i]);
    }
    //check any reverse subtraction result is max 
    for(int i=1;i<=n-1;i++){
        mx=max(mx,v[i-1]-v[i]);
    }
    cout<<mx<<ln;
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
a bit tricky cause we have to maintain serial here which ig many
of us did forgot. 
so to maintain serial: 
1)subtract the 0th from 1st to (n-1)th value & check highest
so straight serial maintained here. 
2)subtract till (n-2)th from (n-1)th value & check highest
so another straight serial maintained here. 
3)subtract 1st to (n-1)th value with its previous value & check highest
here we maintained a reverse straight serial. 
suppose we got-> 
4
2 3 8 1
so from 1st loop we'll get 6 which is max
2nd loop we'll get negative values so 6 is still max
3rd loop we'll get 8-1 which is 7 & new max
here if we made [1 2 3 8] our array then we get 7 
so these 3 loop will be enough. 
*/