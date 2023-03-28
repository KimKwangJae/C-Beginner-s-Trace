#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 이진수 더하기
// 
// 문제 설명
// 이진수를 의미하는 두 개의 문자열 bin1과 bin2가 매개변수로 주어질 때, 두 이진수의 합을 return하도록 solution 함수를 완성해주세요.
//
// 제한사항
// return 값은 이진수를 의미하는 문자열입니다.
// 1 ≤ bin1, bin2의 길이 ≤ 10
// bin1과 bin2는 0과 1로만 이루어져 있습니다.
// bin1과 bin2는 "0"을 제외하고 0으로 시작하지 않습니다.
// 
// 입출력 예
// bin1	    bin2	result
// "10"	    "11"	"101"
// "1001"	"1111"	"11000"
//
//*************************************************************************************************************************************

string solution(string bin1, string bin2) {
    string answer = "";
    string answer_rev = "";

    //----------------------------------------------------------------
    //reverse bin1, bin2
    string bin1_rev, bin2_rev;
    for (int i = bin1.size()-1; i >= 0; i--)
        bin1_rev.push_back(bin1[i]);
    for (int i = bin2.size()-1; i >= 0; i--)
        bin2_rev.push_back(bin2[i]);
    //----------------------------------------------------------------


    unsigned int x = bin1_rev.size() > bin2_rev.size() ? bin1_rev.size() : bin2_rev.size();     // 둘 중 큰 값
    int sum = 0, up_add = 0;
    for (unsigned int i = 0; i < x; i++) {
        if (bin1_rev.size()-1 >= i) {
            if (bin1_rev[i] == '1')  sum += 1;
        }

        if (bin2_rev.size() - 1 >= i) {
            if (bin2_rev[i] == '1')  sum += 1;
        }

        sum += up_add;

        switch (sum) {
            case 0:
                answer_rev.push_back('0');
                up_add = 0;
                break;
            case 1:
                answer_rev.push_back('1');
                up_add = 0;
                break;
            case 2:
                answer_rev.push_back('0');
                up_add = 1;
                break;
            case 3:
                answer_rev.push_back('1');
                up_add = 1;
                break;
        }

        if (i == x - 1 && up_add == 1)
            answer_rev.push_back('1');

        sum = 0;
    }

    printf("answer reverse : %s\n", answer_rev.c_str());

    for (int i = answer_rev.size() - 1; i >= 0; i--)
        answer.push_back(answer_rev[i]);

    return answer;
}

int main() {
    printf("output : %s\n", solution("10", "11").c_str());
    printf("output : %s\n", solution("1001", "1111").c_str());
    return 0;
}