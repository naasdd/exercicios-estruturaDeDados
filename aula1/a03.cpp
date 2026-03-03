#include <iostream>

using namespace std;

int verificaNumero(){
    int value;

    cout << "\n";
    cout << "-- Verificar um número inteiro --" << endl;
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


// ex2
bool verificaMultiplo(int value)
    {
        if(value % 3 == 0) return 1;
        return 0;
    }

string exibeTabuada(int value, int i){
    int resultado = value * i;

    if(verificaMultiplo(value)){
        cout << value << " x " << i << " = " << resultado << endl;
    }
    i++;
    if(i <= 10) exibeTabuada(value, i);


    return "Fim";
}

int tabuadaSeMultiplo3()
{
    int value;
    cout << "\nDigite um número inteiro: ";
    cin >> value;

    int i = 1;
    exibeTabuada(value, i);


    return 0;
}


int main()
{
    int option = 0;
    do
    {
        cout << "\n \n";
        cout << "1 - Verifica Numero" << endl;
        cout << "2 - Tabuada se divisível por 3" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> option;

        if(option == 0) break;

        switch (option)
        {
        case 1:
            verificaNumero();

        break;

        case 2:
            tabuadaSeMultiplo3();
            
            break;
        default:
            cout << "SISTEMA: Opção incorreta.";
            break;
        }

    } while (option != 0);

    return 0;
}