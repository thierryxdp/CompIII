#include <iostream>
#include <sstream>
#include <cstdlib>

#define MAX_PILHA 10
using namespace std;

class PilhaInt
{
public:
    PilhaInt(const int tamanho = 10)
    {
        tab = (int *)malloc(tamanho * sizeof(int));
        max_pilha = tamanho;
        for (int i = 0; i < tamanho; i++)
        {
            tab[i] = 0;
        }
        atual = 0;
    }
    PilhaInt(const PilhaInt &p)
    {
        tab = (int *)malloc(p.max_pilha * sizeof(int));
        for (int i = 0; i < p.max_pilha; i++)
        {
            tab[i] = p.tab[i];
        }
        atual = p.atual;
        max_pilha = p.max_pilha;
    }
    ~PilhaInt()
    {
        free(tab);
    }

    int capacidade()
    {
        return max_pilha;
    }

    void empilha(const int valor)
    {
        if (atual < max_pilha)
            tab[atual++] = valor;
        else
        {
            int *aux = (int *)malloc(2 * max_pilha * sizeof(int));
            for (int i = 0; i <= max_pilha; i++)
                aux[i] = tab[i];
            free(tab);
            tab = aux;
            max_pilha *= 2;
            tab[atual++] = valor;
        }
    }

    int desempilha()
    {
        if (atual > 0)
            return tab[--atual];
        else
            std::cout << "Erro! Não há elementos para desempilhar!" << std::endl;
        return -1;
    }
    void redimensiona(const int n)
    {
        if (n >= max_pilha)
        {
            int *aux = (int *)malloc(n * sizeof(int));
            for (int i = 0; i < atual; i++)
                aux[i] = tab[i];
            for (int i = atual; i < n; i++)
                aux[i] = 0;
            free(tab);
            tab = aux;
            max_pilha = n;
        }
        else
        {
            int *aux;
            aux = (int *)malloc(n * sizeof(int));
            for (int i = 0; i < n; i++)
                aux[i] = tab[i];
            free(tab);
            tab = aux;
            max_pilha = n;
            if (atual > n)
                atual = n;
        }
    }
    void print(std::ostream &o)
    {
        o << "[ ";
        for (int i = 0; i < atual - 1; i++)
        {
            o << tab[i] << ", ";
        }
        o << tab[atual - 1] << " ]";
    }

    PilhaInt &operator<<(const int valor)
    {
        empilha(valor);
        return *this;
    }

    const PilhaInt &operator=(const PilhaInt &p)
    {

        PilhaInt aux = p;
        free(tab);
        tab = (int *)malloc(aux.max_pilha * sizeof(int));
        atual = aux.atual;
        max_pilha = aux.max_pilha;
        for (int i = 0; i < aux.atual; i++)
        {
            tab[i] = aux.tab[i];
        }
        return *this;
    }

private:
    int *tab;
    int atual;
    int max_pilha;
};

PilhaInt embaralha(PilhaInt q)
{
    int aux = q.desempilha();
    q << 32 << 9 << aux;

    return q;
}

int main()
{
    /* PilhaInt a(5), b(15);
    cout << a.capacidade() << endl;
    cout << b.capacidade() << endl; */
    /*
    --- Expected output (exact text)---
    5
    15
    */
    /* PilhaInt a(7);
    a << 3 << 5 << 13 << 19;
    PilhaInt b{embaralha(a)};
    a.print(cout);
    cout << endl;
    b.print(cout);
    cout << endl; */
    /*
    --- Expected output (exact text)---
    [ 3, 5, 13, 19 ]
    [ 3, 5, 13, 32, 9, 19 ]
    */
    /* PilhaInt a{7}, b{500}, c{5};
    a << 8 << 3 << 1 << 4 << 5;
    b << 1 << 2 << 3;
    c = a;
    a = b;
    b = c;
    c.desempilha();
    c << 7;
    a.print(cout);
    cout << endl;
    b.print(cout);
    cout << endl;
    c.print(cout);
    cout << endl; */
    /*
    --- Expected output (exact text)---
    [ 1, 2, 3 ]
    [ 8, 3, 1, 4, 5 ]
    [ 8, 3, 1, 4, 7 ]
    */
    /* PilhaInt a{7}, b{500000}, c{5};
    a << 8 << 3 << 1 << 4 << 5;
    for (int i = 0; i < b.capacidade(); i++)
        b << i;
    c = a;
    a = b;
    b = c;
    cout << a.capacidade() << ", " << b.capacidade() << ", " << c.capacidade() << endl; */
    /* --- Expected output (exact text)---
    500000, 7, 7
    */
    /* PilhaInt a{7};
    a << 8 << 3 << 1 << 4 << 5;
    a = a;
    a.print(cout);
    cout << endl; */
    /*
    --- Expected output (exact text)---
    [ 8, 3, 1, 4, 5 ]
    */
    /* PilhaInt a{81};
    a << 5 << 6 << 3 << 2 << 9 << 13;
    a.redimensiona(81);
    cout << a.capacidade() << endl;
    a.redimensiona(11);
    cout << a.capacidade() << endl;
    a.redimensiona(6);
    cout << a.capacidade() << endl;
    a.print(cout);
    cout << endl;
    a.redimensiona(3);
    cout << a.capacidade() << endl;
    a.print(cout);
    cout << endl; */
    /*
    --- Expected output (exact text)---
    81
    11
    6
    [ 5, 6, 3, 2, 9, 13 ]
    3
    [ 5, 6, 3 ]
    */
    PilhaInt a{3};
    for (int i = 0; i < 20; i++)
    {
        a << i;
        cout << a.capacidade() << " ";
    }
    cout << endl;
    a.print(cout);
    cout << endl;
    /*
    --- Expected output (exact text)---
    3 3 3 6 6 6 12 12 12 12 12 12 24 24 24 24 24 24 24 24
    [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 ]
    */
}