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
        int n;
        cin>>n;
        vector<int> v(n);
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            cin>>v[i];
            mn=min(mn,v[i]);
        }
        int ans=mn;
        for(int i=0;i<n;i++){
            ans&=v[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}