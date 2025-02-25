#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    priority_queue<pair<int,string>> pq;
    map<string,int> mp;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        mp[s]=i;
    }
    for(auto [x,y]:mp){
        pq.push({y,x});
    }

    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        int len=p.second.size();
        cout<<p.second[len-2]<<p.second[len-1];
    }
    cout<<endl;
    return 0;
}
