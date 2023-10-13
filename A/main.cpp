#include <bits/stdc++.h>

using namespace std;

int max_table_width = 50;

string gen_top_string(int n, int w){
    string s = "┌";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < w; j++)
            s += "─";
        if(i != n - 1){
            s += "┬";
        } else {
            s += "┐";
        }
    }
    return s;
}

string gen_bottom_string(int n, int w){
    string s = "└";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < w; j++)
            s += "─";
        if(i != n - 1){
            s += "┴";
        } else {
            s += "┘";
        }
    }
    return s;
}

string gen_middle_string(int n, int w){
    string s = "├";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < w; j++)
            s += "─";
        if(i != n - 1){
            s += "┼";
        } else {
            s += "┤";
        }
    }
    return s;
}


void make_table(vector<string> parametrs, vector<vector<int>> v){
    int number_of_parametrs = parametrs.size();
    int column_width = max_table_width/parametrs.size();
    int local_table_width = column_width * number_of_parametrs;
    
    
    string top_str = gen_top_string(number_of_parametrs+1, column_width);
    string middle_str = gen_middle_string(number_of_parametrs+1, column_width);
    string bottom_str = gen_bottom_string(number_of_parametrs+1, column_width);
    
    cout << top_str << '\n';
    for(int i = -1; i < number_of_parametrs; i++){
        if(i == -1){
            cout << "|"<< setw(column_width)  << "Step" << "|";
            continue;
        } else {                                 
            cout << setw(column_width) << parametrs[i] << "|";
        }
    }
    cout << '\n' << middle_str << '\n';
    for(int i = 0; i < v.size(); i++){
        for(int j = -1; j < number_of_parametrs; j++){
            if(j == -1){
               cout << "|"<< setw(column_width)  << i+1 << "|"; 
            } else {
               cout << setw(column_width) << v[i][j] << "|"; 
            }
        }
        cout << '\n';
        if(i == v.size() - 1){
            cout << bottom_str;
        } else {
            cout << middle_str << '\n';
        }
    }
}


int32_t main()
{
    freopen("output.txt", "w", stdout);
    //make_table({"a","b","c"}, {{1,2,3},{1,2,3},{1,2,3}});
    int i = 0;
    vector<string> parametrs = {"i"};
    vector<vector<int>> steps = {};
    vector<int> step;
    while (i <= 11){
        step = {i};
        steps.push_back(step);
        step.clear();
        i = i + 2;
    }
    make_table(parametrs, steps);
}