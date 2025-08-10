# =ob-Screening



- Words per minute (WPM): How many words can the applicant speak per minute and remain clear. We would like that value to be as high as possible.

- Improper words per minute (IPM): There are certain words/phrases that are deemed improper by your company. We want to detect how likely the applicant would mention those terms. We want that value to be as low as possible.

We consider an applicant x to be an eligible candidate if there is no other applicants that is strictly better than applicant x in both WPM and IPM. 

The way this can be solved is below:

````
vector<int> naiveBestApplicants(const vector<pair<float, float>>& applicants){
    vector<int> sol;
    for (int i = 0; i < applicants.size(); i++){
        bool eligible = true;
        for (int j = 0; j < applicants.size(); j++){
            if ((i != j) && (applicants[i].first < applicants[j].first) && (applicants[i].second > applicants[j].second)){
                eligible = false;
                break;
            }
        }
        if (eligible) {
            sol.push_back(i);
        }
    }
    return sol;
}
  ````
  
  

This algorithm will take O(n^2) time for a set of n applicants. However, there is a recursive solution to this
problem that we can implement and can run in O(n log n) time. In this project, we
implement that algorithm.

- The function returns a vector of integers containing the list of eligible candidates (each integer
denotes the location of the applicant in the applicants’ vector that is passed in. Notice that there cannot
be duplicate value in the output vector. 

A second function was written, recursiveBestApplicant() that is the actual recursive algorithm.
The recursive algorithm:

# The basic idea of the recursive algorithm is like this:
- Break your set of applicants into two groups
- Recursively find the best applicants of each group (as if that group is the only applicants)
- Combine the results of the two sets to form the final solution.
- For example, if you have six applicants (app[0] ... app[5]), what you may do is the following
- Divide the applicants into two groups (app[0], app[1], app[2]), (app[3], app[4], app[5]))
- In the group of (app[0], app[1], app[2]) find all applicants that are eligible (as if those 3 are the only applicants)
- Similar for the group (app[3], app[4], app[5])
- Look at the eligible candidate returns, and from them select the applicants that are eligible candidates (as if all 6 of them are applicants)

