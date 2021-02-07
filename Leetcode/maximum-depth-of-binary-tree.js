//https://leetcode.com/problems/maximum-depth-of-binary-tree/

var maxDepth = function(root) {
  if (!root) return 0;
  let leftHeight = maxDepth(root.left);
  console.log(`left height from ${root.val}: ${leftHeight}`);
  let rightHeight = maxDepth(root.right);
  console.log(`right height from ${root.val}: ${rightHeight}`)
  console.log(Math.max(leftHeight, rightHeight) + 1);
  return (Math.max(leftHeight, rightHeight) + 1);
};

