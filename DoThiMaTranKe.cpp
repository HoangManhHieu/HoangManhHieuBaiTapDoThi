#include <bits/stdc++.h>
using namespace std;

const int sodinh = 11;

int maTranKe[sodinh + 1][sodinh + 1];

bool daTham[sodinh + 1];

string tenTinh[sodinh + 1] = {
    "",
    "Ha Noi",
    "Hai Duong",
    "Hai Phong",
    "Uong Bi",
    "Bac Giang",
    "Bac Ninh",
    "Thai Nguyen",
    "Son Tay",
    "Hoa Binh",
    "Phu Ly",
    "Hung Yen"
};

void khoiTaoDoThi() {
    for (int i = 1; i <= sodinh; i++) {
        for (int j = 1; j <= sodinh; j++) {
            maTranKe[i][j] = 0;
        }
    }

    for (int i = 1; i <= sodinh; i++) {
        daTham[i] = false;
    }
    maTranKe[1][2] = maTranKe[2][1] = 1;
    maTranKe[1][6] = maTranKe[6][1] = 1;
    maTranKe[1][7] = maTranKe[7][1] = 1;
    maTranKe[1][8] = maTranKe[8][1] = 1;
    maTranKe[1][9] = maTranKe[9][1] = 1;
    maTranKe[1][10] = maTranKe[10][1] = 1;
    maTranKe[2][3] = maTranKe[3][2] = 1;
    maTranKe[2][11] = maTranKe[11][2] = 1;
    maTranKe[3][4] = maTranKe[4][3] = 1;
    maTranKe[4][5] = maTranKe[5][4] = 1;
    maTranKe[5][6] = maTranKe[6][5] = 1;
    maTranKe[6][4] = maTranKe[4][6] = 1;
    maTranKe[10][11] = maTranKe[11][10] = 1;
}
void DFS(int dinhBatDau) {
    queue<int> hangDoi;

    daTham[dinhBatDau] = true;
    hangDoi.push(dinhBatDau);

    cout << "Thu tu duyet BFS:\n";

    while (!hangDoi.empty()) {
        int dinhHienTai = hangDoi.front();
        hangDoi.pop();

        cout << tenTinh[dinhHienTai] << endl;

        for (int dinhKe = sodinh; dinhKe >= 1; dinhKe--) {
            if (maTranKe[dinhHienTai][dinhKe] == 1 && !daTham[dinhKe]) {
                daTham[dinhKe] = true;
                hangDoi.push(dinhKe);
            }
        }
    }
}

int main() {
    khoiTaoDoThi();
    DFS(1); 
    return 0;
}