#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int a,b,l;
    cin>>a>>b>>l;
    set<int> s;
    for(int i=1;i<=l;i*=a){
        for(int j=1;i*j<=l;j*=b){
            if(l%(i*j)==0){
                s.insert(i*j);
            }
        }
    }
    cout<<s.size()<<ln;
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
no need to think about prime factorization because for a sinle
l, it's prime factorization can be more than 2. So then we won't
be able to fit them into only a & b. 
also constraint of both a & b is (2-100) & l<=10^6
so we can use brute force here. 
lets just use nested loop where first loop get multiplied by
a & nested loop get multiplied by b. 
first loop will only go till i becomes greater than l. Because
if first value is already greater than l then there is no
need to check for the second value. 
second loop will only go till i*j becomes greater than l. Because
if the multiplication get bigger then it won't divisible a value
which is smaller than itself. 
also using set for reducing the duplicates. 
*/