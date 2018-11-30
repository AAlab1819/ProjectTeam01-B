# ProjectTeam01-B
A comparison of implementation of &lt;problem name> using Dynamic Programming and Greedy

# [PROBLEM 917A - THE MONSTER](https://codeforces.com/problemset/problem/917/A)
         

## TEAM MEMBERS
* Angellica 
* Ariel Dimitri 
* Kayleen Priscilia 
* Raysa Gohtami 

## PROGRAMMING LANGUAGE
C++ 14

## PROBLEM STATEMENT
 ![Problem 1](https://github.com/AAlab1819/ProjectTeam01-B/blob/master/problem%20monster%20first.PNG)
 ![Problem 2](https://github.com/AAlab1819/ProjectTeam01-B/blob/master/problem%20monster%20second.PNG)
 ![Problem 3](https://github.com/AAlab1819/ProjectTeam01-B/blob/master/problem%20monster%20third.PNG)

Basically, to solve this problem, we must find the "correct brackets" in a string. Hence, the time complexity and memory allocation must be considered in terms on creating a good and efficient algorithm. Therefore we use greedy and dynamic programming approach to compare which algorithm is better and more efficient. 

## INPUT/OUTPUT SAMPLES

### Sample #1 
__input__ 
```
(?))))?(
```

__output__
```
3
```
### Sample #2
__input__
```
(???((()))?)
```
__output__
```
15
```
### Sample #3
__input__
```
())??()(?()
```
__output__
```
11
```

## GREEDY ALGORITHM

### THOUGHT PROCESS
One of the solution is to use greedy algorithm. Greedy algorithm is the one that always makes the choice that seems to be the best at that moment. The greedy algorithm has only one shot to compute the optimal solution so that it can never goes back and reverses the decision. 
In this particular case, we can conclude that there are 3 methods in term of finding the correct bracket: 

1. |S| must be even. |S| is number of chars in a string that is/are currently checked. 
    Example: ((?))
    - |S| = 1 --> `(`  (not fulfilled)
    - |S| = 1 --> `(`  (not fulfilled)
    - |S| = 1 --> `?`  (not fulfilled)
    - (to be continued)
    
    - |S| = 2 --> `((`  (fulfilled)
    - |S| = 2 --> `(?`  (fulfilled)
    - |S| = 2 --> `?)`  (fulfilled)
    - |S| = 2 --> `))`  (fulfilled)
     
    - |S| = 3 --> `((?`  (not fulfilled)
    - |S| = 3 --> `(?)`  (not fulfilled)
    - |S| = 3 --> `?))`  (not fulfilled)
   
    - |S| = 4 --> `((?)` (fulfilled)
    - |S| = 4 --> `(?))` (fulfilled)
    
    - |S| = 5 --> `((?))` (not fulfilled)
     
2. if 0 ≤ s[1..i].count('(') + s[1..i].count('?') - s[1..i].count(')') for each 1 ≤ i ≤ |s|. Therefore, we must check one index with other index from left to right (encounter '(' and '?'). 2 dimensional array is used because we want to check one index with another index. Therefore to achieve this method, we use 'for' looping to check one index with another. 'cur' variable to save the changes and 'vis' array to record the current "feasible" bracket. If we find `(` bracket and `?` (since `?` could be considers as correct bracket, then the `cur` will be increased. Else, if `cur` is less than 0, then it did not meet the expetation of the bracket that we desire in this particular method (for example: ")", "())", or "?))" ) it will breaks.

         for(int i = 0; i < len; i++) 
         {
            int cur = 0;
            for(int j = i; j < len; j++) { 
            if(s[j] == '(' || s[j] == '?')                             
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
             else break;                               
               }
           }
         
 
 3. 0 ≤ s[i..|s|].count(')') + s[i..|s|].count('?') - s[i..|s|].count('(') for each 1 ≤ i ≤ |s|. Check the index with another index from right to left ( encounter ')' and '?'). It is similiar to the second method, but the index is checked from right index to left index. Below is the code for this method.
    
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
 
Lastly, for the output. If the `|S|` equals to even, and the 'correct bracket' `vis[i][j]` is 2 as we already increase it from the code in 2nd and 3rd method, the `ans` will be increase to count the correct brackets.
 
          for(int i = 0;i < len;i++) {
          for(int j = 0;j < len;j++) {
          if((i + j) % 2 && vis[i][j] == 2) { 
             ans++;
                }
             }
          }
 
The greedy part is when we check one index with another index from right to left and also from left to right to find the optimal solution, in terms, not reverses the decision. By looking at our algorithm, we can see that it never reverses the decision which fit the one of the greedy terms.
 
**TIME COMPLEXITY   : O(N^2) where N = |s|** | **MEMORY ALLOCATION : 0 (Insignificantly small)**

## DYNAMIC PROGRAMMING
Dynamic Programming is breaking down an optimization problem into simple sub-problems, and storing the solution to each sub-problem so that each sub-problem is only solved once. In order solve this problem by using DP, we use memoization which ensures that a method doesn't run for the same inputs more than once by keeping a record of the results for the given inputs. 

Memoization is used by using `bool solve (int pos, int nopen)` and then `temp` to store the calculation.
So, the `bool solve` function is to finds out if a certain substring can be a valid sequence of brackets. 

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

The DP part is when we use 'bool solve' function for the memoization, which is the optimization technique to store the calculation so they don't need to be recalculated. So it 'supposedly' should save time. But, as we can see, the time complexity is not as efficient as we expected to be. 

**TIME COMPLEXITY   : O(N^4)** | **MEMORY ALLOCATION : 0<=k<=10^9**

## COMPARISON 

|   __Input__             |    ((?))     | ()?)()()??()())( | ((()))()()??()()???)()(()())?)(?) | ()?(???(?(????????????(??((???(???....|
| ----------------------- | :----------: | :--------------: | :-------------------------------: | :---------------------------------: |
|  __Output__             |    4         | 29               | 91                                | 4270310                             |
|   __Greedy__            |    0.001 s   | 0.00099 s        | 0.002 s                           | 0.12 s                              |
| __Dynamic Programming__ |    0.157 s   | 0.327 s          | 0.636 s                           | TLE                                 |

 ## CONCLUSION
 
Greedy is better than DP for this problem in terms on memory and time complexity. One of the reason is that because DP uses nested loops which make the time complexity higher. The memory allocation of greedy is also significantly less than DP as DP require the creation of array with size of n, where n may be a number as big as 10^9.As we can see from the complexity of both techniques: 
- TIME COMPLEXITY:
   - DP = O(N^4) 
   - Greedy = O(N^2)
- MEMORY ALLOCATION:
   - DP = 0<=k<=10^9
   - Greedy = 0
