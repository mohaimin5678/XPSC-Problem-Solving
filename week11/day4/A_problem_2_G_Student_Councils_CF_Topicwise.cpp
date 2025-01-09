#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    ll k;
    int n;
    cin>>k>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    // sort(v.begin(),v.end(),greater<int>());
    // for(auto x:v) cout<<x<<" ";
    
    auto check=[&](ll groups){
        ll cnt=groups*k;
        for(int i=0;i<n;i++){
            cnt-=min(groups,v[i]);
        }
        return cnt<=0;
    };

    ll l=1,r=1e11,mid,ans=0;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    mohaimin();
    return 0;
}

/*
testcase: 
4 6
1 2 3 4 5 6

now to make councils consist of 4 different student, we'll check
how many student each group can provide.
group 1: 1 student only which is less than demanding so 1
group 2: 2 students only which is less than demanding so 2 
group 3: 3 students only which is less than demanding so 3 
group 4: 4 students which is equal to demand so 4
group 5: 5 students which is > demand so take only 4 as per demand
group 6: 6 students which is > demand so take only 4 as per demand

so total students for making councils=1+2+3+4+4+4=18
now suppose mid=4 then groups in check function is also 4
now total seats=groups*k(students per group)=4*4=16
since 18>16 OR we can say 16-18<=0 so we can create 4 groups or
councils consisting of 4 students per group. 

in check function we'll supply council numbers & then we'll 
calculate the seat numbers. Then we'll check for all the values 
of the vector that who is minimum? the v[i] or k, whoever is 
minimum, will take seats. After completing the vector loop, if 
seats become <=0 that means the numbers of councils consisting 
of K students can be made. 

if we can make it with the mid, then we'll search for more on 
right to find if more groups can be made consisting of K students. 
if we can't make it with the mid, then we'll search for more on
the left side to find the number of groups. 

now l=1 as the lowest. 
r=1e11 is because suppose n=50, k=2 & all v[i]=10^9
then highest amount can be 2*50*10^9=10^11. 
*/