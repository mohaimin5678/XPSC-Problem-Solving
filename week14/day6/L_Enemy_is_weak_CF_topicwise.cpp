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
    vector<int> sec;
    pbds<int> p;
    for(int i=n-1;i>=0;i--){
        sec.push_back(p.order_of_key(v[i]));
        p.insert(v[i]);
    }
    reverse(sec.begin(),sec.end());
    // for(int x:sec) cout<<x<<" ";
    // cout<<ln<<ln;
    ll ans=0;
    pbds<int> p2;
    for(int i=0;i<n;i++){
        if(i==0){
            p2.insert(v[i]);
        }
        else{
            ll less=p2.order_of_key(v[i]);
            ll big=(1LL*p2.size())-less;
            ans+=(big*sec[i]*1LL);
            p2.insert(v[i]);
        }
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
we have to do inversion count twice because they want i<j<k & Vi>Vj>Vk
so initially we'll do j<k & Vj>Vk inversion count. 
then we'll save those counts into an inversion count array. Since we're
pushing values from behind so we need to reverse the array after doing
the first inversion count. 

then for i<j & Vi>Vj , we'll take another pbds & initially we'll put
v[0] in there. then from 1 to n-1, we'll check how many lesser values
are in the pbds p2. If we remove lesser value amount from p2's size,
we'll get bigger values than v[i]. Now we also know the inversion 
count of v[i] from inversion count array. So to make triplets we can 
simply do (bigger values * v[i]'s inversion count) which is the total
amount of triplets we can make by using v[i]

example: 
7
11 3 8 4 2 9 6

inversion array: 6 1 3 1 0 1 0          sec vector

ans=0                                               ans+=(big*sec[i])
i=0 & v[0]=11 so p2=[11 ]
i=1 & v[1]=3 p2.order_of_key(3)==0 so  less=0,big=1 ans=0+(1*1)=1
p2=[3 11]

i=2 & v[2]=8 p2.order_of_key(8)==1 so  less=1,big=1 ans=1+(1*3)=4
p2=[3 8 11]

i=3 & v[3]=4 p2.order_of_key(4)==1 so  less=1,big=2 ans=4+(2*1)=6
p2=[3 4 8 11]

i=4 & v[4]=2 p2.order_of_key(2)==0 so  less=0,big=4 ans=6+(4*0)=6
p2=[2 3 4 8 11]

i=5 & v[5]=9 p2.order_of_key(9)==4 so  less=4,big=1 ans=6+(1*1)=7
p2=[2 3 4 8 9 11]

i=6 & v[6]=6 p2.order_of_key(6)==3 so  less=3,big=3 ans=7+(3*0)=7
p2=[2 3 4 6 8 9 11]

so final ans=7


*/