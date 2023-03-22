#include <string>
#include <vector>
#include <iostream>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 문자열 계산하기
// 
// 문제 설명
// my_string은 "3 + 5"처럼 문자열로 된 수식입니다. 문자열 my_string이 매개변수로 주어질 때, 수식을 계산한 값을 return 하는 solution 함수를 완성해주세요.
// 
// 제한사항
// 연산자는 +, -만 존재합니다.
// 문자열의 시작과 끝에는 공백이 없습니다.
// 0으로 시작하는 숫자는 주어지지 않습니다.
// 잘못된 수식은 주어지지 않습니다.
// 5 ≤ my_string의 길이 ≤ 100
// my_string을 계산한 결과값은 1 이상 100, 000 이하입니다.
// my_string의 중간 계산 값은 - 100, 000 이상 100, 000 이하입니다.
// 계산에 사용하는 숫자는 1 이상 20, 000 이하인 자연수입니다.
// my_string에는 연산자가 적어도 하나 포함되어 있습니다.
// return type 은 정수형입니다.
// my_string의 숫자와 연산자는 공백 하나로 구분되어 있습니다.
// 
// 입출력 예
// my_string	result
// "3 + 4"	    7
//
//*************************************************************************************************************************************

int solution(string my_string) {
    int answer = 0;

    //연산자는 연산자끼리 배열에 넣고
    //숫자는 숫자끼리 배열에 넣고
    //마지막에 위 두 배열 참조하여 계산
    //////////////////////////////////////////////////////////////////////////////////////////////
    vector<string> oper_str;
    int pos = 0;
    string tmp_str;
    int chk_plus_npos = 1;
    int chk_minus_npos = 1;
    int cnt = 1;
    while(true){
        tmp_str = "";                               //초기화
        chk_plus_npos = my_string.find('+', pos);
        chk_minus_npos = my_string.find('-', pos);

        if (chk_plus_npos == -1 && chk_minus_npos == -1)
            break;

        if (chk_plus_npos == -1)
            pos = chk_minus_npos;                   //남은 연산자가 minus 만 존재
        else if (chk_minus_npos == -1)
            pos = chk_plus_npos;                    //남은 연산자가 plus 만 존재
        else if (chk_plus_npos < chk_minus_npos)
            pos = my_string.find('+', pos);         // plus 연산자가 앞
        else
            pos = my_string.find('-', pos);         // minus 연산자가 앞
        tmp_str.push_back(my_string[pos]);
        oper_str.emplace_back(tmp_str);
        pos++;
        cnt++;
    }
    //////////////////////////////////////////////////////////////////////////////////////////////
    vector<int> num_int;
    string tmp_str2;
    for (unsigned int i = 0; i < my_string.size(); i++) {
        if (my_string[i] != '+' && my_string[i] != '-') {
            tmp_str2.push_back(my_string[i]);
            if (i == my_string.size() - 1)
                num_int.emplace_back(stoi(tmp_str2));
        }
        else {
            num_int.emplace_back(stoi(tmp_str2));
            tmp_str2 = "";
        }
    }
    //////////////////////////////////////////////////////////////////////////////////////////////

    int cal_a = 0, cal_b = 0;
    bool chk_cross = false;
    for (int j = 0; j < num_int.size(); j++) {
        // 0 1 2... : 숫자
        // 1 3 5... : 연산자
        if (!chk_cross)                                                 //0, 짝수
            cal_a = num_int[j];
        else                                                            //홀수
            cal_b = num_int[j];

        if (j == 0)
            answer = cal_a;                                             //최초 값 대입

        if (j > 0 && oper_str[j - 1] == "+") {
            if(j % 2==0)
                answer += cal_a;
            else
                answer += cal_b;
        }
        else if (j > 0 && oper_str[j - 1] == "-") {
            if (j % 2 == 0)
                answer -= cal_a;
            else
                answer -= cal_b;
        }

        chk_cross = !chk_cross;
    }

    return answer;
}

int main() {
    string input;

    input = "100 + 200";            //300
    cout << "input calcuation : " << solution(input) << endl;

    input = "100 + 200 + 300";      //600
    cout << "input calcuation : " << solution(input) << endl;

    input = "100 - 200";            //-100
    cout << "input calcuation : " << solution(input) << endl;

    input = "100 - 200 - 300";      //-400
    cout << "input calcuation : " << solution(input) << endl;

    input = "100 + 234 - 50";       //284
    cout << "input calcuation : " << solution(input) << endl;

    input = "100 - 234 + 50";       //-84
    cout << "input calcuation : " << solution(input) << endl;

    return 0;
}