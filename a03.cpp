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

int main()
{
    int option = 0;
    do
    {
        cout << "\n \n";
        cout << "1 - Verifica Numero" << endl;
        cout << "2 - Hora atual" << endl;
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
            cout << "SISTEMA: 17:22";
            break;
        default:
            cout << "SISTEMA: Opção incorreta.";
            break;
        }

    } while (option != 0);

    return 0;
}