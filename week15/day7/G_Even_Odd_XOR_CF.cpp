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
    if(n==3){
        cout<<"2 1 3"<<ln;
        return;
    }
    if(n%4==0){                     //CASE 1
        ll add=(1LL<<30);        
        ll cur=1;
        for(int i=1;i<=(n/2);i++){
            cout<<cur<<" "<<cur+add<<" "; 
            //making 1 on LMSB for even indices
            cur++;
        }
        cout<<ln;
    }
    else{
        if(n%2==1){
            ll addf=(1LL<<30);
            ll adds=(1LL<<29);
            cout<<addf<<" ";
            //starting with the first LMSB on for odd index
            ll cur=1;
            for(int i=1;i<n/2;i++){
                cout<<cur<<" "<<cur+adds<<" ";
                //making 1 on second LMSB for odd indices
                cur++;
            }
            if((n/2)%2==0){   //CASE 3
                cout<<cur<<" "<<cur+addf+adds<<ln;
                //making 1 on both first & second LMSB for odd indices
            }
            else{   //CASE 4
                cout<<cur<<" "<<cur+addf<<ln;
                //making 1 on first LMSB for odd indices
            }
        }
        else{
            ll addf=(1LL<<30);
            ll adds=(1LL<<29);
            cout<<0<<" "<<addf<<" ";
            //starting from 0 & making first LMSB 1 for even index
            ll cur=1;
            for(int i=1;i<=(n/2)-2;i++){
                cout<<cur<<" "<<cur+adds<<" ";
                //making 1 on second LMSB for even indices
                cur++;
            }
            cout<<cur<<" "<<cur+addf+adds<<ln;
            //making 1 on both first & second LMSB for even indices
        }
    }
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
since its a bitwise problem, any answer that matches the conditions
can be printed. 
condition is simple: N will be given & we have make an N length
vector where all odd index's XOR == all even index's XOR

CASE 1:-------------------------------------------------
now suppose n%4==0
means there are even numbers of even & odd indices
so we can put values from 1:
                even            odd
                0001            0001    - 1
                0010            0010    - 2
                0011            0011    - 3
                0100            0100    - 4
we can place both side same but now we need to change the values
since all values have to be distinct. so what we did here is:
                even            odd
               10001            0001    - 1
               10010            0010    - 2
               10011            0011    - 3
               10100            0100    - 4 
we added 1 infront of all even indices cause we know even numbers
of 1's XOR result is 0. which means XOR(even)==XOR(odd). 

CASE 2:-------------------------------------------------
now what if N is even but N%4!=0
so we can put values from 0:
                even            odd
                0000            0000    - 0
                0001            0001    - 1
                0010            0010    - 2
                0011            0011    - 3
                0100            0100    - 4
but now there is odd amount of even indices so we can't just put
1 in all index's LMSB. We need to make it even amounts. So we'll
put (N/2)-1 amount of 1 from 2nd to last even index. then put two
1 on first index & last index 'on the bit after that'. means: 
                even             odd
               100000            0000    - 0
               010001            0001    - 1
               010010            0010    - 2
               010011            0011    - 3
               110100            0100    - 4
now there is even amount of 1s in all even indices which means
XOR(even)==XOR(odd).

CASE 3:-------------------------------------------------
now suppose N%2==1  
then we need to check how many even indices we are having
if (N-2)%2==0 then we are having even amount of even indices. 
Although there is an extra slot for odd index which we'll fill up
with 0 & others we can start filling up with 1:        
                even            odd
                                0000    - 0
                0001            0001    - 1
                0010            0010    - 2
                0011            0011    - 3
                0100            0100    - 4
now we'll do changes on odd indices. Since there is odd amount
of odd indices, we need to put 1 on two different bits where in
the end the XOR result will be 0. So we'll put 1 on 2nd to last
& then put two 1s on first and last odd index. Just like we did
with even on CASE 2. 
                even              odd
                                100000    - 0
                0001            010001    - 1
                0010            010010    - 2
                0011            010011    - 3
                0100            110100    - 4
now there is even amount of 1s in all odd indices which means
XOR(even)==XOR(odd).

CASE 4:-------------------------------------------------
now suppose N%2==1  again but now
if (N-2)%2==1 then we are having odd amount of even indices.
which means there are even amount of odd indices. But to minimize
the operations we can simply do the CASE 3 on odd indices but
now So we'll put 1 on 2nd to last-1 & then put two 1s on first 
and last odd index. Which looks like this: 
                even              odd
                                100000    - 0
                0001            010001    - 1
                0010            010010    - 2
                0011            100011    - 3
now there is even amount of 1s in all odd indices which means
XOR(even)==XOR(odd).
*/
