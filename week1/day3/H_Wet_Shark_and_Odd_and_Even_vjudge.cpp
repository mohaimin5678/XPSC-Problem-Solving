#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    ll ans=0;
    vector<int> odd;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]%2==0) ans+=v[i];
        else odd.push_back(v[i]);
    }
    int sz=odd.size();
    if(sz%2==0){
        for(int i=0;i<sz;i++){
            ans+=odd[i];
        }
    }
    else{
        sort(odd.begin(),odd.end(),greater<int>());
        sz--;
        for(int i=0;i<sz;i++){
            ans+=odd[i];
        }
    }
    cout<<ans<<'\n';
    return 0;
}