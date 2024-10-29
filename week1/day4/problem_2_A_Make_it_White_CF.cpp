#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int f=-1,l=-1;
        int n;
        cin>>n;
        string s;
        cin>>s;
        f=s.find('B');
        l=s.rfind('B');
        int res=l-f+1;
        cout<<res<<'\n';
    }
    return 0;
}