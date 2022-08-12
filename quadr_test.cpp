#include <fstream>
#include "quadr.h"


//this function returns true if the given data 
//and the appropriate string in the given file are similiar 
bool match(std::fstream &g_file, std::string data) {
        std::string g_str;
        getline(g_file, g_str);
        return g_str == data;
}


//this function reads the values from the input file, calls the <quadr> function, 
//writes the gotten answer into the output file, compares it with the 
//corresponding data from the golden file and writes the appropriate message in
//the result file. These operations are performed one after another for every line 
void test() {
        std::fstream i_file;//input
        std::fstream o_file; //output
        std::fstream r_file; //result
        std::fstream g_file; //golden
        r_file.open("result.txt", std::ios::out);
        i_file.open("input.txt", std::ios::in);
        o_file.open("output.txt", std::ios::out);
        g_file.open("golden.txt", std::ios::in);
        std::string answer;
	std::string str1;
        std::string str2;
	std::string str3;
        while(!i_file.eof()) {
                i_file >> str1 >> str2 >> str3;
                if(i_file.eof()) {
			break;
		}
                quadr(answer, str1, str2, str3);
                o_file << answer << std::endl;
                if(match(g_file, answer)) {
		       	r_file << "-> test passed" << std::endl;
		}else {
		       	r_file << "-> test not passed" << std::endl;
		}
        }
        r_file.close();
        i_file.close();
        o_file.close();
        g_file.close();
}


int main() {
        test();
        return 0;
}


