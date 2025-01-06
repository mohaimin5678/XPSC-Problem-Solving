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
        ll n;
        cin>>n;
        vector<int> a(n);
        ll sum=0;
        ll ones=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
            if(a[i]==1) ones++;
        }
        // cout<<sum<<endl;
        if(n==1 || sum==n) cout<<"NO"<<endl;
        else{
            ll sum2=sum-(ones*1LL*2);
            int idx=n-ones;
            if(sum2>=idx) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
/*
distribution is the main check here. 
testcase: 
12
1 2 1 2 1 3 1 2 1 1 1 2
total sum=18
total one=7
now if we need to substitute all 1, we'll need atleast 2 in
all 1's place. so total one will take 7*2=14 from total sum. 
now remaining sum=4
& remaining index=12-7=5
since we cant distribute 4 in 5 indexes so answer is NO. 

testcase: 
11
1 1 12 1 1 1 1 1 1 1 1
total sum=22
total one=10
now if we need to substitute all 1, we'll need atleast 2 in
all 1's place. so total one will take 10*2=20 from total sum. 
now remaining sum=2
& remaining index=11-10=1
since 2>1 so answer is YES. 
*/