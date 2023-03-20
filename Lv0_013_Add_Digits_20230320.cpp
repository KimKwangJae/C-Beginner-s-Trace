#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : �ڸ��� ���ϱ�
// 
// ���� ����
// ���� n�� �Ű������� �־��� �� n�� �� �ڸ� ������ ���� return�ϵ��� solution �Լ��� �ϼ����ּ���
// 
// ���ѻ���
// 0 �� n �� 1,000,000
// 
// ����� ��
// n	result
// 1234	10
// 930211	16
//
//*************************************************************************************************************************************

int solution(int n) {
    int answer = 0;

    //�ڸ��� �˻�
    int cnt = 1;
    for (int i = 10; i <= 1000000; i*=10) {
        if (n < i) {
            cnt;                                                                                // i = 10 --> 1�� �ڸ�
            break;
        }
        cnt++;
    }

    //12345 (cnt 5)
    int temp_n = n;
    for (int j = 1; j <= cnt; j++) {
        answer += temp_n % 10;   //j=1 1���ڸ�
        temp_n /= 10;
    }

    return answer;
}

int main() {
    printf("Start!!\n");
    printf("Add Digits : %d\n", solution(12345));
    printf("Add Digits : %d\n", solution(10000));
    printf("Add Digits : %d\n", solution(10100));
    printf("End!!\n");
    return 0;
}