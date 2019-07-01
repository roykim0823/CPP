## Column 2: Aha! Algorithm
1. Consider the problem of finding all the anagrams of a given input word. How would you solve this problem given only the word and the dictionary? What if you could spend some time and space to process the dictionary before answering any queries?
-> by signature (sortted version of the word). If this preprocessing is not allowed, then there is nothing we can do besides iterating through every word and comparing its signature to the word's signature.
2. Given a sequential file containing 4,300,000,000 32-bit integers, how can you find one that appears at least twice?
-> Using bitvector, O(n)
3. We skimmed two vector rotation algorithms that require subtle code; implement each as a program. How does the greatest common divisor of i and n appear in each program?
4. Several readers pointed out that while all three rotation algorithms require time proportional to n, the juggling algorithm is apparently twice as fast as the reversal algorithm: it stores and retrieves each element of the array just once, while the reversal algorithm does so twice. Experiment with the functions to compare their speeds on real machines; be especially sensitive to issues surrounding the locality of memory references.
-> Check the book solution
5. Vector rotation functions change the vector ab to ba; how would you transform the vector abc to cba? (This models the problem of swapping nonadjacent blocks of memory.)
6. In the late 1970's, Bell Labs deployed a "user-operated directory assistance" program that allowed employees to look up a number in a company telephone directory using a standard push-button telephone. To find the number of the designer of the system, Mike Lesk, one pressed "LESK*M*" (that is, "5375*6*") and the system spoke his number. Such services are now ubiquitous. One problem that arises in such systems is that different names may have the same push-button encoding; when this happens in Lesk's system, it asks the user for more information. Given a large file of names, such as a standard metropolitan telephone directory, how would you locate these "false matches"? (When Lesk did this experiment on such telephone directories, he found that the incidence of false matches was just 0.2 percent.) How would you implement the function that is given a push-button encoding of a name and returns the set of possible matching names?
-> Check the bool solution
7. In the early 1960's, Vic Vyssotsky worked with a programmer who had to transpose a 4000-by-4000 matrix stored on magnetic tape (each record had the same format in several dozen bytes). The original program his colleague suggested would have taken fifty hours to run; how did Vyssotsky reduce the run time to half an hour?
-> read sol/transpose.txt
8. [J. Ullman] Given a set of n real numbers, a real number t, and an integer k, how quickly can you determine whether there exists a k-element subset of the set that sums to at most t?
-> check sol/ksum.txt
9. Sequential search and binary search represent a tradeoff between search time and preprocessing time. How many binary searches need to be performed in an n-element table to buy back the preprocessing time required to sort the table?
-> check sol/binaryVsSeq.txt
