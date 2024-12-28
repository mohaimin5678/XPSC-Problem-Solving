#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        ll sum=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            sum+=v[i];
        }
        // cout<<sum<<endl;
        ll mx=INT_MIN;
        ll running=0;
        for(int i=0;i<n-1;i++){
            running+=v[i];
            mx=max(mx,__gcd(running,sum-running));
        }
        cout<<mx<<endl;
    }
    return 0;
}
/*
testcase:
6
1 2 1 1 1 3

we can identify that there is no need to make 3 subset to make
the gcd higher. Only 2 subset is enough & the possibility can be
higher. 
so lets check how to maximize the gcd of both subset. 
i=0
s1=1 & s2=9-1=8 gcd(1,8)=1 ---> mx=1

i=1
s1=1+2=3 & s2=9-3=6 gcd(3,6)=3 ---> mx=3

i=2
s1=3+1=4 & s2=9-4=5 gcd(4,5)=1 ---> mx=3

i=3
s1=4+1=5 & s2=9-5=4 gcd(5,4)=1 ---> mx=3

i=4
s1=5+1=6 & s2=9-6=3 gcd(6,3)=3 ---> mx=3

no need to check the last part, because if we do then we'll 
remove all contribution from the sum & it will provide wrong 
answer. 
*/