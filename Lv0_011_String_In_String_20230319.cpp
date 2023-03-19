#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 문자열안에 문자열
// 
// 문제 설명
// 문자열 str1, str2가 매개변수로 주어집니다. str1 안에 str2가 있다면 1을 없다면 2를 return하도록 solution 함수를 완성해주세요.
// 
// 제한사항
// 1 ≤ str1의 길이 ≤ 100
// 1 ≤ str2의 길이 ≤ 100
// 문자열은 알파벳 대문자, 소문자, 숫자로 구성되어 있습니다.
// 
// 입출력 예
// str1	str2	result
// "ab6CDE443fgh22iJKlmn1o"	"6CD"	1
// "ppprrrogrammers"	"pppp"	2
// "AbcAbcA"	"AAA"	2
//
//*************************************************************************************************************************************

int solution(string str1, string str2) {
    int answer = 0;

    if (str1.find(str2) != -1)
        answer = 1;
    else
        answer = 2;

    return answer;
}

int main() {

    string a = "abcdefgh";

    int rtn = a.find("bcd");
    printf("%d\n", rtn);

    rtn = a.find("bcf");
    printf("%d\n", rtn);

    return 0;
}