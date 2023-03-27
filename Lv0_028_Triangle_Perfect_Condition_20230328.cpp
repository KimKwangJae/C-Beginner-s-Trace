#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : �ﰢ���� �ϼ����� (1)
// 
// ���� ����
// ���� �� ���� �ﰢ���� ����� ���ؼ��� ������ ���� ������ �����ؾ� �մϴ�.
// ���� �� ���� ���̴� �ٸ� �� ���� ������ �պ��� �۾ƾ� �մϴ�.
// �ﰢ���� �� ���� ���̰� ��� �迭 sides�� �Ű������� �־����ϴ�.�� ������ �ﰢ���� ���� �� �ִٸ� 1, ���� �� ���ٸ� 2�� return�ϵ��� solution �Լ��� �ϼ����ּ���.
//
// ���ѻ���
// sides�� ���Ҵ� �ڿ����Դϴ�.
// sides�� ���̴� 3�Դϴ�.
// 1 �� sides�� ���� �� 1, 000
// 
// ����� ��
// sides	        result
// [1, 2, 3]	    2
// [3, 6, 2]	    2
// [199, 72, 222]	1
//
//*************************************************************************************************************************************

int solution(vector<int> sides) {
    int answer = 2;

    int tmp = sides[0];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (sides[j] > sides[j+1]) {
                tmp = sides[j];
                sides[j] = sides[j + 1];
                sides[j + 1] = tmp;
            }
        }
    }

    if (sides[0] + sides[1] > sides[2])
        answer = 1;

    return answer;
}

int main() {
    vector<int> input_vec = {1,2,3};
    printf("Triangle Condition : %d\n", solution(input_vec));

    input_vec = { 3,6,2 };
    printf("Triangle Condition : %d\n", solution(input_vec));

    input_vec = { 199,72,222 };
    printf("Triangle Condition : %d\n", solution(input_vec));

    return 0;
}