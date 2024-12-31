#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int q;
    cin>>q;
    while(q--){
        int key;
        cin>>key;
        int l=0,r=n-1,mid,ans=-1;
        while(l<=r){
            mid=(l+r)/2;
            if(v[mid]<=key){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        cout<<ans+1<<endl;
    }
    return 0;
}