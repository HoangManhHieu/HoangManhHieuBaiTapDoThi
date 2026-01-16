#include <bits/stdc++.h>
using namespace std;

const int sodinh = 11;

struct Node {
    int dinhKe;
    Node* next;
};

Node* danhSachKe[sodinh + 1];

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
        danhSachKe[i] = NULL;
        daTham[i] = false;
    }
}

void themDinhKe(int u, int v) {
    Node* Newnode = new Node;
    Newnode->dinhKe = v;
    Newnode->next = NULL;

    if (danhSachKe[u] == NULL || danhSachKe[u]->dinhKe < v) {
        Newnode->next = danhSachKe[u];
        danhSachKe[u] = Newnode;
        return;
    }

    Node* hienTai = danhSachKe[u];
    while (hienTai->next != NULL &&
           hienTai->next->dinhKe > v) {
        hienTai = hienTai->next;
    }

    Newnode->next = hienTai->next;
    hienTai->next = Newnode;
}

void addCanh(int u, int v) {
    themDinhKe(u, v);
    themDinhKe(v, u);
}

void BFS(int dinhBatDau) {
    queue<int> hangDoi;

    daTham[dinhBatDau] = true;
    hangDoi.push(dinhBatDau);

    cout << "Thu tu duyet BFS:\n";

    while (!hangDoi.empty()) {
        int dinhHienTai = hangDoi.front();
        hangDoi.pop();

        cout << tenTinh[dinhHienTai] << endl;

        Node* p = danhSachKe[dinhHienTai];
        while (p != NULL) {
            int dinhKe = p->dinhKe;
            if (!daTham[dinhKe]) {
                daTham[dinhKe] = true;
                hangDoi.push(dinhKe);
            }
            p = p->next;
        }
    }
}

int main() {
    khoiTaoDoThi();
    addCanh(1, 2);
    addCanh(1, 6);
    addCanh(1, 7);
    addCanh(1, 8);
    addCanh(1, 9);
    addCanh(1, 10);
    addCanh(2, 3);
    addCanh(2, 11);
    addCanh(3, 4);
    addCanh(4, 5);
    addCanh(4, 6);
    addCanh(5, 6);
    addCanh(10, 11);
    BFS(1);
    return 0;
}