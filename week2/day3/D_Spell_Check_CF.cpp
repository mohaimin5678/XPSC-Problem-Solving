//https://codeforces.com/contest/1722
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(n!=5) cout<<"NO"<<endl;
        else{
            sort(s.begin(),s.end());
            if(s=="Timru") cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}