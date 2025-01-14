#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
const int maxN=1e6+9;
vector<int> divisors(maxN);
// vector<int> divisors[maxN];  //to find all divisor numbers
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<maxN;i++){
        for(int j=i;j<maxN;j+=i){
            divisors[j]++;
        }
    }

    //to find all divisor numbers
    // for(int i=1;i<maxN;i++){
    //     for(int j=i;j<maxN;j+=i){
    //         divisors[j].push_back(i);
    //     }
    // }

    //see the counts
    // for(int i=1;i<=30;i++){
    //     cout<<i<<" ->  "<<divisors[i]<<endl;
    // }

    //to find all divisor numbers
    // for(int i=1;i<=30;i++){
    //     cout<<i<<" ->  ";
    //     for(int x:divisors[i]){
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<divisors[n]<<endl;
    }
    return 0;
}
/*
Sieve algorithm way te amra multiple gula te traverse
korbo & jekhane jekhane multiple pabo shekhane shekhane
either pushback/++ kore "numbers save"/"numbers count"
kore rekhe dibo. complexity O(Nlog(log(N)))
then input niye O(1) e sheta execution
kore dibo. 

*/
