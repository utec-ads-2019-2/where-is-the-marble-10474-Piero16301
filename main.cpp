#include <bits/stdc++.h>

using namespace std;

int cuenta[10001] = {}, suma[10001] = {};

int encontrarPosicion(vector <int> &numerosCanicas, int consulta) {

    int maximo = *max_element(begin(numerosCanicas), end(numerosCanicas));
    for (int i = 1; i <= maximo; ++i) {
        suma[i] = suma[i-1] + cuenta[i-1];
    }
    if (!cuenta[consulta]) {
        return 0;
    } else {
        return suma[consulta] + 1;
    }
}

int main() {
    
    int canicas, consultas, numeroCaso = 1;
    while (scanf("%d %d", &canicas, &consultas) == 2) {
        if (canicas == 0 && consultas == 0) break;
        vector <int> numerosCanicas;
        for (int i = 0; i < canicas; ++i) {
            int numero;
            cin >> numero;
            numerosCanicas.push_back(numero);
            cuenta[numero]++;
        }
        cout << "CASE# " << numeroCaso << ':' << endl;
        for (int i = 0; i < consultas; ++i) {
            int numero;
            cin >> numero;
            int resultadoConsulta = encontrarPosicion(numerosCanicas, numero);
            if (resultadoConsulta != 0) {
                cout << numero << " found at " << resultadoConsulta << endl;
            } else {
                cout << numero << " not found" << endl;
            }
        }
        numeroCaso++;
        fill_n(cuenta, 10001, 0);
        fill_n(suma, 10001, 0);
    }

    return 0;
}