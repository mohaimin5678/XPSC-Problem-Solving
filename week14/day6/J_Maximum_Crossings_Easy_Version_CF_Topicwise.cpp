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
// template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//for multiset
template <typename T> using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void mohaimin(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    pbds<int> p;
    int ans=0;
    for(int i=n-1;i>=0;i--){
        ans+=p.order_of_key(v[i]+1);
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
observation: the amount of smaller values will be on the right side,
each of them can make a cross. Since we wants to maximize that so we'll
also include equal values on the right side too. 
so here we can do inversion count. cause in inversion count, we check
how many smaller values are on the right side by using order_of_key()
function. so to find smaller+equal we'll check order_of_key(v[i]+1)
which will also include equal values too. 
testcase: 
7
4 1 4 6 7 7 5
            i       order_of_key(5+1)=order_of_key(6)=0 ans=0+0=0
          i         order_of_key(7+1)=order_of_key(8)=1 ans=0+1=1
        i           order_of_key(7+1)=order_of_key(8)=2 ans=1+2=3
      i             order_of_key(6+1)=order_of_key(7)=1 ans=3+1=4
    i               order_of_key(4+1)=order_of_key(5)=0 ans=4+0=4
  i                 order_of_key(1+1)=order_of_key(2)=0 ans=4+0=4
i                   order_of_key(4+1)=order_of_key(5)=2 ans=4+2=6
final ans=6  
*/