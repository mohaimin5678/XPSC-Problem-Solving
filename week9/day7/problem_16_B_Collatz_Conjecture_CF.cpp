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
        ll x,y,k;
        cin>>x>>y>>k;
        while(k && x!=1){
            ll nxt=((x/y)+1)*y;
            ll dis=nxt-x;
            if(dis<=k){
                k-=dis;
                x+=dis;
            }
            else{
                x+=k;
                k=0;
            }
            while(x%y==0){
                x/=y;
            }
        }
        cout<<x+k%(y-1)<<endl;
    }
    return 0;
}
/*
testcase: 
24 5 5
ll nxt=((x/y)+1)*y; = 25
dis=25-24=1
k=5-1=4
x=24+1=25
now,
while(x%y==0){
    x/=y;
}
25/5=5
5/5=1
since x=1,
now we still got k=4
so x+k=1+4=5%(y-1)=5%(5-1)=5%4=1
why this as the final answer?
because from 1->2->3->4->5 & the moment we'll went on 5, it will
get divided by y again & the answer will be 1. 
so basically 1->2->3->4->1.
thats why we are keeping x+k%(y-1) as the final answer.
*/