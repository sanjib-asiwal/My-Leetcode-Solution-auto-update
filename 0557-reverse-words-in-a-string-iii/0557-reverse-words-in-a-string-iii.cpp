class Solution {
public:
    string reverseWords(string s) {
        int last_space_index=-1;
        int len=s.size();
        for(int idx=0;idx<=len;idx++){
            if(s[idx]==' '||idx ==len){
                int start_index=last_space_index+1;
                int last_index=idx-1;
                while(start_index<last_index){
                    swap(s[start_index],s[last_index]);
                    start_index++;
                    last_index--;
                }
                last_space_index=idx;
            }
        }
        return s;
    }
};