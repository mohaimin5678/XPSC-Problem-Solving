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
        int XOR=0;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            XOR^=v[i];
        }
        int ans=XOR;
        for(int i=0;i<n;i++){
            int val=(XOR^v[i]);
            ans=min(ans,val);
        }
        cout<<ans<<endl;
    }
    return 0;
}