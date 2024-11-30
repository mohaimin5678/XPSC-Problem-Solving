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
        cout<<n<<" "<<n-1<<endl;
    }
    return 0;
}
/*
they wanted x & y who can make this condition true-> (x|y)*(x^y)=N 
now lets see for N=21: 

16 8 4 2 1
1  0 1 0 1 -> 21
1  0 1 0 0 -> 20
-------------   OR operation
1  0 1 0 1 -> 21

-------------   XOR operation
0  0 0 0 1 -> 1

so finally 21*1=21 answer done. 
*/