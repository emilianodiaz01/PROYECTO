//
// Created by mauri on 23-11-2025.
//

#include "CTablero.h"


CTablero::CTablero(int _tipo) {
    tipoTablero = _tipo;
    tableroInterno = 2*_tipo-1;
    crearTablero();
}

void CTablero::crearTablero() {
    for (int i = 0; i < tableroInterno; i++) {
        vector<CElementos*> fila;
        for (int j = 0; j < tableroInterno; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    fila.push_back(new CPunto());
                }else {
                    fila.push_back(new CLinea());
                }
            }else {
                if (j % 2 == 0) {
                    fila.push_back(new CLinea());
                }else {
                    fila.push_back(new CCaja());
                }
            }
        }
        tablero.push_back(fila);
    }
}

CTablero::~CTablero() {
    for (auto& fila: tablero) {
        for (auto& item : fila) {
            delete item;
        }
    }
}

void CTablero::mostrar() {
    cout << "Tablero de " << tipoTablero << "x" << tipoTablero << " (Matriz interna " << tableroInterno << "x" << tableroInterno << "):\n\n";
    cout <<  "    ";
    for (int j = 1; j < tableroInterno; i++) {
        cout << j;
        if (j < 10){
            cout << "     ";
        }else {
            cout << " ";
        }
        cout << endl;
        int filas = 1;
        for(int i = 0, i < tableroInterno; i++){
            if(i% 2 == 0 && filas <= tipoTablero){
                if (filas < 10) {
                    cout <<" " << filas  << " ";
                }else {
                    cout << filas << " ";
                }
                filas++;
        }else {
            cout << "    ";
        }
        for (int i = 0; i < tableroInterno; j++) {
            cout << " " << tablero[i][j]->getSimbolo() << " ";
        }
        cout << endl;
    }
}

void CTablero::revisarTablero() {
}
