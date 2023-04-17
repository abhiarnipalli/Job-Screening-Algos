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

    // Divide the set of applicants into two groups
    int middle = (start + end) / 2;
    vector<int> leftSide = recursiveBestApplicant(app, start, middle);
    vector<int> rightSide = recursiveBestApplicant(app, middle + 1, end);

    // Combine the two sets of best applicants
    vector<int> sol;
    int i = 0;
    int j = 0;
    while (i < leftSide.size() && j < rightSide.size() ) {
        // Compare the best applicants from the left and right groups
        int bestLeft = leftSide[i], bestRight = rightSide[j];
        if (app[bestLeft].first >= app[bestRight].first) {
            if (app[bestLeft].second >= app[bestRight].second) {
                // If the left applicant is better than or equal to the right applicant in both criteria,
                // add the left applicant to the solution and move to the next left applicant
                sol.push_back(bestLeft);
                i++;
            }
            else {
                // Otherwise, move to the next right applicant
                j++;
            }
        }
        else {
            if (app[bestRight].second >= app[bestLeft].second) {
                // If the right applicant is better than or equal to the left applicant in both criteria,
                // add the right applicant to the solution and move to the next right applicant
                sol.push_back(bestRight);
                j++;
            }
            else {
                // Otherwise, move to the next left applicant
                i++;
            }
        }
    }

    // Add any remaining best applicants from the left group to the solution
    while (i < leftSide.size()) {
        int bestLeft = leftSide[i];
        bool isEligible = true;
        for (int k = j; k < rightSide.size(); k++) {
            // Check if the left applicant is eligible by comparing them to all remaining right applicants
            if (app[bestLeft].first < app[rightSide[k]].first && app[bestLeft].second > app[rightSide[k]].second) {
                isEligible = false;
                break;
            }
        }
        if (isEligible) {
            // If the left applicant is eligible, add them to the solution and move to the next left applicant
            sol.push_back(bestLeft);
        }
        i++;
    }


    // Add any remaining best applicants from the right group to the solution
    while (j < rightSide.size()) {
        int bestRight = rightSide[j];
        bool eligible = true;
        for (int k = i; k < leftSide.size(); k++) {
            // Check if the right applicant is eligible by comparing them to all remaining left applicants
            if (app[bestRight].first < app[leftSide[k]].first && app[bestRight].second > app[leftSide[k]].second) {
                eligible = false;
                break;
            }
        }
        if (eligible) {
            // If the right applicant is eligible, add them to the solution and move to the next right applicant
            sol.push_back(bestRight);
        }
        j++;
    }
    return sol;
}








// BestApplicants function which calls the recursiveBestApplicant function
vector<int> BestApplicants(const vector<pair<float, float>>& applicants) {
    // Find the best applicants and store their index in a vector
    vector<int> bestApplicants = recursiveBestApplicant(applicants, 0, (applicants.size() - 1) );
    // Sort indices
    sort(bestApplicants.begin(), bestApplicants.end());
    // Return best applicants
    return bestApplicants;
}