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
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>v[i];
        mx=max(mx,v[i]);
    }
    int z=0;
    ll sum=0;
    for(int i=0;i<n;i++){
        z=__gcd(z,mx-v[i]);
        sum+=(mx-v[i]);
    }
    ll cnt=sum/z;
    
    cout<<cnt<<" "<<z<<endl;
    return 0;
}
/*
target is to check the lost swords. 
Observation: the target is to find the gcd of all lost amounts of each
types. 
testcase: 
3
3 12 6
suppose: all of them are 12 12 12
                         3  12  6
so the lost are:         9  0   6
so the gcd of losts are 3, means all of the theifs took 3 swords.(z)
now total lost are 15 & if we divide it, we'll found the number of
theifs.(y)
*/