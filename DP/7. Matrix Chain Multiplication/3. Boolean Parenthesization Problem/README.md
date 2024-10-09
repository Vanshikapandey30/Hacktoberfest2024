Boolean Parenthesization Problem
================================

Problem Definition
------------------

The **Boolean Parenthesization Problem** involves counting the number of ways to parenthesize a boolean expression such that it evaluates to a specified boolean value (True or False).

### Example

*   Input: `expression = "T|F&T^F"`, `result = True`
*   Output: `4` (There are 4 ways to parenthesize the expression to evaluate to True)

Solution Approaches
-------------------

### 1\. Recursive Approach (Exponential Time)

This approach recursively evaluates all possible ways to parenthesize the expression.

#### Pseudocode

    function countParentheses(expression, i, j, isTrue):
            if i == j:
                return (isTrue == (expression[i] == 'T')) ? 1 : 0
            count = 0
            for k from i + 1 to j step 2:
                leftTrue = countParentheses(expression, i, k - 1, true)
                leftFalse = countParentheses(expression, i, k - 1, false)
                rightTrue = countParentheses(expression, k + 1, j, true)
                rightFalse = countParentheses(expression, k + 1, j, false)
                totalWays = leftTrue + leftFalse
                if expression[k] == '&':
                    count += (isTrue) ? (leftTrue * rightTrue) : (totalWays * totalWays - leftTrue * rightTrue)
                else if expression[k] == '|':
                    count += (isTrue) ? (totalWays * totalWays - leftFalse * rightFalse) : (leftFalse * rightFalse)
                else if expression[k] == '^':
                    count += (isTrue) ? (leftTrue * rightFalse + leftFalse * rightTrue) : (leftTrue * rightTrue + leftFalse * rightFalse)
            return count
        

#### Java Implementation

    public class BooleanParenthesizationRecursive {
            public static int countParentheses(String expression, int i, int j, boolean isTrue) {
                if (i == j) {
                    return (isTrue == (expression.charAt(i) == 'T')) ? 1 : 0;
                }
                int count = 0;
                for (int k = i + 1; k < j; k += 2) {
                    int leftTrue = countParentheses(expression, i, k - 1, true);
                    int leftFalse = countParentheses(expression, i, k - 1, false);
                    int rightTrue = countParentheses(expression, k + 1, j, true);
                    int rightFalse = countParentheses(expression, k + 1, j, false);
                    int totalWays = leftTrue + leftFalse;
    
                    if (expression.charAt(k) == '&') {
                        count += (isTrue) ? (leftTrue * rightTrue) : (totalWays * totalWays - leftTrue * rightTrue);
                    } else if (expression.charAt(k) == '|') {
                        count += (isTrue) ? (totalWays * totalWays - leftFalse * rightFalse) : (leftFalse * rightFalse);
                    } else if (expression.charAt(k) == '^') {
                        count += (isTrue) ? (leftTrue * rightFalse + leftFalse * rightTrue) : (leftTrue * rightTrue + leftFalse * rightFalse);
                    }
                }
                return count;
            }
        }
        

### Time and Space Complexity (Recursive Approach)

*   **Time Complexity:** O(2<sup>n</sup>) - Due to the exponential number of recursive calls.
*   **Space Complexity:** O(n) - Space used by the recursion stack.

### 2\. Dynamic Programming Approach (O(n<sup>3</sup>))

This approach uses a 2D array to store results for subproblems, improving efficiency by avoiding redundant calculations.

#### Pseudocode

    function countParentheses(expression):
            n = length(expression)
            trueCount = 2D array of size n x n
            falseCount = 2D array of size n x n
            for i from 0 to n:
                trueCount[i][i] = (expression[i] == 'T') ? 1 : 0
                falseCount[i][i] = (expression[i] == 'F') ? 1 : 0
            for length from 2 to n:
                for i from 0 to n - length:
                    j = i + length - 1
                    for k from i + 1 to j step 2:
                        totalTrue = trueCount[i][k - 1] + falseCount[i][k - 1];
                        totalFalse = trueCount[k + 1][j] + falseCount[k + 1][j];
                        if expression[k] == '&':
                            trueCount[i][j] += trueCount[i][k - 1] * trueCount[k + 1][j];
                            falseCount[i][j] += totalTrue * totalFalse - trueCount[i][k - 1] * trueCount[k + 1][j];
                        else if expression[k] == '|':
                            trueCount[i][j] += totalTrue * totalFalse - falseCount[i][k - 1] * falseCount[k + 1][j];
                            falseCount[i][j] += falseCount[i][k - 1] * falseCount[k + 1][j];
                        else if expression[k] == '^':
                            trueCount[i][j] += trueCount[i][k - 1] * falseCount[k + 1][j] + falseCount[i][k - 1] * trueCount[k + 1][j];
                            falseCount[i][j] += trueCount[i][k - 1] * trueCount[k + 1][j] + falseCount[i][k - 1] * falseCount[k + 1][j];
            return trueCount[0][n - 1]
        

#### Java Implementation

    public class BooleanParenthesizationDP {
            public static int countParentheses(String expression) {
                int n = expression.length();
                int[][] trueCount = new int[n][n];
                int[][] falseCount = new int[n][n];
                for (int i = 0; i < n; i++) {
                    trueCount[i][i] = (expression.charAt(i) == 'T') ? 1 : 0;
                    falseCount[i][i] = (expression.charAt(i) == 'F') ? 1 : 0;
                }
                for (int length = 2; length <= n; length++) {
                    for (int i = 0; i <= n - length; i++) {
                        int j = i + length - 1;
                        for (int k = i + 1; k < j; k += 2) {
                            int totalTrue = trueCount[i][k - 1] + falseCount[i][k - 1];
                            int totalFalse = trueCount[k + 1][j] + falseCount[k + 1][j];
                            if (expression.charAt(k) == '&') {
                                trueCount[i][j] += trueCount[i][k - 1] * trueCount[k + 1][j];
                                falseCount[i][j] += totalTrue * totalFalse - trueCount[i][k - 1] * trueCount[k + 1][j];
                            } else if (expression.charAt(k) == '|') {
                                trueCount[i][j] += totalTrue * totalFalse - falseCount[i][k - 1] * falseCount[k + 1][j];
                                falseCount[i][j] += falseCount[i][k - 1] * falseCount[k + 1][j];
                            } else if (expression.charAt(k) == '^') {
                                trueCount[i][j] += trueCount[i][k - 1] * falseCount[k + 1][j] + falseCount[i][k - 1] * trueCount[k + 1][j];
                                falseCount[i][j] += trueCount[i][k - 1] * trueCount[k + 1][j] + falseCount[i][k - 1] * falseCount[k + 1][j];
                            }
                        }
                    }
                }
                return trueCount[0][n - 1];
            }
        }
        

### Time and Space Complexity (Dynamic Programming)

*   **Time Complexity:** O(n<sup>3</sup>) - Due to the three nested loops iterating over the expression length.
*   **Space Complexity:** O(n<sup>2</sup>) - Space used for the 2D arrays to store true and false counts.