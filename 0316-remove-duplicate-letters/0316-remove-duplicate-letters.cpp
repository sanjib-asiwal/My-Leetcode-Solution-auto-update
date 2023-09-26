class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        stack<char> stk;
        int freq[26]={0};
        for (int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        int present[26]={0};
        stk.push(s[0]);
        freq[s[0]-'a']--;
        present[s[0]-'a']=1;
        for(int i=1;i<n;i++){
            freq[s[i]-'a']--;
            if(present[s[i]-'a']) continue;
            while(!stk.empty()&&(s[i]-'a')<(stk.top()-'a')&&freq[stk.top()-'a']>0){
                present[stk.top()-'a']=0;
                stk.pop();
            }
            stk.push(s[i]);
            present[s[i]-'a']=1;
        }
        stack<char> tmp;
        while(!stk.empty()){
            tmp.push(stk.top());
            stk.pop();
        }
        string ans;
        while(!tmp.empty()){
            ans+=tmp.top();
            tmp.pop();
        }
        return ans;
    }
};