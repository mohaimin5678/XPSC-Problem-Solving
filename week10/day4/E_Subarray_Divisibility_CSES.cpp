#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    map<ll,int> mp;
    ll sum=0;
    int r=0;
    ll cnt=0;
    ll res;
    mp[0]=1;
    while(r<n){
        sum+=v[r];
        // res=((sum%n)+n)%n;
        cnt+=mp[((sum%n)+n)%n];
        // cnt+=mp[res];
        mp[((sum%n)+n)%n]++;
        
        r++;
    }
    cout<<cnt<<endl;
    return 0;
}
/*
((sum%n)+n)%n --> to handle the negative values too

Here out target is to see if any subarray can be divisible by n
our given testcase: 
5
3 1 2 7 4
now we know that the subarray 1 2 7=10%5==0
and that is the only subarray possible. 
But how can we get the answer? we'll use a map where we'll initially
put 0. because if sum%n directly then it needs to be counted too. 
ans=0+3= 3%5 =3 
mp= 0 3
ans=3+1= 4%5 =4
mp= 0 3 4
ans=4+2= 6%5 =1
mp= 0 1 3 4
ans=4+7= 13%5 =3
now map already has 3 on it, means if we can remove 3 from the
current sum then it'll be divisible by 5. like 13-3=10%5==0
so count=1;
mp= 0 1 3 3 4
ans=13+4= 17%5 =2
mp= 0 1 2 3 3 4
so count=1

*/