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
    vector<pair<int,int>> zero,one;
    set<int> a,b;
    while(n--){
        int x,y;
        cin>>x>>y;
        if(y==0){
            zero.push_back({x,y});
            a.insert(x);
        }
        else{
            one.push_back({x,y});
            b.insert(x);
        }
    }
    sort(zero.begin(),zero.end());
    sort(one.begin(),one.end());
    // for(auto [x,y]:one){
    //     cout<<x<<" "<<y<<ln;
    // }
    ll cnt=0;
    int l=0,r=0;
    while(l<zero.size() && r<one.size()){
        if(zero[l].first==one[r].first){
            // cnt+=(one.size()-1);
            cnt+=l;
            cnt+=r;
            cnt+=(zero.size()-l-1);
            cnt+=(one.size()-r-1);
            l++,r++;
        }
        else if(zero[l].first<one[r].first) l++;
        else if(one[r].first<zero[l].first) r++;
    }
    for(int x:a){
        int f=x-1,s=x+1;
        if(b.find(f)!=b.end() && b.find(s)!=b.end()){
            cnt++;
        }
    }
    for(int x:b){
        int f=x-1,s=x+1;
        if(a.find(f)!=a.end() && a.find(s)!=a.end()){
            cnt++;
        }
    }
    cout<<cnt<<ln;
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
since we need to make triangle with 90∘ on it, 
we can check if we get {x,0} & {x,1} on two pair vectors. when we find
then we'll just calculate count. And we'll break the loop if any of l/r
reach their corresponding size limit. 

now first we'll calculate for lower side(0's side), so we'll check how 
many triangle we can make on left(means current l's value since its 0-based)
& how many triangle we can make on right(means size-l-1 since its 0-based)
then add both of them to count. 
same for upper side(1's side) just the change is now we'll calculate with
r. then add both of them to count too. 

now for 2 more type of triangle shape remains to calculate!
they are:       __      &       
                \/              /_\

for first type of triangle: 
we'll take a value from A set(0's side) & check value-1 & value+1 both
are exists on B set(1's side). if they are exists then we can make first
type of triangle with this 3 position. so count++;

for second type of triangle: 
we'll take a value from B set(1's side) & check value-1 & value+1 both
are exists on A set(0's side). if they are exists then we can make second
type of triangle with this 3 position. so count++;

after counting all possible triangle counting, we'll just print the count. 
*/
