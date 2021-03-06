## Column 5: A Small Matter of Programming
5. [R. S. Cox] A common bug applies binary search to an unsorted array. Completely checking whether the array is sorted before each search has the exorbitant cost of n-1 extra comparisons. How can you add partial checking to the function at significantly less cost?
-----
First of all, let's assume that we want to keep the binary search runtime in O(log(n)). Thus, the extra comparisons must be made in O(1) time. 
We have two possible approaches to deal with this. 

The first and easier one is to look at m's neighbors in each iteration and check that x[m-1] <= x[m] <= x[m+1]. This requires 2 additional comparisons for each value of m, turning the binary search into O(2\*log(n)).

An alternative is to make sure that m's values make sense: when x[m] > t, then we will set u = m-1, and in the next iteration, the new value for m, m', must be a value such that x[m'] <= x[m]. This is true because we shrinked the upper limit, so if the array x is ordered, then the next value m' must index an element lower than the one indexed by m. 

Similarly, if x[m] < t, then we will be changing the lower range limit, so the next value m' must be a value such that x[m'] >= x[m]. This is generally a good solution, because for each value of m we just compute an additional comparison; the cost is that we need to use some more memory to store the previous m and what happened to the range (we need to know which one of lower or upper bound was changed so that we can test for the proper condition).
