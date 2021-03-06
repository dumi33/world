#include <iostream>
#include<algorithm>

using namespace std;

int cheese[9][9] = {
   {0, 0, 1, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 1, 0, 0, 0},
   {1, 0, 0, 0, 0, 0, 0, 1, 0},
   {0, 0, 0, 0, 1, 0, 0, 0, 0},
   {0, 1, 0, 1, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 1, 0, 0},
   {0, 1, 0, 0, 1, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 1, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0} };

int cheeseWtihTrap[9][9] = {
{0, 0, 1, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 1, 0, 2, 0},
{1, 0, 2, 0, 0, 0, 0, 1, 0},
{0, 0, 0, 0, 1, 2, 0, 0, 0},
{0, 1, 0, 1, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 2, 1, 2, 0},
{0, 1, 0, 0, 1, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 1, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0} };

int dp1[9][9] = { 0, };
int dp2[9][9] = { 0, };

int main()
{
    for (int i = 8; i >= 0; i--) {  // 덫이 없는경우
        for (int j = 0; j < 9; j++)
        {
            int ans = max(dp1[i + 1][j], dp1[i][j - 1]); //최댓값을 ans로 한다.
            dp1[i][j] = ans + cheese[i][j]; //이전값과 ans를 더하여 dp1배열에 넣어준다.
        }
    }

    for (int i = 8; i >= 0; i--) // 덫이 있는경우
    {
        for (int j = 0; j < 9; j++)
        {
            if (cheeseWtihTrap[i][j] == 2) { dp2[i][j] = 0; } //덫인경우 값을 0으로 만든다.
            else {
                int ans = max(dp2[i + 1][j], dp2[i][j - 1]); // 최댓값을 ans로 설정한다.
                dp2[i][j] = ans + cheeseWtihTrap[i][j]; //이전값과 ans를 더하여 dp2배열에 넣는다.
            }
        }
    }


    cout << "예제 1) 치즈의 최대값 : " << dp1[0][8] << "\n";
    cout << "예제 2) 치즈의 최대값 : " << dp2[0][8] << "\n\n";
    cout << "12191728_정보통신공학과_김두미";

}



