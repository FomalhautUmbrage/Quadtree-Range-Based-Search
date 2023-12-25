# Description
A quadtree is a type of “space partitioning tree” that enables fast lookup of points in a space. A quadtree is optimized specifically for 2D space. Each node represents a rectangular region in space bounded by the points (𝑥𝑜, 𝑦𝑜) and (𝑥1, 𝑦1). Within each node is an array of points of known, fixed size, given by (𝑥, 𝑦) coordinates. Typically, these points represent important locations within the 2D space under study, with the rest of the space considered to be irrelevant. The rule is that if a node contains a specific point, then its coordinates fall within the rectangular region bounded by the node. Once the node’s array is full, the tree grows as follows:<br/>
1. Add exactly four children to the node
2. The bounding rectangles for each child comprise exactly ¼ of the original bounding rectangle. That is, the range
on both x and y are split exactly in half, giving us four identically sized sub-regions in space
3. The points stored in the parent node are distributed amongst the children according to their location in space
4. The parent node’s point array is empty and will no longer be used to store points
