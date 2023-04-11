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
    int middle = start + (end - start) / 2;
    // Find the best applicants from left and right
    vector<int> bestLeft = recursiveBestApplicant(app, start, middle);
    vector<int> bestRight = recursiveBestApplicant(app, (middle + 1), end);

    // Combine the two sets of best applicants
    vector<int> sol;
    sol.reserve(bestLeft.size() + bestRight.size());
    int i = 0;
    int j = 0;
    while (i < bestLeft.size() && j < bestRight.size()) {
        if (app[bestLeft[i]].second > app[bestRight[j]].second) {
            if (app[bestLeft[i]].first >= app[bestRight[j]].first) {
                sol.push_back(bestLeft[i]);
            }
            ++i;
        }
        else {
            if (app[bestRight[j]].first >= app[bestLeft[i]].first) {
                sol.push_back(bestRight[j]);
            }
            ++j;
        }
    }
    // Add remaining elements from bestLeft or bestRight, if any
    while (i < bestLeft.size()) {
        sol.push_back(bestLeft[i]);
        i++;
    }
    while (j < bestRight.size()) {
        sol.push_back(bestRight[j]);
        j++;
    }
    return sol;
}


// BestApplicants function which calls the recursiveeBestApplicant
vector<int> BestApplicants(const vector<pair<float, float>>& applicants) {
    // Find the best applicants and store their index in a vector
    vector<int> bestApp = recursiveBestApplicant(applicants, 0, applicants.size() - 1);
    // Order the indices in ascending order
    sort(bestApp.begin(), bestApp.end());
    // Return the indices of best applicants
    return bestApp;
}