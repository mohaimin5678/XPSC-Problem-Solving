//https://codeforces.com/contest/1791
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
        int ans=n;
        int i=0,j=n-1;
        while(i<j){
            if(s[i]!=s[j]) ans-=2;
            else break;
            i++;
            j--;
        }
        cout<<ans<<endl;
    }
    return 0;
}