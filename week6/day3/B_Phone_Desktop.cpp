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
        int n,m;
        cin>>n>>m;
        int ans=(m+1)/2;
        if(ans==0){
            float rem=(n*1.0)/15;
            int remInt=rem;
            if(remInt==rem) cout<<ans+remInt<<endl;
            else cout<<ans+remInt+1<<endl;
        }
        else{
            int totalCell=ans*15;
            int remCell=totalCell-(m*4);
            if(n<=remCell) cout<<ans<<endl;
            else{
                int restN=n-remCell;
                float rem=(restN*1.0)/15;
                int remInt=rem;
                if(remInt==rem) cout<<ans+remInt<<endl;
                else cout<<ans+remInt+1<<endl;
            }
        }
    }
    return 0;
}