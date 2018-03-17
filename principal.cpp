#include <iostream>
#include <iterator>
using namespace std;
int buscaSequencial( int *first, int *last, int value )
{
    //Armazena o tamanho do array
    int tamanho = last-first;
    //Percorre todo o array verificando cada elemento se é igual a value
    for (int i=0; i<tamanho; i++)
    {
        //Se value foi encontrado no array, então retorna o indice
        if(first[i] == value)
        {
            return i;
        }
    }
    //Se value não foi encontrado no array, então retorna -1
    return -1;
}

int buscaBinaria( int *first, int *last, int value )
{
    //Armazena o tamanho do array
    int tamanho = last-first;
    //Armazena a metade do array
    int metade = tamanho/2;
    //Verifica se value está no meio do array
    if (value == first[metade])
    {
        return metade;
    }
    //Verifica se value está na primeira metade do array
    else if (value > first[metade])
    {
        for (int i=(metade+1); i<tamanho; i++)
        {
            //Se value foi encontrado no array, então retorna o indice
            if(first[i] == value)
            {
                return i;
            }
        }
    }
    //Verifica se value está na segunda metade do array
    else if (value < first[metade])
    {
        for (int i=0; i < metade; i++)
        {
            //Se value foi encontrado no array, então retorna o indice
            if(first[i] == value)
            {
                return i;
            }
        }
    }
    //Se value não foi encontrado no array, então retorna -1
    return -1;
}

int buscaTernaria( int *first, int *last, int value )
{
    //Armazena o tamanho do array
    int tamanho = last-first;
    //Armazena o primeiro limite do array
    int t1 = tamanho/3;
    //Armazena o segundo limite do array
    int t2 = t1*2;
    //Verifica se value está no primeiro limite do array
    if (value == first[t1])
    {
        return t1;
    }
    //Verifica se value está no segundo limite do array
    else if (value == first[t2])
    {
        return t2;
    }
    //Verifica se value está na primeira metade do array
    else if (value < first[t1])
    {
        for (int i=0; i<t1; i++)
        {
            //Se value foi encontrado no array, então retorna o indice
            if(first[i] == value)
            {
                return i;
            }
        }
    }
    //Verifica se value está na segunda metade do array
    else if (value > first[t1] && value < first[t2])
    {
        for (int i=t1; i < t2; i++)
        {
            //Se value foi encontrado no array, então retorna o indice
            if(first[i] == value)
            {
                return i;
            }
        }
    }
    //Verifica se value está na terceira metade do array
    else
    {
        for (int i=t2; i < tamanho; i++)
        {
            //Se value foi encontrado no array, então retorna o indice
            if(first[i] == value)
            {
                return i;
            }
        }
    }
    //Se value não foi encontrado no array, então retorna -1
    return -1;
}

int main( void )
{
    int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
    //Imprime o array A
    cout << ">>> Original array A: [ ";
    copy( begin(A), end(A), ostream_iterator<int>( cout, " ") );
    cout << "]\n";

    //Imprime o indice do elemento encontrado
    cout << "Indice eh: " << buscaTernaria(begin(A), end(A), 17) << '\n';
    return 0;
}
