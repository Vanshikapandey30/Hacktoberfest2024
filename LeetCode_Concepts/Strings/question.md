# Leetcode String Questions 

## Table of Contents
1. ['Minimum number of swaps to make the string balanced'](#Q1)
2. ['Sentence Similarity 3'](#Q2)
3. ['Permutation in String'](#Q3)
4. ['Reverse Vowels Of a String'](#Q4)
5. ['Greatest Common Divisor'](#Q5)
6. ['Merge Strings Alternatively'](#Q6)
7. ['Find the length of the longest common prefix'](#Q7)
8. ['Extra Characters in a String'](#Q8)
9. ['Different ways to add parenthesis'](#Q9)
10. ['Reverse Words in a string'](#Q10)


# #Q1 
<h1>Minimum number of swaps to make the string balanced</h1>
Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 10^4.

### Test Cases 
<h2>Example 1:</h2>

<h2>Input:</h2>expression = "2-1-1"
<h2>Output:</h2> [0,2]
<h2>Explanation:</h2>
((2-1)-1) = 0 
(2-(1-1)) = 2


<h2>Example 2:</h2>

<h2>Input:</h2> expression = "2*3-4*5"
<h2>Output:</h2> [-34,-14,-10,-10,10]
<h2>Explanation:</h2>
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10

<h2>Reference:</h2>
https://leetcode.com/problems/different-ways-to-add-parentheses/description/


# #Q2
<h1>Sentence Similarity 3</h1>
You are given two strings sentence1 and sentence2, each representing a sentence composed of words. A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of only uppercase and lowercase English characters.

Two sentences s1 and s2 are considered similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. Note that the inserted sentence must be separated from existing words by spaces.

For example,

s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in s1.
s1 = "Frog cool" and s2 = "Frogs are cool" are not similar, since although there is a sentence "s are" inserted into s1, it is not separated from "Frog" by a space.
Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.


### Test Cases 
<h2>Example 1:</h2>

<h2>Input:</h2>sentence1 = "My name is Haley", sentence2 = "My Haley"
<h2>Output:</h2> true
<h2>Explanation:</h2>
sentence2 can be turned to sentence1 by inserting "name is" between "My" and "Haley".

<h2> Example 2:</h2>

<h2>Input:</h2> sentence1 = "of", sentence2 = "A lot of words"
<h2>Output:</h2> false
<h2>Explanation:</h2>
No single sentence can be inserted inside one of the sentences to make it equal to the other.

<h2>Reference:</h2>
https://leetcode.com/problems/sentence-similarity-iii/description/


# #Q3
<h1>Permutation in String</h1>

Given two strings s1 and s2, return true if s2 contains a 
permutation
 of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

### Test Cases 
<h2>Example 1:</h2>

<h2>Input:</h2> s1 = "ab", s2 = "eidbaooo"
<h2>Output:</h2> true
<h2>Explanation:</h2>
s2 contains one permutation of s1 ("ba").

<h2> Example 2:</h2>

<h2>Input:</h2> s1 = "ab", s2 = "eidboaoo"
<h2>Output:</h2> false

<h2>Reference:</h2>
https://leetcode.com/problems/permutation-in-string/description/



# #Q4

<h1></h1>
