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
    int mid = (start + end) / 2;
    vector<int> leftApplicants = recursiveBestApplicant(app, start, mid);
    vector<int> rightApplicants = recursiveBestApplicant(app, mid+1, end);

    // Combine the two sets of best applicants
    vector<int> sol;
    int i = 0;
    int j = 0;
    while (i < leftApplicants.size() && j < rightApplicants.size()) {
        int bestLeft = leftApplicants[i], bestRight = rightApplicants[j];
        if (app[bestLeft].first >= app[bestRight].first) {
            if (app[bestLeft].second >= app[bestRight].second) {
                sol.push_back(bestLeft);
                i++;
            }
            else {
                j++;
            }
        }
        else {
            if (app[bestRight].second >= app[bestLeft].second) {
                sol.push_back(bestRight);
                j++;
            }
            else {
                i++;
            }
        }
    }
    while (i < leftApplicants.size()) {
        int bestLeft = leftApplicants[i];
        bool eligible = true;
        for (int k = j; k < rightApplicants.size(); k++) {
            if (app[bestLeft].first < app[rightApplicants[k]].first &&
                app[bestLeft].second > app[rightApplicants[k]].second) {
                eligible = false;
                break;
            }
        }
        if (eligible) {
            sol.push_back(bestLeft);
        }
        i++;
    }

    while (j < rightApplicants.size()) {
        int bestRight = rightApplicants[j];
        bool eligible = true;
        for (int k = i; k < leftApplicants.size(); k++) {
            if (app[bestRight].first < app[leftApplicants[k]].first &&
                app[bestRight].second > app[leftApplicants[k]].second) {
                eligible = false;
                break;
            }
        }
        if (eligible) {
            sol.push_back(bestRight);
        }
        j++;
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