#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int cnt=0;
    int l=0,r=0;
    ll sum=0;
    while(r<n){
        sum+=v[r];
        if(sum==k) cnt++;
        else if(sum>k){
            while(sum>k){
                sum-=v[l];
                l++;
            }
            if(sum==k) cnt++;
        }
        r++;
    }
    cout<<cnt<<endl;
    return 0;
}
/*
variable size sliding window
*/