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
    int ans=0, sz=0;
    while(n){
        if(n%10==7){    //ends with 7
            ans+=(1<<sz);
        }
        n/=10;
        sz++;
    }
    for(int i=1;i<sz;i++){
        ans+=(1<<i);
    }
    ans++;
    cout<<ans<<endl;
    return 0;
}
/*
suppose we have n=477 (they will only give us lucky number)
so we will get 4,7,44,47,74,77,444,447,474,477 total=10
sz=0;
n%10=7 == 7 so ans+=(1<<0) so ans+=2^0 means ans+=1 now ans=1;
n/=10 so n=47 & sz++; now sz=1;
n%7=7 == 7 so ans+=(1<<1) so ans+=2^1 means ans+=2 now ans=3;
n/=10 so n=4 & sz++; now sz=2;
n%10=4 != 7 so no change and ans=3;
n/=10 so n=0 & sz++; now sz=3;
while loop break;

now i=1<3
ans+=(1<<i) so ans+=2^1 means ans+=2 now ans=5;
now i=2<3
ans+=(1<<i) so ans+=2^2 means ans+=4 now ans=9;
for loop break;

now we need to include the given lucky number also into the answer
so ans++;
now ans=10;
*/