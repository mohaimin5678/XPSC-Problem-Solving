#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> lim(n);
    int mx=v[0];
    for(int i=0;i<n;i++){
        mx=max(mx,v[i]);
        lim[i]=mx;
    }
    int mx2=INT_MIN;
    ll need=0;
    for(int i=0;i<n;i++){
        need+=(lim[i]-v[i]);
        mx2=max(mx2,(lim[i]-v[i]));
    }
    cout<<need+mx2<<ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        mohaimin();
    }
}
/*
we took the maximum target for each value & checked how many op
it will be needed to make it go to the target so sum of all 
(target-cur)+max of (target-cur) will be our answer. 
why +max of (target-cur) also?
becuase to make v[i] goes to it's lim[i] we'll need at least
that lim[i]-v[i] amounts of operations. And when it has maximum
gap then to fill up that gap we'll need that gap amount added to
the answer also. 
example: 
testcase 4: 
9
344 12  37  60  311 613 365 328 675    -v
344 344 344 344 344 613 613 613 675    -lim
--------------------------------------
 0  332 307 284 33   0  248 285  0      need

so total op=332+307+284+33+248+285=1489 
now since every op cost op+1 so here highest op is 332 so we'll
add 332 times 1 to 1489 to find the final cost so the final 
answer will be 1489+332=1821. 
*/