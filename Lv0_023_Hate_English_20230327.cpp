#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : ��� �Ⱦ��
// 
// ���� ����
// ��� ���� �Ӿ��̴� ����� ǥ��Ǿ��ִ� ���ڸ� ���� �ٲٷ��� �մϴ�. ���ڿ� numbers�� �Ű������� �־��� ��, numbers�� ������ �ٲ� return �ϵ��� solution �Լ��� �ϼ��� �ּ���.
// 
// ���ѻ���
// numbers�� �ҹ��ڷθ� �����Ǿ� �ֽ��ϴ�.
// numbers�� "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" ���� ���� ���� ���յǾ� �ֽ��ϴ�.
// 1 �� numbers�� ���� �� 50
// "zero"�� numbers�� �� �տ� �� �� �����ϴ�.
// 
// ����� ��
// numbers	                                result
// "onetwothreefourfivesixseveneightnine"	123456789
// "onefourzerosixseven"	                14067
//
//*************************************************************************************************************************************

long long solution(string numbers) {
    long long answer = 0;

    //"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    string tmp_str = "";
    long long answer_bk = 0;
    for (unsigned int i = 0; i < numbers.size(); i++) {
        tmp_str.push_back(numbers[i]);

        if (tmp_str == "zero")            answer = answer * 10 + 0;
        else if (tmp_str == "one")        answer = answer * 10 + 1;
        else if (tmp_str == "two")        answer = answer * 10 + 2;
        else if (tmp_str == "three")      answer = answer * 10 + 3;
        else if (tmp_str == "four")       answer = answer * 10 + 4;
        else if (tmp_str == "five")       answer = answer * 10 + 5;
        else if (tmp_str == "six")        answer = answer * 10 + 6;
        else if (tmp_str == "seven")      answer = answer * 10 + 7;
        else if (tmp_str == "eight")      answer = answer * 10 + 8;
        else if (tmp_str == "nine")       answer = answer * 10 + 9;

        if (answer_bk != answer)
            tmp_str.clear();

        answer_bk = answer;
    }

    return answer;
}

int main() {

    printf("output : %lld\n", solution("onetwothreefourfivesixseveneightnine"));
    printf("output : %lld\n", solution("onefourzerosixseven"));

    return 0;
}