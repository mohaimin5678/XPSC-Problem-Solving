#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        if(s==t || s[0]=='1') cout<<"YES"<<endl;
        else{
            int pos=-1;
            for(int i=0;i<n;i++){
                if(s[i]=='1'){
                    pos=i;
                    break;
                }
            }
            //pos=-1 will stay if there is no 1 in s.
            int mis=-1;
            for(int i=0;i<n;i++){
                if(s[i]!=t[i]){
                    mis=i;
                    break;
                }
            }
            if(pos==-1 || mis<pos) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}
/*
lets analyze this testcase:
8
10110111
01100000
using 1 based indexing we got S[1]=1
if we take (l,r)=(2,2) then Si=S2=S2^S(2-2+1)=S2^S1=0^1=1=T2
if we take (l,r)=(6,6) then Si=S6=S6^S(6-6+1)=S6^S1=1^1=0=T6
if we take (l,r)=(7,7) then Si=S7=S7^S(7-7+1)=S7^S1=1^1=0=T7
if we take (l,r)=(8,8) then Si=S8=S8^S(8-8+1)=S2^S8=1^1=1=T8
then we take (l,r)=(1,1) then Si=S1=S1^S(1-1+1)=S1^S1=1^1=0=T1
so now: 
s= 01100000
t= 01100000
so scenario 1: if s[1]=1 then answer is straight YES. 

now lets analyze this testcase:
4
0100
0001
using 1 based indexing we got S[2]=1
but this will also give us YES. how?
since first 1 came into 2nd position, any mismatch that we have
to change, we can take a range of 2. for example here S4 needs
to be changed. So we have to take (l,r)=(3,4)
now Si=S3^S(3-3+1)=S3^S1=0^0=0=T3(which didn't change)
now Si=S4^S(4-3+1)=S4^S2=0^1=1=T4(which now changed)
so current S=0101
but we still need to change 2nd position, which itself is 1. 
but we said "since first 1 came into 2nd position, any mismatch 
that we have to change, we can take a range of 2." so lets take
(l,r)=(1,2)
now Si=S1^S(1-1+1)=S1^S1=0^0=0=T1(which didn't change)
now Si=S2^S(2-1+1)=S2^S2=1^1=0=T2(which now changed)
so now S=0001 == T=0001

then when we would say that its not possible?
when the first mismatch occurs before first 1's arrival, we
can't change it.
*/