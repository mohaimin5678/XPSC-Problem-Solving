#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<ll> v(n+2);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        // v[i]=0;
    }
    vector<pair<pair<int,int>,ll>> store(m+2);
    for(int i=1;i<=m;i++){
        int l,r;
        ll d;
        cin>>l>>r>>d;
        // v[l]+=d;
        // v[r+1]-=d;
        store[i]={{l,r},d};
        // store.push_back({{l,r},d});
    }
    // for(int i=1;i<=n;i++){
    //     v[i]=v[i-1]+v[i];
    // }
    // for(int i=1;i<=n;i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<ln;
    vector<ll> s(m+2);
    while(k--){
        int x,y;
        cin>>x>>y;
        s[x]++;
        s[y+1]--;
    }
    for(int i=1;i<=m;i++){
        s[i]=s[i-1]+s[i];
    }
    for(int i=1;i<=m;i++){
        (store[i].second)*=s[i];
    }

    vector<ll> op(n+2);
    for(int i=1;i<=m;i++){
        // v[i]=v[i-1]+v[i];
        // cout<<v[i]<<" ";
        op[store[i].first.first]+=store[i].second;
        op[store[i].first.second+1]-=store[i].second;
    }
    for(int i=1;i<op.size();i++){
        op[i]=op[i-1]+op[i];
    }

    for(int i=1;i<=n;i++){
        v[i]+=op[i];
    }
    for(int i=1;i<=n;i++){
        cout<<v[i]<<" ";
    }
    cout<<ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    mohaimin();
    
}
/*
Here its a different type of "difference array" 
first they want us to perform M operations & then we 
need to do those operation K times where they'll give us
operation range!

Observation: We don't need to do M operation initially!
Lets store it first & then we'll check how many times
these operations we'll need to do. (On K queries)

Explanation: 
i) we initialize the vector & keep that as it is. 
ii) We made a pair<pair<int,int>,ll> vector to store the operations. 
    We did it with indexing because it will be needed. 
iii) We took another vector S to calculate the operations which 
    is given on K queries. We did the difference array concept 
    on this. After doing s[x]++ & s[y+1]--. We took the prefix 
    sum & by that now we can understand how many times we'll do 
    each operation. 
iv) Now that we know how many times we'll perform a particular 
    operation, we can simply do (d × times), which will make d 
    the same as if we had performed the operation that many times 
    separately.
v) Now we took a vector op to perform the operations using
   the difference array concept & after doing the operations we
   we'll calculate the prefix sum. 
vi) finally we'll add them with the initial vector v & that will
    the final answer.

testcase: 
3 3 3
1 2 3
1 2 1
1 3 2
2 3 4
1 2
1 3
2 3

v=[1 2 3]

store=[{{1 2},1}, {{1 3},2}, {{2 3},4}]
now K queries:- 
0 1  2  3  4
  1    -1
  1       -1
     1    -1
--------------
0 2  3  2 0    -->prefix sum
operations contribution which is s. so s=[2 3 2]

now lets change d's value on store vector using s. 
(store[i].second)*=s[i];
now store=[{{1 2},2}, {{1 3},6}, {{2 3},8}]

lets take op vector to do the operations: 
0 1  2  3  4
  2    -2
  6       -6
     8    -8
------------
0 8 16 14  0
so ans=[8 16 14]
     v=[1  2  3]
       ---------
     v=[9 18 17]    final answer
*/
