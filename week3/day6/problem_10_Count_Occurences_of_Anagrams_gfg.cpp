class Solution{
public:
    int search(string pat, string txt) {
        int k=pat.size();
        int n=txt.size();
        vector<int> t(26,0);
        vector<int> win(26,0);
        for(int i=0;i<k;i++){
            t[pat[i]-'a']++;
        }
        int l=0,r=0;
        int cnt=0;
        while(r<n){
            win[txt[r]-'a']++;
            if(r-l+1==k){
                bool flag=true;
                for(int i=0;i<26;i++){
                    if(t[i]!=win[i]){
                        flag=false;
                        break;
                    }
                }
                if(flag) cnt++;
                win[txt[l]-'a']--;
                l++;
                r++;
            }
            else r++;
        }
        return cnt;
    }

};