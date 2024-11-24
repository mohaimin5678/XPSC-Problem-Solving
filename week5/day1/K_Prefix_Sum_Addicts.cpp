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
        int n,k;
        cin>>n>>k;
        // vector<ll> s(n+1,0);
        vector<ll> s(n+1);
        for(int i=n-k+1;i<=n;i++){
            cin>>s[i];
        }

        vector<ll> a(n+1);
        if(n==1 || k==1){
            cout<<"YES"<<endl;
            continue;
        }
        for(int i=n;i>=n-k+2;i--){
            a[i]=s[i]-s[i-1];
        }
        bool flag=true;
        //checking ascending order
        for(int i=n-k+2;i<=n;i++){
            if(i+1<=n && a[i+1]<a[i]){
                flag=false;
                break;
            }
        }

        if(!flag){
            cout<<"NO"<<endl;
            continue;
        }

        for(int i=n-k+1;i>1;i--){
            a[i]=a[i+1];
            s[i-1]=s[i]-a[i];
        }
        a[1]=s[1];

        //checking full array if its in ascending order
        for(int i=1;i<=n;i++){
            if(i+1<=n && a[i+1]<a[i]){
                flag=false;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    return 0;
}
/*
they will provide me the number of an array & k where k is the 
prefix sum array's number starting from the end.
so we will be given those k numbers which are the prefix sum
values from the last of the original array. We need to find out
if the creating original array is in ascending order or not.

example with explanation:
if(n==1 || k==1){
    cout<<"YES"<<'\n';
    continue;
}
means if n==1 then it will be in ascending order by default so
the answer is YES.
if k==1 then there will be only 1 value given & we can obviously
make an ascending order array from it so the answer is YES.

a[] is original array & s[] is prefix sum array
suppose we have:
7 4
-6 -5 -3 0
where n=7, k=4
s[4]=-6     s[5]=-5     s[6]=-3     s[7]=0

for(int i=n;i>=n-k+2;i--){
    a[i]=s[i]-s[i-1];
}
using this loop we can set
a[7] = s[7]-s[6] = 0-(-3) = 3
a[6] = s[6]-s[5] = -3-(-5)= 2
a[5] = s[5]-s[4] = -5-(-6)= 1

so a=[_ _ _ _ 1 2 3]    right now.

bool flag=true;
//checking ascending order
for(int i=n-k+2;i<=n;i++){
    if(i+1<=n && a[i+1]<a[i]){
        flag=false;
        break;
    }
}
now we will check if the n to k-1 parts of the original array that
we built is in ascending order or not. if its not then flag=false
& break the loop.
for this example it won't be false.

for(int i=n-k+1;i>1;i--){
    a[i]=a[i+1];
    s[i-1]=s[i]-a[i];
}
a[1]=s[1];
and then loop through from n-k+1=4 to 2 and set a[] & s[].
a[4] = a[5]= 1   ---    s[3] = s[4]-a[4] = -6-1 = -7
a[3] = a[4]= 1   ---    s[2] = s[3]-a[3] = -7-1 = -8
a[2] = a[3]= 1   ---    s[1] = s[2]-a[2] = -8-1 = -9
& outside of the loop we can put a[1]=s[1].

now a[]= [-9  1  1  1  1  2 3]
    s[]= [-9 -8 -7 -6 -5 -3 0]

for(int i=1;i<=n;i++){
    if(i+1<=n && a[i+1]<a[i]){
    flag=false;
    break;
    }
}
now lets check if the new a[] is in ascending order or not using
the flag. since for this example its true, we will print yes.
*/