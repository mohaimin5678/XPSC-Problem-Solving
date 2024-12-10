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
        map<int,int> msb;
        for(int i=0;i<n;i++){
            cin>>v[i];
            msb[__lg(v[i])]++;
        }
        ll pair=0;
        for(auto [x,y]:msb){
            if(y==2) pair++;
            else if(y>2){
                pair+=((1LL*y*(y-1))/2);
            }
        }
        cout<<pair<<endl;
    }
    return 0;
}
/*
why only checking msb here?
testcase 3:
4
6 2 5 3

here,
110 -> 6  MSB=2
010 -> 2  MSB=1
101 -> 5  MSB=2
011 -> 3  MSB=1

if we think about making Ai&Aj >= Ai^Aj then we must keep the
MSB bit same for both Ai and Aj. because in AND operation, if
Ai's MSB bit is 1 but Aj's same bit is 0 then in AND operation,
that bit will give 0(which will decrease the AND value). But
for XOR operation, 1^0=1 which will keep the XOR value high. 
Since we want AND result >= XOR result, we can't let this happen.
Thats why we are counting the similar MSB. 
here MSB[2]=2 so there are 2 elements exist with the msb value 2.
if we make AND operation among those 2, the result will be 
greater than XOR result(because even number of 1 in XOR=0 which
will reduce the XOR result).
also same for MSB[1]=2 so another pair exist according to the 
condition. So answer=2. 
*/