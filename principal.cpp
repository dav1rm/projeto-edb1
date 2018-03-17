#include <iostream>
#include <iterator>
using namespace std;
int buscaSequencial( int *first, int *last, int value )
{
    //armazena o tamanho do array
    int tamanho = last-first;
    //Percorre todo o array verificando cada elemento se é igual a value
    for (int i=0; i<tamanho; i++)
    {
        if(first[i] == value)
        {
            //Se value foi encontrado no array, então retorna o indice
            return i;
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
    cout << "Indice eh: " << buscaSequencial(begin(A), end(A), 23) << '\n';
    return 0;
}
