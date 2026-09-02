class Solution {
    public int minMeetingRooms(int[] start, int[] end) {
        // code here
        // Step 1: Dono arrays ko sort karo
        Arrays.sort(start);
        Arrays.sort(end);

        int i = 0; // Pointer for start
        int j = 0; // Pointer for end

        int currentRooms = 0;
        int maxRooms = 0;

        // Loop tab tak chalega jab tak saari meetings shuru nahi ho jaatin
        while (i < start.length) {

            // start[i] < end[j] (True) -> Naya banda aaya, Room +1
            if (start[i] < end[j]) {
                currentRooms++;
                i++;
            } 
            // start[i] < end[j] (False, jaise 8 < 7) -> Purana banda gaya, Room -1
            else {
                currentRooms--;
                j++;
            }

            // Peak rooms ka track rakho
            maxRooms = Math.max(maxRooms, currentRooms);
        }

        return maxRooms;
    }
}
