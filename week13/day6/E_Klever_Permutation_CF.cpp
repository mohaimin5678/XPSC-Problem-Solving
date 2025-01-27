#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,k;
    cin>>n>>k;
    int mn=1,mx=n;
    vector<int> v(n+1,-1);
    for(int i=1;i<=k;i++){
        if(i%2==1){
            v[i]=mn;
            mn++;
            int j=i+k;
            while(j<=n){
                v[j]=mn;
                mn++;
                j+=k;
            }
        }
        else{
            v[i]=mx;
            mx--;
            int j=i+k;
            while(j<=n){
                v[j]=mx;
                mx--;
                j+=k;
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<v[i]<<" ";
    cout<<ln;
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
rearranging is tough. 
lets think more simply. They want any continuous segments of 
length k's difference not to be more than 1. 
so we need to make sequence so that after K length, the next
digit should be (+/-)1 from first index of that K length 
segment. 
means if k=4 so first segment is from 1 to 4th index, and 
the 5th index should be either +1 or -1 from 1st index. 
if 1st index is 1, then logically 5th index will be 2 (cause
0 is not acceptable). Also if 1st index is N, then logically
5ht index will be N-1. (cause N+1 is not acceptable). 
Then how we'll confirm this that for which value we'll do
+1 or -1 ?
they said K is even & we'll try something based on parity. 
we'll put all minimum value on odd indexes & maximum value
on even indexes. 
so if i is odd then v[i]=min & then v[i+k]=min+1
And if i is even then v[i]=max & then v[i+k]=max-1

why we didn't put all min on odd indexes serially?
because after the length of K, the difference between min
will be bigger than 1. EX:- 
1 _ 2 _ 3 _ 4 _ 5
here we put all min value on all odd indexes serially but 
now if k=4 then [1 _ 2 _] - [_ 4 _ 5] will be more than 1. 

so we are putting value based on K. 
EX:-
10 4
1 2 3 4 5 6 7 8 9 10    --index & min=1,max=10
_ _ _ _ _ _ _ _ _ _
since i=1%2==1 so v[1]=1 & min++;
then v[1+4]=v[5]=2 & min++;
then v[5+4]=v[9]=3 & min++;

1 2 3 4 5 6 7 8 9 10    --index & min=4,max=10
1 _ _ _ 2 _ _ _ 3 _
since i=2%2==0 so v[2]=10 & max--;
then v[2+4]=v[6]=9 & max--;
then v[6+4]=v[10]=8 & max--;

1 2  3 4 5 6 7 8 9 10    --index & min=4,max=7
1 10 _ _ 2 9 _ _ 3 8
since i=3%2==1 so v[3]=4 & min++;
then v[3+4]=v[7]=5 & min++;

1 2  3 4 5 6 7 8 9 10    --index & min=6,max=7
1 10 4 _ 2 9 5 _ 3 8
since i=4%2==0 so v[4]=7 & max--;
then v[4+4]=v[8]=6 & max--;

1 2  3 4 5 6 7 8 9 10    --index & min=6,max=5
1 10 4 7 2 9 5 6 3 8
(final sequence)
AND we need to do the outer loop K times because on that
K times inner loop will fill up all the values
*/