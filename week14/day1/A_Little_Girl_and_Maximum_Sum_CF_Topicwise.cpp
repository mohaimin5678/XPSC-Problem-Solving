#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    
    vector<int> dif(n+1);
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--; //since 0-based indexing
        dif[l]++;
        dif[r+1]--;
    }
    for(int i=1;i<=n;i++){
        dif[i]=dif[i-1]+dif[i];
    }

    sort(v.rbegin(),v.rend());
    sort(dif.rbegin(),dif.rend());

    ll total_sum=0;
    for(int i=0;i<n;i++){
        total_sum+=(1LL*v[i]*dif[i]);
    }
    cout<<total_sum<<ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    mohaimin();
    
}
/*
array diye dibe. queries diye dibe. emon vabe array reorder korte
hobe jeno queries e dewa range er sum gula finally total korar por
shei total sum jeno maximize hoy. 
now since amra difference array jani so amra difference array diye
check korbo kon index er contribution koto. 
testcase: 
3 3
5 3 2
1 2
2 3
1 3

difference array:-  0 1 2 3  4   -idx
                    0 0 0 0  0

query 1: 1 2        0 1 0 -1 0
query 2: 2 3        0 0 1 0  -1
query 3: 1 3        0 1 0 0  -1
                    ------------
now difference arr->0 2 1 -1 -2
now prefix sum->    0 2 3  2  0

so 3 size vector's contributions will be 2 3 2 

ekhon amra dekhtesi 2nd index shobcheye beshi contribution kortese
then 1st & 3rd index. 
so most contributed index e amra jodi amader array er max value ta
rakhi & evabe maximum contributed index er upor base kore kore next
maximum value gula assign kore dile amra je array ta pabo shetar 
total e maximum hobe.  
so amra descending order e value gula set kore dibo descending 
order e most contributed index e. 
so most contributed index on descending order: 3 2 2
And descending order vector will be:           5 3 2

we can just multiply between them and add them into the total sum 
which will be the maximum possible total sum. 
so total sum=(3*5)+(2*3)+(2*2)=25 (final answer)
*/