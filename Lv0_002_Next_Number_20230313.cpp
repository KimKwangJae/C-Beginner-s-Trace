#include <string>
#include <vector>
#include <iostream>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : ������ �� ����
// 
// ���� ����
// �������� Ȥ�� ������ common�� �Ű������� �־��� ��, ������ ���� �������� �� ���ڸ� return �ϵ��� solution �Լ��� �ϼ��غ�����.
//
// ���ѻ���
// 2 < common�� ���� < 1,000
// -1,000 < common�� ���� < 2,000
// common�� ���Ҵ� ��� �����Դϴ�.
// �������� Ȥ�� �������� �ƴ� ���� �����ϴ�.
// �������� ��� ����� 0�� �ƴ� �����Դϴ�.
//
// ����� ��
// common	result
// [1, 2, 3, 4]	5
// [2, 4, 8]	16
//*************************************************************************************************************************************

// �־��� �Լ� (���ο� Logic ����)
int solution(vector<int> common) {
    int answer = 0;

    // ���� : ��, �� ������ ��
    // ���� : ��, �� ������ ��

    // 1. ������ �� �������� �� ���� �˻�
    // 2. �˻� ����� ���� ���� �� ������ ���� ����

    //���� �˻�
    if((common.at(1) - common.at(0)) == (common.at(2) - common.at(1)) ? true : false){
        printf("���� �˻� ����!\n");
        int temp1 = common.at(1) - common.at(0);                //����
        answer = common.back() + temp1;
    }
    else {
        printf("���� �˻� ����!\n");
        int temp1_divided = common.at(1) / common.at(0);        //����
        answer = common.back() * temp1_divided;
    }

    return answer;
}


int main() {

    vector<int> vInput;
    vInput = {1, 2, 3, 4};       //�Է� ���� 1
    //vInput = {2, 4, 8};          //�Է� ���� 2

    printf("This sequence is \n");        //vector �� ����ϴ� ��� Ȯ�� (https://cocoze.tistory.com/6)

    vector<int>::iterator iter;         //�����̳� ���Ҹ� �����ϴ� Iterator �� �̿��Ͽ� ���� ���� ���
    for (iter = vInput.begin(); iter != vInput.end(); iter++) {
        cout << *iter << endl;
    }


    printf("Next Number is %d\n", solution(vInput));

    return 0;
}