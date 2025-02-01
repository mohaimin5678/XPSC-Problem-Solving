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
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int l=0,r=0;
    pbds<pair<int,int>> p;
    while(r<n){
        p.insert({v[r],r});
        if(r-l+1==k){
            int x;
            if(k%2==0) x=(k/2)-1;   //even's median
            else x=k/2;             //odd's median
            auto it=p.find_by_order(x);
            auto pa=*it;
            cout<<pa.first<<" ";
            p.erase({v[l],l});
            l++;
        }
        r++;
    }
    cout<<ln;
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
need to find median of a window size K. if K is even then there 
will be two median & we'll take the smaller one. To find 
median, the array needs to be sorted. But here we can't sort it
initially. We need to sort the K range & find that particular 
range's median. 
observation: To get an automatic sorted range & that range's middle
element, we can use pbds set. Because we'll be needed to erase the
contribution(sliding window technique) but in pbds multiset, we 
can't do that. 

testcase:
8 3
2 4 3 5 8 1 2 1

0 1 2 3 4 5 6 7     --index
l=0,r=0;
p.insert({v[r],r});
p= {2,0}

l=0,r=1;
p.insert({v[r],r});
p= {2,0}
   {4,1}

l=0,r=2;
p.insert({v[r],r});
p= {2,0}
   {3,2}
   {4,1}    r-l+1==3==k so find_by_order(k/2) & print 3
            also remove {2,0} & l++

l=1,r=3;
p.insert({v[r],r});
p= {3,2}
   {4,1}
   {5,3}    r-l+1==3==k so find_by_order(k/2) & print 4
            also remove {4,1} & l++

l=2,r=4;
p.insert({v[r],r});
p= {3,2}
   {5,3}
   {8,4}    r-l+1==3==k so find_by_order(k/2) & print 5
            also remove {3,2} & l++

l=3,r=5;
p.insert({v[r],r});
p= {1,5}
   {5,3}
   {8,4}    r-l+1==3==k so find_by_order(k/2) & print 5
            also remove {5,3} & l++

l=4,r=6;
p.insert({v[r],r});
p= {1,5}
   {2,6}
   {8,4}    r-l+1==3==k so find_by_order(k/2) & print 2
            also remove {8,4} & l++

l=5,r=7;
p.insert({v[r],r});
p= {1,5}
   {1,7}
   {2,6}    r-l+1==3==k so find_by_order(k/2) & print 1
            also remove {1,5} & l++

r==n loop break;
so printed result: 3 4 5 5 2 1
*/
