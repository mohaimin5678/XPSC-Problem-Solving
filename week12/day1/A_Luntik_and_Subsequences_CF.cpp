#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    int n;
    cin>>n;
    vector<int> v(n);
    ll zero=0,one=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]==0) zero++;
        if(v[i]==1) one++;
    }
    ll zerosCombination=(1LL<<zero);
    ll total=zerosCombination*one;
    cout<<total<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) mohaimin();
    return 0;
}
/*
testcase 4: 
5
3 0 2 1 1
zero=1, one=2
so 2^zero==2^1==2
total=2*one=2*2=4
 
testcase 5: 
5
2 1 0 3 0
zero=2, one=1
so 2^zero==2^2==4
total=2*one=4*1=4
*/