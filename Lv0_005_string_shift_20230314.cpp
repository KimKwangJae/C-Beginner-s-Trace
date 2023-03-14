#include <string>
#include <vector>
#include <iostream>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : ���ڿ� �б�
// 
// ���� ����
// ���ڿ� "hello"���� �� ���ڸ� ���������� �� ĭ�� �а� ������ ���ڴ� �� ������ �̵���Ű�� "ohell"�� �˴ϴ�. 
// �̰��� ���ڿ��� �δٰ� �����Ѵٸ� ���ڿ� A�� B�� �Ű������� �־��� ��, A�� �о B�� �� �� �ִٸ� �о�� �ϴ� �ּ� Ƚ���� return�ϰ� 
// �о B�� �� �� ������ -1�� return �ϵ��� solution �Լ��� �ϼ��غ�����.
// 
// ���ѻ���
// 0 < A�� ���� = B�� ���� < 100
// A, B�� ���ĺ� �ҹ��ڷ� �̷���� �ֽ��ϴ�.
// 
// ����� ��
// A	B	result
// "hello"	"ohell"	1
// "apple"	"elppa" - 1
// "atat"	"tata"	1
// "abc"	"abc"	0
// 
// ��¥ : 2023.03.14
// ����Ʈ : ���ڿ� ó��
//*************************************************************************************************************************************



int solution(string A, string B);

int main() {
    string input_a, input_b;
    while (1) {
        cout << "please input string a" << endl;
        cin >> input_a;
        if (input_a == "end")
            break;
        cout << "please input string b" << endl;
        cin >> input_b;
        cout << "input a, b string is '" << input_a << "' '" << input_b << "'" << endl;
        cout << "string right shift count : " << solution(input_a, input_b) << endl;
    }
    return 0;
}

int solution(string A, string B) {
    int answer = 0;
    if (A.size() != B.size())
        answer = -1;
    else if (A == B)
        answer = 0;
    else {
        //input_a �� ���ڿ� ���� ��ŭ for() (string�� null �� ���� ����)
        unsigned int i, j, cnt = 1, A_size, B_size;
        A_size = A.size();
        B_size = B.size();

        string temp_str, temp_str_bk;
        char temp_chr;

        for (i = 0; i < B_size; i++) {
            if (i == 0) {
                temp_str_bk = A;                                        //origin string ���ڿ� ����
                temp_chr = (char)temp_str_bk.back();                    //origin string ������ ���� ����
            }
            else {
                temp_str_bk = temp_str;                                 //temp string ���ڿ� ����
                temp_chr = (char)temp_str_bk.back();                    //temp string ������ ���� ����
            }

            temp_str.clear();                                           //�ݺ� for() ���� �� string �ʱ�ȭ

            for (j = 0; j < A_size; j++) {
                if (j == 0)
                    temp_str.push_back(temp_chr);                       //shift �� ���ڿ��� ������ ���ڸ� 0 index�� ����
                else
                    temp_str.push_back(temp_str_bk[j - 1]);
            }

            if (B == temp_str) {                                        //target found!
                answer = cnt;
                break;
            }
            else if (i == B_size - 1) {                                 //target not found
                answer = -1;
                break;
            }
            cnt++;
        }
    }
    return answer;
}
