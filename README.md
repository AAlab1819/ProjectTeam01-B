# ProjectTeam01-B
A comparison of implementation of &lt;problem name> using Dynamic Programming and Greedy

# [PROBLEM 917A - THE MONSTER](https://codeforces.com/problemset/problem/917/A)

## Problem Explanation 
A string consisting only of parentheses ('( and ')') is called bracket sequence. 
- Empty string is a correct bracket sequence
- if s is a correct bracket sequence, then (s) is also a correct bracket sequence.
- if s and t are correct bracket sequences, then st (concatenation of s and t) is also a correct bracket sequence

A string consisting of parentheses and question marks ('?') is called pretty if and only if there's a way to replace each question mark with either '(' or ')' such that the resulting string is a non-empty correct bracket sequence.

We are asked in this problem to output how many correct bracket sequence in a string input. 

## SOLUTION 

### 1. Greedy Algorithm
One of the solution is to use greedy algorithm. Greedy algorithm means that always makes the choice that seems to be the best at that moment. The greedy algorithm has only one shot to compute the optimal solution so that it never goes back and reverses the decision
In this particular case, we can conclude that there are 3 condition in terms of finding the correct bracket: 
1. if |S| is even 
    example: 
    
    ((?)) 
 
