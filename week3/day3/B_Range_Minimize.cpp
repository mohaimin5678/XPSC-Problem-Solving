#include<bits/stdc++.h>
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
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int tp1=v[n-1]-v[2];    //ignoring first 2 min value
        int tp2=v[n-3]-v[0];    //ignoring first 2 max value
        int tp3=v[n-2]-v[1];    //ignoring both min & max value
        int mn=min(tp1,tp2);
        int ans=min(mn,tp3);
        cout<<ans<<endl;
    }
    return 0;
}