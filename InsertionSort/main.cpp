//
//  main.cpp
//  InsertionSort
//
//  Created by Sart Way on 8/2/23.
//

#include <iostream>
#include <string>
#include<algorithm>
#include<functional>
#include<fstream>
#include<vector>
#include <set>
#include <queue>
#include<map>
#include <chrono>
#include <thread>
#include "SwapSort.h"

using namespace std;

string ltrim(const string &str);
string rtrim(const string &str);
vector<string> split(const string &str);

int main(int argc, const char * argv[]) {
    
    fstream input("Testcase.txt", ios::in | ios::out);
    string intrepretor;
    
    if(input.is_open())
    {
        getline(input, intrepretor);
        int N = stoi(ltrim(rtrim(intrepretor)));
        
        int i = 0;
        vector<vector<int>>testcases(N);
        while(i<N)
        {
            string temp;
            getline(input, temp);
            int size = stoi(ltrim(rtrim(temp)));
            int* arr = new int[size];
            getline(input, temp);
            vector<string>values = split(ltrim(rtrim(temp)));
            int a = 0;
            for(auto x=values.begin();x!=values.end();++x)
            {
                testcases[i].push_back(stoi(*x));
                arr[a] = stoi(*x);
                ++a;
            }
//            SwapSort* sorter = new SwapSort();
//            cout << sorter->getAnswer(arr, (int)testcases[i].size()) << endl;
            SwapSort soter;
            soter.getAnswer(arr, a);
            cout << soter.count << endl;
            delete[] arr;
            ++i;
        }
        
        
        
    }
    
    
    input.close();
    return 0;
}



string ltrim(const string &str) {
    string s(str);

    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c);}));
    return s;

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c);}));
    return s;

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
