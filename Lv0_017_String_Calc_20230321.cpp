#include <string>
#include <vector>
#include <iostream>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : ���ڿ� ����ϱ�
// 
// ���� ����
// my_string�� "3 + 5"ó�� ���ڿ��� �� �����Դϴ�. ���ڿ� my_string�� �Ű������� �־��� ��, ������ ����� ���� return �ϴ� solution �Լ��� �ϼ����ּ���.
// 
// ���ѻ���
// �����ڴ� +, -�� �����մϴ�.
// ���ڿ��� ���۰� ������ ������ �����ϴ�.
// 0���� �����ϴ� ���ڴ� �־����� �ʽ��ϴ�.
// �߸��� ������ �־����� �ʽ��ϴ�.
// 5 �� my_string�� ���� �� 100
// my_string�� ����� ������� 1 �̻� 100, 000 �����Դϴ�.
// my_string�� �߰� ��� ���� - 100, 000 �̻� 100, 000 �����Դϴ�.
// ��꿡 ����ϴ� ���ڴ� 1 �̻� 20, 000 ������ �ڿ����Դϴ�.
// my_string���� �����ڰ� ��� �ϳ� ���ԵǾ� �ֽ��ϴ�.
// return type �� �������Դϴ�.
// my_string�� ���ڿ� �����ڴ� ���� �ϳ��� ���еǾ� �ֽ��ϴ�.
// 
// ����� ��
// my_string	result
// "3 + 4"	    7
//
//*************************************************************************************************************************************

int solution(string my_string) {
    int answer = 0;

    //�����ڴ� �����ڳ��� �迭�� �ְ�
    //���ڴ� ���ڳ��� �迭�� �ְ�
    //�������� �� �� �迭 �����Ͽ� ���
    //////////////////////////////////////////////////////////////////////////////////////////////
    vector<string> oper_str;
    int pos = 0;
    string tmp_str;
    int chk_plus_npos = 1;
    int chk_minus_npos = 1;
    int cnt = 1;
    while(true){
        tmp_str = "";                               //�ʱ�ȭ
        chk_plus_npos = my_string.find('+', pos);
        chk_minus_npos = my_string.find('-', pos);

        if (chk_plus_npos == -1 && chk_minus_npos == -1)
            break;

        if (chk_plus_npos == -1)
            pos = chk_minus_npos;                   //���� �����ڰ� minus �� ����
        else if (chk_minus_npos == -1)
            pos = chk_plus_npos;                    //���� �����ڰ� plus �� ����
        else if (chk_plus_npos < chk_minus_npos)
            pos = my_string.find('+', pos);         // plus �����ڰ� ��
        else
            pos = my_string.find('-', pos);         // minus �����ڰ� ��
        tmp_str.push_back(my_string[pos]);
        oper_str.emplace_back(tmp_str);
        pos++;
        cnt++;
    }
    //////////////////////////////////////////////////////////////////////////////////////////////
    vector<int> num_int;
    string tmp_str2;
    for (unsigned int i = 0; i < my_string.size(); i++) {
        if (my_string[i] != '+' && my_string[i] != '-') {
            tmp_str2.push_back(my_string[i]);
            if (i == my_string.size() - 1)
                num_int.emplace_back(stoi(tmp_str2));
        }
        else {
            num_int.emplace_back(stoi(tmp_str2));
            tmp_str2 = "";
        }
    }
    //////////////////////////////////////////////////////////////////////////////////////////////

    int cal_a = 0, cal_b = 0;
    bool chk_cross = false;
    for (int j = 0; j < num_int.size(); j++) {
        // 0 1 2... : ����
        // 1 3 5... : ������
        if (!chk_cross)                                                 //0, ¦��
            cal_a = num_int[j];
        else                                                            //Ȧ��
            cal_b = num_int[j];

        if (j == 0)
            answer = cal_a;                                             //���� �� ����

        if (j > 0 && oper_str[j - 1] == "+") {
            if(j % 2==0)
                answer += cal_a;
            else
                answer += cal_b;
        }
        else if (j > 0 && oper_str[j - 1] == "-") {
            if (j % 2 == 0)
                answer -= cal_a;
            else
                answer -= cal_b;
        }

        chk_cross = !chk_cross;
    }

    return answer;
}

int main() {
    string input;

    input = "100 + 200";            //300
    cout << "input calcuation : " << solution(input) << endl;

    input = "100 + 200 + 300";      //600
    cout << "input calcuation : " << solution(input) << endl;

    input = "100 - 200";            //-100
    cout << "input calcuation : " << solution(input) << endl;

    input = "100 - 200 - 300";      //-400
    cout << "input calcuation : " << solution(input) << endl;

    input = "100 + 234 - 50";       //284
    cout << "input calcuation : " << solution(input) << endl;

    input = "100 - 234 + 50";       //-84
    cout << "input calcuation : " << solution(input) << endl;

    return 0;
}