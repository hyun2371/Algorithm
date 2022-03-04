#include <iostream>
#include <string>
using namespace std;

void hotel(int H, int W, int N) {
    int roomH = 0; //층수와 호수
    int roomW = 0;
    if (N % H == 0) { //
        roomH = H;
        roomW = N / H;
    }
    else {
        roomH = N % H;
        roomW = (N / H) + 1;
    }
    if (roomW < 10) //호수가 한자리 수일 경우
        cout << to_string(roomH) + '0' + to_string(roomW) << endl;
    else
        cout << to_string(roomH) + to_string(roomW) << endl;

}
int main() {
    int  H,W,N, num;  //H: 층 W:호 N번째 손님 
    cin >> num; //테스트 케이스 개수
    for (int i = 0; i < num; i++) {
        cin >> H >> W >> N;
        hotel(H, W, N);
    }
    return 0;
    
}
