//
// Created by Abhilash Arnipalli on 4/7/23.
//
#include <vector>
#include <algorithm>
using namespace std;

vector<int> recursiveBestApplicant(const vector<pair<float, float>>& app, int start, int end) {
    // Base case
    if (start == end) {
        return {start};
    }
    // Break the set of applicants into two groups, start by finding the middle
    int middle = (start + (end - start) / 2);
    // Find the best applicants from left and right side
    vector<int> left = recursiveBestApplicant(app, start, middle);
    vector<int> right = recursiveBestApplicant(app, (middle + 1), end);

    // Combine the two sets of best applicants
    vector<int> sol;
    for (int i = 0, j = 0; i < left.size() || j < right.size();) {
        if (i < left.size() && (j == right.size() || app[left[i]].second > app[right[j]].second)) {
            const float& leftFirst = app[left[i]].first;
            const float& leftSecond = app[left[i]].second;
            if (j == right.size() || leftFirst >= app[right[j]].first) {
                sol.push_back(left[i]);
            }
            ++i;
        }
        else {
            const float& rightFirst = app[right[j]].first;
            const float& rightSecond = app[right[j]].second;
            if (i == left.size() || rightFirst >= app[left[i]].first) {
                sol.push_back(right[j]);
            }
            ++j;
        }
    }
    return sol;
}

// BestApplicants function which calls the recursiveeBestApplicant
vector<int> BestApplicants(const vector<pair<float, float>>& applicants) {
    // Find the best applicants and store their index in a vector
    vector<int> bestApplicants = recursiveBestApplicant(applicants, 0, (applicants.size() - 1) );
    // Sort indices
    sort(bestApplicants.begin(), bestApplicants.end());
    // Return best applicants
    return bestApplicants;
}