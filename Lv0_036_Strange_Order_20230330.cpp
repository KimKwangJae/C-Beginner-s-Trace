#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : Ư���� ����
// 
// ���� ����
// ���� n�� �������� n�� ����� ������ �����Ϸ��� �մϴ�. 
// �̶� n���κ����� �Ÿ��� ���ٸ� �� ū ���� �տ� ������ ��ġ�մϴ�. 
// ������ ��� �迭 numlist�� ���� n�� �־��� �� numlist�� ���Ҹ� n���κ��� ����� ������� ������ �迭�� return�ϵ��� solution �Լ��� �ϼ����ּ���.
//
// ���ѻ���
// 1 �� n �� 10,000
// 1 �� numlist�� ���� �� 10, 000
// 1 �� numlist�� ���� �� 100
// numlist�� �ߺ��� ���Ҹ� ���� �ʽ��ϴ�.
// 
// ����� ��
// numlist	                                n	    result
// [1, 2, 3, 4, 5, 6]	                    4       [4, 5, 3, 6, 2, 1]
// [10000, 20, 36, 47, 40, 6, 10, 7000]	    30      [36, 40, 20, 47, 10, 6, 7000, 10000]
//
//*************************************************************************************************************************************

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;

    answer.push_back(numlist[0]);
    for (unsigned int i = 0; i < numlist.size(); i++) {
        int differ = (n - numlist[i]) < 0 ? (n - numlist[i]) * -1 : (n - numlist[i]);                   //Ÿ�� n�� ���� �񱳰��� ���� ���
        for (unsigned int j = 0; j < answer.size(); j++) {
                int differ_exist = (n - answer[j]) < 0 ? (n - answer[j]) * -1 : (n - answer[j]);        //Ÿ�� n�� answer ���ΰ��� ���� ���

                if (differ <= differ_exist) {                                                           //���� �񱳰��� �۰ų� ������ (���� �Ǵ� ����)
                    if (differ == differ_exist && numlist[i] > answer[j]) {                             //����
                        int tmp = answer[j];
                        answer[j] = numlist[i];
                        answer.insert(answer.begin() + (j + 1), 1, tmp);
                    }
                    else if (differ == differ_exist && numlist[i] < answer[j]) {                        //����
                        answer.insert(answer.begin() + (j + 1), 1, numlist[i]);
                    }
                    else if (differ == differ_exist && numlist[i] == answer[j]) {                       //���� ���� �� �Է°� (Pass)
                        printf("Same Number.. Pass \n");
                    }
                    else {                                                                              //����
                        int tmp = answer[j];
                        answer[j] = numlist[i];
                        answer.insert(answer.begin() + (j + 1), 1, tmp);
                    }
                    break;
                }
                else {
                    if (j == answer.size() - 1)
                        answer.push_back(numlist[i]);                                                    // ���� ���� ��� �� �� ���� ������ ���� ���� ������ �������� �߰�
                }
        }

        for (unsigned int z = 0; z < answer.size(); z++) {
            printf("%d ", answer[z]);
        }
        printf("\n------------------------------------------------------------------\n");
    }

    return answer;
}

int main() {
    vector<int> input;
    vector<int> output;
    int t_number;

    //input = {1, 2, 3, 4, 5, 6};
    //t_number = 4;
    //output = solution(input, t_number);
    //for (unsigned int i = 0; i < output.size(); i++) {
    //    printf("%d ", output[i]);
    //}
    //printf("\n\n\n");

    //input = { 10000, 20, 36, 47, 40, 6, 10, 7000 };
    //t_number = 30;
    //output = solution(input, t_number);
    //for (unsigned int i = 0; i < output.size(); i++) {
    //    printf("%d ", output[i]);
    //}
    //printf("\n\n\n");

    input = { 600, 400, 300, 200, 700, 800, 100, 900 };
    t_number = 500;
    output = solution(input, t_number);
    for (unsigned int i = 0; i < output.size(); i++) {
        printf("%d ", output[i]);
    }
    printf("\n\n\n");

    return 0;
}