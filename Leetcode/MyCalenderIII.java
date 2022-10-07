// https://leetcode.com/problems/my-calendar-iii/

class MyCalendarThree {
	SegmentTree segmentTree;
    public MyCalendarThree() {
    	segmentTree = new SegmentTree(0, 1000000000);
    }
    public int book(int start, int end) {
        segmentTree.add(start, end, 1);
        return segmentTree.getMax();
    }
}

class SegmentTree {
    TreeNode root;
    public SegmentTree(int left, int right) {
        root = new TreeNode(left, right);
    }
    public void add(int start, int end, int val) {
        TreeNode event = new TreeNode(start, end);
    	add(root, event, val);
    }
    private void add(TreeNode root, TreeNode event, int val) {
        if(root == null) {
            return ;
        }
        /**
         * If current node's range lies completely in update query range.
         */
        if(root.inside(event)) {
            root.booked += val;
            root.savedres += val;
        }
        /**
         * If current node's range overlaps with update range, follow the same approach as above simple update.
         */
        if(root.intersect(event)) {
        	// Recur for left and right children.
            int mid = (root.start + root.end) / 2;
            if(root.left == null) {
                root.left = new TreeNode(root.start, mid);
            }
            add(root.left, event, val);
            if(root.right == null) {
                root.right = new TreeNode(mid, root.end);
            }
            add(root.right, event, val);
            // Update current node using results of left and right calls.
            root.savedres = Math.max(root.left.savedres, root.right.savedres) + root.booked;
        }
    }
    public int getMax() {
        return root.savedres;
    }
    /**
     * find maximum for nums[i] (start <= i <= end) is not required.
     * so i did not implement it. 
     */
    public int get(int start, int right) {return 0;}
	class TreeNode {
	    int start, end;
	    TreeNode left = null, right = null;
	    /**
	     * How much number is added to this interval(node)
	     */
	    int booked = 0;
	    /**
	     * The maximum number in this interval(node). 
	     */
	    int savedres = 0;
	    public TreeNode(int s, int t) {
	        this.start = s;
	        this.end = t;
	    }
	    public boolean inside(TreeNode b) {
	        if(b.start <= start && end <= b.end) {
	            return true;
	        }
	        return false;
	    }
	    public boolean intersect(TreeNode b) {
	    	if(inside(b) || end <= b.start || b.end <= start) {
	            return false;
	        }
	        return true;
	    }
	}
}