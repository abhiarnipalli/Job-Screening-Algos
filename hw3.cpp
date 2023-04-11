//
// Created by Abhilash Arnipalli on 4/7/23.
//
#include <vector>
#include <algorithm>
using namespace std;

vector<int> recursiveBestApplicant(const vector<pair<float, float>>& applicant, int begin, int end) {
    // Base case: there is only one applicant
    if (begin == end) {
        return {begin};
    }
    // Recursive case: divide the applicants in two groups
    int middle = begin + (end - begin) / 2;
    auto left = recursiveBestApplicant(applicant, begin, middle);
    auto right = recursiveBestApplicant(applicant, middle+1, end);
    // Combine the results of the two sets to form the final solution
    vector<int> best;
    float best_wpm = 0.0, best_ipm = numeric_limits<float>::max();
    int i = 0, j = 0;
    while (i < left.size() || j < right.size()) {
        if (i < left.size() && (j == right.size() || applicant[left[i]].first > applicant[right[j]].first)) {
            // The applicant in the left group is better in WPM than the one in the right group
            if (applicant[left[i]].second < best_ipm) {
                // The applicant in the left group is also better in IPM
                best_wpm = applicant[left[i]].first;
                best_ipm = applicant[left[i]].second;
                best = {left[i]};
            } else if (applicant[left[i]].second == best_ipm) {
                // The applicant in the left group is equally good in IPM as the best candidate so far
                best.push_back(left[i]);
            }
            ++i;
        } else {
            // The applicant in the right group is better in WPM than the one in the left group
            if (applicant[right[j]].second < best_ipm) {
                // The applicant in the right group is also better in IPM
                best_wpm = applicant[right[j]].first;
                best_ipm = applicant[right[j]].second;
                best = {right[j]};
            } else if (applicant[right[j]].second == best_ipm) {
                // The applicant in the right group is equally good in IPM as the best candidate so far
                best.push_back(right[j]);
            }
            ++j;
        }
    }
    return best;
}

vector<int> BestApplicants(const vector<pair<float, float>>& applicant) {
    auto best = recursiveBestApplicant(applicant, 0, applicant.size() - 1);
    sort(best.begin(), best.end());  // Sort the indices in ascending order
    return best;
}