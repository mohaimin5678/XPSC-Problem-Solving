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
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int ans=INT_MAX,sum=0;
        int l=0,r=0;
        while(r<n){
            sum+=v[r];
            if(sum==k){
                // cout<<sum<<" ";
                int rem=n-(r-l+1);
                ans=min(ans,rem);
            }
            else{
                while(sum>k){
                    sum-=v[l];
                    l++;
                }
                if(sum==k){
                    // cout<<sum<<" ";
                    int rem=n-(r-l+1);
                    ans=min(ans,rem);
                }
            }
            r++;
        }
        // cout<<endl;
        if(ans==INT_MAX) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}