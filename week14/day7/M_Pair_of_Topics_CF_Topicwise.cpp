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
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    pbds<int> p;
    ll ans=0;
    for(int i=n-1;i>=0;i--){
        ans+=p.order_of_key(a[i]-b[i]);
        p.insert(b[i]-a[i]);
    }
    cout<<ans<<ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    t=1;
    while(t--){
        mohaimin();
    }
}
/*
since we need to find a[i]+a[j]>b[i]+b[j] which will take O(N^2) if we
tries to make all pair. 
So we'll solve this using pbds multiset. 
here they said a[i]+a[j]>b[i]+b[j]
              =a[i]-b[i]>b[j]-a[j]
              this is also correct. 
so we'll use a pbds & check how many values are less than (a[i]-b[i])
then we'll add (b[i]-a[i]) into pbds for further calculation. 
Why adding b[i]-a[i] ?
because this is the lesser part which we'll check. So this is basically
a different way to implement inversion count. 
testcase: 
5
4 8 2 6 2
4 5 4 1 3

ans=0
p.order_of_key(a[i]-b[i])=p.order_of_key(2-3)=p.order_of_key(-1)=0
so ans=0 & b[i]-a[i]=3-2=1 so p=[1 ]

p.order_of_key(a[i]-b[i])=p.order_of_key(6-1)=p.order_of_key(5)=1
so ans=1 & b[i]-a[i]=1-6=-5 so p=[-5 1 ]

p.order_of_key(a[i]-b[i])=p.order_of_key(2-4)=p.order_of_key(-2)=1
so ans=2 & b[i]-a[i]=4-2=2 so p=[-5 1 2 ]

p.order_of_key(a[i]-b[i])=p.order_of_key(8-5)=p.order_of_key(3)=3
so ans=5 & b[i]-a[i]=5-8=-3 so p=[-5 -3 1 2 ]

p.order_of_key(a[i]-b[i])=p.order_of_key(4-4)=p.order_of_key(0)=2
so ans=7 & b[i]-a[i]=4-4=0 so p=[-5 -3 0 1 2]
so final ans=7
*/