#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int cuentacifras(int num) {
    int aa = 1, contad = 0;
    if (num < 0) num = num * -1;

    while (aa <= num) {
        aa = aa * 10;
        contad++;
    }
    return contad;
}

bool primo(int num) {
    bool esPrimo = true;
    int q = 2;
    while (q <= num / 2 && esPrimo) {
        if (num % q == 0)
            esPrimo = false;
        q++;
    }
    return esPrimo;

}

int sumaprimos(int n) {
    int h = 1, sum = 0, conta = 1;
    while (h <= n) {
        conta++;
        if (primo(conta)) {
            sum += conta;
            h++;
        }
    }
    return sum;
}

int sumaprimosrecursivo(int limite, int n) {
    if (limite > 0) {
        if (primo(n))
            return sumaprimosrecursivo(limite - 1, n + 1) + n;
        else
            return sumaprimosrecursivo(limite, n + 1);
    } else
        return 0;
}

void adivina(int opor) {
    srand(time(NULL));
    //numeros aleatorios entre 0 y 50:
    int num = 1 + (rand() % 51);
    //int num=15;
    bool adivi = false;
    int n;
    cout << endl << "adivina el numero entre 1 y 50" << endl;
    int ee = 1;
    while (ee <= opor && adivi == false) {
        cout << endl << endl << "OPORTUNIDAD #: " << ee;
        cout << endl << "ingresa tu numero: ";
        cin >> n;
        if (n > num)
            cout << endl << "El numero ingresado es mayor al que se quiere saber" << endl;
        else if (n < num)
            cout << endl << "El numero ingresado es menor al que se quiere saber" << endl;
        else {
            cout << endl << "Felicidades" << endl;
            adivi = true;
        }
        ee++;
    }
    if (adivi)
        cout << endl << "eres el campeon";
    else
        cout << endl << "no lo logro";
}

int mensaje(int ai) {
    if (ai == 1) {
    } else {
        cout << "Presione la tecla Enter para tirar el 2do dado";
    }
    cin.ignore();
}

int tira() {
    int ran;
    srand(time(0));
    ran = rand() % 6 + 1;
    cout << " El dado dio " << ran << endl;
    return ran;
}

int d(int aa, int bb) {
    if (aa == bb) {
        cout << endl << "Felicidades salio par, ha ganado";
    } else if (aa + bb == 11) {
        cout << endl << "Felicidades salio 11, ha ganado";
    } else {
        cout << endl << "No salio par ni llego a 11, la suma de los dados dio" << aa + bb << " , perdio";
    }
}

int main() {
    int num = 8, x, y;
    cout << endl << "el numero " << num << " tiene " << cuentacifras(num) << " cifras";
    cout << endl;
    num = 11;
    if (primo(num))
        cout << num << " Es primo";
    else
        cout << num << " no es primo";
    cout << endl;
    cout << "La suma de los 4 primeros primos es: (2+3+5+7+11) " << sumaprimos(5);
    cout << endl;
    cout << "La suma recursiva de los 4 primeros primos es: (2+3+5+7+11) " << sumaprimosrecursivo(5, 2);
    cout << endl;
    srand(time(NULL));
    //numeros aleatorios entre 0 y 50
    num = rand() % 51;
    cout << endl << "aleatorio: " << num << endl;
    int opcion;
    bool salir = false;
    while (true) {
        cout << endl << endl << "Menu principal - adivina el numero";
        cout << endl << "1. jugar";
        cout << endl << "2. para ir al siguiente juego";
        cout << endl << "Cual es tu opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                adivina(5);
                break;
            case 2:
                salir = true;
                break;
            default:
                cout << endl << " Opcion no valida ";
        }
        if (salir)
            break;
    }
    salir = false;
    while (true) {
        cout << endl << "Quiere jugar a los dados? 1 para si, 2 para no" << endl;
        cin >> num;
        switch (num) {
            case 1:
                mensaje(1);
                x = tira();
                mensaje(2);
                y = tira();
                d(x, y);
                break;
            case 2:
                salir = true;
                break;
            default:
                cout << endl << "opcion no valida" << endl;
        }
        if (salir)
            break;
    }
    return 0;
}
