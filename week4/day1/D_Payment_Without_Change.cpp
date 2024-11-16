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
        ll numX,num1,x,sum;
        cin>>numX>>num1>>x>>sum;
        if(x>sum && numX!=0){
            if(sum<=num1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else{
            if(x==sum && numX!=0) cout<<"YES"<<endl;
            else if(x==sum && numX==0){
                if(sum<=num1) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else{
                if(x*numX==sum) cout<<"YES"<<endl;
                else if(x*numX<sum){
                    sum-=(x*numX);
                    if(sum<=num1) cout<<"YES"<<endl;
                    else cout<<"NO"<<endl;
                }
                else{
                    ll val=(sum/x);
                    sum-=(val*x);
                    if(sum<=num1) cout<<"YES"<<endl;
                    else cout<<"NO"<<endl;
                }
            }
        }
    }
    return 0;
}