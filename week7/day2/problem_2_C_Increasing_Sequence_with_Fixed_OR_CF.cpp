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
    while(t--) {
        ll n;
        cin>>n;
        deque<ll> ans;
        for (int k = 0;k<=__lg(n);k++) {
            if ((n>>k)&1) {
                ll value=n-(1LL<<k);
                if(value>0) ans.push_front(value);
            }
        }
        ans.push_back(n);
        cout<<ans.size()<<endl;
        for (auto x:ans) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
we have to off 1 bit at a time to create the array element. 
And we'll start from right to left to make it strictly lower. 
why only 1 bit on-off? so that the OR operation can be N. 
for n=23
10111 ->23
10110 ->22
10101 ->21
10011 ->19
00111 ->7
any other way can cause the OR operation result!=23

here __lg(n) will give us MSB in O(1)
And using deque providing us the independence to push in front.
if we used vector then we'd have the array in decreasing order,
then we had to reverse it. So to minimize the runtime, we can
simply use deque here. 
after the loop, we have to add n in the end to fulfill the array. 
also we can't push 0. because the condition said so. 
*/
