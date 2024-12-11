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
        bool same=true;
        for(int i=0;i<n-1;i++){
            if(v[i]!=v[i+1]){
                same=false;
                break;
            }
        }
        if(same) cout<<0<<endl;
        else{
            int mn=v[0],mx=0;
            for(int i=0;i<n;i++){
                mx=(mx|v[i]);
                mn=(mn&v[i]);
            }
            cout<<abs(mx-mn)<<endl;
        }
    }
    return 0;
}
/*
testcase with explanation:
7
20 85 100 41 76 49 36

here: 
20:  0010100
36:  0100100
41:  0101001
49:  0110001
76:  1001100
85:  1010101
100: 1100100

we all know that if we can make any one of these value highest &
any one of these value lowest then the difference is the answer 
according to the problem statement. 
we know that to maximize a number in an array, we can do OR operation
on that particular number with all other elements of that array. 
also if we want to minimize a number, we can simply do AND operation
on that number with all other elements of that array. 
means OR operation maximize a value & AND operation potentially 
minimize a value. 
so we took mn & mx where mn=v[0] & mx=0. 
we can't pick mn=0 because then it won't give us the accurate AND
operation result. 
but we can put mx=0 because OR operation works as a summation. So 
the doubt of decreasing the result won't be there. 
mx= 20|85|100|41|76|49|36=125
mn= 20&85&100&41&76&49&36=0
ans=125-0=125
*/