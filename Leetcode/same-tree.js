//https://leetcode.com/problems/same-tree/

function isSameTree(p, q) {
  if (!p && !q) return true;
  if (!p || !q || p.val !== q.val) return false;
 
  return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
}

