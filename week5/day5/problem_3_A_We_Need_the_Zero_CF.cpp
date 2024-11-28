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
        int sum;
        if(n==1){
            sum=v[0];
            cout<<sum<<endl;
        }
        else if(n%2==1){
            for(int i=1;i<n;i++){
                if(i==1){
                    sum=(v[i-1]^v[i]);
                }
                else{
                    sum=sum^v[i];
                }
            }
            if(sum>256) cout<<-1<<endl;
            else cout<<sum<<endl;
        }
        else{
            for(int i=1;i<n;i++){
                if(i==1){
                    sum=(v[i-1]^v[i]);
                }
                else{
                    sum=sum^v[i];
                }
            }
            if(sum==0) cout<<v[n-1]<<endl;
            else cout<<-1<<endl;
        }
    }
    return 0;
}