//
// Created by Abhilash Arnipalli on 4/7/23.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std::chrono;
using namespace std;

vector<int> BestApplicants(const vector<pair<float, float>>& applicants);

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

int main(int argc, char** argv){
    int n;
    ifstream ifile("hw3data.txt");
    vector<pair<float, float> > applicants;
    ifile >> n;

    cout << "n : " << n << endl;
    for (int i = 0; i < n; i++){
        float p, q;
        ifile >> p >> q;
        applicants.push_back(make_pair(p, q));
    }
    vector<int> sol = naiveBestApplicants(applicants);
    cout << "Naive Solution: ";
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    cout << endl;

    // start run time clock
    auto start = high_resolution_clock::now();
    vector<int> sol2 = BestApplicants(applicants);
    //stop run time clock
    auto stop = high_resolution_clock::now();

    cout << "Recursive Solution:" ;
    for (int i = 0; i < sol2.size(); i++) {
        cout << sol2[i] << " ";
    }
    cout << endl;

    //output runtime
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runtime: " << duration.count() << " microseconds" << endl;

    return 0;
}
