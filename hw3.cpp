//
// Created by Abhilash Arnipalli on 4/7/23.
//
#include <vector>
#include <algorithm>
#include <float.h>
using namespace std;

vector<int> recursiveBestApplicant(const vector<pair<float, float>>& app, int start, int end) {
    // Base case
    if (start == end) {
        return {start};
    }
    // Break your set of applicants into two groups, start by finding the middle
    int middle = start + (end - start) / 2;
    // Find the best applicants from left
    auto left = recursiveBestApplicant(app, start, middle);
    // Find the best applicants from right
    auto right = recursiveBestApplicant(app, (middle + 1), end);

    // Combine the results of the two groups to form the final solution
    vector<int> bestApplicant; // Initialize the vector to store the index(es) of the best applicant(s)
    float bestWpm = 0.0;
    float bestIpm = std::numeric_limits<float>::max(); // Initialize the variables to store the best WPM and IPM values
    //float bestIpm = FLT_MAX;
    int i = 0;
    int j = 0;
    while (i < left.size() || j < right.size()) {
        if (i < left.size() && (j == right.size() || app[left[i]].first > app[right[j]].first)) {
            // The applicant in the left group is better in WPM than the one in the right group
            if (app[left[i]].second < bestIpm) {
                // The applicant in the left group is also better in IPM
                bestWpm = app[left[i]].first;
                bestIpm = app[left[i]].second;
                bestApplicant = {left[i]};
            }
            else if (app[left[i]].second == bestIpm) {
                // The applicant in the left group is equally good in IPM as the best candidate so far
                bestApplicant.push_back(left[i]);
            }
            i++;
        }
        else {
            // The applicant in the right group is better in WPM than the one in the left group
            if (app[right[j]].second < bestIpm) {
                // The applicant in the right group is also better in IPM
                bestWpm = app[right[j]].first;
                bestIpm = app[right[j]].second;
                bestApplicant = {right[j]};
            }
            else if (app[right[j]].second == bestIpm) {
                // The applicant in the right group is equally good in IPM as the best candidate so far
                bestApplicant.push_back(right[j]);
            }
            j++;
        }
    }
    return bestApplicant;
}


vector<int> BestApplicants(const vector<pair<float, float>>& applicants) {
    // Find the best applicant(s) from the entire list of applicants
    auto S1 = recursiveBestApplicant(applicants, 0, applicants.size() - 1);
    // Sort the indices of the best applicant(s) in ascending order
    sort(S1.begin(), S1.end());
    // Return the indices of the best applicant(s)
    return S1;
}