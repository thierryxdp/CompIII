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