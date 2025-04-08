class Solution {
    public int minimumOperations(int[] nums) {
        TreeSet<Integer> st = new TreeSet<>();
        for (int i = nums.length - 1; i >= 0; --i) {
            if (!st.add(nums[i])) {
                return (i + 1 + 2) / 3;
            }
        }
        return 0;
    }
}