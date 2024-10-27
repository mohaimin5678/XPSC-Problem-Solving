#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ch[26]={0};
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        ch[s[i]-'a']++;
    }
    char ans='#';
    for(int i=0;i<26;i++){
        if(ch[i]==0){
            ans=i+'a';
            break;
        }
    }
    if(ans=='#') cout<<"None"<<'\n';
    else cout<<ans<<'\n';
    return 0;
}
//a=97