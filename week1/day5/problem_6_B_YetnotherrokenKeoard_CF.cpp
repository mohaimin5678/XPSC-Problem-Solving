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
        int lastIdx=s.size()-1;
        int b=0;
        int B=0;
        string res;
        for(int i=lastIdx;i>=0;i--){
            if(s[i]>='a' && s[i]<='z' && s[i]!='b'){
                if(b==0) res.push_back(s[i]);
                else b--;
            }
            else if(s[i]>='A' && s[i]<='Z' && s[i]!='B'){
                if(B==0) res.push_back(s[i]);
                else B--;
            }
            else if(s[i]=='b') b++;
            else if(s[i]=='B') B++;
        }
        reverse(res.begin(),res.end());
        cout<<res<<'\n';
    }
    return 0;
}