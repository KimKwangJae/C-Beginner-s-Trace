#include <string>
#include <vector>
#include <iostream>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 문자열 밀기
// 
// 문제 설명
// 문자열 "hello"에서 각 문자를 오른쪽으로 한 칸씩 밀고 마지막 문자는 맨 앞으로 이동시키면 "ohell"이 됩니다. 
// 이것을 문자열을 민다고 정의한다면 문자열 A와 B가 매개변수로 주어질 때, A를 밀어서 B가 될 수 있다면 밀어야 하는 최소 횟수를 return하고 
// 밀어서 B가 될 수 없으면 -1을 return 하도록 solution 함수를 완성해보세요.
// 
// 제한사항
// 0 < A의 길이 = B의 길이 < 100
// A, B는 알파벳 소문자로 이루어져 있습니다.
// 
// 입출력 예
// A	B	result
// "hello"	"ohell"	1
// "apple"	"elppa" - 1
// "atat"	"tata"	1
// "abc"	"abc"	0
// 
// 날짜 : 2023.03.14
// 포인트 : 문자열 처리
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
        //input_a 의 문자열 길이 만큼 for() (string은 null 값 갖지 않음)
        unsigned int i, j, cnt = 1, A_size, B_size;
        A_size = A.size();
        B_size = B.size();

        string temp_str, temp_str_bk;
        char temp_chr;

        for (i = 0; i < B_size; i++) {
            if (i == 0) {
                temp_str_bk = A;                                        //origin string 문자열 저장
                temp_chr = (char)temp_str_bk.back();                    //origin string 마지막 문자 저장
            }
            else {
                temp_str_bk = temp_str;                                 //temp string 문자열 저장
                temp_chr = (char)temp_str_bk.back();                    //temp string 마지막 문자 저장
            }

            temp_str.clear();                                           //반복 for() 시작 전 string 초기화

            for (j = 0; j < A_size; j++) {
                if (j == 0)
                    temp_str.push_back(temp_chr);                       //shift 전 문자열의 마지막 문자를 0 index에 저장
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
