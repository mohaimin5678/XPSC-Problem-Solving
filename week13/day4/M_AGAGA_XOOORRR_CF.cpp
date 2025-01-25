#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n;
    cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    vector<int> prefixXor(n+1);
    prefixXor[0]=0;
    for(int i=1;i<=n;i++){
        prefixXor[i]=(prefixXor[i-1]^v[i]);
    }
    bool flag=false;
    //for 2
    for(int i=1;i<n;i++){
        int x=prefixXor[i];
        int y=(prefixXor[n]^prefixXor[i]);
        if(x==y){
            cyes;
            return;
        }
    }
    
    //for 3
    for(int i=1;i<n-1;i++){
        int x=prefixXor[i];
        for(int j=i+1;j<n;j++){
            int y=(prefixXor[j]^prefixXor[i]);
            int z=(prefixXor[n]^prefixXor[j]);
            if(x==y && y==z){
                cyes;
                return;
            }
        }
    }
    cno;
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
needed help from yt
but lets explain the approach here:--------

they want us to make a vector of equal elements where
atleast 2 elements exists. 
suppose we got equal vector E=[5 5 5 5]
then we can XOR on last two & 5^5=0 so E=[5 5 0]
and again we can XOR on last two & 5^0=5 so E=[5 5]
so here atleast 2 equal elements exists from an all 
equal vector. 

again suppose we got equal vector E=[5 5 5 5 5]
then we can XOR on last two & 5^5=0 so E=[5 5 5 0]
and again we can XOR on last two & 5^0=5 so E=[5 5 5]
and again we can XOR on last two & 5^5=0 so E=[5 0]
but here atleast 2 elements exists but they aren't equal. 
which is breaking our initial condition. 
so when we got E=[5 5 5], on that moment we have to stop
the XOR operations among the equal elements vector. 

now at first we saw E=[5 5]
where 1st 5 may carry the XOR result from 1 to X(elements)
& 2nd 5 may carry the XOR result from X+1 to N(elements)
so we can see that we are making 2 partitions among them
where we can loop through from start to X & another loop
through X+1 to end. Then check if their XOR results are
same or not. 

same as for E=[5 5 5]
where 1st 5 may carry the XOR result from 1 to X(elements)
2nd 5 may carry the XOR result from X+1 to Y(elements)
& 3rd 5 may carry the XOR result from Y+1 to N(elements)
so we can see that we're making 3 partitions among them
where we can loop through from start to X & another loop
through X+1 to Y & another loop through Y+1 to N. then
check if their XOR results are same or not. 


but these loop through will take more complexity as for
2 partitions it'll take O(N^2) & for 3 partitions it'll
take O(N^3). Now based on the constraint we can handle
up to O(N^2). So we can't check 3 partitions bruteforce
way. That is where the prefix XOR is coming. 
intially we'll save all the prefix XOR for each element. 

so for partition 2:- 
we'll take partition1=prefixXor[i] & to find the 2nd
partition we can simply remove the result of prefixXor[i]
from the final prefixXor[] value(which is prefixXor[n]).
here remove means XOR it from prefixXor[n].
so partition2=(prefixXor[n]^prefixXor[i]). 
if both partitions matches then YES. 

if not then lets check with partition 3:- 
we'll take partition1=prefixXor[i] & to find the 2nd 
partition we need to do a nested loop which will start
from i+1 & stops on n-1 (because partition 3 atleast 
need 1 value on it). And there the 2nd partition will be
the j's prefixXor after removing(XOR) the contribution 
of prefixXor[i]. Now partition2=(prefixXor[j]^prefixXor[i])
& to find the 3rd partition we can simply remove the 
result of prefixXor[j] from the final prefixXor[] value
(which is prefixXor[n]). 
so partition3=(prefixXor[n]^prefixXor[j]). 
if all three paritions matches then YES. 

if none of the 2 partitions or 3 partitions can't match
then the answer will be NO. 
*/