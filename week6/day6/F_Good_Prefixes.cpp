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
        for(int i=0;i<n;i++) cin>>v[i];
        ll sum=0;
        int mx=0,cnt=0;
        for(int i=0;i<n;i++){
            if(mx<v[i]){
                sum+=mx;
                mx=v[i];
            }
            else sum+=v[i];

            if(sum==mx) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}