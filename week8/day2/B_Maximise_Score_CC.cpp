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
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            int x=0;
            if(i+1<n){
                x=max(x,abs(v[i+1]-v[i]));
            }
            if(i-1>=0){
                x=max(x,abs(v[i]-v[i-1]));
            }
            mn=min(x,mn);
        }
        cout<<mn<<endl;
    }
    return 0;
}