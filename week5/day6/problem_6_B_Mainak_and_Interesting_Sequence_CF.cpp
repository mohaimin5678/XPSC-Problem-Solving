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
        int n,m;
        cin>>n>>m;
        if(n>m || (n%2==0 && m%2==1)) cout<<"NO"<<endl;
        else if(m%n==0){
            cout<<"YES"<<endl;
            int x=m/n;
            for(int i=1;i<=n;i++){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        else{
            vector<int> v(n);
            if(n%2==1){
                cout<<"YES"<<endl;
                for(int i=0;i<n-1;i++) v[i]=1;
                v[n-1]=(m-n)+1;
                for(int x:v){
                    cout<<x<<" ";
                }
                cout<<endl;
            }
            else if(n%2==0 && m%2==0){
                cout<<"YES"<<endl;
                for(int i=0;i<n-2;i++) v[i]=1;
                int last=(m-n+2)/2;
                v[n-2]=last;
                v[n-1]=last;
                for(int x:v){
                    cout<<x<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}

/*
if sum is less than numbers then answer is straight NO.

how (n%2==0 && m%2==1) is also a NO?
-> suppose we got n=4 & m=7
now to make it interesting sequence we must maintain p1=p2=p3..pn=0
now since if sum is odd but n is even then atleast 1 odd value 
will be there to interrupt the p1=p2=p3..pn=0. lets see,
they want to pick a value fron array & all the element strictly
less than the value will be collected & their total XOR will be 0. 
now [2 2 1 2] sum=7=m
less than 2 is only [1] & it's XOR!=0
again lets say n=4 & m=9
now [2 2 2 3] for arr[4]=3, less than 3 is [2 2 2] & it's XOR=2!=0
so (n%2==0 && m%2==1) is also a NO. 

how (m%n==0) is a YES?
-> suppose n=3 & m=9, we can make [3 3 3] where no one is less than
any other picked value. so we'll always get 0 for each selective index. 

how (n%2==1) is a YES?
->case 1: suppose n=3 & m=10 (case of odd & even) [3 3 4]
strictly less than 4 is [3 3] & their XOR=0. So its acceptable. 
case 2: suppose n=5 & m=11 (case of odd & odd) [1 2 1 2 5]
strictly less than 1 is [] so XOR=0.
strictly less than 2 is [1 1] & their XOR=0.
strictly less than 5 is [1 1 2 2] & their XOR=0. So its acceptable.

how (n%2==0 && m%2==0) is a YES?
-> suppose n=4 & m=10 then we can make [1 1 4 4]
strictly less than 4 is [1 1] & their XOR=0. So its acceptable.
*/