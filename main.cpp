#include <iostream>
#include <cmath>
#include <string>
#include <algorithm> // Usar a função reverse()

using namespace std;

// Função para converter de decimal para binário.
// O resultado estará em ordem errada.
string DecimalParaBinario(int n){

  
    string resultadoParcial = "";

    while (n != 0){
        resultadoParcial = resultadoParcial + ( n % 2 == 0 ? "0" : "1" );
        n = n / 2;
    }

    // Pega e inverte a string, simulando a mesma
    // operação de pegar os valores da direita para esquerda.
    reverse(resultadoParcial.begin(),resultadoParcial.end());

    string resultado = "";

    // Prenchendo com zeros a esquerda (se for o caso.

    if (resultadoParcial.length()<8){
    for (int i = 0; i < (8-resultadoParcial.length()); i++)
        resultado = resultado + "0";

    resultado = resultado + resultadoParcial;
    }else        

    resultado = resultadoParcial;

    return resultado;

}

// Função para converter de binário para decimal.
// Percorre o vetor e faz o cálculo, retornando
// o resultado.
int binario_para_decimal(int v[], int t){

    int valor = 0;
    int base = 2;
    int fator = 1;

    for (int i = t - 1; i >= 0; i -= 1){
        valor = valor + v[i] * fator;
        fator = fator * base;
    }

    return valor;

}

// Função para calcular números decimais de acordo com o operador.
// Quando for o cálculo for executado, converte ele em string
// DecimalParaBinario() e retorna para a função principal.
string calcular(int nb1, int nb2, char o){

    switch(o){
        case '+': return DecimalParaBinario(nb1+nb2); break;
        case '-': return DecimalParaBinario(nb1-nb2); break;
        case '*': return DecimalParaBinario(nb1*nb2); break;
        case '/': if ( nb2 != 0 ) return DecimalParaBinario(nb1/nb2);
                  else return "Não existe divisão por 0";
        case '%': return ( nb1%nb2 == 0 ? "0" : DecimalParaBinario(nb1%nb2) ); break;
    }

    return NULL;

}

int main(){

    char operador;
    string nb1, nb2; // nb = numero binário
    int tv1, tv2;    // tv = tamanho do vetor

    int i;

    cin >> operador;

    cin >> nb1;

    tv1 = nb1.length(); // Pegando o tamanho da string nb1

    int numero_binario1[tv1]; // Criando vetor que vai armazenar o nb1

    for (i = 0; i < tv1; i++)
        numero_binario1[i] = nb1[i] - '0'; // Convertendo de char para int

    cin >> nb2;

    tv2 = nb2.length(); // Pegando o tamanho da string nb2

    int numero_binario2[tv2]; // Criando vetor que vai armazenar o nb2

    for (i = 0; i < tv2; i++)
        numero_binario2[i] = nb2[i] - '0'; // Convertendo de char para int

    int n1 = binario_para_decimal(numero_binario1,tv1); // Converte 'numero_binario1' de binário para decimal
    int n2 = binario_para_decimal(numero_binario2,tv2); // Converte 'numero_binario1' de binário para decimal



    // Verificando se está no intervalo de 0 a 255
    if ( (n1 >= 0) && (n1 <= 255) && (n2 >= 0) && (n2 <= 255) ){

        // Pega o rescultado do cálculo.
        string resultado = calcular(n1,n2,operador);
        cout << "\n" << resultado <<"\n";

    }else
        cout << "\n numero 1 e/ou numero 2 esta(ao) fora da faixa [0..255].\n";

    cout << "\n";

    return 0;

}
