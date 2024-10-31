#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    map<pair<string,string>,bool> mp;
    while(n--){
        string a,b;
        cin>>a>>b;
        mp[{a,b}]=true;
    }
    // for(auto val:mp){
    //     pair<string,string> p=val.first;
    //     bool ok=val.second;
    //     cout<<p.first<<" "<<p.second<<" "<<ok<<'\n';
    // }
    cout<<mp.size()<<'\n';
    return 0;
}