# Project-3-----Job-Screening

Screening off initial applicants using two
criteria to screen the applicants. For each applicant, you measure two quantities:

- Words per minute (WPM): How many words can the applicant speak per minute and remain
clear. You would like that value to be as high as possible.

- Improper words per minute (IPM): There are certain words/phrases that are deemed improper
by your company. You want to detect how likely the applicant would mention those terms. You
want that value to be as low as possible.
- We consider an applicant x to be an eligible candidate if there is no other applicants that is strictly
better than applicant x in both WPM and IPM. Your task is that, given a pool of applicants, select all the
eligible candidates.

This algorithm will take O(n2) time for a set of n applicants. However, there is a recursive solution to this
problem that you can implement and can run in O(n log n) time.
