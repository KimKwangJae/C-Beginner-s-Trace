#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : A�� B �����
// 
// ���� ����
// ���ڿ� before�� after�� �Ű������� �־��� ��, before�� ������ �ٲپ� after�� ���� �� ������ 1��, ���� �� ������ 0�� return �ϵ��� solution �Լ��� �ϼ��غ�����.
//
// ���ѻ���
// 0 < before�� ���� == after�� ���� < 1,000
// before�� after�� ��� �ҹ��ڷ� �̷���� �ֽ��ϴ�.
// 
// ����� ��
// before	after	result
// "olleh"	"hello"	1
// "allpe"	"apple"	0
//
//*************************************************************************************************************************************

int solution(string before, string after) {
    int answer = 0;

    //�׳� ���� ������ �� �� �������� ��
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