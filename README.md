# Project-3-----Job-Screening

You are the head of the HR department of your company. Your company wants to hire a new CTO (Chief
Talking Officer), and you are tasked with screening off initial applicants. You have decided to using two
criteria to screen the applicants. For each applicant, you measure two quantities:

- Words per minute (WPM): How many words can the applicant speak per minute and remain
clear. You would like that value to be as high as possible.

- Improper words per minute (IPM): There are certain words/phrases that are deemed improper
by your company. You want to detect how likely the applicant would mention those terms. You
want that value to be as low as possible.

We consider an applicant x to be an eligible candidate if there is no other applicants that is strictly
better than applicant x in both WPM and IPM. Your task is that, given a pool of applicants, select all the
eligible candidates.



The simplest way of solving this problem is a naïve double for loop:

````

    S = φ
    For each applicant x 
      Eligible = true
    For each applicant y that is not x
    If (y is better than x)
      Eligible = false
      Break
      If Eligible)
        Add x to the set of solution S
    Return S
  ````
  
  

This algorithm will take O(n2) time for a set of n applicants. However, there is a recursive solution to this
problem that you can implement and can run in O(n log n) time. Your task for this program is to
implement that algorithm.

- Your function should return a vector of integers containing the list of eligible candidates (each integer
denotes the location of the applicant in the applicants’ vector that is passed in. Notice that there cannot
be duplicate value in the output vector. 

You should write a second function, recursiveBestApplicant() that is the actual recursive algorithm.
The recursive algorithm:

The basic idea of the recursive algorithm is like this:
- Break your set of applicants into two groups
- Recursively find the best applicants of each group (as if that group is the only applicants)
- Combine the results of the two sets to form the final solution.
- For example, if you have six applicants (app[0] ... app[5]), what you may do is the following
- Divide the applicants into two groups (app[0], app[1], app[2]), (app[3], app[4], app[5]))
- In the group of (app[0], app[1], app[2]) find all applicants that are eligible (as if those 3 are the only applicants)
- Similar for the group (app[3], app[4], app[5])
- Look at the eligible candidate returns, and from them select the applicants that are eligible candidates (as if all 6 of them are applicants)

