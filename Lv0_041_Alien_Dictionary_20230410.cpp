#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : �ܰ�� ����
// 
// ���� ����
// PROGRAMMERS-962 �༺�� �ҽ����� ���ֺ���� �Ӿ��̴� �ܰ��༺�� �� �����Ϸ��� �մϴ�. 
// ���ĺ��� ��� �迭 spell�� �ܰ�� ���� dic�� �Ű������� �־����ϴ�. 
// spell�� ��� ���ĺ��� �ѹ����� ��� ����� �ܾ dic�� �����Ѵٸ� 1, �������� �ʴ´ٸ� 2�� return�ϵ��� solution �Լ��� �ϼ����ּ���.
//
// ���ѻ���
// spell�� dic�� ���Ҵ� ���ĺ� �ҹ��ڷθ� �̷�����ֽ��ϴ�.
// 2 �� spell�� ũ�� �� 10
// spell�� ������ ���̴� 1�Դϴ�.
// 1 �� dic�� ũ�� �� 10
// 1 �� dic�� ������ ���� �� 10
// spell�� ���Ҹ� ��� ����� �ܾ ������ �մϴ�.
// spell�� ���Ҹ� ��� ����� ���� �� �ִ� �ܾ�� dic�� �� �� �̻� �������� �ʽ��ϴ�.
// dic�� spell ��� �ߺ��� ���Ҹ� ���� �ʽ��ϴ�.
// 
// ����� ��
// spell	                                                        dic	result
// ["p", "o", "s"]["sod", "eocd", "qixm", "adio", "soo"]	        2
// ["z", "d", "x"]["def", "dww", "dzx", "loveaw"]	                1
// ["s", "o", "m", "d"]["moos", "dzx", "smm", "sunmmo", "som"]	    2
//
//*************************************************************************************************************************************

int solution(vector<string> spell, vector<string> dic) {
    int answer = 2;
    bool chk_nfnd_spell = false;
    int chk_fnd_spell_cnt = 0;

    for (unsigned int i = 0; i < dic.size(); i++) {                                     //������ �ִ� �ܾ� ������ŭ for()�� ����
        chk_fnd_spell_cnt = 0;
        for (unsigned int j = 0; j < spell.size(); j++) {                               //�־��� ���� ������ŭ for()�� ����
            for (unsigned int k = 0; k < dic[i].size(); k++) {                          //���� �ε��� �ܾ �־��� ���ڰ� �ִ� �� Ȯ��
                if (spell[j][0] == dic[i][k]) {
                    dic[i][k] = '_';                                                    //�־��� ���ڰ� ���� ��� '_' �� ġȯ
                    chk_fnd_spell_cnt++;                                                //�߰ߵ� �־��� ���� ���� ī��Ʈ
                    break;
                }
            }
        }
        
        unsigned int str_size = dic[i].size();
        unsigned int cnt = 0;
        for (unsigned int l = 0; l < dic[i].size(); l++) {                              //���� �ε��� �ܾ�� ġȯ�� '_' ���� Ȯ��
            if (dic[i][l] == '_') {
                cnt++;
            }
        }
        if (cnt == str_size && chk_fnd_spell_cnt == spell.size()) {                     //���� �ε��� �ܾ ��� '_' �� ġȯ�Ǿ��� �־��� ���ڰ� ��� ���Ǿ����� '1' ��ȯ
            answer = 1;
            break;
        }
    }

    return answer;
}

int main() {
    vector<string> input_spell;
    vector<string> input_dic;

    input_spell = {"p","o","s"};
    input_dic = {"sod","eocd","qixm","adio","soo"};
    printf("output : %d\n", solution(input_spell, input_dic));      //2

    input_spell = { "z","d","x" };
    input_dic = { "def", "dww", "dzx", "loveaw" };
    printf("output : %d\n", solution(input_spell, input_dic));      //1

    input_spell = { "s","o","m","d"};
    input_dic = { "moos", "dzx", "smm", "sunmmo", "som" };
    printf("output : %d\n", solution(input_spell, input_dic));      //2

    return 0;
}