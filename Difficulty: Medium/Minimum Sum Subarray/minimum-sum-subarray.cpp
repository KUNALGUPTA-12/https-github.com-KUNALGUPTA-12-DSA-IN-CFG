class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
        // code here
        // kadens se hua hai
        // int min_sum = arr[0], current_sum = 0 , n = arr.size();
        
        // for(int i = 0;i < n;i++){
        //     current_sum += arr[i];
            
        //     if(current_sum < min_sum){
        //         min_sum = current_sum;
        //     }
        //     if (current_sum > 0){
        //         current_sum = 0;
        //     }
        // }
        // return min_sum;
        
        // sliding window ka 
        int min_sum = INT_MAX; // Sabse badi value se shuru kiya
        int current_sum = 0;
        int left = 0;          // Window ka starting pointer

        for (int right = 0; right < arr.size(); right++) {
            current_sum += arr[right]; // Window ko right se badao

            // Agar hamari current window ka sum abhi tak ka sabse chota hai
            if (current_sum < min_sum) {
                min_sum = current_sum;
            }

            // Sliding Window Rule: Agar window ka total positive (> 0) ho gaya,
            // toh yeh aage ke sum ko bada karega, chota nahi. Isliye window shrink/reset karo.
            if (current_sum > 0) {
                current_sum = 0;
                left = right + 1; // Window ko naye element par shift karo
            }
        }
        return min_sum;
    }
};