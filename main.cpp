#include <math.h>
#include <time.h>
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

int random_number(int number){
    return rand() % number;
}

int main(){
    int nlaw = 8;
    string laws[nlaw][2]; 
    laws[0][0] = "Constitucion Politica de Colombia";
    laws[0][1] = "Articulos 11,12,14,17,21,22,24,29,44. Ciudadano tiene derecho al manejo de sus datos";
    laws[1][0] = "Ley 527 de 1999";
    laws[1][1] = "Comercio electrónico. Se define y se reglamente el uso del manejo de datos";
    laws[2][0] = "Ley 594 de 2000";
    laws[2][1] = "Ley General de Archivos. Habilita el uso de tecnologías en general";
    laws[3][0] = "Ley 599 y 600 de 2000";
    laws[3][1] = "Establecimiento de codigo penal";
    laws[4][0] = "Ley 679 de 2001";
    laws[4][1] = "Pornografia y explotacion sexual infantil. Sistemas de autoregulacion y condcuta";
    laws[5][0] = "Ley 906 de 2004";
    laws[5][1] = "Codigo Penal. Ediciones leyes 599 y 600 del 2000";
    laws[6][0] = "Ley 962 de 2005";
    laws[6][1] = "Racionalizacion de tramites y procedimientos. Buscando reducir tiempo en tramites";
    laws[7][0] = "Ley 1032 de 2006";
    laws[7][1] = "Derechos de autor y conexos. Modificación articulos 257,271(violacion derechos patrimoniales de autor),272 y 306 del codigo penal";
/*    laws[8][0]
    laws[8][1]
    laws[9][0]
    laws[9][1]
    laws[10][0]*/
    string opcion;
    while(opcion[0] != 'q'){
        srand (time(NULL));
        int num_o = 3;
        int num[num_o];
        /*int num = random_number(nlaw);
        int num2 = random_number(nlaw);
        int num3 = random_number(nlaw);
        while(num == num2){
            num2 = random_number(nlaw);
        }
        while(num3 == num2 || num3 == num){
            num3 = random_number(nlaw);
        }*/
        for(int i = 0; i < num_o; i++){
            num[i] = random_number(nlaw);
            for(int j = 0; j < i; j++){
                if(num[i] == num[j]){
                    num[i] = random_number(nlaw);
                    j = 0;
                }
            }
        }
        cout << laws[num[0]][0] << endl;
        int nopt = random_number(num_o);
        //int correct;
        for(int i = 1,j = 1; i <= num_o; i++){
            if((i-1) == nopt){
                cout << i << ". " << laws[num[0]][1];
            }
            else{
                cout << i << ". " << laws[num[j]][1];
                j++;
            }
            cout << endl;
        }
        /**if(nopt%num_o == 0){
            correct = 1;
            cout << "1. " << laws[num][1] << endl;
            cout << "2. " << laws[num2][1] << endl;
        }
        else{
            correct = 2;
            cout << "1. " << laws[num2][1] << endl;
            cout << "2. " << laws[num][1] << endl;
        }*/
        int answ; 
        cout << "Ingresar respuesta: ";
        cin >> answ;
        do{
            if(answ == (nopt+1)){
                cout << "Correcto" << endl;
            }
            else{
                cout << "Incorrecto" << endl;
                cout << "Ingresar opcion: ";
                cin >> answ;
            }
        }
        while(answ != (nopt+1));
        cout << "Cualquier letra para continuar(excepto 'q'): ";
        cin >> opcion;
    }
    return 0;
}
