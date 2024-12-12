#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
const int maxN=(1LL<<15);
vector<int> palindromeCollection;

bool isPalindrome(int x){
    string s=to_string(x);
    string t=s;
    reverse(t.begin(),t.end());
    return t==s;
}
void markPalindrome(){
    for(int i=0;i<maxN;i++){
        if(isPalindrome(i)) palindromeCollection.push_back(i);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    markPalindrome();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        vector<int> frq(maxN+1);
        for(int i=0;i<n;i++){
            cin>>v[i];
            frq[v[i]]++;
        }
        ll ans=n;
        for(int i=0;i<n;i++){
            for(int j=0;j<palindromeCollection.size();j++){
                int cur=(v[i]^palindromeCollection[j]);
                ans+=frq[cur];
            }
        }
        cout<<(ans/2)<<endl;
    }
    return 0;
}
/*
here this 0≤A[i]<2^15 plays a big part. we know that all element
from A must be from 0 to 32767. And not more than that. Means
any result of A[i]^A[j] will always in between 0 <-> 32767. 
So why not precalculate it before starting to solve all the
testcases? 
so we will call markPalindrome() to calculate all palindrome
from 0 to 32767. There will be less than 450 palindrome number. 
Which ultimately shorten our total calculation on each testcase. 
since A[i]^A[j]=P then we can also say that A[i]^P=A[j] too. 
So we'll XOR full palindromeCollection vector for all elements
of the Array. if we find A[i]^P[j]=X where X also exists on 
Array,then we'll add it's frequency into the answer. Why not 
increment it only once, because that X can be occure multiple 
times on the Array. 
testcase:
4
13 27 12 26
initially ans=4 because
13^13=0
27^27=0
12^12=0
26^26=0
all of them are palindrome so lets count them initially. 
then with 13^1=12 & 12^1=13 so ans+=1; ans=5
13^22=27 & 27^22=13 so ans+=1; ans=6
27^1=26 & 26^1=27 so ans+=1; ans=7
12^22=26 & 26^22=12 so ans+=1; ans=8

since all of them are counting twice on the loop, we just have
to ans/=2 it. 
*/