#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;

void mohaimin(){
    string s,p;
    cin>>s>>p;
    if(s.size()>p.size()){
        cno;
        return;
    }
    sort(s.begin(),s.end());
    int sz=s.size();
    for(int i=0;i<=p.size()-sz;i++){
        // cout<<p[i];
        string x=p.substr(i,sz);
        sort(x.begin(),x.end());
        if(x==s){
            cyes;
            return;
        }
    }
    cno;
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