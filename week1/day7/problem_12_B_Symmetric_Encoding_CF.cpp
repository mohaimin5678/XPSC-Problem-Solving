#include<bits/stdc++.h>
using namespace std;
void encode(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int freq[26]={0};
    for(int i=0;i<s.size();i++){
        freq[s[i]-'a']++;
    }
    string r;
    for(int i=0;i<26;i++){
        if(freq[i]!=0){
            char c='a'+i;
            r.push_back(c);
        }
    }
    // cout<<r<<'\n';
    map<char,char> mp;
    for(int i=0;i<r.size();i++){
        int len=r.size()-1;
        mp[r[i]]=r[len-i];
    }
    for(int i=0;i<s.size();i++){
        cout<<mp[s[i]];
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        encode();
    }
    return 0;
}