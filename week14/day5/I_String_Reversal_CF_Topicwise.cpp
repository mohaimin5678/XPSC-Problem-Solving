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
    string s;
    cin>>s;
    string r=s;
    reverse(r.begin(),r.end());

    //storing every character's index into a vector.
    map<char,vector<int>> pos_s,pos_r;
    for(int i=0;i<n;i++){
        pos_s[s[i]].push_back(i);
        pos_r[r[i]].push_back(i);
    }
    // for(auto [x,y]:pos_s){
    //     cout<<x<<" --> ";
    //     for(int z:y) cout<<z<<" ";
    //     cout<<ln;
    // }
    // cout<<ln;
    // for(auto [x,y]:pos_r){
    //     cout<<x<<" --> ";
    //     for(int z:y) cout<<z<<" ";
    //     cout<<ln;
    // }
    // cout<<ln;

    vector<int> permutation(n);
    for(char c='a';c<='z';c++){
        for(int i=0;i<pos_s[c].size();i++){
            permutation[pos_r[c][i]]=pos_s[c][i];
        }
    }
    // for(int x:permutation) cout<<x<<" ";
    // cout<<ln;

    //inversion concept repeated
    pbds<int> p;
    ll ans=0;
    for(int i=n-1;i>=0;i--){
        // cout<<p.order_of_key(permutation[i])<<ln;
        ans+=p.order_of_key(permutation[i]);
        p.insert(permutation[i]);
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
they'll provide us a string. To make the given string into it's
reverse form, how many swap operations will be needed?
example: aaaza --1--> aazaa --2--> azaaa (revese form) so ans=2

observation: 
A= dbbkbk & reverse form B= kbkbbd
since our target is to make B from A in minimum operations so we
will start traversing from backward & check B[i]'s closest 
position in A string's backward position. We'll swap till the
equivalent position. lets demonstrate it to make it more clear:- 
   0 1 2 3 4 5
A= d b b k b k        3 5
                here, k k (B[0]=k & closest k from A is A[3]=k)
                          (B[2]=k & closest k from A is A[5]=k)
                same b is in 1 2 4 position in A & for B, B[1]=b
                so lets put A[1] there, then A[2] in B[3] & A[4]
                in B[4]
                Also d is in A[0] which will be in B[5]
B= k b k b b d
   3 1 5 2 4 0   --putting A's index position corresponding to B

now lets work on [3 1 5 2 4 0]
we know that A=[0 1 2 3 4 5]    since reverse of A=B & vice versa
             B=[3 1 5 2 4 0]    so we can try to make A from B &
                                calculate the operations. 
                         [3 1 5 2 4 0]
to place 0 on it's place=[0 3 1 5 2 4]  --> 5 operations
to place 1 on it's place=[0 1 3 5 2 4]  --> 1 operations
to place 2 on it's place=[0 1 2 3 5 4]  --> 2 operations
to place 3 on it's place=[0 1 2 3 5 4]  --> 0 operations
to place 4 on it's place=[0 1 2 3 4 5]  --> 1 operations
total 9 operations
as we can see that a value is swaping until it finds a bigger
value than itself. So we can use the inversion logic here.
cause: [3 1 5 2 4 0] <-- for 0 =(3,0)(1,0)(5,0)(2,0)(4,0)=5
                         for 1 =(3,1)=1
                         for 2 =(3,2)(5,2)=2
                         for 3 =0
                         for 4 =(5,4)=1     total 9 inversions

code approach:------
map<char,vector<int>> pos_s,pos_r;
for(int i=0;i<n;i++){
    pos_s[s[i]].push_back(i);
    pos_r[r[i]].push_back(i);
}
using this we stored a character's indexes proportionally. 
for original string we are getting: 
for(auto [x,y]:pos_s){
    cout<<x<<" --> ";
    for(int z:y) cout<<z<<" ";
    cout<<ln;
}
output: 
b --> 1 2 4 
d --> 0 
k --> 3 5 

for reverse string we are getting: 
for(auto [x,y]:pos_r){
    cout<<x<<" --> ";
    for(int z:y) cout<<z<<" ";
    cout<<ln;
}
output: 
b --> 1 3 4 
d --> 5 
k --> 0 2 

now we need to make the array on which we'll use our inversion logic. 
so we'll try to put position of original string into index of the
reverse string. 
vector<int> permutation(n);
for(char c='a';c<='z';c++){
    for(int i=0;i<pos_s[c].size();i++){
        permutation[pos_r[c][i]]=pos_s[c][i];
    }
}
demonstrate: 
permutation=[_ _ _ _ _ _]
FIRST c=='b'
pos_s[c].size()=3
now permutation[pos_r['b'][0]]==permutation[1] = pos_s['b'][0]==1
permutation[pos_r['b'][1]]==permutation[3] = pos_s['b'][1]==2
permutation[pos_r['b'][2]]==permutation[4] = pos_s['b'][2]==4
permutation=[_ 1 _ 2 4 _]
SECOND c=='d'
now permutation[pos_r['d'][0]]==permutation[5] = pos_s['d'][0]==0
permutation=[_ 1 _ 2 4 0]
THIRD c=='k'
now permutation[pos_r['k'][0]]==permutation[0] = pos_s['k'][0]==3
permutation[pos_r['k'][1]]==permutation[2] = pos_s['k'][1]==5
permutation=[3 1 5 2 4 0]

now we can do the inversion concept on permutation=[3 1 5 2 4 0]
ans=0;
3 1 5 2 4 0
          i     order_of_key(0)=0 so ans=0 & p=[0]
        i       order_of_key(4)=1 so ans=1 & p=[0 4]
      i         order_of_key(2)=1 so ans=1+1=2 & p=[0 2 4]
    i           order_of_key(5)=3 so ans=2+3=5 & p=[0 2 4 5]
  i             order_of_key(1)=1 so ans=5+1=6 & p=[0 1 2 4 5]
i               order_of_key(3)=3 so ans=6+3=9 & p=[0 1 2 3 4 5]
*/
