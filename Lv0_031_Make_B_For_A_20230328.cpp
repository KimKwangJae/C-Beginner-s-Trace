#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : A로 B 만들기
// 
// 문제 설명
// 문자열 before와 after가 매개변수로 주어질 때, before의 순서를 바꾸어 after를 만들 수 있으면 1을, 만들 수 없으면 0을 return 하도록 solution 함수를 완성해보세요.
//
// 제한사항
// 0 < before의 길이 == after의 길이 < 1,000
// before와 after는 모두 소문자로 이루어져 있습니다.
// 
// 입출력 예
// before	after	result
// "olleh"	"hello"	1
// "allpe"	"apple"	0
//
//*************************************************************************************************************************************

int solution(string before, string after) {
    int answer = 0;

    //그냥 정렬 때려서 두 개 동일한지 비교
    for (unsigned int i = 0; i < before.size() - 1; i++) {
        char tmp_before, tmp_after;
        for (unsigned int j = 0; j < before.size() - 1; j++) {
            if (before[j] > before[j + 1]) {
                tmp_before = before[j];
                before[j] = before[j + 1];
                before[j + 1] = tmp_before;
            }

            if (after[j] > after[j + 1]) {
                tmp_after = after[j];
                after[j] = after[j + 1];
                after[j + 1] = tmp_after;
            }
        }
    }

    if (before == after)
        answer = 1;
    else
        answer = 0;

    return answer;
}

int main() {
    printf("output : %d\n", solution("olleh", "hello"));
    printf("output : %d\n", solution("allpe", "apple"));
    return 0;
}