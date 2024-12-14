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
        ll b,c,d;
        cin>>b>>c>>d;
        ll a=(c^d);
        if((a|b)-(a&c)==d) cout<<a<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
/*
testcase:
10 2 14

1010 -->10 
0010 -->2
1110 -->14

0010
1110
----- XOR
1100 -->12

 (12|10)-(12&2)
=14-0
=14 == d
*/