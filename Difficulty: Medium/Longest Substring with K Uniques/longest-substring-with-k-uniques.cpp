class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size(),left = 0,unique_count = 0,max_value = -1;
        std::vector<int> freq(26,0);
        for(int r = 0;r < n;r++){
            if(freq[s[r] - 'a']++ == 0)unique_count++;
            while(unique_count > k){
                if(--freq[s[left++] - 'a'] == 0)unique_count--;
            }
            if(unique_count == k){
            max_value = std::max(max_value,r-left+1);
            }
        }
        return max_value;
    }
};