#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "quadr.h"

//this function checks whether the string is a real number or not
bool is_real(std::string str)
{
        int countDots = 0;
        if(str[0] == '.' || str[str.length() - 1] == '.') {
                return false;
        }
        for(int i = 0; i < str.length(); i++) {
                if(str[i] == '-' && i == 0) {
                        continue;
                }
                if(str[i] < '0' || str[i] > '9') {
                        if(str[i] == '.') {
                                countDots++;
                        }
                        else{
                                return false;
                        }
                }
        }
        return countDots <= 1;
}

//this function sets the precision of the double <a> number as <n>
//if the precision of the given <a> number is less than <n> 
//the <a> number remains the same
std::string set_precision(double a, int n)
{
        if(a == (-0)) {
                return "0";
	}
        std::string str = std::to_string(a); //12.34 => 12.340000
        int i=0;
        while(str[i] != '.') {
                i++;
        }
        while((str.length()-1 > i) && str[str.length()-1]=='0') {
                str.pop_back();
        }
        if(str[str.length()-1] == '.') {
                str.pop_back();
                return str;
        }
        int after_point = str.length() - 1 - i;
        if(after_point > n) {
                for(int j = 0; j < after_point - n; j++) {
                        str.pop_back();
                }
        }
        return str;
}

//this function solves the ax+b=0 linear equation, where str1=a, str2=b
//and stores the result in the string "answer"
void linear(std::string &answer, std::string str1, std::string str2)
{
        if(!is_real(str1) || !is_real(str2)) {
                answer = "mistake";
        }
        else{
                double a = std::stod(str1);
                double b = std::stod(str2);
                if(a == 0 && b == 0) {
                        answer = "R"; //infinity
                }else if(b != 0 && a == 0) {
                        answer = "no solution";
                }else if(b == 0) {
                        answer = '0';
                }else{
                        answer = set_precision(- b / a, 3);
                }
        }
}

//this function solves the quadratic equation ax^2+bx+c=0, where a, b, and c are given as 
//str1, str2, str3.  Answer is written in the <answer> string
void quadr(std::string &answer, std::string str1, std::string str2, std::string str3)
{
        if(!is_real(str1) || !is_real(str2) || !is_real(str3)) {
                answer = "mistake";
        }
        else{
                double a = std::stod(str1);
                if(a == 0) {
                        linear(answer, str2, str3);
                }
                else {
                        double b = std::stod(str2);
			double c = std::stod(str3);
                        double d = b * b - 4 * a * c;
                        if(d == 0) {
                                answer = set_precision( - b / ( 2 * a ), 3);
                        }
                        else if(d < 0) {
                                answer = "no solution";
                        }else {
                                double s1 = (- b + sqrt(d)) / (2 * a);
                                double s2 = (-b - sqrt(d)) / (2 * a);
                                if(s1 < s2) {
                                        answer = set_precision(s1, 3) + " " + set_precision(s2, 3);
				} else {
                                        answer = set_precision(s2, 3) + " " + set_precision(s1, 3);
				}
                        }
                }
        }
}

