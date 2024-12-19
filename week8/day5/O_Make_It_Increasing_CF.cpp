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
        for(int i=0;i<n;i++) cin>>v[i];
        
        int cnt=0;
        bool flag=false;
        for(int i=n-2;i>=0;i--){
            while(v[i]>=v[i+1] && v[i]>0){
                v[i]/=2;
                cnt++;
            }
            if(v[i]==v[i+1]){   //means both are 0
                flag=true;
                break;
            }
        }
        if(flag) cout<<-1<<endl;
        else cout<<cnt<<endl;
    }
    
    return 0;
}
/*
target is to get a strictly incrasing array
to get it, we have to traverse from the back & use an inner while
loop until the v[i] is lower than its next value which is v[i+1]
& the value can't be 0 on while loop because otherwise it will go
to infinite loop. This is where -1 comes in! if we see v[i]==v[i+1]
then it means even after performing while loop, it didn't become
less than v[i+1]. So it won't become a strictly increasing array. 
so we'll print -1. 
testcase 5:
4
2 8 7 5
v[2]>=v[3] so 7/2=3<5 & cnt=1
v=2 8 3 5
now v[1]>=v[2] so 8/2=4 --> 4/2=2<3 & cnt+=2 so cnt=3
v=2 2 3 5
now v[0]==v[1] so 2/2=1<2 & cnt++ so cnt=4 (final)

testcase 2: 
4
5 3 2 1
v[2]>=v[3] so 2/2=1 & 1/2=0<1 & cnt=1;
v=5 3 0 1
now v[1]>=v[2] so 3/2=1 & 1/2=0 but v[1]==v[2] where both are 0
so flag is true & we can't make it strictly increasing. 
v=5 0 0 1
ans=-1
*/