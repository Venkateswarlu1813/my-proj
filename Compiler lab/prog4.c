#include <iostream>
#include <cstring>
using namespace std;

class parse {
    int nt, t, m[20][20], i, s, n, p1, q, k, j;
    char p[30][30], n1[20], t1[20], ch, b, c, f[30][30], fl[30][30];

public:
    int scant(char);
    int scannt(char);
    void process();
    void input();
};

int parse::scannt(char a) {
    for (int i = 0; i < nt; i++) {
        if (n1[i] == a)
            return i;
    }
    return -1;
}

int parse::scant(char b) {
    for (int j = 0; j < t; j++) {
        if (t1[j] == b)
            return j;
    }
    return -1;
}

void parse::input() {
    cout << "Enter the number of productions: ";
    cin >> n;
    cout << "Enter the productions one by one (e.g., E->aE or E->e):\n";
    for (i = 0; i < n; i++) {
        cin >> p[i];
    }
    nt = 0;
    t = 0;
}

void parse::process() {
    for (i = 0; i < n; i++) {
        if (scannt(p[i][0]) == -1)
            n1[nt++] = p[i][0];
    }

    for (i = 0; i < n; i++) {
        for (j = 3; j < strlen(p[i]); j++) {
            if (p[i][j] != 'e') {
                if (scannt(p[i][j]) == -1 && scant(p[i][j]) == -1)
                    t1[t++] = p[i][j];
            }
        }
    }
    t1[t++] = '$'; // End of input marker

    // Initialize parse table with -1
    for (i = 0; i < nt; i++) {
        for (j = 0; j < t; j++) {
            m[i][j] = -1;
        }
    }

    // Input FIRST and FOLLOW sets
    for (i = 0; i < nt; i++) {
        cout << "Enter FIRST[" << n1[i] << "]: ";
        cin >> f[i];
    }

    for (i = 0; i < nt; i++) {
        cout << "Enter FOLLOW[" << n1[i] << "]: ";
        cin >> fl[i];
    }

    // Fill parse table
    for (i = 0; i < n; i++) {
        p1 = scannt(p[i][0]);
        char symbol = p[i][3];

        if (scant(symbol) != -1)
            m[p1][scant(symbol)] = i;

        if (scannt(symbol) != -1) {
            for (j = 0; j < strlen(f[scannt(symbol)]); j++) {
                m[p1][scant(f[scannt(symbol)][j])] = i;
            }
        }

        if (symbol == 'e') {
            for (j = 0; j < strlen(fl[p1]); j++) {
                m[p1][scant(fl[p1][j])] = i;
            }
        }
    }

    // Print parse table
    cout << "\nPredictive Parsing Table:\n";
    cout << "\t";
    for (i = 0; i < t; i++)
        cout << t1[i] << "\t";
    cout << endl;

    for (j = 0; j < nt; j++) {
        cout << n1[j] << "\t";
        for (i = 0; i < t; i++) {
            if (m[j][i] != -1)
                cout << p[m[j][i]] << "\t";
            else
                cout << " \t";
        }
        cout << endl;
    }
}

int main() {
    parse p;
    p.input();
    p.process();
    return 0;
}

