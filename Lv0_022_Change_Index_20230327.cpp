#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 인덱스 바꾸기
// 
// 문제 설명
// 문자열 my_string과 정수 num1, num2가 매개변수로 주어질 때, my_string에서 인덱스 num1과 인덱스 num2에 해당하는 문자를 바꾼 문자열을 return 하도록 solution 함수를 완성해보세요.
// 
// 제한사항
// 1 < my_string의 길이 < 100
// 0 ≤ num1, num2 < my_string의 길이
//     my_string은 소문자로 이루어져 있습니다.
//     num1 ≠ num2
// 
// 입출력 예
// my_string	num1	num2	result
// "hello"	    1	    2	    "hlelo"
// "I love you"	3	    6	    "I l veoyou"
//
//*************************************************************************************************************************************

string solution(string my_string, int num1, int num2) {
    char tmp_chr;
    tmp_chr = my_string[num1];
    my_string[num1] = my_string[num2];
    my_string[num2] = tmp_chr;
    return my_string;
}

int main() {
    string output_str;

    output_str = solution("hello", 1, 2);
    printf("%s\n", output_str.c_str());

    output_str = solution("I love you", 3, 6);
    printf("%s\n", output_str.c_str());
    
    return 0;
}