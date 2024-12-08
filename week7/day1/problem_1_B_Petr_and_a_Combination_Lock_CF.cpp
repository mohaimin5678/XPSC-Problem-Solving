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
    for(int i=0;i<n;i++) cin>>v[i];
    bool flag=false;
    for(int mask=0;mask<(1<<n);mask++){  //left shifting to find the power
        ll sum=0;
        for(int k=0;k<n;k++){
            if((mask>>k)&1){   //to check if the bit is on or off
                sum+=v[k];
            }
            else sum-=v[k];
        }
        if(sum%360==0){
            flag=true;
            break;
        }
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}