#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 영어가 싫어요
// 
// 문제 설명
// 영어가 싫은 머쓱이는 영어로 표기되어있는 숫자를 수로 바꾸려고 합니다. 문자열 numbers가 매개변수로 주어질 때, numbers를 정수로 바꿔 return 하도록 solution 함수를 완성해 주세요.
// 
// 제한사항
// numbers는 소문자로만 구성되어 있습니다.
// numbers는 "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" 들이 공백 없이 조합되어 있습니다.
// 1 ≤ numbers의 길이 ≤ 50
// "zero"는 numbers의 맨 앞에 올 수 없습니다.
// 
// 입출력 예
// numbers	                                result
// "onetwothreefourfivesixseveneightnine"	123456789
// "onefourzerosixseven"	                14067
//
//*************************************************************************************************************************************

long long solution(string numbers) {
    long long answer = 0;

    //"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    string tmp_str = "";
    long long answer_bk = 0;
    for (unsigned int i = 0; i < numbers.size(); i++) {
        tmp_str.push_back(numbers[i]);

        if (tmp_str == "zero")            answer = answer * 10 + 0;
        else if (tmp_str == "one")        answer = answer * 10 + 1;
        else if (tmp_str == "two")        answer = answer * 10 + 2;
        else if (tmp_str == "three")      answer = answer * 10 + 3;
        else if (tmp_str == "four")       answer = answer * 10 + 4;
        else if (tmp_str == "five")       answer = answer * 10 + 5;
        else if (tmp_str == "six")        answer = answer * 10 + 6;
        else if (tmp_str == "seven")      answer = answer * 10 + 7;
        else if (tmp_str == "eight")      answer = answer * 10 + 8;
        else if (tmp_str == "nine")       answer = answer * 10 + 9;

        if (answer_bk != answer)
            tmp_str.clear();

        answer_bk = answer;
    }

    return answer;
}

int main() {

    printf("output : %lld\n", solution("onetwothreefourfivesixseveneightnine"));
    printf("output : %lld\n", solution("onefourzerosixseven"));

    return 0;
}