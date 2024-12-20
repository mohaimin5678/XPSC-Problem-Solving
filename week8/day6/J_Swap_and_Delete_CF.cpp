#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tests;
    cin>>tests;
    while(tests--){
        string s;
        cin>>s;
        int zero=0,one=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') zero++;
            else one++;
        }
        if(s.size()==1) cout<<1<<endl;
        else if(zero==one) cout<<0<<endl;
        else{
            int dif=abs(zero-one);
            if(zero>one) zero-=dif;
            else one-=dif;
            string t;
            for(int i=0;i<s.size();i++){
                if(s[i]=='0' && one!=0){
                    t.push_back('1');
                    one--;
                }
                else if(s[i]=='1' && zero!=0){
                    t.push_back('0');
                    zero--;
                }
                else break;
            }
            dif+=zero;
            dif+=one;
            cout<<dif<<endl;
        }
    }
    return 0;
}
/*
testcase 2: 
011
zero--> 1
one--> 2
so dif=1
remove dif from one then one=1
t=10
answer 1

testcase 3: 
0101110001
zero--> 5
one--> 5
equal so no delete needed
t=1010001110
answer 0

testcase 4: 
111100
zero--> 2
one--> 4
so dif=2
remove dif from one then one=2
t=00.. but on .. place we can't put the ones, because if we do then 
s[i]==t[i] will occur. so we can't put them. Since we can't put them,
we have to delete them. 
t=00
so ans=dif+remaning one=2+2=4
*/