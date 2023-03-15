#include <string>
#include <vector>
#include <iostream>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : �߶� �迭�� �����ϱ�
// 
// ���� ����
// ���ڿ� my_str�� n�� �Ű������� �־��� ��, my_str�� ���� n�� �߶� ������ �迭�� return�ϵ��� solution �Լ��� �ϼ����ּ���.
// 
// ���ѻ���
// 1 �� my_str�� ���� �� 100
// 1 �� n �� my_str�� ����
// my_str�� ���ĺ� �ҹ���, �빮��, ���ڷ� �̷���� �ֽ��ϴ�.
// 
// ����� ��
// my_str	            n	result
// "abc1Addfggg4556b"	6   ["abc1Ad", "dfggg4", "556b"]
// "abcdef123"	        3   ["abc", "def", "123"]
// 
// ��¥ : 2023.03.15
// ����Ʈ : ���ڿ�, �迭 ó��
//*************************************************************************************************************************************


vector<string> solution(string my_str, int n);

int main() {
    string input_str = "abc1Addfggg4556b";
    int input_num = 6;

    vector<string> rtn = solution(input_str, input_num);
    vector<string>::iterator vi;
    for (vi = rtn.begin(); vi != rtn.end(); vi++) {
        cout << *vi << endl;
    }

    return 0;
}

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    vector<string>::iterator ianswer;
    
    unsigned int str_size = my_str.size();                                          // my_str ������ Ȯ��
    int excute_cnt = str_size / n;                                                  // �������� 0�� �ƴϸ� �� + 1
    if (str_size % n != 0)
        excute_cnt++;

    int i, pos = 0;
    for (i = 0; i < excute_cnt; i++) {
        ianswer = answer.begin() + i;                                               // insert ��ġ ����
        answer.insert(ianswer, my_str.substr(pos, n));
        pos += n;
    }
    return answer;
}

/* Best Source -------------------------------------------------------------
vector<string> solution(string my_str, int n) {
    vector<string> answer;
    for (int i=0; i<my_str.length(); i+=n){
        answer.push_back(my_str.substr(i,n));
    }
    return answer;
}
------------------------------------------------------------------------- */