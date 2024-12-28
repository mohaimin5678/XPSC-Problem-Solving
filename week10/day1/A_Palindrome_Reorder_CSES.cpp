#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    map<char,int> cnt;
    int n=s.size();
    for(int i=0;i<n;i++){
        cnt[s[i]]++;
    }
    
    int oddcnt=0;
    for(auto [ch,value] : cnt){
        if(value%2==1) oddcnt++;
    }

    if(oddcnt>1){   
        //odd jodi 1 er beshi hoy tahole palindrome impossible
        cout<<"NO SOLUTION"<<endl;
    }
    else{
        string first,middle, last;
        for(auto [ch,value] : cnt){
            if(value%2==1){ //odd part
                for(int i=1;i<=value;i++){
                    middle.push_back(ch);   //odd part full middle e
                }
            }
            else{ //even part
                for(int i=1;i<=(value/2);i++){ //half half jabe
                    first.push_back(ch);    //half shamne jabe
                    last.push_back(ch);     //half last e jabe
                }
            }
        }
        //before reverse: first: AAABC      last: AAABC
        reverse(last.begin(),last.end());
        //after reverse: first: AAABC      last: CBAAA

        string ans = first+middle+ last; 
        //for even middle is null but for odd middle will have something
        cout<<ans<<endl;

        //here total approximate complexity O(NlogN)
    }
    return 0;
}
/*
input: AAAACACBA
output: AACABACAA
output can be different since there can be multiple palindrome 

here we'll use counting technique. (using frequency array)
condition:
1) all character even thakte hobe jate pair kora possible hoy.
ete length even hobe.
2) all character even na thakle highest 1ta character odd hoite
parbe. 2ta/tar theke beshi odd hoile NO SOLUTION. ete length odd
hobe.

we will make 2 portion for even length- first & last portion
but for odd there will be 3 portion- first, middle & last

then we will concatenate those portions to make the final ans.
*/