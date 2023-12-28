# Description
A quadtree is a type of “space partitioning tree” that enables fast lookup of points in a space. A quadtree is optimized specifically for 2D space. Each node represents a rectangular region in space bounded by the points (𝑥𝑜, 𝑦𝑜) and (𝑥1, 𝑦1). Within each node is an array of points of known, fixed size, given by (𝑥, 𝑦) coordinates. Typically, these points represent important locations within the 2D space under study, with the rest of the space considered to be irrelevant. The rule is that if a node contains a specific point, then its coordinates fall within the rectangular region bounded by the node. Once the node’s array is full, the tree grows as follows:<br/>
1. Add exactly four children to the node
2. The bounding rectangles for each child comprise exactly ¼ of the original bounding rectangle. That is, the range
on both x and y are split exactly in half, giving us four identically sized sub-regions in space
3. The points stored in the parent node are distributed amongst the children according to their location in space
4. The parent node’s point array is empty and will no longer be used to store points
## Understanding Range-Based Search
In a range-based search, we are interested obtaining a list of points within a given range. For example, I might want to know all points whose coordinates lie within the range 𝑥 ∈ (0,1), 𝑦 ∈ (−1, −0.4). If we are guaranteed that all search regions are contained entirely within a single node’s rectangular region of space, this problem is simple. However, if the search region intersects multiple nodes’ rectangles, the problem is more difficult. Recursion or stack-based algorithms are often used for this purpose. You are expected to investigate options for algorithms to solve this problem, and implement one.
# Command
## INIT
**Parameters:** *m x0 y0 x1 y1* <br/>
**Description:** Create a new quadtree. The parameter m, which is guaranteed to be greater than 4, represents the number of points that can be stored at a node before the quadtree expands. The points (x0,y0), (x1,y1) represent a rectangle
