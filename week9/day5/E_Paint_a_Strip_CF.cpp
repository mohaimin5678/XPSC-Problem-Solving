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
        if(n==1 || n==2) cout<<n<<endl;
        else{
            ll cnt=1;
            ll start=1;
            while(start<n){
                start*=2;
                start+=2;
                cnt++;
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}
/*
n=1 then type1=1

n=2 then type1=2

n=4 then type1=2 how? 
1 0 0 1
l     r
ceil((r-l+1)/2)=2 & total sum of element is also 2. 
so in that range, all will be 1. 
1 1 1 1 ---> with only 2 type1 operation. 

n=10 then, 
1 0 0 1 0 0 0 0 0 0
initially using 2 type1 operation to make 1st & 4th position 1. Now,
1 0 0 1 0 0 0 0 0 0
l     r
ceil((r-l+1)/2)=2 & total sum of element is also 2. 
so in that range, all will be 1. 
1 1 1 1 0 0 0 0 0 0
now if we take 1st & 9th as l & r, we have to use type1 operation to
make 9th position 1. Which will make the range sum=5. But if we take
10th position instead of 9th, it will also make the range sum 5. 
1 1 1 1 0 0 0 0 0 1     --> range sum =5
l                 r     --> ceil((r-l+1)/2)=5
so all of them in that range will be 1. 
1 1 1 1 1 1 1 1 1 1
we used type1 operation 3 times. for 1st, 4th & 10th. 

n=20 then,
intially using 2 type1 to make 1st & 4th position 1. 
1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
l     r
ceil((r-l+1)/2)=2 & total sum of element is also 2. 
so in that range, all will be 1. 
1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
since we already have the range sum 4 & if we use a type1 operation
from 5th to 20th, the sum will be 5. We know if we have range sum 5
we can easily make a 1 to 10 range filled up with 1. 
Because (10-1+1)/2=5. So lets make 10th position 1 using the type1 
operation & use it as r. 
1 1 1 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0     --> range sum=5
l                 r                         --> (r-l+1)/2=5
so,
1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0
now range sum is 10. so if we take any other position from 11 to 20th,
the range sum will be 11. And with this range sum we can make 11*2=22
position 1. But since we have 20 as our highest position, lets take it
as r using type1 operation. 
1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 1     --> range sum=11
l                                     r     --> (20-1+1)/2=10 <=11
so lets make all the remaining positions from 0 to 1 till 20. 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
now to make all of them 1, we had to use the typ1 operation 4 times. 
for 1st, 4th, 10th, 20th. Answer. 
*/