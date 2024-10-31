#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    map<string,bool> mp;
    vector<string> v;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    for(int i=n-1;i>=0;i--){
        if(mp.count(v[i])){
            v[i]='%';
        }
        mp[v[i]]=true;
    }
    for(int i=n-1;i>=0;i--){
        if(v[i]!="%") cout<<v[i]<<'\n';
    }
    return 0;
}