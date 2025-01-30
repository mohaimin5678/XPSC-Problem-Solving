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
    map<int,int> dif;
    while(n--){
        int l,r;
        cin>>l>>r;
        dif[l]++;
        dif[r+1]--;
    }
    ll sum=0;
    // for(auto [key,value]:dif){
    //     cout<<key<<" ";
    // }
    // cout<<ln;
    for(auto [key,value]:dif){
        sum+=value;
        if(sum>2){
            cno;
            return;
        }
    }
    cyes;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    mohaimin();
    
}