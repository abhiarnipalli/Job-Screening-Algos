//
// Created by Abhlash Arnipalli on 4/7/23.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Helper function to compare two applicants based on WPM and IPM
bool compareApplicants(const pair<float, float>& a, const pair<float, float>& b) {
    if (a.first != b.first) {
        return a.first > b.first; // Sort by decreasing WPM
    } else {
        return a.second < b.second; // Sort by increasing IPM if WPM is equal
    }
}

// Recursive function to find the best applicants
vector<int> recursiveBestApplicant(const vector<pair<float, float>>& applicants, int left, int right) {
    vector<int> bestApplicants;

    // Base case: If there is only one applicant, it is automatically the best
    if (left == right) {
        bestApplicants.push_back(left);
        return bestApplicants;
    }

    // Divide the applicants into two groups
    int mid = left + (right - left) / 2;
    vector<int> bestLeft = recursiveBestApplicant(applicants, left, mid);
    vector<int> bestRight = recursiveBestApplicant(applicants, mid + 1, right);

    // Combine the results of the two sets to form the final solution
    int bestIPM = INT_MAX;
    for (int i : bestLeft) {
        if (applicants[i].second < bestIPM) {
            bestIPM = applicants[i].second;
            bestApplicants.clear();
            bestApplicants.push_back(i);
        } else if (applicants[i].second == bestIPM) {
            bestApplicants.push_back(i);
        }
    }
    for (int i : bestRight) {
        if (applicants[i].second < bestIPM) {
            bestIPM = applicants[i].second;
            bestApplicants.clear();
            bestApplicants.push_back(i);
        } else if (applicants[i].second == bestIPM) {
            bestApplicants.push_back(i);
        }
    }

    // Sort the final solution by decreasing WPM
    sort(bestApplicants.begin(), bestApplicants.end(), [&](int a, int b) {
        return applicants[a].first > applicants[b].first;
    });

    return bestApplicants;
}

// Main function to find the best applicants
vector<int> BestApplicants(const vector<pair<float, float>>& applicants) {
    // Sort the applicants in decreasing order of WPM and increasing order of IPM
    vector<pair<float, float>> sortedApplicants = applicants;
    sort(sortedApplicants.begin(), sortedApplicants.end(), compareApplicants);

    // Call the recursive function to find the best applicants
    return recursiveBestApplicant(sortedApplicants, 0, sortedApplicants.size() - 1);
}