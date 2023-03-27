#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 대문자와 소문자
// 
// 문제 설명
// 문자열 my_string이 매개변수로 주어질 때, 대문자는 소문자로 소문자는 대문자로 변환한 문자열을 return하도록 solution 함수를 완성해주세요.
// 
// 제한사항
// 1 ≤ my_string의 길이 ≤ 1,000
// my_string은 영어 대문자와 소문자로만 구성되어 있습니다.
// 
// 입출력 예
// my_string	result
// "cccCCC"	    "CCCccc"
// "abCdEfghIJ"	"ABcDeFGHij"
//
//*************************************************************************************************************************************

string solution(string my_string) {
    for (unsigned int i = 0; i < my_string.size(); i++) {
        if (my_string[i] < 91)   //대문자이면
            my_string[i] += 32;
        else                     //소문자이면
            my_string[i] -= 32;
    }
    return my_string;
}

int main() {
    string output_str;

    output_str = solution("cccCCC");
    printf("output string : %s\n", output_str.c_str());

    output_str = solution("abCdEfghIJ");
    printf("output string : %s\n", output_str.c_str());

    //char a, b;
    //a = 'a';    //97
    //b = 'A';    //65        (32 차이)

    //printf("a : %d\n", a);
    //printf("A : %d\n", b);

    //a = 'z';    //122
    //b = 'Z';    //90
    //printf("z : %d\n", a);
    //printf("Z : %d\n", b);

    return 0;
}