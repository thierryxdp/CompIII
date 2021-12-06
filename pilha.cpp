#include <iostream>
#include <sstream>
#define MAX_PILHA 1000

class PilhaInt {
    public:

    PilhaInt() {
        for (int i = 0; i < MAX_PILHA; i++)
			tab[i] = 0;
        atual = 0;
	}

    void empilha(const int valor) {
        if (atual <= MAX_PILHA)
            tab[atual++] = valor;
        else {
            std::cout << "Erro! Tamanho máximo da pilha atingido!" << std::endl;
        }
    }

    int desempilha() { 
        if (atual > 0) return tab[--atual];
        else std::cout << "Erro! Não há elementos para desempilhar!" << std::endl;
        return -1;
    }

    void print( std::ostream& o) {
        o << "[ ";
        for (int i = 0; i < atual - 1; i++){
            o << tab[i] << ", ";
        }
        o << tab[atual - 1] << " ]";
    }
    
    PilhaInt& operator << (const int valor) {
        empilha(valor);
        return *this;
	}

    const PilhaInt& operator = (const PilhaInt& p) {
		atual = p.atual;
		for(int i = 0; i < atual; i++)
			tab[i] = p.tab[i];
		return *this;
	}

    private:
        int tab[MAX_PILHA];
	    int atual;
};

int main(){
    PilhaInt p, q;
    q << 2;
    p << 19 << 18 << 17 << 30;
    q = p;
    p.desempilha();
    q << 7;
    std::stringstream ssp, ssq;
    p.print( ssp );
    q.print( ssq );
}