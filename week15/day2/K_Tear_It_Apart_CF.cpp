#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    string s;
    cin>>s;
    map<char,int> mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    int mx=INT_MIN;
    char c;
    for(auto [x,y]:mp){
        if(mx<y){
            mx=y;
            c=x;
        }
    }
    vector<int> dis;
    int d=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==c){
            dis.push_back(i-d+1);
            d=i+1;
        }
        if(i==s.size()-1){
            if(d!=s.size()){
                dis.push_back(i-d+1);
                // d=i;
            }
        }
    }
    int ans=0;
    for(int x:dis){
        ans+=log2(x);
    }
    cout<<ans<<ln;
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