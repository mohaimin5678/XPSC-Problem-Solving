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
        int m=(n*(n-1))/2;
        vector<int> v(m);
        int mx=INT_MIN;
        for(int i=0;i<m;i++){
            cin>>v[i];
            mx=max(mx,v[i]);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<m;){
            cout<<v[i]<<" ";
            n--;
            i+=n;
        }
        cout<<mx<<endl;
    }
    return 0;
}