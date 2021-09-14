"""
Node is defined as
self.left (the left child of the node)
self.right (the right child of the node)
self.info (the value of the node)
"""
import queue

def levelOrder(root):
    result = []

    to_see = queue.Queue()
    to_see.put(root)

    while not to_see.empty():
        node = to_see.get()
        result.append(node.info)

        if node.left:
            to_see.put(node.left)
        if node.right:
            to_see.put(node.right)
    
    print(' '.join(map(str, result)))

