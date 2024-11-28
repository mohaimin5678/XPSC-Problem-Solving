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
        for(int i=n;i>0;i--){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
we can print all in descending order and it will be accepted. 
how? because whenever we perform OR, the answer never goes down
than the maximum value in that OR operation. It can be same as
the maximum/more but never less. 
example: 
5
answer: 5 4 3 2 1

now (5|4)=5 != 3
now (4|3)=7 != 2
now (3|2)=3 != 1
so 5 4 3 2 1 valid answer. 
*/