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

long int buscaFibonacci( long int *first, long int *last, long int value);

int main( void ) {
    long int n = 100, L = 300000000, indiceS, indiceJS, indiceB, indiceBR, indiceT, indiceTR, indiceF;
    double mS = 0, mJS = 0, mB = 0, mBR = 0, mT = 0, mTR = 0, mF = 0;

    vector<long int> vet(L);

    //Preenchendoo vetor com elementos ordenados
    for (long int i = 0; i < L; i++) {
        vet[i] = i+1;
    }
    std::cout << "#" << "   " << "mS"  <<  "  " << "mJS" << "   " << "mB" << "    " << "mBR" << "   " << "mT" << "    " << "mTR" << "   " << "mF" << "\n";
    //Executando 50 amostras iniciando de 1000 até 100000000 com incremento de 1999980
    //Executando 200 amostras iniciando de 100 até 300000000 com incremento de 1499999.5
    while (n <= L) {
        //Cada função de busca é testada 100 vezes para obter um tempo médio de execução
        for(auto i = 1; i <= 100; i++){
            //---------------------------------BUSCASEQUENCIAL--------------------------------------
            //Inicia a contagem de tempo para funcao;
            auto inicioS = std::chrono::steady_clock::now();
            //Salva o indice
            indiceS = buscaSequencial(&vet[0], &vet[n], L+1);
            //Finaliza a contagem de tempo para funcao;
            auto fimS = std::chrono::steady_clock::now();
            // Calcula a média progressiva em milliseconds (10^-3)
            mS += std::chrono::duration <double, std::milli> (fimS - inicioS).count();

            //----------------------------------BUSCAJUMPSEARCH-------------------------------------
            //Inicia a contagem de tempo para funcao;
            auto inicioJS = std::chrono::steady_clock::now();
            //Salva o indice
            indiceJS = jumpSearch(&vet[0], &vet[n], L+1);
            //Finaliza a contagem de tempo para funcao;
            auto fimJS = std::chrono::steady_clock::now();
            // Calcula a média progressiva em milliseconds (10^-3)
            mJS += std::chrono::duration <double, std::milli> (fimJS - inicioJS).count();

            //----------------------------------BUSCABINARIA-------------------------------------
            //Inicia a contagem de tempo para funcao;
            auto inicioB = std::chrono::steady_clock::now();
            //Salva o indice
            indiceB = buscaBinaria(&vet[0], &vet[n], L+1);
            //Finaliza a contagem de tempo para funcao;
            auto fimB = std::chrono::steady_clock::now();
            // Calcula a média progressiva em milliseconds (10^-3)
            mB += std::chrono::duration <double, std::milli> (fimB - inicioB).count();

            //----------------------------------BUSCABINARIARECURSIVA-------------------------------------
            //Inicia a contagem de tempo para funcao;
            auto inicioBR = std::chrono::steady_clock::now();
            //Salva o indice
            indiceBR = buscaBinariaRecursiva(&vet[0], &vet[n], L+1);
            //Finaliza a contagem de tempo para funcao;
            auto fimBR = std::chrono::steady_clock::now();
            // Calcula a média progressiva em milliseconds (10^-3)
            mBR += std::chrono::duration <double, std::milli> (fimBR - inicioBR).count();

            //----------------------------------BUSCATERNARIA-------------------------------------
            //Inicia a contagem de tempo para funcao;
            auto inicioT = std::chrono::steady_clock::now();
            //Salva o indice
            indiceT = buscaTernaria(&vet[0], &vet[n], L+1);
            //Finaliza a contagem de tempo para funcao;
            auto fimT = std::chrono::steady_clock::now();
            // Calcula a média progressiva em milliseconds (10^-3)
            mT += std::chrono::duration <double, std::milli> (fimT - inicioT).count();
            //
            //----------------------------------BUSCATERNARIARECURSIVA-------------------------------------
            //Inicia a contagem de tempo para funcao;
            auto inicioTR = std::chrono::steady_clock::now();
            //Salva o indice
            indiceTR = buscaTernariaRecursiva(&vet[0], &vet[n], L+1);
            //Finaliza a contagem de tempo para funcao;
            auto fimTR = std::chrono::steady_clock::now();
            // Calcula a média progressiva em milliseconds (10^-3)
            mTR += std::chrono::duration <double, std::milli> (fimTR - inicioTR).count();

            //----------------------------------BUSCAFIBONACCI-------------------------------------
            //Inicia a contagem de tempo para funcao;
            auto inicioF = std::chrono::steady_clock::now();
            //Salva o indice
            indiceF = buscaFibonacci(&vet[0], &vet[n], L+1);
            //Finaliza a contagem de tempo para funcao;
            auto fimF = std::chrono::steady_clock::now();
            // Calcula a média progressiva em milliseconds (10^-3)
            mF += std::chrono::duration <double, std::milli> (fimF - inicioF).count();
        }
        std::cout.precision(4);

		std::cout << n << "   " << (mS/100) <<  "   " << (mJS/100) << "   " <<  (mB/100) << "    " << (mBR/100) << "   " << (mT/100) << "    " << (mTR/100) << "   " << (mF/100) << "\n";
        //Incremento calculado com base no intervalo das amostras
        n += 1499999.5;
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
    long int * n_first = first;
    while (first < last) {
        //Armazena o tamanho do array
        long int size = last-first;
        //Armazena a metade do array
        long int m = size/2;
        //Verifica se value está no meio do array
        if (value == first[m]) {
            return ((first+m) - n_first);
        //Verifica se value está na primeira metade do array
        } else if (value > first[m]) {
            first+=(m+1);
        //Verifica se value está na segunda metade do array
        } else if (value < first[m]) {
            last=(first+m);
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
    //Armazena o tamanho do array
    int n = last-first;
    //Armazena os três primeiros valores de Fibonacci
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;
    //Armazena o tamanho do subvetor removido do inicio
    int offset = -1;
    //Armazena em fibM o número de Fibonacci menor ou igual ao tamanho do vetor
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
    //Se existir elementos entre fibM e 1, continua verificando
    while (fibM > 1) {
        // Verifica se fibMm2 é um local válido
        int i = min(offset+fibMMm2, n-1);
        //Se value for maior que first[i], então é eliminado o subarray de offset até i
        if (first[i] < value) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        //Se value for menor que first[i], então é eliminado o subarray a partir de i+1
        else if (first[i] > value) {
            fibM  = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        //Se o elemento foi encontrado
        else return i;
    }
    //Verifica se o último elemento é igual a value
    if (fibMMm1 && first[offset+1] == value) {
        return offset+1;
    }
    //Se o elemento não foi encontrado
    return -1;
}
