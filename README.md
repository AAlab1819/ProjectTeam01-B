# ProjectTeam01-B
A comparison of implementation of &lt;problem name> using Dynamic Programming and Greedy

# [PROBLEM 917A - THE MONSTER](https://codeforces.com/problemset/problem/917/A)

## TEAM MEMBERS
- Angellica 
- Ariel Dimitri 
- Kayleen Priscilia 
- Raysa Gohtami 

## PROGRAMMING LANGUAGE
C++ 14

## Problem Explanation 
A string consisting only of parentheses ('( and ')') is called bracket sequence. 
- Empty string is a correct bracket sequence
- if s is a correct bracket sequence, then (s) is also a correct bracket sequence.
- if s and t are correct bracket sequences, then st (concatenation of s and t) is also a correct bracket sequence

A string consisting of parentheses and question marks ('?') is called pretty if and only if there's a way to replace each question mark with either '(' or ')' such that the resulting string is a non-empty correct bracket sequence.

We are asked in this problem to output how many correct bracket sequence in a string input. 

## SOLUTION 

### 1. Greedy Algorithm
One of the solution is to use greedy algorithm. Greedy algorithm is the one that always makes the choice that seems to be the best at that moment. The greedy algorithm has only one shot to compute the optimal solution so that it can never goes back and reverses the decision.
In this particular case, we can conclude that there are 3 methods in term of finding the correct bracket: 
1. |S| is even 
    example: ((?))
    - 'char=1' --> (   --> odd char --> not fulfilled
    - 'char=2' --> ((  --> even chars --> fulfilled
    - 'char=3' --> ((? --> odd chars --> not fulfilled
    - 'char=4' --> ((?) --> even chars --> fulfilled
    - 'char=5' --> ((?)) --> odd chars --> not fulfilled
    Therefore, there are 2 fulfilled condition for condition number 1, which are when |s| is even. 
2. Check one index with other index from left to right (encounter '(' and '?')
    * notes : we use 2 dimensional array because we want to check one index with another index, which will be explained below* 
    
             for(int i = 0; i < len; i++)  // checking one index
             {
            int cur = 0;
            for(int j = i; j < len; j++) { // with the index next to the first index that we check
            if(s[j] == '(' || s[j] == '?') // if we find '(' bracket and '?' (since '?' could be consider as correct bracket)
                                            //then the cur will be increase.
            {
                cur++;
            }
            else 
            {
            cur--;  
            }
            if(cur >= 0) 
            {
             vis[i][j]++;
            }
               else break; // if the cur is less than 0 than it did not meet the expectation of bracket that we desire in this  <br>                                    //particular method (for example: ")", "())", or "?))")
            }
             }
         
 * we use cur variable to save the changes and vis array to record the current "feasible" bracket. 
 
 3. Check the index with another index from right to left ( encounter ')' and '?') 
    it is similiar to the second method, but the index is checked from right index to left index. 
    Below is the code for this method.
    
        for(int i = len - 1;i >= 0;i--) {
        int cur = 0;
        for(int j = i;j >= 0;j--) {
            if(s[j] == ')' || s[j] == '?') {
                cur++;
            } else {
                cur--;
            }
            if(cur >= 0) vis[j][i]++;
            else break;
        }
           }
 
 lastly, for the output: 
 
          for(int i = 0;i < len;i++) {
          for(int j = 0;j < len;j++) {
          if((i + j) % 2 && vis[i][j] == 2) { /*if it's |S| equals to even, and the 'correct bracket' (vis[i][j]) is 2 as we
                                                already increase it from the code in 2nd and 3rd method, the ans will be increase to                                                     count the correct brackets.*/
             ans++;
                }
             }
          }
    
#### WHERE IS THE GREEDY PART? 
The greedy part is when we use those methods, which are checking one index with another index from right to left and also from left to right to find the optimal solution, in terms, not reverses the decision. By looking at our algorithm, we can see that it never reverses the decision which fit the one of the greedy terms.

COMPLEXITY : O(N^2) where N = |s|

#### INPUT SAMPLES

![GREEDY](https://github.com/AAlab1819/ProjectTeam01-B/blob/master/greedy%20monster.PNG)

### 2. Dynamic Programming
Dynamic Programming is to breaking down an optimization problem into simples sub-problems, and storing the solution to each sub-problem so that each sub-problem is only solved once. In order solve this problem by using DP, we use memoization which ensures that a method doesn't run for the same inputs more than once by keeping a record of the results for the given inputs. 

Memoization is used by using 'bool solve (int pos, int nopen)' and then 'temp' to store the calculation.
So, the 'bool solve' function is to finds out if a certain substring can be a valid sequence of brackets. 

        const char open='(',close=')';
        string str;
        int ans,e;
        int DP[5005][5005];

        bool solve(int pos,int nopen){
        if (pos==e)
            return nopen==0;
        if (DP[pos][nopen]!=-1)
            return DP[pos][nopen];
        if (str[pos]==open)
            return DP[pos][nopen]=solve(pos+1, nopen+1);
        if (str[pos]==close)
            return DP[pos][nopen]=nopen?solve(pos+1, nopen-1):false;
        return DP[pos][nopen]=max(nopen?solve(pos+1, nopen-1):false,solve(pos+1, nopen+1));
        }
        
Here is to output the amount of "correct bracket" in the inputted string. 

        cin>>str;
        for (int j=(int)str.size()-1; j>=0; j--) {
        memset(DP, -1, sizeof(DP));
        e=j+1;
        for (int i=0; i<j; i++) ans+=solve(i, 0);
        }
        cout<<ans<<endl;
        return 0;
        }

COMPLEXITY : O(N^4)

#### WHERE IS THE DP PART? 
The DP part is when we use 'bool solve' function for the memoization, to store the calculation so that it keeps the records of the results and does not run the same inputs more than once. So it is 'supposedly' should save time. 

#### INPUT SAMPLES
![DP](https://github.com/AAlab1819/ProjectTeam01-B/blob/master/monster%20dp.PNG)
### CONCLUSION 
Greedy is better than DP for this problem if we see from the memory and time complexity. One of the reason is DP uses nested loops which make the time complexity become higher. As we can see from the complexity of both techniques: 
- DP = O(N^4) 
- Greedy = O(N^2)
