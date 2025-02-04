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
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<k/2;i++){
        vector<int> frq(26,0);
        for(int j=0;j+k-1<n;j+=k){
            int l=j+i;
            int r=j+(k-1-i);
            // cout<<l<<"->"<<s[l]<<" "<<r<<"->"<<s[r]<<ln;
            frq[s[l]-'a']++;
            frq[s[r]-'a']++;
        }
        int req=2*(n/k);
        int mx=*max_element(frq.begin(),frq.end());
        ans+=(req-mx);
    }
    if(k%2==1){
        vector<int> frq(26,0);
        for(int i=k/2;i<n;i+=k){
            // cout<<i<<"->"<<s[i]<<ln;
            frq[s[i]-'a']++;
        }
        int req=n/k;
        int mx=*max_element(frq.begin(),frq.end());
        ans+=(req-mx);
    }
    cout<<ans<<ln;
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
to solve this problem we need to see a testcase first.
15 3
abcazacbcabaaba
they want us to make the whole string palindrome & we can see that when
we make each period a palindrome, we can easily make the whole string
a palindrome. 
here we can see that there is 5 periods because n/k=15/3=5
abc aza cbc aba aba
 1   2   3   4   5
now if we wants to change those characters which is preventing us to 
make all periods palindrome, we need to do it with frequency counting
because they wants to change the minimum amounts of characters. 

now we need to traverse optimizely. so we'll use a Two pointers concept
without using it! here is how:- 
we'll start a loop i which will go half of a period which is k/2.(this
will count all the even parts)
And there will be a nested loop j which will traverse each period with
j+=k increment. Inside that loop we'll calculate the frequencye of the 
front & back value. 
Now whats happening on these loops?

when i=0  j=0   & l=0+0=0 so frq['a']=1 , r=0+(3-1-0)=2 so frq['c']=1
          j=3   & l=3+0=3 so frq['a']=2 , r=3+(3-1-0)=5 so frq['a']=3
          j=6   & l=6+0=6 so frq['c']=2 , r=6+(3-1-0)=8 so frq['c']=3
          j=9   & l=9+0=9 so frq['a']=4 , r=9+(3-1-0)=12 so frq['a']=5
          j=12  & l=12    so frq['a']=6 , r=12+2=14     so frq['a']=7

now the requirment is the same character on "both side" of that period
so if period is 5 then requirment of a character is 5*2=10
Now after finishing the j loop for i=0, we'll check the max frequency
of a character for both side and thats 'a' which appeared 7 times. So
if we can change 10-7=3 characters from both side & replace them with
'a' then both side will be palindrome. so currently ans=3
i++ so i=1 but k/2=3/2=1 & since i<(k/2) so outer loop break.

now since the period is in odd length, we also have to calculate the
middle element's frequency for all period. 
for(int i=k/2;i<n;i+=k) this loop will check each period's middle element. 
now i=1 so frq['b']=1
    i=4 so frq['z']=1
    i=7 so frq['b']=2
    i=10 so frq['b']=3
    i=13 so frq['b']=4
but for the middle element the requirment is 15/3=5 because each period
has only 1 middle element if K is odd. 
since max frequency of this frequency vector is 4 which is 'b' so if
we change 5-4=1 character from all middle element & replace that character
with 'b' then all middle element will be same & it will make full string
a palindrome. 

so ans=3+1=4 which is the final answer.
*/
