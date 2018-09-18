#include <fstream>
#include <math.h>
#include <time.h>
#include <string>
#include <vector>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int random_number(int number){
    return rand() % number; //sets a random number
}

int main(int argc, char * argv[]){
    
    ifstream fe (argv[1]);//it reads the line argv[1] which especifies the name of the file to read
    if(!fe.is_open()){ //this try to open the file, if there is a problem the program would be closed
        cout << "Problemas cargando el archivo" << endl;
        return 0;
    }
    
    int nQ = 0; //counter to know the amount of questions == vector.size()

    vector <pair<string, string>> queAns; //vector to set the pair<question, answer>
    string lineGet[2]; //"temporary" string*
    for(int i = 0; getline(fe,lineGet[i]);){ //it stops when getline() == false => end of the file
        if(i == 1){ //i == 1 => next question
            nQ++; //increase the amount of questions
            i = -1; //sets i = -1 because it would be increased by one
            queAns.push_back(make_pair(lineGet[0],lineGet[1])); //push the question with its respectively answer
        }
        i++;
    }

    fe.close(); //close the file

    cout << "-----------------------------" << endl;
    cout << "Para salir oprimir 'q' y luego enter" << endl;
    cout << "-----------------------------" << endl;

    string answ; //this string would be used to get any answer from the user
    while(answ[0] != 'q'){ //the program stops when the user has typed 'q'
        srand (time(NULL)); //sets time to get "random" numbers
        
        int num_o = 3; //number of answers
        int num[num_o]; //array which would have the number of the answers
        
        for(int i = 0; i < num_o; i++){
            num[i] = random_number(nQ); //gets a first random number and the question
            for(int j = 0; j < i; j++){ //it checks that that number hasn't been already choose
                if(num[i] == num[j]){ //if number already exists
                    num[i] = random_number(nQ); //sets a new number
                    j = -1; //start to check from 0
                }
            }
        }
        cout << "Pregunta: ";
        cout << get<0>(queAns[num[0]]) << endl; //prints the question
        int nopt = random_number(num_o); //sets the position in which the right answer would be set
        
        for(int i = 1,j = 1; i <= num_o; i++){
            if((i-1) == nopt){ //print the position of the right answer
                cout << i << ". " << get<1>(queAns[num[0]]);
            }
            else{ //print all other answers
                cout << i << ". " << get<1>(queAns[num[j]]);
                j++;
            }
            cout << endl;
        }
         
        cout << "Ingresar respuesta: ";
        cin >> answ; //get answer from the user
        do{
            if(answ[0] == 'q'){ //if it is equals to the exit code
                cout << "-----------------------------" << endl;
                cout << "Adiós ^^" << endl;
            }
            else{
                if((answ[0]-48) == (nopt+1)){ //this would be printed if the first answer was right
                    cout << "Correcto" << endl;
                    cout << "-----------------------------" << endl;
                }
                else{ //wrong or not valid answer
                    cout << "Incorrecto" << endl;
                    cout << "Ingresar opcion: ";
                    cin >> answ; //introduce a new answer
                    if((answ[0]-48) == (nopt+1)){ //if it is correct this would be printed
                        cout << "Correcto" << endl;
                        cout << "-----------------------------" << endl;
                    }
                }
            }
        }while((answ[0]-48) != (nopt+1) && answ[0] != 'q'); //the cycle finishes when the answer is right or the user typed the letter q
    }
    return 0;
}
