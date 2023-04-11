#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// 문제 : 외계어 사전
// 
// 문제 설명
// PROGRAMMERS-962 행성에 불시착한 우주비행사 머쓱이는 외계행성의 언어를 공부하려고 합니다. 
// 알파벳이 담긴 배열 spell과 외계어 사전 dic이 매개변수로 주어집니다. 
// spell에 담긴 알파벳을 한번씩만 모두 사용한 단어가 dic에 존재한다면 1, 존재하지 않는다면 2를 return하도록 solution 함수를 완성해주세요.
//
// 제한사항
// spell과 dic의 원소는 알파벳 소문자로만 이루어져있습니다.
// 2 ≤ spell의 크기 ≤ 10
// spell의 원소의 길이는 1입니다.
// 1 ≤ dic의 크기 ≤ 10
// 1 ≤ dic의 원소의 길이 ≤ 10
// spell의 원소를 모두 사용해 단어를 만들어야 합니다.
// spell의 원소를 모두 사용해 만들 수 있는 단어는 dic에 두 개 이상 존재하지 않습니다.
// dic과 spell 모두 중복된 원소를 갖지 않습니다.
// 
// 입출력 예
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

    for (unsigned int i = 0; i < dic.size(); i++) {                                     //사전에 있는 단어 개수만큼 for()문 실행
        chk_fnd_spell_cnt = 0;
        for (unsigned int j = 0; j < spell.size(); j++) {                               //주어진 문자 개수만큼 for()문 실행
            for (unsigned int k = 0; k < dic[i].size(); k++) {                          //현재 인덱스 단어에 주어진 문자가 있는 지 확인
                if (spell[j][0] == dic[i][k]) {
                    dic[i][k] = '_';                                                    //주어진 문자가 있을 경우 '_' 로 치환
                    chk_fnd_spell_cnt++;                                                //발견된 주어진 문자 개수 카운트
                    break;
                }
            }
        }
        
        unsigned int str_size = dic[i].size();
        unsigned int cnt = 0;
        for (unsigned int l = 0; l < dic[i].size(); l++) {                              //현재 인덱스 단어에서 치환된 '_' 개수 확인
            if (dic[i][l] == '_') {
                cnt++;
            }
        }
        if (cnt == str_size && chk_fnd_spell_cnt == spell.size()) {                     //현재 인덱스 단어가 모두 '_' 로 치환되었고 주어진 문자가 모두 사용되었으면 '1' 반환
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