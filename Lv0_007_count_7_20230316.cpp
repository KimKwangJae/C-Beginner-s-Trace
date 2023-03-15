#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : 7�� ����
// 
// ���� ����
// �Ӿ��̴� ����� ���� 7�� ���� �����մϴ�. ���� �迭 array�� �Ű������� �־��� ��, 7�� �� �� �� �ִ��� return �ϵ��� solution �Լ��� �ϼ��غ�����.
// 
// ���ѻ���
// 1 �� array�� ���� �� 100
// 0 �� array�� ���� �� 100, 000
// 
// ����� ��
// array	    result
// [7, 77, 17]	4
// [10, 29]	    0
//*************************************************************************************************************************************


int solution(vector<int> array);

int main() {

    vector<int> input_array = {7, 77, 17};
    cout << solution(input_array) << endl;

    return 0;
}

int solution(vector<int> array) {
    int answer = 0;
    int tmp_array_bk;
    for (int i = 0; i < array.size(); i++) {
        //cout << "First for() Start! [" << i << "] ==============================================" << endl;
        //cout << "index : " << i << " (array value:" << array[i] << ")" << endl;
        
        tmp_array_bk = array[i];
        for (int j = 4; j >= 0; j--) {
            int divided_num = pow(10.0, (double)j);                         // 10�� ��� (ū������ ��������)

            if (divided_num > 1) {
                if (tmp_array_bk / divided_num == 7)
                    answer++;
            }
            else {
                if (tmp_array_bk == 7)
                    answer++;
            }
            tmp_array_bk %= divided_num;
        }
    }
    return answer;
}