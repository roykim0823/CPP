## Column 3 : Data Structure Programs
1. As the second edition of this book goes to press, individual income in the United States is taxed at five different rates, the maximum of which is around forty percent. The situation was formerly more complicated, and more expensive. A programming text gave the following twenty-fixe if statements as a reasonable approach for calculating the 1978 United States Federal Income Tax. The rate sequence .14, .15, .16, .17, .18, ... exhibits jumps larger than 0.01 later in the sequence. Any comments?

if income <= 2200
	tax = 0
else if income <= 2700
	tax = .14 * (income - 2200)
else if income <= 3200
	tax = 70 + .15 * (income - 2700)
else if income <= 3700
	tax = 145 + .16 * (income - 3200)
else if income <= 4200
	tax = 225 + .17 * (income - 3700)
	...
else
	tax = 53090 + .70 * (income - 102200)

2. A k-th order linear recurrence with constant coefficients defines a series as
	a_n = c_1*a_(n-1) + c_2*a_(n-2) + ... + c_k*a_(n-k) + c_(k+1),
where c\_1, ..., c\_(k+1) are real numbers. Write a program that with input k, a\_1, ..., a\_k, c\_1, ..., c\_(k+1), and m produces the output a\_1 through a\_m. How difficult is that program compared to a program that evaluates one particular fifth-order recurrence, but does so without using arrays?

3. Write a "banner" function that is given a capital letter as input and produces as output an array of characters that graphically depicts that letter.

4. Write functions for the following date problems: given two dates, compute the number of days between them; given a date, return its day of the week; given a month and year, produce a calendar for the month as an array of characters.

5. This problem deals with a small part of the problem of hyphenating English words. The following list of rules describes some legal hyphenations of words that end in the letter "c":
	et-ic al-is-tic s-tic p-tic -lyt-ic ot-ic an-tic n-tic c-tic at-ic h-nic n-ic m-ic l-lic b-lic -clic
	l-ic h-ic f-ic d-ic -bic a-i -mac i-ac
The rules must be applied in the above order; thus the hyphenations "eth-nic" (which is caught by the rule "h-nic") and "clinic" (which fails that test and falls through to "n-ic"). How would you represent such rules in a function that is given a word and must return suffix hyphenations?

6. Build a "form-letter generator" that can prepare a customized document for each record in a database (this is often referred to as a "mail-merge" feature). Design small schemas and input files to test the correctness of your program.

7. Typical dictionaries allow one to look up the definition of a word, and Problem 2.1 describes a dictionary that allows one to look up the anagrams of a word. Design dictionaries for looking up the proper spelling of a word and for looking up the rhymes of a word. Discuss dictionaries for looking up an integer sequence (such as 1, 1, 2, 3, 5, 8, 13, 21, ...), a chemical structure, or the metrical structure of a song.

8. [S. C. Johnson] Seven-segment devices provide an inexpensive display of the ten decimal digits:
          __        __   __        __   __   __   __   __ 
		 |  |    |  __|  __| |__| |__  |__     | |__| |__|
		 |__|    | |__   __|    |  __| |__|    | |__|    |
		 
The seven segments are usually numbered as

  _2_
3|_1_|4
5|_0_|6

Write a program that displays a 16-bit positive integer in five seven-segment digits. The output is an array of five bytes; bit i of byte j is one if and only if the i-th segment of digit j should be on.
