/**
 * https://leetcode.com/problems/maximum-binary-tree/
 *
 * Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
 *
 * The root is the maximum number in the array.
 * The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
 * The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
 * Construct the maximum tree by the given array and output the root node of this tree.
 */
public class MaximumBinaryTree
{
    private class TreeNode
    {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x)
        {
            val = x;
        }
    }

    public TreeNode solution(int[] nums)
    {
        return construct(nums,0,nums.length);
    }

    private TreeNode construct(int[] nums, int left, int right)
    {
        if (left == right)
            return null;

        int max_i = max(nums, left, right);
        TreeNode root = new TreeNode(nums[max_i]);
        root.left = construct(nums, left, max_i);
        root.right = construct(nums, max_i + 1, right);

        return root;
    }

    private int max(int[] nums, int left, int right)
    {
        int max_i = left;
        for (int i = left; i < right; i++)
        {
            if (nums[i] > nums[max_i])
                max_i = i;
        }

        return max_i;
    }

    public static void main(String[] args)
    {
        MaximumBinaryTree example = new MaximumBinaryTree();

    }
}
