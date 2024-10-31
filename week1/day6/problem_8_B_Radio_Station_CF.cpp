#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    map<string,string> server;
    // map<string,string> command;
    while(n--){
        string a,b;
        cin>>a>>b;
        server[b]=a;
    }
    vector<pair<string,string>> v;
    while(m--){
        string a,b;
        cin>>a>>b;
        b.pop_back();
        v.push_back({a,b});
    }
    for(auto p:v){
        cout<<p.first<<" "<<p.second<<"; #"<<server[p.second]<<'\n';
    }
    return 0;
}