/*Given an array of integers nums, sort the array in ascending order and return it.
You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
Example 1:
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessarily unique.
Constraints:
1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104 */
class Solution {
public:
    // Heapify subtree rooted at index i for size n
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;        // root
        int left = 2*i + 1;     // left child
        int right = 2*i + 2;    // right child
        if(left < n && nums[left] > nums[largest])
            largest = left;
        if(right < n && nums[right] > nums[largest])
            largest = right;
        if(largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        // Build max heap
        for(int i = n/2 - 1; i >= 0; i--)
            heapify(nums, n, i);

        // Extract elements from heap one by one
        for(int i = n-1; i >= 0; i--) {
            swap(nums[0], nums[i]); // move current largest to end
            heapify(nums, i, 0);    // heapify reduced heap
        }
        return nums;
    }
};