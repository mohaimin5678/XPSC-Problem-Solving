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
        if(n%2==1) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++){
                if(i%2==0) cout<<"AA";
                else cout<<"AB";
            }
            cout<<endl;
        }
    }
    return 0;
}