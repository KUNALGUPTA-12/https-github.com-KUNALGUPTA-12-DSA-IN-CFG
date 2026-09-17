class Solution {
    int lowerBound(int[] arr, int target) {
        // code here
        int n = arr.length;
               int low = 0, high = n - 1;
               int ans = n; // Default answer agar koi element bada na mile (length of array)

               while (low <= high) {
                   int mid = low + (high - low) / 2;

                   // Agar mid element target se bada ya barabar hai
                   if (arr[mid] >= target) {
                       ans = mid;        // Is index ko save karo
                       high = mid - 1;   // Aur pehle (chote) index ke liye left side jao
                   } else {
                       low = mid + 1;    // Agar chhota hai toh right side jao
                   }
               }
               return ans;
    }
}
