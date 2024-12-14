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
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        int bits[30]={0};
        for(int i=0;i<30;i++){
            ll num=(1LL<<i);
            for(int j=0;j<n;j++){
                if((v[j]&num)!=0) bits[i]++;
            }
        }
        for(int k=1;k<=n;k++){
            bool flag=true;
            for(int i=0;i<30;i++){
                if(bits[i]%k!=0){
                    flag=false;
                    break;
                }
            }
            if(flag) cout<<k<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
testcase:
4
13 7 25 19
for k=1,
x=v[i] so v[i]=v[i]-x
x=13 so v[i]=13-13=0
x=7 so v[i]=7-7=0
x=25 so v[i]=25-25=0
x=19 so v[i]=19-19=0
for k=2
lets x=v[0]&v[3]=13&19=1 so v[0]=13-1=12 v[3]=19-1=18
so v=[12 7 25 18]
again lets x=v[2]&v[3]=25&18=16 so v[2]=25-16=9 v[3]=18-16=2
so v=[12 7 9 2]
again lets x=v[0]&v[2]=12&9=8 so v[0]=12-8=4 v[2]=9-8=1
so v=[4 7 1 2]
again lets x=v[0]&v[1]=4&7=4 so v[0]=4-4=0 v[1]=7-4=3
so v=[0 3 1 2]
again lets x=v[1]&v[2]=3&1=1 so v[1]=3-1=2 v[2]=1-1=0
so v=[0 2 0 2]
again lets x=v[1]&v[3]=2&2=2 so v[1]=2-2=0 v[3]=2-2=0
so finally v=[0 0 0 0]

this is a very critical process & we don't know how we can choose
which pair. so lets try this approach
01101  -->13
00111  -->7
11001  -->25
10011  -->19
-------
22224  -->counts of on value per bits

for k=1, we can divisible all of this so ans=[1 ]
for k=2, we can divisible all of this counts so ans=[1 2]
for k=3, we can't divisible all so next
for k=4, we can't divisible all
k<=n so loop break. 
this is the shortest way to solve this problem. 
if there are enough frequency on a particular bit which can be
divisible by k, then its doesn't matter how many operation k will
be needed to make all of them zero, but it will make them zero. 
but if its not divisible by k, means atleast 1 or few bits will 
still remain on after several operations. so it won't be able to
make all numbers 0. 
*/