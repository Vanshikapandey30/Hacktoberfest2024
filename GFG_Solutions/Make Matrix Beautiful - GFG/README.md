# Make Matrix Beautiful
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">A beautiful matrix is a matrix in which the sum of elements in each row and column is equal. Given a square matrix&nbsp;of size <strong>N</strong>x<strong>N</strong>. Find the&nbsp;minimum number of operation(s) that are required to make the matrix beautiful.&nbsp;In one operation you can&nbsp;<strong>increment</strong> the&nbsp;value of any one&nbsp;<strong>cell by 1</strong>.<br><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>:
N = 2
matrix[][] = {{1, 2},
&nbsp;             {3, 4}}
<strong>Output</strong>: <br>4
<strong>Explanation</strong>:
Updated matrix:
4 3
3 4
1. Increment value of cell(0, 0) by 3
2. Increment value of cell(0, 1) by 1
Hence total 4 operation are required.
</span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>:
N = 3
matrix[][] = {{1, 2, 3},
&nbsp;             {4, 2, 3},
&nbsp;             {3, 2, 1}}
<strong>Output</strong>: <br>6
<strong>Explanation</strong>:
Number of operations applied on each cell are as follows:<br>1 2 0<br>0 0 0<br>0 1 2<br>Such that all rows and columns have sum of 9.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Your Task:&nbsp;</strong><br>You don't need to read input or print anything.&nbsp;Complete the function <strong>findMinOpeartion()&nbsp;</strong>that takes <strong>matrix and n</strong> as input&nbsp;<strong>parameters </strong>and returns the&nbsp;<strong>minimum number of operations</strong>.</span><br><br><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong>&nbsp;O(N * N)<br><strong>Expected Auxiliary Space:</strong>&nbsp;O(N)</span><br><br><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= N &lt;= 10<sup>3</sup><br>1 &lt;= matrix[i][j] &lt;= 10<sup>6</sup></span></p></div>