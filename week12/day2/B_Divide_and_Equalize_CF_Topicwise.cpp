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
        map<int,int> cnt;
        for(int i=0;i<n;i++) {
            for(int j=2;j*j<=v[i];j++) {
                if(v[i]%j==0) {
                    while(v[i]%j==0) {
                        cnt[j]++;
                        v[i]/=j;
                    }
                }
            }
            if(v[i]>1){
                cnt[v[i]]++;
            }
        }
        bool ok=true;
        for(auto [x,y]:cnt){
            if (y%n!=0) {
                ok=false;
                break;
            }
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
/*
they will give us an array where we can do: 
-> choose Ai & Aj and a divisor of Ai which is x
-> then replace Ai with (Ai/x) & Aj with (Aj*x). 
by doing these operation we have to make all elements of the array 
equal. 
HINT: we'll solve this using Prime Factorization

suppose we have 18,
after prime factorization we'll get-> 2*3*3
using prime factorization we can find all of 18's divisors!
by making all possible combination from [2^1 * 3^2],
divisors=[ 1 (2^1) (3^1) (3^2) (2^1*3^1) (2^1*3^2)] 
        =[ 1   2     3     9       6         18   ]
        =[ 1 2 3 6 9 18 ] all divisors of 18

--------------------------------------------------------------
We call also find out the number of divisors of N. 
suppose N=90
its divisors=[1 2 3 5 6 9 10 15 18 30 45 90]
Prime factorization: (2^1)*(3^2)*(5^1) 
there is a formula on this: 
                                e1    e2    e3
if N's prime factorization is= P1  * P2  * P3........
then total divisors of N = (e1 + 1)*(e2 + 1)*(e3 + 1).... 
using this formula on 90's prime factors we get=(1+1)*(2+1)*(1+1)
                                               =2*3*2=12 (number of divisors)
{Although this technique is not used here but its related}
--------------------------------------------------------------

Now how to solve this uisng prime factorization?
we'll find all elements prime factor & count them. Here we used 
map for this. 
since we need to distribute all primes into each element equally,
so we'll simply check if all prime's occurance get %N or not. 
if it does then we can distribute that prime equally on all element. 
And the answer will be YES. we'll use a flag for it. 
but if it doesn't & trigger that if condition that means we can't
distribute it equally on every element so the array will never
become equal. So then the answer will be NO. 
*/
