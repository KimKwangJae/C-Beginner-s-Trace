#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 문자열 정렬하기 (2)
// 
// 문제 설명
// 영어 대소문자로 이루어진 문자열 my_string이 매개변수로 주어질 때, my_string을 모두 소문자로 바꾸고 알파벳 순서대로 정렬한 문자열을 return 하도록 solution 함수를 완성해보세요.
// 
// 제한사항
// 0 < my_string 길이 < 100
// 
// 입출력 예
// my_string	result
// "Bcad"	"abcd"
// "heLLo"	"ehllo"
// "Python"	"hnopty"
//*************************************************************************************************************************************

// 대문자 A~Z (65~90)
// 소문자 a~z (97~122)

string solution(string my_string) {
    printf("-----------------------------------------------------\n");
    printf("[before] %s\n", my_string.c_str());

    //문자의 정수값이 91보다 작으면 대문자 --> 소문자 변환 --> "+32"
    //문자의 정수값이 91보다 크거나 같으면 PASS

    //소문자 변환
    unsigned int i, j, k, str_size = my_string.size();
    for (i = 0; i < str_size; i++) {
        if (my_string[i] < 91)
            my_string[i] += 32;
    }

    printf("[Cap change] %s\n", my_string.c_str());

    //정렬
    char chr_bk = '\n';
    for (j = 0; j < str_size; j++) {
        printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

        printf("[%d] Char : %c(%d)\n", j, my_string[j], my_string[j]);
        for (k = j; k < str_size; k++) {
            printf(">>>>>>>>>>>>>>>>\n");
            printf("[Compare] %c(%d) <-> %c(%d) ", my_string[j], my_string[j], my_string[k], my_string[k]);

            if (my_string[j] > my_string[k]) {
                chr_bk = my_string[j];
                my_string[j] = my_string[k];
                my_string[k] = chr_bk;
            }

            printf("[S_Result] %c(%d)\n", my_string[j], my_string[j]);
        }
        printf("[L_Result] %c(%d) (%s)\n", my_string[j], my_string[j], my_string.c_str());
    }

    printf("[after] %s\n", my_string.c_str());

    return my_string;
}

int main() {
    string input_str, rtn;

    input_str = "Bcad";
    rtn = solution(input_str);

    input_str = "heLLo";
    rtn = solution(input_str);

    input_str = "Python";
    rtn = solution(input_str);

    return 0;
}