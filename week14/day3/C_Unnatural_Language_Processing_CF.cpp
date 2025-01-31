#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
// a,e == V     b,c,d==C        CV || CVC
void mohaimin(){
    int n;
    string s;
    cin>>n>>s;
    string a;
    for(int i=0;i<n;i++){
        if(s[i]=='a' || s[i]=='e') a.push_back('V');
        else a.push_back('C');
    }
    // cout<<a<<ln;
    string ans;
    for(int i=0;i<n;){
        if(i+3<n){
            if(a[i+2]==a[i+3]){
                ans.push_back(s[i]);
                ans.push_back(s[i+1]);
                ans.push_back(s[i+2]);
                ans.push_back('.');
                i+=3;
            }
            else{
                ans.push_back(s[i]);
                ans.push_back(s[i+1]);
                ans.push_back('.');
                i+=2;
            }
        }
        else{
            ans.push_back(s[i]);
            ans.push_back(s[i+1]);
            if(i+2<n){
                ans.push_back(s[i+2]);
                i++;
            }
            i+=2;
        }
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
