#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 암호 해독
// 
// 문제 설명
// 군 전략가 머쓱이는 전쟁 중 적군이 다음과 같은 암호 체계를 사용한다는 것을 알아냈습니다.
// 암호화된 문자열 cipher를 주고받습니다.
// 그 문자열에서 code의 배수 번째 글자만 진짜 암호입니다.
// 문자열 cipher와 정수 code가 매개변수로 주어질 때 해독된 암호 문자열을 return하도록 solution 함수를 완성해주세요.
//
// 제한사항
// 1 ≤ cipher의 길이 ≤ 1,000
// 1 ≤ code ≤ cipher의 길이
// cipher는 소문자와 공백으로만 구성되어 있습니다.
// 공백도 하나의 문자로 취급합니다.
// 
// 입출력 예
// cipher	                    code	result
// "dfjardstddetckdaccccdegk"	4	    "attack"
// "pfqallllabwaoclk"	        2	    "fallback"
//
//*************************************************************************************************************************************

string solution(string cipher, int code) {
    string answer = "";

    for (unsigned int i = code; i <= cipher.size(); i+=code) {
        answer.push_back(cipher[i - 1]);
        printf("[%u/%u] answer : %s\n", i, cipher.size(), answer.c_str());
    }

    return answer;
}

int main() {

    string output_str;
    output_str = solution("dfjardstddetckdaccccdegk", 4);
    printf("output string : %s\n", output_str.c_str());

    output_str = solution("pfqallllabwaoclk", 2);
    printf("output string : %s\n", output_str.c_str());

    return 0;
}