/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int maxi;
    int helper(TreeNode root){
        if(root == null) return 0;
        int left = Math.max(0,helper(root.left));
        int right = Math.max(0,helper(root.right));
        maxi = Math.max(left+right+root.val, maxi);

        return Math.max(left,right) + root.val;
    }
    public int maxPathSum(TreeNode root) {
        maxi = Integer.MIN_VALUE;
        helper(root);
        return maxi;
    }
}