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
        ll n;
        cin>>n;
        vector<ll> pos;
        for(ll i=32;i>=0;i--){
            if((n>>i)&1){
                pos.push_back(1);
            }
            else pos.push_back(0);
        }
        // for(int val:pos) cout<<val<<" ";
        // cout<<endl;
        ll ones=0,cnt=0;
        for(int i=0;i<pos.size();i++){
            if(pos[i]==1){
                if(ones<2) ones++;
            }
            else if(pos[i]==0 && ones==2) cnt++;
        }
        ll x=(1<<cnt);
        cout<<x<<endl;
        
    }
    return 0;
}
/*
suppose we have 24=[11000]
here after first 2 MSB there is three 0
one case can be: 
10100 = 20
01100 = 12
-----   XOR
11000 = 24

10010 = 18
01010 = 10
-----   XOR
11000 = 24

10001 = 17
01001 = 9
-----   XOR
11000 = 24

10011 = 19
01011 = 11
-----   XOR
11000 = 24

10110 = 22
01110 = 14
-----   XOR
11000 = 24

10101 = 21
01101 = 13
-----   XOR
11000 = 24

10000 = 16
01000 = 8
-----   XOR
11000 = 24

10111 = 23
01111 = 15
-----   XOR
11000 = 24

total 8 possible pairs less than 24,0
*/