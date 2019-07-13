class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l;
        int r;
        int len = s.size();
        int count = 0;
        int max_len = 0;
        int tmp_len;

        // s is a null string, which maybe dummy
        if(len == 0){
            return 0;
        }

        for (l=0;l<len;l++){
            // char tmp[1000];
            string tmp = "";
            int idx = 0;

            // Adding the first element to tmp
            // tmp[idx] = s[l];
            tmp += s[l];
            idx += 1;
            tmp_len = 1;
            if (max_len < tmp_len){
                max_len = tmp_len;
            }

            // Consider the left elements
            for (r=l+1;r<len;r++){
                if (is_in_string(tmp, s[r])){
                    tmp_len = r-l;
                    // cout<<r<<" "<<s[r]<<" "<<tmp_len<<endl;
                    if (max_len < tmp_len){
                        max_len = tmp_len;
                    }
                    break;
                }
                else{
                    // tmp[idx] = s[r];
                    tmp += s[r];
                    idx += 1;
                    // Update the max_len
                    tmp_len = r-l+1;
                    // cout<<l<<" "<<r<<" "<<s[r]<<" "<<tmp_len<<endl;
                    if (max_len < tmp_len){
                        max_len = tmp_len;
                    }
                }
            }
        }
        return max_len;
    }

    bool is_in_string(string s, char c){
        int len = s.size();
        for (int i=0;i<len;i++){
            if (s[i] == c){
                return true;
            }
        }
        return false;
    }
};
