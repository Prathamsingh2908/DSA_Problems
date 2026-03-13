<h2><a href="https://www.geeksforgeeks.org/problems/implementing-floor-in-bst/0">Floor in BST</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p data-pm-slice="0 0 []">Given a <strong>root</strong> binary search tree and an integer <strong>x</strong>, complete the function that returns the floor of x in the BST.<br><strong>Note</strong>: The floor of x is defined as the greatest value in the tree that is less than or equal to x.<br>If no such value exists, return -1</p>
<p>&nbsp;</p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>       8
&nbsp;    /  \
&nbsp;   5    9
&nbsp;  / \    \
&nbsp; 2   6   10
X = 3
<strong>Output: </strong>2<strong>
Explanation: </strong>Floor of 3 in the given BST is 2</span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>       3
&nbsp;    /   \
&nbsp;   2     5
&nbsp;       /  \
&nbsp;      4    7
&nbsp;     /
&nbsp;    3
X = 1
<strong>Output: </strong>-1<strong>
Explanation: </strong>No smaller element exits</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ Number of nodes ≤ 10<sup>5</sup><br>1 ≤ x, Value of Node ≤ 10<sup>6</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Binary Search Tree</code>&nbsp;<code>Data Structures</code>&nbsp;