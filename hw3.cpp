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
    // Find the best applicants from left
    vector<int> bestLeft = recursiveBestApplicant(app, start, middle);
    // Find the best applicants from right
    vector<int> bestRight = recursiveBestApplicant(app, (middle + 1), end);

    // Combine the two sets of best applicants
    vector<int> bestApplicant; // Vector to store the indexes of the best applicant(s)
    float bestWpm = 0.0;
    float bestIpm = std::numeric_limits<float>::max();
    int i = 0;
    int j = 0;
    while (i < bestLeft.size() || j < bestRight.size()) {
        if (i < bestLeft.size() && (app[bestLeft[i]].first > app[bestRight[j]].first) || j == bestRight.size() ) {
            // The applicant in the left group is better in WPM than the one in the right group
            if (app[bestLeft[i]].second < bestIpm) {
                // The applicant in the left group is also better in IPM
                bestWpm = app[bestLeft[i]].first;
                bestIpm = app[bestLeft[i]].second;
                bestApplicant = {bestLeft[i]};
            }
            else if (app[bestLeft[i]].second == bestIpm) {
                // The applicant in the left group is equally good in IPM as the best candidate so far
                bestApplicant.push_back(bestLeft[i]);
            }
            ++i;
        }
        else {
            // The applicant in the right group is better in WPM than the one in the left group
            if (app[bestRight[j]].second < bestIpm) {
                // The applicant in the right group is also better in IPM
                bestWpm = app[bestRight[j]].first;
                bestIpm = app[bestRight[j]].second;
                bestApplicant = {bestRight[j]};
            }
            else if (app[bestRight[j]].second == bestIpm) {
                // The applicant in the right group is equally good in IPM as the best candidate so far
                bestApplicant.push_back(bestRight[j]);
            }
            ++j;
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