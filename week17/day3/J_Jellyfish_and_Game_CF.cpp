#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,m,k;
    cin>>n>>m>>k;
    multiset<int> x,y;
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        x.insert(v);
    }
    for(int i=0;i<m;i++){
        int v;
        cin>>v;
        y.insert(v);
    }
    for(int i=1;i<=min(50,k);i++){
        if(i%2==1){
            int a=*x.begin();   //smallest
            int b=*y.rbegin();  //largest
            if(a<b){
                auto it=x.begin();
                x.erase(it);
                x.insert(b);

                auto it2=y.end();
                --it2;
                y.erase(it2);
                y.insert(a);
            }
        }
        else{
            int a=*x.rbegin();  //largest
            int b=*y.begin();   //smallest
            if(a>b){
                auto it=x.end();
                --it;
                x.erase(it);
                x.insert(b);

                auto it2=y.begin();
                y.erase(it2);
                y.insert(a);
            }
        }
    }
    if(k>50){
        if((k-50) & 1){
            int a=*x.begin();   //smallest
            int b=*y.rbegin();  //largest
            if(a<b){
                auto it=x.begin();
                x.erase(it);
                x.insert(b);

                auto it2=y.end();
                --it2;
                y.erase(it2);
                y.insert(a);
            }
        }
    }
    ll sum=0;
    for(int val:x){
        sum+=val;
    }
    cout<<sum<<ln;
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
if we check carefully then we'll see that these 2 person are swapping
the min element & max element. 
also constraint can be highest 50 for both n,m so we don't need to
check for more than 50 (cause after 50, all swapping result will be
same). 
So we'll swap till min(k,50) but 50 is an even turn which will favor
2nd person even if K is an odd value! so if K>50 then we'll check 
the remaining turns(k-50) is odd or not. if odd, then we'll do
1 more operation which is swapping 1st person's smallest with 2nd
person's largest. And then we'll just print the sum. 
*/