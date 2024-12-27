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
        vector<int> v(n+1);
        map<int,int> mp;
        for(int i=1;i<=n;i++){
            cin>>v[i];
            mp[v[i]]=i;
        }
        int mx=INT_MIN;
        for(auto a:mp){
            for(auto b:mp){
                // cout<<a.first<<" "<<a.second<<" --- ";
                // cout<<b.first<<" "<<b.second<<endl;
                if(__gcd(a.first,b.first)==1){
                    mx=max(mx,a.second+b.second);
                }
            }
        }
        if(mx==INT_MIN) cout<<-1<<endl;
        else cout<<mx<<endl;
    }
    return 0;
}