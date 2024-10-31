#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(s.size()==1){
            char c=s[0];
            if(c=='z') cout<<c<<'y'<<'\n';
            else cout<<c<<char(c+1)<<'\n';
        }
        else{
            int freq[26]={0};
            for(int i=0;i<s.size();i++){
                freq[s[i]-'a']++;
            }
            char distinct;
            for(int i=0;i<26;i++){
                if(freq[i]==0){
                    distinct=i+'a';
                    break;
                }
            }
            string p1="",p2="";
            bool flag=false;
            for(int i=1;i<s.size();i++){
                if(s[i]==s[i-1]){
                    flag=true;
                    p1=s.substr(0,i);
                    p2=s.substr(i);
                    break;
                }
            }
            if(flag) cout<<p1<<distinct<<p2<<'\n';
            else cout<<s<<distinct<<'\n';
        }
    }
    return 0;
}