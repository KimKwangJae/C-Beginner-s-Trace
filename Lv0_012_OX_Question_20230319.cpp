#include <string>
#include <vector>
#include <iostream>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : OX����
// 
// ���� ����
// ����, ���� ���ĵ��� 'X [������] Y = Z' ���·� ����ִ� ���ڿ� �迭 quiz�� �Ű������� �־����ϴ�. 
// ������ �Ǵٸ� "O"�� Ʋ���ٸ� "X"�� ������� ���� �迭�� return�ϵ��� solution �Լ��� �ϼ����ּ���.
// 
// ���ѻ���
// ���� ��ȣ�� ���� ���̴� �׻� �ϳ��� ������ �����մϴ�. �� ������ ǥ���ϴ� ���̳ʽ� ��ȣ�� ���� ���̿��� ������ �������� �ʽ��ϴ�.
// 1 �� quiz�� ���� �� 10
// X, Y, Z�� ���� 0���� 9���� ���ڷ� �̷���� ������ �ǹ��ϸ�, �� ������ �� �տ� ���̳ʽ� ��ȣ�� �ϳ� ���� �� �ְ� �̴� ������ �ǹ��մϴ�.
// X, Y, Z�� 0�� �����ϰ�� 0���� �������� �ʽ��ϴ�.
// - 10, 000 �� X, Y �� 10, 000
// - 20, 000 �� Z �� 20, 000
// [������]�� + �� - �� �ϳ��Դϴ�.
// 
// ����� ��
// quiz	result
// ["3 - 4 = -3", "5 + 6 = 11"]["X", "O"]
// ["19 - 6 = 13", "5 + 66 = 71", "5 - 15 = 63", "3 - 1 = 2"]["O", "O", "X", "O"]
//
//*************************************************************************************************************************************

vector<string> solution(vector<string> quiz) {
    vector<string> answer;

    // ���� ���ڿ� �����ȣ�� �����Ͽ� ã�ƾ��Ѵ�.
    // �����ȣ�� ġȯ (" + ")(" - ")(" * ")(" / ")
    // = ��ȣ ġȯ (" = ")

    vector<string>::iterator iquiz;
    string temp_str;
    for (iquiz = quiz.begin(); iquiz != quiz.end(); iquiz++) {
        cout << "-----------------------------------------------------------" << endl;
        cout << *iquiz << endl;
        temp_str = *iquiz;                                                                                              // ���� string ����
        
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
            cout << "first number : " << first_num << endl;                                                             // ù ��° ���� (0 ~ blank1-1)
        }
        else {
            char temp_chr = temp_str.at(sub_start_1);
            string temp_str2;
            temp_str2.push_back(temp_chr);
            first_num = stoi(temp_str2);
            cout << "first number : " << first_num << endl;                                                             // ù ��° ���� (0 ~ blank1-1)
        }
        //----------------------------------------------------------------------------------------------------------------------------------------------------
        operator_chr = temp_str.at(sub_start_2);
        cout << "operator : " << operator_chr << endl;                                                                  // ������       (blank1+1)
        //----------------------------------------------------------------------------------------------------------------------------------------------------
        if (((find_blank_3 - 1) - (find_blank_2 + 1)) == 0) {
            char temp_chr = temp_str.at(sub_start_3);
            string temp_str2;
            temp_str2.push_back(temp_chr);
            second_num = stoi(temp_str2);
            cout << "second_number : " << second_num << endl;                                                           // �� ��° ���� (blank2+1 ~ blank3-1)
        }
        else {
            second_num = stoi(temp_str.substr(sub_start_3, sub_end_3));
            cout << "second_number : " << second_num << endl;                                                           // �� ��° ���� (blank2+1 ~ blank3-1)
        }
        //----------------------------------------------------------------------------------------------------------------------------------------------------
        calc_num = stoi(temp_str.substr(sub_start_4, sub_end_4));
        cout << "calc number : " << calc_num << endl;                                                                   // �����       (blank4+1 ~ end)

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