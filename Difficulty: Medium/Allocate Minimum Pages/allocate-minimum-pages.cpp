class Solution {
private:
    // Helper function me elements ko tight check karne ke liye types correct kiye
    bool isValid(const vector<int>& arr, int k, long long maxPages) {
        int studentsRequired = 1;
        long long currentPagesSum = 0;

        for (int pages : arr) {
            // Agar koi akeli book hi is limit se badi hai, toh ye limit invalid hai
            if (pages > maxPages) return false;

            if (currentPagesSum + pages > maxPages) {
                studentsRequired++;
                currentPagesSum = pages; // Agle student ko pehli book di

                if (studentsRequired > k) return false;
            } else {
                currentPagesSum += pages;
            }
        }
        return true;
    }

public:
    int findPages(vector<int>& arr, int k) {
        int n = arr.size();

        // Agar students books se zyada hain, toh sabko kam se kam ek book nahi mil sakti
        if (k > n) return -1;

        long long low = 0;
        long long high = 0;

        for (int pages : arr) {
            low = max(low, (long long)pages); // Sabse badi book ke pages
            high += pages;                   // Saari books ke pages ka sum
        }

        long long ans = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (isValid(arr, k, mid)) {
                ans = mid;       // Potential candidate mil gaya
                high = mid - 1;  // Aur kam karne ki koshish karo (left jao)
            } else {
                low = mid + 1;   // Limit choti hai, badhao isey (right jao)
            }
        }
        return (int)ans;
        
    }
};