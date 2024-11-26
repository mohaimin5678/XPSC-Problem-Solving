#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int op;
        cin>>op;
        string s;
        cin>>s;
        string t=s;
        reverse(t.begin(),t.end());
        if(s<=t) cout<<s<<endl;
        else cout<<t<<s<<endl;
    }
    return 0;
}