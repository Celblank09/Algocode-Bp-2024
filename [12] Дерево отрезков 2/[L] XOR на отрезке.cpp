#include <bits/stdc++.h>

using namespace std;

struct NODE {
    int c0;
    int c1;
    bool push;
};

NODE NODE_0 {
        NODE_0.c0 = 0,
        NODE_0.c1 = 0,
        NODE_0.push = false
};

void apply(int v, bool p, vector <NODE> &t) {
    if (p) {
        int c0, c1;
        c0 = t[v].c0;
        c1 = t[v].c1;
        t[v].c0 = c1;
        t[v].c1 = c0;
        t[v].push = !t[v].push;
    }
}

void push(int v, vector <NODE> &t) {
    apply(2 * v, t[v].push, t);
    apply(2 * v + 1, t[v].push, t);
    t[v].push = false;
}

void BUILD(int v, int l, int r, vector <NODE> &t, vector <NODE> &a) {
    if (l + 1 == r) {
        t[v] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    BUILD(2 * v, l, mid, t, a);
    BUILD(2 * v + 1, mid, r, t, a);
    t[v].c0 = t[2 * v].c0 + t[2 * v + 1].c0;
    t[v].c1 = t[2 * v].c1 + t[2 * v + 1].c1;
}

void SET(int v, int vl, int vr, int ql, int qr, vector <NODE> &t) {
    if (vl >= qr || vr <= ql) {
        return;
    }
    if (vl >= ql && vr <= qr) {
        apply(v, 1, t);
        return;
    }
    push(v, t);
    int mid = (vl + vr) / 2;
    SET(2 * v, vl, mid, ql, qr, t);
    SET(2 * v + 1, mid, vr, ql, qr, t);
    t[v].c0 = t[2 * v].c0 + t[2 * v + 1].c0;
    t[v].c1 = t[2 * v].c1 + t[2 * v + 1].c1;
}

long long GET(int v, int vl, int vr, int ql, int qr, vector <NODE> &t) {
    if (vl >= qr || vr <= ql) {
        return 0;
    }
    if (vl >= ql && vr <= qr) {
        return t[v].c1;
    }
    push(v, t);
    int mid = (vl + vr) / 2;
    auto res1 = GET(2 * v, vl, mid, ql, qr, t);
    auto res2 = GET(2 * v + 1, mid, vr, ql, qr, t);
    return res1 + res2;
}

string to_2(long long a) {
    string res = "00000000000000000000000000000000";
    for (int i = 0; i < 32; ++i) {
        if (a % 2 == 1) {
            res[i] = '1';
        }
        a /= 2;
    }
    return res;
}

int main() {
    long long n, dop, q, l, r, t, res;
    string s;
    cin >> n;
    vector <NODE> a1(n, NODE_0);
    vector <NODE> a2(n, NODE_0);
    vector <NODE> a3(n, NODE_0);
    vector <NODE> a4(n, NODE_0);
    vector <NODE> a5(n, NODE_0);
    vector <NODE> a6(n, NODE_0);
    vector <NODE> a7(n, NODE_0);
    vector <NODE> a8(n, NODE_0);
    vector <NODE> a9(n, NODE_0);
    vector <NODE> a10(n, NODE_0);
    vector <NODE> a11(n, NODE_0);
    vector <NODE> a12(n, NODE_0);
    vector <NODE> a13(n, NODE_0);
    vector <NODE> a14(n, NODE_0);
    vector <NODE> a15(n, NODE_0);
    vector <NODE> a16(n, NODE_0);
    vector <NODE> a17(n, NODE_0);
    vector <NODE> a18(n, NODE_0);
    vector <NODE> a19(n, NODE_0);
    vector <NODE> a20(n, NODE_0);
    vector <NODE> a21(n, NODE_0);
    vector <NODE> a22(n, NODE_0);
    vector <NODE> a23(n, NODE_0);
    vector <NODE> a24(n, NODE_0);
    vector <NODE> a25(n, NODE_0);
    vector <NODE> a26(n, NODE_0);
    vector <NODE> a27(n, NODE_0);
    vector <NODE> a28(n, NODE_0);
    vector <NODE> a29(n, NODE_0);
    vector <NODE> a30(n, NODE_0);
    vector <NODE> a31(n, NODE_0);
    vector <NODE> a32(n, NODE_0);
    vector <NODE> t1(8 * n + 12, NODE_0);
    vector <NODE> t2(8 * n + 12, NODE_0);
    vector <NODE> t3(8 * n + 12, NODE_0);
    vector <NODE> t4(8 * n + 12, NODE_0);
    vector <NODE> t5(8 * n + 12, NODE_0);
    vector <NODE> t6(8 * n + 12, NODE_0);
    vector <NODE> t7(8 * n + 12, NODE_0);
    vector <NODE> t8(8 * n + 12, NODE_0);
    vector <NODE> t9(8 * n + 12, NODE_0);
    vector <NODE> t10(8 * n + 12, NODE_0);
    vector <NODE> t11(8 * n + 12, NODE_0);
    vector <NODE> t12(8 * n + 12, NODE_0);
    vector <NODE> t13(8 * n + 12, NODE_0);
    vector <NODE> t14(8 * n + 12, NODE_0);
    vector <NODE> t15(8 * n + 12, NODE_0);
    vector <NODE> t16(8 * n + 12, NODE_0);
    vector <NODE> t17(8 * n + 12, NODE_0);
    vector <NODE> t18(8 * n + 12, NODE_0);
    vector <NODE> t19(8 * n + 12, NODE_0);
    vector <NODE> t20(8 * n + 12, NODE_0);
    vector <NODE> t21(8 * n + 12, NODE_0);
    vector <NODE> t22(8 * n + 12, NODE_0);
    vector <NODE> t23(8 * n + 12, NODE_0);
    vector <NODE> t24(8 * n + 12, NODE_0);
    vector <NODE> t25(8 * n + 12, NODE_0);
    vector <NODE> t26(8 * n + 12, NODE_0);
    vector <NODE> t27(8 * n + 12, NODE_0);
    vector <NODE> t28(8 * n + 12, NODE_0);
    vector <NODE> t29(8 * n + 12, NODE_0);
    vector <NODE> t30(8 * n + 12, NODE_0);
    vector <NODE> t31(8 * n + 12, NODE_0);
    vector <NODE> t32(8 * n + 12, NODE_0);
    for (int i = 0; i < n; ++i) {
        cin >> dop;
        s = to_2(dop);
        a1[i].c1 = s[0] - '0';
        a1[i].c0 = 1 - (s[0] - '0');
        a2[i].c1 = s[1] - '0';
        a2[i].c0 = 1 - (s[1] - '0');
        a3[i].c1 = s[2] - '0';
        a3[i].c0 = 1 - (s[2] - '0');
        a4[i].c1 = s[3] - '0';
        a4[i].c0 = 1 - (s[3] - '0');
        a5[i].c1 = s[4] - '0';
        a5[i].c0 = 1 - (s[4] - '0');
        a6[i].c1 = s[5] - '0';
        a6[i].c0 = 1 - (s[5] - '0');
        a7[i].c1 = s[6] - '0';
        a7[i].c0 = 1 - (s[6] - '0');
        a8[i].c1 = s[7] - '0';
        a8[i].c0 = 1 - (s[7] - '0');
        a9[i].c1 = s[8] - '0';
        a9[i].c0 = 1 - (s[8] - '0');
        a10[i].c1 = s[9] - '0';
        a10[i].c0 = 1 - (s[9] - '0');
        a11[i].c1 = s[10] - '0';
        a11[i].c0 = 1 - (s[10] - '0');
        a12[i].c1 = s[11] - '0';
        a12[i].c0 = 1 - (s[11] - '0');
        a13[i].c1 = s[12] - '0';
        a13[i].c0 = 1 - (s[12] - '0');
        a14[i].c1 = s[13] - '0';
        a14[i].c0 = 1 - (s[13] - '0');
        a15[i].c1 = s[14] - '0';
        a15[i].c0 = 1 - (s[14] - '0');
        a16[i].c1 = s[15] - '0';
        a16[i].c0 = 1 - (s[15] - '0');
        a17[i].c1 = s[16] - '0';
        a17[i].c0 = 1 - (s[16] - '0');
        a18[i].c1 = s[17] - '0';
        a18[i].c0 = 1 - (s[17] - '0');
        a19[i].c1 = s[18] - '0';
        a19[i].c0 = 1 - (s[18] - '0');
        a20[i].c1 = s[19] - '0';
        a20[i].c0 = 1 - (s[19] - '0');
        a21[i].c1 = s[20] - '0';
        a21[i].c0 = 1 - (s[20] - '0');
        a22[i].c1 = s[21] - '0';
        a22[i].c0 = 1 - (s[21] - '0');
        a23[i].c1 = s[22] - '0';
        a23[i].c0 = 1 - (s[22] - '0');
        a24[i].c1 = s[23] - '0';
        a24[i].c0 = 1 - (s[23] - '0');
        a25[i].c1 = s[24] - '0';
        a25[i].c0 = 1 - (s[24] - '0');
        a26[i].c1 = s[25] - '0';
        a26[i].c0 = 1 - (s[25] - '0');
        a27[i].c1 = s[26] - '0';
        a27[i].c0 = 1 - (s[26] - '0');
        a28[i].c1 = s[27] - '0';
        a28[i].c0 = 1 - (s[27] - '0');
        a29[i].c1 = s[28] - '0';
        a29[i].c0 = 1 - (s[28] - '0');
        a30[i].c1 = s[29] - '0';
        a30[i].c0 = 1 - (s[29] - '0');
        a31[i].c1 = s[30] - '0';
        a31[i].c0 = 1 - (s[30] - '0');
        a32[i].c1 = s[31] - '0';
        a32[i].c0 = 1 - (s[31] - '0');
    }
    BUILD(1, 0, n, t1, a1);
    BUILD(1, 0, n, t2, a2);
    BUILD(1, 0, n, t3, a3);
    BUILD(1, 0, n, t4, a4);
    BUILD(1, 0, n, t5, a5);
    BUILD(1, 0, n, t6, a6);
    BUILD(1, 0, n, t7, a7);
    BUILD(1, 0, n, t8, a8);
    BUILD(1, 0, n, t9, a9);
    BUILD(1, 0, n, t10, a10);
    BUILD(1, 0, n, t11, a11);
    BUILD(1, 0, n, t12, a12);
    BUILD(1, 0, n, t13, a13);
    BUILD(1, 0, n, t14, a14);
    BUILD(1, 0, n, t15, a15);
    BUILD(1, 0, n, t16, a16);
    BUILD(1, 0, n, t17, a17);
    BUILD(1, 0, n, t18, a18);
    BUILD(1, 0, n, t19, a19);
    BUILD(1, 0, n, t20, a20);
    BUILD(1, 0, n, t21, a21);
    BUILD(1, 0, n, t22, a22);
    BUILD(1, 0, n, t23, a23);
    BUILD(1, 0, n, t24, a24);
    BUILD(1, 0, n, t25, a25);
    BUILD(1, 0, n, t26, a26);
    BUILD(1, 0, n, t27, a27);
    BUILD(1, 0, n, t28, a28);
    BUILD(1, 0, n, t29, a29);
    BUILD(1, 0, n, t30, a30);
    BUILD(1, 0, n, t31, a31);
    BUILD(1, 0, n, t32, a32);
    cin >> q;
    /*cout << " | ";
    for (int j = 0; j < n; ++j) {
        cout << GET(1, 0, n, j, j + 1, t32);
    }
    cout << "\n";*/
    for (int i = 0; i < q; ++i) {
        cin >> t;
        if (t == 1) {
            res = 0;
            cin >> l >> r;
            l--;
            res += GET(1, 0, n, l, r, t1);
            res += GET(1, 0, n, l, r, t2) * 2;
            res += GET(1, 0, n, l, r, t3) * 4;
            res += GET(1, 0, n, l, r, t4) * 8;
            res += GET(1, 0, n, l, r, t5) * 16;
            res += GET(1, 0, n, l, r, t6) * 32;
            res += GET(1, 0, n, l, r, t7) * 64;
            res += GET(1, 0, n, l, r, t8) * 128;
            res += GET(1, 0, n, l, r, t9) * 256;
            res += GET(1, 0, n, l, r, t10) * 512;
            res += GET(1, 0, n, l, r, t11) * 1024;
            res += GET(1, 0, n, l, r, t12) * 2048;
            res += GET(1, 0, n, l, r, t13) * 4096;
            res += GET(1, 0, n, l, r, t14) * 8192;
            res += GET(1, 0, n, l, r, t15) * 16384;
            res += GET(1, 0, n, l, r, t16) * 32768;
            res += GET(1, 0, n, l, r, t17) * 65536;
            res += GET(1, 0, n, l, r, t18) * 131072;
            res += GET(1, 0, n, l, r, t19) * 262144;
            res += GET(1, 0, n, l, r, t20) * 524288;
            res += GET(1, 0, n, l, r, t21) * 1048576;
            res += GET(1, 0, n, l, r, t22) * 2097152;
            res += GET(1, 0, n, l, r, t23) * 4194304;
            res += GET(1, 0, n, l, r, t24) * 8388608;
            res += GET(1, 0, n, l, r, t25) * 16777216;
            res += GET(1, 0, n, l, r, t26) * 33554432;
            res += GET(1, 0, n, l, r, t27) * 67108864;
            res += GET(1, 0, n, l, r, t28) * 134217728;
            res += GET(1, 0, n, l, r, t29) * 268435456;
            res += GET(1, 0, n, l, r, t30) * 536870912;
            res += GET(1, 0, n, l, r, t31) * 1073741824;
            res += GET(1, 0, n, l, r, t32) * 2147483648;
            cout << res << "\n";
        } else {
            cin >> l >> r >> dop;
            s = to_2(dop);
            l--;
            if (s[0] == '1') {
                SET(1, 0, n, l, r, t1);
            }
            if (s[1] == '1') {
                SET(1, 0, n, l, r, t2);
            }
            if (s[2] == '1') {
                SET(1, 0, n, l, r, t3);
            }
            if (s[3] == '1') {
                SET(1, 0, n, l, r, t4);
            }
            if (s[4] == '1') {
                SET(1, 0, n, l, r, t5);
            }
            if (s[5] == '1') {
                SET(1, 0, n, l, r, t6);
            }
            if (s[6] == '1') {
                SET(1, 0, n, l, r, t7);
            }
            if (s[7] == '1') {
                SET(1, 0, n, l, r, t8);
            }
            if (s[8] == '1') {
                SET(1, 0, n, l, r, t9);
            }
            if (s[9] == '1') {
                SET(1, 0, n, l, r, t10);
            }
            if (s[10] == '1') {
                SET(1, 0, n, l, r, t11);
            }
            if (s[11] == '1') {
                SET(1, 0, n, l, r, t12);
            }
            if (s[12] == '1') {
                SET(1, 0, n, l, r, t13);
            }
            if (s[13] == '1') {
                SET(1, 0, n, l, r, t14);
            }
            if (s[14] == '1') {
                SET(1, 0, n, l, r, t15);
            }
            if (s[15] == '1') {
                SET(1, 0, n, l, r, t16);
            }
            if (s[16] == '1') {
                SET(1, 0, n, l, r, t17);
            }
            if (s[17] == '1') {
                SET(1, 0, n, l, r, t18);
            }
            if (s[18] == '1') {
                SET(1, 0, n, l, r, t19);
            }
            if (s[19] == '1') {
                SET(1, 0, n, l, r, t20);
            }
            if (s[20] == '1') {
                SET(1, 0, n, l, r, t21);
            }
            if (s[21] == '1') {
                SET(1, 0, n, l, r, t22);
            }
            if (s[22] == '1') {
                SET(1, 0, n, l, r, t23);
            }
            if (s[23] == '1') {
                SET(1, 0, n, l, r, t24);
            }
            if (s[24] == '1') {
                SET(1, 0, n, l, r, t25);
            }
            if (s[25] == '1') {
                SET(1, 0, n, l, r, t26);
            }
            if (s[26] == '1') {
                SET(1, 0, n, l, r, t27);
            }
            if (s[27] == '1') {
                SET(1, 0, n, l, r, t28);
            }
            if (s[28] == '1') {
                SET(1, 0, n, l, r, t29);
            }
            if (s[29] == '1') {
                SET(1, 0, n, l, r, t30);
            }
            if (s[30] == '1') {
                SET(1, 0, n, l, r, t31);
            }
            if (s[31] == '1') {
                SET(1, 0, n, l, r, t32);
            }
        }
        /*cout << " | ";
        for (int j = 0; j < n; ++j) {
            cout << GET(1, 0, n, j, j + 1, t1);
        }
        cout << "\n";*/
    }
}
