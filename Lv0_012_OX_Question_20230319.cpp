#include <string>
#include <vector>
#include <iostream>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : OX퀴즈
// 
// 문제 설명
// 덧셈, 뺄셈 수식들이 'X [연산자] Y = Z' 형태로 들어있는 문자열 배열 quiz가 매개변수로 주어집니다. 
// 수식이 옳다면 "O"를 틀리다면 "X"를 순서대로 담은 배열을 return하도록 solution 함수를 완성해주세요.
// 
// 제한사항
// 연산 기호와 숫자 사이는 항상 하나의 공백이 존재합니다. 단 음수를 표시하는 마이너스 기호와 숫자 사이에는 공백이 존재하지 않습니다.
// 1 ≤ quiz의 길이 ≤ 10
// X, Y, Z는 각각 0부터 9까지 숫자로 이루어진 정수를 의미하며, 각 숫자의 맨 앞에 마이너스 기호가 하나 있을 수 있고 이는 음수를 의미합니다.
// X, Y, Z는 0을 제외하고는 0으로 시작하지 않습니다.
// - 10, 000 ≤ X, Y ≤ 10, 000
// - 20, 000 ≤ Z ≤ 20, 000
// [연산자]는 + 와 - 중 하나입니다.
// 
// 입출력 예
// quiz	result
// ["3 - 4 = -3", "5 + 6 = 11"]["X", "O"]
// ["19 - 6 = 13", "5 + 66 = 71", "5 - 15 = 63", "3 - 1 = 2"]["O", "O", "X", "O"]
//
//*************************************************************************************************************************************

vector<string> solution(vector<string> quiz) {
    vector<string> answer;

    // 먼저 숫자와 연산기호를 구분하여 찾아야한다.
    // 연산기호를 치환 (" + ")(" - ")(" * ")(" / ")
    // = 기호 치환 (" = ")

    vector<string>::iterator iquiz;
    string temp_str;
    for (iquiz = quiz.begin(); iquiz != quiz.end(); iquiz++) {
        cout << "-----------------------------------------------------------" << endl;
        cout << *iquiz << endl;
        temp_str = *iquiz;                                                                                              // 개별 string 저장
        
        int find_blank_1, find_blank_2, find_blank_3, find_blank_4;
        int sub_start_1=0, sub_start_2=0, sub_start_3=0, sub_start_4=0;
        int sub_end_1=0, sub_end_2=0, sub_end_3=0, sub_end_4=0;

        find_blank_1 = temp_str.find_first_of(" ", 0);
        find_blank_2 = temp_str.find_first_of(" ", find_blank_1 + 1);
        find_blank_3 = temp_str.find_first_of(" ", find_blank_2 + 1);
        find_blank_4 = temp_str.find_first_of(" ", find_blank_3 + 1);

        cout << find_blank_1 << endl;
        cout << find_blank_2 << endl;
        cout << find_blank_3 << endl;
        cout << find_blank_4 << endl;

        if (find_blank_1 > 1) {
            sub_start_1 = 0;
            sub_end_1 = (find_blank_1 - 1) - sub_start_1 + 1;
        }
        else
            sub_start_1 = 0;

        sub_start_2 = find_blank_1 + 1;

        if (((find_blank_3 - 1) - (find_blank_2 + 1)) == 0) {
            sub_start_3 = find_blank_2 + 1;
        }
        else {
            sub_start_3 = find_blank_2 + 1;
            sub_end_3 = (find_blank_3 - 1) - (find_blank_2 + 1) + 1;
        }

        sub_start_4 = find_blank_4 + 1;
        sub_end_4 = (temp_str.size()) - (find_blank_4 + 1) + 1;


        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        int first_num, second_num, calc_num;
        char operator_chr;
        //----------------------------------------------------------------------------------------------------------------------------------------------------
        if (find_blank_1 > 1) {
            first_num = stoi(temp_str.substr(sub_start_1, sub_end_1));
            cout << "first number : " << first_num << endl;                                                             // 첫 번째 숫자 (0 ~ blank1-1)
        }
        else {
            char temp_chr = temp_str.at(sub_start_1);
            string temp_str2;
            temp_str2.push_back(temp_chr);
            first_num = stoi(temp_str2);
            cout << "first number : " << first_num << endl;                                                             // 첫 번째 숫자 (0 ~ blank1-1)
        }
        //----------------------------------------------------------------------------------------------------------------------------------------------------
        operator_chr = temp_str.at(sub_start_2);
        cout << "operator : " << operator_chr << endl;                                                                  // 연산자       (blank1+1)
        //----------------------------------------------------------------------------------------------------------------------------------------------------
        if (((find_blank_3 - 1) - (find_blank_2 + 1)) == 0) {
            char temp_chr = temp_str.at(sub_start_3);
            string temp_str2;
            temp_str2.push_back(temp_chr);
            second_num = stoi(temp_str2);
            cout << "second_number : " << second_num << endl;                                                           // 두 번째 숫자 (blank2+1 ~ blank3-1)
        }
        else {
            second_num = stoi(temp_str.substr(sub_start_3, sub_end_3));
            cout << "second_number : " << second_num << endl;                                                           // 두 번째 숫자 (blank2+1 ~ blank3-1)
        }
        //----------------------------------------------------------------------------------------------------------------------------------------------------
        calc_num = stoi(temp_str.substr(sub_start_4, sub_end_4));
        cout << "calc number : " << calc_num << endl;                                                                   // 결과값       (blank4+1 ~ end)

        if (operator_chr == '+') {
            if (first_num + second_num == calc_num)
                answer.push_back("O");
            else
                answer.push_back("X");
        }
        else if (operator_chr == '-') {
            if (first_num - second_num == calc_num)
                answer.push_back("O");
            else
                answer.push_back("X");
        }
        else if (operator_chr == '*') {
            if (first_num * second_num == calc_num)
                answer.push_back("O");
            else
                answer.push_back("X");
        }
        else if (operator_chr == '/') {
            if (first_num / second_num == calc_num)
                answer.push_back("O");
            else
                answer.push_back("X");
        }
    }
    return answer;
}

int main() {
    vector<string> input_quiz = { "19 - 6 = 13", "5 + 66 = 71", "5 - 15 = 63", "3 - 1 = 2" };
    vector<string> output_quiz = solution(input_quiz);

    vector<string>::iterator ioutput_quiz;
    for (ioutput_quiz = output_quiz.begin(); ioutput_quiz != output_quiz.end(); ioutput_quiz++) {
        cout << *ioutput_quiz << endl;
    }

    return 0;
}