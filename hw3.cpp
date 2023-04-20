//
// Created by Abhilash Arnipalli on 4/7/23.
//
#include <vector>
#include <algorithm>
using namespace std;


vector<int> recursiveBestApplicant(const vector<pair<float, float>>& app, int start, int end){
    if (start == end) {
        return {start};
    }
    int middle = (start + end) / 2;
    // split applicants into 2 groups, left and right
    vector<int> leftSide = recursiveBestApplicant(app, start, middle);
    vector<int> rightSide = recursiveBestApplicant(app, middle + 1, end);
    vector<int> sol;
    int i = 0;
    int j = 0;
    while (i < leftSide.size() && j < rightSide.size() ) {
        int bestLeft = leftSide[i], bestRight = rightSide[j];
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
    while (i < leftSide.size()) {
        int bestLeft = leftSide[i];
        bool isEligible = true;
        for (int k = j; k < rightSide.size(); k++) {
            if (app[bestLeft].first < app[rightSide[k]].first && app[bestLeft].second > app[rightSide[k]].second) {
                isEligible = false;
                break;
            }
        }
        if (isEligible) {
            sol.push_back(bestLeft);
        }
        i++;
    }
    while (j < rightSide.size()) {
        int bestRight = rightSide[j];
        bool eligible = true;
        for (int k = i; k < leftSide.size(); k++) {
            if (app[bestRight].first < app[leftSide[k]].first && app[bestRight].second > app[leftSide[k]].second) {
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



// BestApplicants function
vector<int> BestApplicants(const vector<pair<float, float>>& applicants) {
    // Find the best applicants by calling recursive function
    vector<int> bestApplicants = recursiveBestApplicant(applicants, 0, (applicants.size() - 1) );
    // Sort indices in order
    sort(bestApplicants.begin(), bestApplicants.end());
    // Return the best applicants vector of integers
    return bestApplicants;
}