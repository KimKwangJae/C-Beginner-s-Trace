#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : k의 개수
// 
// 문제 설명
// 1부터 13까지의 수에서, 1은 1, 10, 11, 12, 13 이렇게 총 6번 등장합니다. 정수 i, j, k가 매개변수로 주어질 때, i부터 j까지 k가 몇 번 등장하는지 return 하도록 solution 함수를 완성해주세요.
//
// 제한사항
// 1 ≤ i < j ≤ 100,000
// 0 ≤ k ≤ 9
// 
// 입출력 예
// i	j	k	result
// 1	13	1	6
// 10	50	5	5
// 3	10	2	0
//
//*************************************************************************************************************************************

int solution(int i, int j, int k) {
    int answer = 0;
    string tmp_str, tmp_str_k = to_string(k);
    
    printf("%d~%d, k : %s\n", i, j, tmp_str_k.c_str());

    for (i; i <= j; i++) {
        tmp_str = to_string(i);
        for (unsigned int a = 0; a < tmp_str.size(); a++) {
            if (tmp_str[a] == tmp_str_k[0])
                answer++;
        }
    }

    return answer;
}

int main() {
    printf("output : %d\n", solution(1, 13, 1));
    printf("output : %d\n", solution(10, 50, 5));
    printf("output : %d\n", solution(3, 10, 2));

    return 0;
}