#include <iostream>
#include <iterator>
using namespace std;

int jumpSearch( int *first, int *last, int value, int num);

int buscaBinaria( int *first, int *last, int value );

int buscaBinariaRecursiva( int *first, int *last, int value );

int buscaBinariaRecursiva( int *first, int *last, int value, int * _first );

int buscaTernaria( int *first, int *last, int value );

int buscaTernariaRecursiva( int *first, int *last, int value );

int buscaTernariaRecursiva( int *first, int *last, int value, int * firstP );

int buscaSequencial( int *first, int *last, int value );

int main( void ) {
    int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
    //Imprime o array A
    cout << ">>> Original array A: [ ";
    copy( begin(A), end(A), ostream_iterator<int>( cout, " ") );
    cout << "]\n";

    //Imprime o indice do elemento encontrado
    cout << "Indice eh: " << buscaTernariaRecursiva(begin(A), end(A), 1) << '\n';
    return 0;
}

int buscaSequencial( int *first, int *last, int value ) {
    //Armazena o tamanho do array
    int size = last-first;
    //Percorre todo o array verificando cada elemento se é igual a value
    for (int i=0; i<size; i++) {
        //Se value foi encontrado no array, então retorna o indice
        if(first[i] == value) {
            return i;
        }
    }
    //Se value não foi encontrado no array, então retorna -1
    return -1;
}

int buscaBinaria( int *first, int *last, int value ) {
    //Armazena o tamanho do array
    int size = last-first;
    //Armazena a metade do array
    int m = size/2;
    //Verifica se value está no meio do array
    if (value == first[m]) {
        return m;
    //Verifica se value está na primeira metade do array
    } else if (value > first[m]) {
        for (int i=(m+1); i<size; i++) {
            //Se value foi encontrado no array, então retorna o indice
            if(first[i] == value) {
                return i;
            }
        }
    //Verifica se value está na segunda metade do array
    } else if (value < first[m]) {
        for (int i=0; i < m; i++) {
            //Se value foi encontrado no array, então retorna o indice
            if(first[i] == value) {
                return i;
            }
        }
    }
    //Se value não foi encontrado no array, então retorna -1
    return -1;
}

int buscaBinariaRecursiva( int *first, int *last, int value ) {
    return buscaBinariaRecursiva( first, last, value, first );
}

int buscaBinariaRecursiva( int *first, int *last, int value, int * firstP ) {
    //Armazena o elemento central
    int * center = first+((last-first)/2);
    //Verifica se o array nao chegou ao fim
    if (first < last) {
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
    }else{
        return -1;
    }
}

int buscaTernaria( int *first, int *last, int value ) {
    //Armazena o tamanho do array
    int size = last-first;
    //Armazena o primeiro limite do array
    int t1 = size/3;
    //Armazena o segundo limite do array
    int t2 = t1*2;
    //Verifica se value está no primeiro limite do array
    if (value == first[t1]) {
        return t1;
        //Verifica se value está no segundo limite do array
    } else if (value == first[t2]) {
        return t2;
    //Verifica se value está na primeira metade do array
    } else if (value < first[t1]) {
        for (int i=0; i<t1; i++) {
            //Se value foi encontrado no array, então retorna o indice
            if(first[i] == value) {
                return i;
            }
        }
        //Verifica se value está na segunda metade do array
    } else if (value > first[t1] && value < first[t2]) {
        for (int i=t1; i < t2; i++) {
            //Se value foi encontrado no array, então retorna o indice
            if(first[i] == value) {
                return i;
            }
        }
    //Verifica se value está na terceira metade do array
    } else {
        for (int i=t2; i < size; i++) {
            //Se value foi encontrado no array, então retorna o indice
            if(first[i] == value) {
                return i;
            }
        }
    }
    //Se value não foi encontrado no array, então retorna -1
    return -1;
}

int buscaTernariaRecursiva( int *first, int *last, int value ) {
    return buscaTernariaRecursiva(first, last, value, first);
}

int buscaTernariaRecursiva( int *first, int *last, int value, int * firstP ) {
    //Armazena o tamanho dos subvetores
    int part = (last-first)/3;
    //Armazena o primeiro limite do array
    int * t1 = first+part;
    //Armazena o segundo limite do array
    int * t2 = first+(part*2);
    //Verifica se o array nao chegou ao fim
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

int jumpSearch( int *first, int *last, int value, int num) {
    //Armazena o tamanho do array
    int size = last-first;
    //Armazena o numero de partes do array
    int part = size/num;
    //Armazena os limites de cada subvetor do array
    int t[num-1];
    for (int i = 0; i < (num-1); i++) {
        t[i] = part*(i+1);
    }
    int l = 0;
    //Percorrendo os limites do array
    for (int i = 0; i < (num-1); i++) {
        //Verifica se value está em algum dos limites do array
        if (value == first[t[i]]) {
            //Se value foi encontrado no array, então retorna o indice
            return t[i];
        //Verifica se value está em um subvetor do array
        } else if (value < first[t[i]]) {
            for (int j=l; j<t[i]; j++) {
                //Se value foi encontrado no array, então retorna o indice
                if (first[j] == value) {
                    return j;
                }
            }
        //Verifica se value está no ultimo subvetor do array
        } else if (t[i] == t[num-2]) {
            for (int j=l; j<size; j++) {
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
