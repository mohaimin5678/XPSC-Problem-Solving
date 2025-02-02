#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace __gnu_pbds;
using namespace std;
//for set
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//for multiset
// template <typename T> using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void mohaimin(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    ll ans=0;
    pbds<int> p;
    for(int i=n-1;i>=0;i--){
        ans+=p.order_of_key(v[i]);
        p.insert(v[i]);
    }
    cout<<ans<<ln;
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
inversion: if i<j && v[i]>v[j] then count that pair. 
testcase: 
5
2 3 8 6 1

inversions are= (2,1) (3,1) (8,6) (8,1) (6,1) total=5

observation: we can solve this using order_of_key() cause it'll
return the counts of strictly less than the value. 
but to solve this using order_of_key() we need to traverse in 
reverse order. we'll count order_of_key(v[i]) & add it to the 
answer & then add v[i] into the pbds. So that for the next v[i]
it can contribute. To clearly understand lets check the process.
ans=0;
so 2 3 8 6 1
           i    order_of_key(1)=0 so ans=0 & p=[1]
         i      order_of_key(6)=1 so ans=1 & p=[1 6]
       i        order_of_key(8)=2 so ans=1+2=3 & p=[1 6 8]
     i          order_of_key(3)=1 so ans=3+1=4 & p=[1 3 6 8]
   i            order_of_key(2)=1 so ans=4+1=5 & p=[1 2 3 6 8]
*/
