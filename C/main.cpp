#include <bits/stdc++.h>
#define int long long

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


void make_table(string file_name, vector<string> parametrs, vector<vector<int>> v){
    
    ofstream output_file(file_name);

    int number_of_parametrs = parametrs.size();
    int column_width = max_table_width/parametrs.size();
    int local_table_width = column_width * number_of_parametrs;

    string top_str = gen_top_string(number_of_parametrs+1, column_width);
    string middle_str = gen_middle_string(number_of_parametrs+1, column_width);
    string bottom_str = gen_bottom_string(number_of_parametrs+1, column_width);

    output_file << top_str << '\n';
    for(int i = -1; i < number_of_parametrs; i++){
        if(i == -1){
            output_file << "|"<< setw(column_width)  << "Step" << "|";
            continue;
        } else {                                 
            output_file << setw(column_width) << parametrs[i] << "|";
        }
    }
    output_file << '\n' << middle_str << '\n';

    for(int i = 0; i < v.size(); i++){
        for(int j = -1; j < number_of_parametrs; j++){
            if(j == -1){
               output_file << "|" << setw(column_width)  << i+1 << "|"; 
            } else {
               output_file << setw(column_width) << v[i][j] << "|"; 
            }
        }
        output_file << '\n';
        if(i == v.size() - 1){
            output_file << bottom_str << '\n';
        } else {
            output_file << middle_str << '\n';
        }
    }

    output_file.close();
}


int32_t main()
{
    srand(time(NULL));
    
    for(int test_number = 1; test_number <= 30; test_number++){
        string name_of_outputFile = "gen_output/output" + to_string(test_number) + ".txt";

        int i = 1;
        int n = rand() % (100*test_number*test_number);
        int m = rand() % (100*test_number*test_number);
        vector<string> parametrs = {"i", "j", "n", "m"};
        vector<vector<int>> steps = {};
        vector<int> step;
        while (i <= n){
            for(int j = i; j <= m; j++){
                if(i != 0){
                    cout << i << endl;
                }
                step = {i, j, n, m};
                steps.emplace_back(step);
                if(i * 4 > n){ //Lets be honest, i dont want to work with 4^1000000000 and greater numbers.
                    i = n + 1;
                } else {  
                    i = i * 4;
                }
            }
        }
        make_table(name_of_outputFile, parametrs, steps);

        ofstream output_file_check("gen_output/output_check" + to_string(test_number) + ".txt");
        output_file_check << n << ' ' << m << ' ' << steps.size();
        output_file_check.close();
    }
}