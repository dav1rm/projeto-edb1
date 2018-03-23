#include <iostream>
#include <iterator>
#include <cmath>
#include <vector>
#include <chrono>

using namespace std;

long int jumpSearch( long int *first, long int *last, long int value);

long int buscaBinaria( long int *first, long int *last, long int value );

long int buscaBinariaRecursiva( long int *first, long int *last, long int value );

long int buscaBinariaRecursiva( long int *first, long int *last, long int value, long int * firstP );

long int buscaTernaria( long int *first, long int *last, long int value );

long int buscaTernariaRecursiva( long int *first, long int *last, long int value );

long int buscaTernariaRecursiva( long int *first, long int *last, long int value, long int * firstP );

long int buscaSequencial( long int *first, long int *last, long int value );

int main( void ) {
    long int n = 1000, L = 100000000, indiceJS, indiceBB, indiceBR, indiceBT, indiceBS, indice;
    double mJS, mBB, mBR, mBT, mBS, media, diferenca, inicio, fim;

    vector<long int> vet(L);

    //Preenchendoo vetor com elementos ordenados
    for (long int i = 0; i < L; i++)
    {
        vet[i] = i+1;
    }

    //Executando 50 amostras iniciando de 1000 até 100000000 com incremento de 1999980
    while (n <= L) {
        //Cada função de busca é testada 100 vezes para obter um tempo médio de execução
        for(auto i = 0; i < 100; i++){

                //std::cout << ">>> STARTING computation that needs timing <<<\n";
                auto inicio = std::chrono::steady_clock::now();
                //================================================================================
                //std::cout << ">>> Testando busca sequencial...\n";
                //Imprime o indice do elemento encontrado
                indice = buscaSequencial(&vet[0], &vet[n], L);

                //================================================================================
                auto fim = std::chrono::steady_clock::now();
                //std::cout << ">>> ENDING computation that needs timing <<<\n";

                //Store the time difference between start and end
                auto diferenca = fim - inicio;

                // Milliseconds (10^-3)
                media = media + ((std::chrono::duration <double, std::milli> (diferenca).count() - media)/i);
                cout << "media: " << media << endl;
        }
        std::cout.precision(4);
		std::cout << n << " " << media << "\n";
        //cout << "media foi: " << media << endl;
        //Incremento calculado com base no intervalo das amostras
        n = n + 3999960;
    }
    return 0;
}

long int buscaSequencial( long int *first, long int *last, long int value ) {
    //Armazena o tamanho do array
    long int size = last-first;
    //Percorre todo o array verificando cada elemento se é igual a value
    for (long int i=0; i<size; i++) {
        //Se value foi encontrado no array, então retorna o indice
        if(first[i] == value) {
            return i;
        }
    }
    //Se value não foi encontrado no array, então retorna -1
    return -1;
}

long int buscaBinaria( long int *first, long int *last, long int value ) {
    //Armazena o tamanho do array
    long int size = last-first;
    //Armazena a metade do array
    long int m = size/2;
    //Verifica se value está no meio do array
    if (value == first[m]) {
        return m;
    //Verifica se value está na primeira metade do array
    } else if (value > first[m]) {
        for (long int i=(m+1); i<size; i++) {
            //Se value foi encontrado no array, então retorna o indice
            if(first[i] == value) {
                return i;
            }
        }
    //Verifica se value está na segunda metade do array
    } else if (value < first[m]) {
        for (long int i=0; i < m; i++) {
            //Se value foi encontrado no array, então retorna o indice
            if(first[i] == value) {
                return i;
            }
        }
    }
    //Se value não foi encontrado no array, então retorna -1
    return -1;
}

long int buscaBinariaRecursiva( long int *first, long int *last, long int value ) {
    return buscaBinariaRecursiva( first, last, value, first );
}

long int buscaBinariaRecursiva( long int *first, long int *last, long int value, long int * firstP ) {
    //Armazena o elemento central
    long int * center = first+((last-first)/2);

    //Verifica se o array chegou ao fim
    if (first > last) {
        //Se value não foi encontrado no array, então retorna -1
        return -1;
    }
    //Verifica se value está no meio do array
    if (value == *center) {
        return center-firstP;
    //Verifica se value está no final do array
    } else if (value > *center) {
        buscaBinariaRecursiva(center+1, last, value, firstP);
    //Verifica se value está no inicio do array
    } else if (value < *center) {
        buscaBinariaRecursiva(first, center-1, value, firstP);
    //Se value não foi encontrado no array, então retorna -1
    }
}

