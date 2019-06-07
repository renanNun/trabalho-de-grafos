#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED

class Aresta{

private:
    int id;
    float peso;
    Aresta* prox;
    No* alvo;

public:
    Aresta();
    ~Aresta();

    int getId();
    void setId(int id);
    Aresta* getProx();
    void setProx(Aresta *p);
    float getPeso();
    void setPeso(float peso);
    No* getNoAlvo();
    void setNoAlvo(No* noAlvo);
};

#endif // ARESTA_H_INCLUDED
