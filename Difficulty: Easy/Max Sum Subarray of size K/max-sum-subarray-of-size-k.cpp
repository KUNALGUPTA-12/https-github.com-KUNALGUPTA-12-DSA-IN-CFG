class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        // check karna ki array se bada suarray to nahi
        if (n < k){
            return -1;
        }
        int current_Sum = 0;
        // loop chalao coapre ka leya fierst elment se
        // phali initaila window taiyar karo
        for(int i = 0;i < k;i++){
            current_Sum += arr[i];
        }
        int max_Sum = current_Sum;
        
        // slidind winndow
        for(int i = k;i < n;i++){
            current_Sum += arr[i] - arr[i-k];
            // condtion ki max sum update karana
            if(current_Sum > max_Sum){
                max_Sum = current_Sum;
            }
        }
        return max_Sum;
    }
};