#include <iostream>

using namespace std;

int main(){
    int value;

    cout << "-- Inicio do programa --" << endl;
    cout << "Insira um número inteiro: ";
    cin >> value;

    if(value == 0){
        cout << "O valor é zero." << endl;
        return 0;
    }

    if(value > 0){
        cout << "O valor é positivo." << endl;

    }
    else if(value < 0){
        cout << "O valor é negativo." << endl;
    }
    
    if(value % 2 == 0){
        cout << "O valor é par." << endl;
    }
    else{
        cout << "O valor é impar." << endl;
    }

    return 0;
}