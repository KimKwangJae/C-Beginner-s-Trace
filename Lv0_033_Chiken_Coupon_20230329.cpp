#include <string>
#include <vector>

using namespace std;

//*************************************************************************************************************************************
// Programmers [Lv0] 
// 
// ���� : ġŲ ����
// 
// ���� ����
// ���α׷��ӽ� ġŲ�� ġŲ�� ���Ѹ����� �� ������ ������ �� �� �߱��մϴ�. ������ �� �� ������ ġŲ�� �� ���� ���񽺷� ���� �� �ְ�, 
// ���� ġŲ���� ������ �߱޵˴ϴ�. ���Ѹ��� ġŲ�� �� chicken�� �Ű������� �־��� �� ���� �� �ִ� �ִ� ���� ġŲ�� ���� return�ϵ��� solution �Լ��� �ϼ����ּ���.
//
// ���ѻ���
// chicken�� �����Դϴ�.
// 0 �� chicken �� 1, 000, 000
// 
// ����� ��
// chicken	result
// 100	    11
// 1,081	120
//
//*************************************************************************************************************************************

int solution(int chicken) {
    int answer = -1;

    int service_chicken = 0;
    int coupon = 0;
    while ((chicken+coupon) / 10 > 0) {
        coupon += chicken % 10;
        if (coupon / 10 > 0) {
            service_chicken = service_chicken + (chicken / 10) + (coupon / 10);
            coupon = (coupon % 10) + (coupon / 10);
        }
        else
            service_chicken = service_chicken + (chicken / 10);

        chicken /= 10;
    }

    return answer = service_chicken;
}

int main() {
    printf("output : %d\n", solution(100));     //11
    printf("output : %d\n", solution(1081));    //120
    printf("output : %d\n", solution(10));        //1
    printf("output : %d\n", solution(19));        //2
    printf("output : %d\n", solution(1999));        //222
    return 0;
}