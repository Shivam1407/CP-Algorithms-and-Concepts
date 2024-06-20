Q. what is a heap?
A. A heap is a complete binary tree that comes with heap order property.


Q. What is heap order property?
A. In a max heap, the key at the root must be greater than or equal to the keys at its children.
   In a min heap, the key at the root must be less than or equal to the keys at its children.


Q. What is A complete Binary Tree?
A. A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.


Q. What is the height of a heap?
A. The height of a heap is O(log n), where n is the number of nodes in the heap.


Q. What is the height of a complete binary tree?
A. The height of a complete binary tree is O(log n), where n is the number of nodes in the tree.his is because each level of the tree approximately doubles the number of nodes, leading to a logarithmic relationship between the number of nodes and the height.

// the parent of any node at index i is stored at index i/2.

Q. Representation of Max Heap
A. A max heap can be represented as an array. The root of the heap is stored at index 1. For any node at index i, and the left child is tored at the index 2i and the right child is stored at 2i+1.
            100
          /     \
        90       80
       /  \     /   \
     75    60  50    40
    / \   /
  45  30 25



Q. from which index to which index does  leafnode lie??
A. if arr is of N then  (N/2)+1 to N tak.