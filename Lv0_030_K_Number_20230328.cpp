#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : k�� ����
// 
// ���� ����
// 1���� 13������ ������, 1�� 1, 10, 11, 12, 13 �̷��� �� 6�� �����մϴ�. ���� i, j, k�� �Ű������� �־��� ��, i���� j���� k�� �� �� �����ϴ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.
//
// ���ѻ���
// 1 �� i < j �� 100,000
// 0 �� k �� 9
// 
// ����� ��
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