#include "quadr.h"
#include <string>
#include <fstream>


int main()
{
        std::ifstream i_file;
        std::ofstream o_file;
        i_file.open("input.txt");
        o_file.open("output.txt");
        std::string answer, str1, str2, str3;
        while(!i_file.eof()) {
                i_file >> str1 >> str2 >> str3;
                if(i_file.eof()) {
			break;
		}
                quadr(answer, str1, str2, str3);
                o_file << answer << std::endl;
        }
        i_file.close();
        o_file.close();
}

