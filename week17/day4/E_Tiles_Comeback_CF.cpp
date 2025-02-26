#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,k;
    cin>>n>>k;
    map<int,int> mp;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        mp[v[i]]++;
    }
    if(k==1){
        cyes;
        return;
    }
    if(k==2){
        if(v[0]==v[n-1]){
            cyes;
            return;
        }
    }
    int leftneed=k,rightneed=k;
    if(v[0]==v[n-1]){
        leftneed/=2;
        rightneed-=leftneed;
    }
    int l=0,r=0;
    int left=0;
    for(int i=0;i<n;i++){
        if(v[i]==v[0]) l++;
        if(l==leftneed) break;
        left++;
    }
    int right=n-1;
    for(int i=n-1;i>=0;i--){
        if(v[i]==v[n-1]) r++;
        if(r==rightneed) break;
        right--;
    }
    if(left<right) cyes;
    else cno;
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
for k=1 & k=2 is easy to understand but then for the other values 
of k:- 
if first & last index's colour is same then we'll only check for
this one particular color path. thats why we splited them on half. 
we'll start checking from front for left need, from back for right
need. 
when both of them are fill up, we'll just break. 
since we are also counting first & last thats why we won't take the
condition breaking index (thats why both left++ & right++ are happening
after loop breaking condition). 
then if left stays lower than right that means enough colors index
are available to make the path so answer is YES. Else NO.

but if first & last index's color are not same then we'll check
for 2 colors (first index's color & last index's color) for K
amount. we'll start checking from front for left need which is equal
to K, from back for right need which is equal to K. 
when both of them are fill up, we'll just break. 
since we are also counting first & last thats why we won't take the
condition breaking index (thats why both left++ & right++ are happening
after loop breaking condition). 
then if left stays lower than right that means we can make 2 blocks
from these 2 colors. So answer is YES. Else NO.
*/
