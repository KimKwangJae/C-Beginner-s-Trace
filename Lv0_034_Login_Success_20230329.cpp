#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : �α��� ����?
// 
// ���� ����
// �Ӿ��̴� ���α׷��ӽ��� �α����Ϸ��� �մϴ�. �Ӿ��̰� �Է��� ���̵�� �н����尡 ��� �迭 id_pw�� ȸ������ ������ ��� 2���� �迭 db�� �־��� ��, ������ ���� �α��� ����, 
// ���п� ���� �޽����� return�ϵ��� solution �Լ��� �ϼ����ּ���.
// ���̵�� ��й�ȣ�� ��� ��ġ�ϴ� ȸ�������� ������ "login"�� return�մϴ�.
// �α����� �������� �� ���̵� ��ġ�ϴ� ȸ���� ���ٸ� ��fail����, ���̵�� ��ġ������ ��й�ȣ�� ��ġ�ϴ� ȸ���� ���ٸ� ��wrong pw���� return �մϴ�.
//
// ���ѻ���
// ȸ������ ���̵�� ���ڿ��Դϴ�.
// ȸ������ ���̵�� ���ĺ� �ҹ��ڿ� ���ڷθ� �̷���� �ֽ��ϴ�.
// ȸ������ �н������ ���ڷ� ������ ���ڿ��Դϴ�.
// ȸ������ ��й�ȣ�� ���� �� ������ ���̵�� ���� �� �����ϴ�.
// id_pw�� ���̴� 2�Դϴ�.
// id_pw�� db�� ���Ҵ�[���̵�, �н�����] �����Դϴ�.
// 1 �� ���̵��� ���� �� 15
// 1 �� ��й�ȣ�� ���� �� 6
// 1 �� db�� ���� �� 10
// db�� ������ ���̴� 2�Դϴ�.
// 
// ����� ��
// id_pw	                    db	                                                                                result
// ["meosseugi", "1234"]        [["rardss", "123"], ["yyoom", "1234"], ["meosseugi", "1234"]]                       "login"
// ["programmer01", "15789"]    [["programmer02", "111111"], ["programmer00", "134"], ["programmer01", "1145"]]     "wrong pw"
// ["rabbit04", "98761"]        [["jaja11", "98761"], ["krong0313", "29440"], ["rabbit00", "111333"]]               "fail"
//
//*************************************************************************************************************************************

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "fail";
    for (unsigned int i = 0; i < db.size(); i++) {
        if (id_pw[0] == db[i][0]) {
            if (id_pw[1] == db[i][1]) {
                answer = "login";
                break;
            }
            answer = "wrong pw";
            break;
        }
    }
    return answer;
}

int main() {
    vector<string> input_id_pw;
    vector<vector<string>> input_db;

    input_id_pw = { "meosseugi", "1234" };
    input_db = { {"rardss", "123"}, {"yyoom", "1234"}, {"meosseugi", "1234"}};
    printf("output : %s\n", solution(input_id_pw, input_db).c_str());

    input_id_pw = { "programmer01", "15789" };
    input_db = { {"programmer02", "111111"}, {"programmer00", "134"}, {"programmer01", "1145"} };
    printf("output : %s\n", solution(input_id_pw, input_db).c_str());

    input_id_pw = { "rabbit04", "98761" };
    input_db = { {"jaja11", "98761"}, {"krong0313", "29440"}, {"rabbit00", "111333"} };
    printf("output : %s\n", solution(input_id_pw, input_db).c_str());

    return 0;
}