long int buscaTernaria( long int *first, long int *last, long int value ) {
    //Armazena o tamanho do array
    long int size = last-first;
    //Armazena o primeiro limite do array
    long int t1 = size/3;
    //Armazena o segundo limite do array
    long int t2 = t1*2;
    //Verifica se value está no primeiro limite do array
    if (value == first[t1]) {
        return t1;
        //Verifica se value está no segundo limite do array
    } else if (value == first[t2]) {
        return t2;
    //Verifica se value está na primeira metade do array
    } else if (value < first[t1]) {
        for (long int i=0; i<t1; i++) {
            //Se value foi encontrado no array, então retorna o indice
            if(first[i] == value) {
                return i;
            }
        }
        //Verifica se value está na segunda metade do array
    } else if (value > first[t1] && value < first[t2]) {
        for (long int i=t1; i < t2; i++) {
            //Se value foi encontrado no array, então retorna o indice
            if(first[i] == value) {
                return i;
            }
        }
    //Verifica se value está na terceira metade do array
    } else {
        for (long int i=t2; i < size; i++) {
            //Se value foi encontrado no array, então retorna o indice
            if(first[i] == value) {
                return i;
            }
        }
    }
    //Se value não foi encontrado no array, então retorna -1
    return -1;
}

long int buscaTernariaRecursiva( long int *first, long int *last, long int value ) {
    return buscaTernariaRecursiva(first, last, value, first);
}

long int buscaTernariaRecursiva( long int *first, long int *last, long int value, long int * firstP ) {
    //Armazena o tamanho dos subvetores
    long int part = (last-first)/3;
    //Armazena o primeiro limite do array
    long int * t1 = first+part;
    //Armazena o segundo limite do array
    long int * t2 = first+(part*2);
    //Verifica se o array chegou ao fim
    if (first > last) {
        //Se value não foi encontrado no array, então retorna -1
        return -1;
    }
    //Verifica se value está no primeiro limite do array
    if (value == *t1) {
        return t1-firstP;
    //Verifica se value está no segundo limite do array
    } else if (value == *t2) {
        return t2-firstP;
    //Verifica se value está no primeiro subvetor
    } else if (value < *t1) {
        buscaTernariaRecursiva(first, t1-1, value, firstP);
    //Verifica se value está no segundo subvetor
    } else if (value > *t1 && value < *t2) {
        buscaTernariaRecursiva(t1+1, t2-1, value, firstP);
    //Verifica se value está no terceiro subvetor
    } else {
        buscaTernariaRecursiva(t2+1, last, value, firstP);
    }
}

long int jumpSearch( long int *first, long int *last, long int value) {
    //Armazena o tamanho do array
    long int size = last-first;
    //Armazena o tamanho das partes do array
    long int num = sqrt(size);
    //Armazena o numero de partes do array
    long int part = size/num;
    //Armazena os limites de cada subvetor do array
    long int t[num-1];
    for (int i = 0; i < (num-1); i++) {
        t[i] = part*(i+1);
    }
    long int l = 0;
    //Percorrendo os limites do array
    for (long int i = 0; i < (num-1); i++) {
        //Verifica se value está em algum dos limites do array
        if (value == first[t[i]]) {
            //Se value foi encontrado no array, então retorna o indice
            return t[i];
        //Verifica se value está em um subvetor do array
        } else if (value < first[t[i]]) {
            for (long int j=l; j<t[i]; j++) {
                //Se value foi encontrado no array, então retorna o indice
                if (first[j] == value) {
                    return j;
                }
            }
        //Verifica se value está no ultimo subvetor do array
        } else if (t[i] == t[num-2]) {
            for (long int j=l; j<size; j++) {
                //Se value foi encontrado no array, então retorna o indice
                if (first[j] == value) {
                    return j;
                }
            }
        }
        //Armazena o inicio de um subvetor
        l = t[i];
    }
    //Se value não foi encontrado no array, então retorna -1
    return -1;
}

long int buscaFibonacci( long int *first, long int *last, long int value) {
    //Array Fibonacci
    int F[value];
    //
    for ( int i=0; i < value; i++ ) {
		if ( i == 0 ) {
            F[i] = 0;
        } else if ( i == 1 ){
            F[i] = 1;
        } else {
            F[i] = F[i-1] + F[i-2];
        }
	}

    for ( int i=0; i < value; i++ ) {
        std::cout << F[i] << '\n';
    }

    //Se value não foi encontrado no array, então retorna -1
    return -1;
}
