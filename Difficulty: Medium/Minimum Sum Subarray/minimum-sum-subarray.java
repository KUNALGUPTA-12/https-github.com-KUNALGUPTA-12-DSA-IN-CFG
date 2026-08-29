class Solution {
    public int minSubarraySum(int[] arr) {
        // code here
        // kadens sehua hai
        // int minSum = arr[0],currentSum = 0,n = arr.length;
        // for(int i = 0;i < n;i++){
        //     currentSum += arr[i];
        //     if(currentSum < minSum ){
        //         minSum = currentSum;
        //     }
        //     if(currentSum > 0){
        //         currentSum = 0;
        //     }
        // }
        // return minSum;
        
        // window sliding sa hua hsi
        int minSum = Integer.MAX_VALUE; // Sabse badi value se shuru kiya
        int currentSum = 0;
        int left = 0;                   // Window ka starting pointer

        for (int right = 0; right < arr.length; right++) {
            currentSum += arr[right]; // Window ko right se badao

            // Agar hamari current window ka sum abhi tak ka sabse chota hai
            if (currentSum < minSum) {
                minSum = currentSum;
            }

            // Sliding Window Rule: Agar window ka total positive (> 0) ho gaya,
            // toh yeh aage ke sum ko bada karega, chota nahi. Isliye window shrink/reset karo.
            if (currentSum > 0) {
                currentSum = 0;
                left = right + 1; // Window ko naye element par shift karo
            }
        }
        return minSum;
    }
}