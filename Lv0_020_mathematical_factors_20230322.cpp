#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : ��� ���ϱ�
// 
// ���� ����
// ���� n�� �Ű������� �־��� ��, n�� ����� ������������ ���� �迭�� return�ϵ��� solution �Լ��� �ϼ����ּ���.
// 
// ���ѻ���
// 1 �� n �� 10,000
// 
// ����� ��
// n	result
// 24   [1, 2, 3, 4, 6, 8, 12, 24]
// 29   [1, 29]
//
//*************************************************************************************************************************************

vector<int> solution(int n) {
    vector<int> answer;
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            answer.emplace_back(i);
    return answer;
}

int main() {
    int input_num;
    vector<int> output_mathmetical_factor;

    input_num = 24;
    printf("���� %d�� ��� : \n", input_num);

    output_mathmetical_factor = solution(input_num);
    for (const auto& a : output_mathmetical_factor) {
        printf("%d\n", a);
    }


    return 0;
}