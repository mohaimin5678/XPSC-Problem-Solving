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
    int l=0,r=0,u=0,d=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='L') l++;
        if(s[i]=='R') r++;
        if(s[i]=='U') u++;
        if(s[i]=='D') d++;
    }
    string ans="";
    int side=min(l,r);
    int tb=min(u,d);
    if(side==tb && side==0){
        cout<<ans.size()<<ln;
        cout<<ans<<ln;
        return;
    }
    else if(side==0){
        cout<<2<<ln;
        cout<<"UD"<<ln;
        return;
    }
    else if(tb==0){
        cout<<2<<ln;
        cout<<"LR"<<ln;
        return;
    }

    for(int i=1;i<=side;i++){
        ans.push_back('L');
    }
    for(int i=1;i<=tb;i++){
        ans.push_back('U');
    }
    for(int i=1;i<=side;i++){
        ans.push_back('R');
    }
    for(int i=1;i<=tb;i++){
        ans.push_back('D');
    }
    cout<<ans.size()<<ln;
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
/*
count their frequency & check left-right's minimum & up-down's 
minimum. if both's minimum 0 that means 0. If only side's min is
0 then answer will be UD. If only up-down's min is 0 then LR will
be the answer. If none from above then print:- 
i) min amount of L
ii) min amount of U
iii) min amount of R
iv) min amount of D
so that (0,0) doesn't occur until the string is finished. 
*/