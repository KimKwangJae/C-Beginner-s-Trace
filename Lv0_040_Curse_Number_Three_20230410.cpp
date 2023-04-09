#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : ������ ���� 3
// 
// ���� ����
// 3x ���� ������� 3�� ������ ���ڶ�� �����ϱ� ������ 3�� ����� ���� 3�� ������� �ʽ��ϴ�. 3x ���� ������� ���ڴ� ������ �����ϴ�.
// 10����	3x �������� ���� ����	10����	3x �������� ���� ����
// 1	    1	                    6	    8
// 2	    2	                    7	    10
// 3	    4	                    8	    11
// 4	    5	                    9	    14
// 5	    7	                    10	    16
// ���� n�� �Ű������� �־��� ��, n�� 3x �������� ����ϴ� ���ڷ� �ٲ� return�ϵ��� solution �Լ��� �ϼ����ּ���.
//
// ���ѻ���
// 1 �� n �� 100
// 
// ����� ��
// n	result
// 15	25
// 40	76
//
//*************************************************************************************************************************************

bool check_three(int i, bool &num_chk) {
    num_chk = false;

    if (i % 3 == 0)
        num_chk = true;
    else {
        string i_str = to_string(i);
        for (unsigned int k = 0; k < i_str.size(); k++) {
            if (i_str[k] == '3') {
                num_chk = true;
                break;
            }
        }
    }

    return num_chk;
}

int solution(int n) {
    int answer = 0;
    bool num_chk = false;
    while (n) {
        answer++;
        check_three(answer, num_chk);
        if (num_chk)
            continue;
        else
            n--;
    }

    return answer;
}

int main() {

    printf("output : %d\n", solution(15));      //25
    printf("output : %d\n", solution(40));      //76

    return 0;
}