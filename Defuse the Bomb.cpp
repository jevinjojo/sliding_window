class Solution {
public:
    vector<int> decrypt(std::vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0); // Initialize result vector with zeros
        if (k == 0) {
            return result; // If k is 0, return result which is already filled with zeros
        }// this is a good problem
        int start, end, sum = 0;
        if (k > 0) {
            start = 1;
            end = k;
        } else {
            start = n + k; // k is negative, adjust start accordingly
            end = n - 1;
        } // Calculate initial sum of the window
        for(int i = start; i <= end; i++){
            sum += code[i % n];
        }  // Slide the window across the array
        for (int i = 0; i < n;i++) {
            result[i] = sum;
            sum -= code[start % n]; // Remove the element going out of the window
            start = (start + 1) % n; // Move start forward, wrap around if necessary
            end = (end + 1) % n; // Move end forward, wrap around if necessary
            sum += code[end % n]; // Add the new element coming into the window
        }
        return result; } // DRY RUN    FOR K = -2
};
// code = [2,4,9,3]
// k = -2
// n = 4 (length of the code)
// Adjust k and Setup Window:
// Since k is negative, we adjust the window to start from n + k:
// start = 4 - 2 = 2
// end = 3 (last index since k is negative)
// Calculate Initial Sum:
// We calculate the sum of elements from index start to end:
// sum += code[2 % 4] -> sum += 9
// sum += code[3 % 4] -> sum += 3
// Initial sum = 9 + 3 = 12
// Sliding Window Across the Array:
// Iteration 1 (i = 0):
// result[0] = sum -> result[0] = 12
// sum -= code[start % n] -> sum -= code[2 % 4] -> sum -= 9 (sum = 3)
// start = (start + 1) % n -> start = 3
// end = (end + 1) % n -> end = 0
// sum += code[end % n] -> sum += code[0 % 4] -> sum += 2 (sum = 5)
// Iteration 2 (i = 1):
// result[1] = sum -> result[1] = 5
// sum -= code[start % n] -> sum -= code[3 % 4] -> sum -= 3 (sum = 2)
// start = (start + 1) % n -> start = 0
// end = (end + 1) % n -> end = 1
// sum += code[end % n] -> sum += code[1 % 4] -> sum += 4 (sum = 6)
// Iteration 3 (i = 2):
// result[2] = sum -> result[2] = 6
// sum -= code[start % n] -> sum -= code[0 % 4] -> sum -= 2 (sum = 4)
// start = (start + 1) % n -> start = 1
// end = (end + 1) % n -> end = 2
// sum += code[end % n] -> sum += code[2 % 4] -> sum += 9 (sum = 13)
// Iteration 4 (i = 3):
// result[3] = sum -> result[3] = 13
// sum -= code[start % n] -> sum -= code[1 % 4] -> sum -= 4 (sum = 9)
// start = (start + 1) % n -> start = 2
// end = (end + 1) % n -> end = 3
// sum += code[end % n] -> sum += code[3 % 4] -> sum += 3 (sum = 12, but not used further)
// Final Result:
// result = [12, 5, 6, 13]
