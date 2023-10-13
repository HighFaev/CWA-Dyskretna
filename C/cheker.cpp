#include <bits/stdc++.h>

using namespace std;

int formula(int n, int m){
    return m;
}

int32_t main()
{  
    srand(time(NULL));
    int ans = 0;
    for(int test_number = 1; test_number <= 30; test_number++){
        fstream output_file_check("gen_output/output_check" + to_string(test_number) + ".txt");
        
        int n, m, steps;
        output_file_check >> n >> m >> steps;
        
        int formula_ans = formula(n, m);
        
        if (formula_ans == steps)
            ans++;
        
        output_file_check.close();
    }
    ofstream result_file("RESULT.txt");
    result_file << "Formula = m" << '\n';
    result_file << "Formula worked in " + to_string(ans) + " tests out of 30";
    result_file.close();
}