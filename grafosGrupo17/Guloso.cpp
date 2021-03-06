#include "Guloso.h"

using namespace std;

Guloso::Guloso(Grafo *g)
{

}

Guloso::~Guloso()
{

}

void Guloso::preencheVector(Grafo *g)
{
    std::list<No*> auxiliar = g->retornaListaNos();
    for(auto i = auxiliar.begin(); i != auxiliar.end(); i++)
    {
        No *aux = *i;
        this->candidatos.push_back(aux);
    }
}

void Guloso::ordenaCriterio(bool (*criterio)(No *no1, No *no2), float alpha)
{
    std::sort(this->candidatos.begin(), this->candidatos.end(),criterio);
}

bool Guloso::ponderadoIgual(No *no1,No *no2)
{
    return no1->getPeso() < no2->getPeso();
}

void Guloso::atulizarVetor(No *escolhido)
{
    this->removeVizinhosDoCandidato(escolhido); // Remove os vizinhos do candidato escolhido
    this->removeNoDoCandidato(escolhido); // Remove o candidato escolhido da lista de candidatos
}

void Guloso::removeNoDoCandidato(No *no)
{
    candidatos.erase(std::remove(candidatos.begin(),candidatos.end(),no),candidatos.end());
}

void Guloso::removeVizinhosDoCandidato(No *no)
{
    for (auto i = no->adjacentes.begin(); i != no->adjacentes.end(); i++)
    {
        if(i != nullptr){
            No *aux = *i;
            this->removeNoDoCandidato(aux);
        }
    }
}

std::list<No *> Guloso::preencheSubConjVert(Grafo *g)
{
    this->preencheVector(g);
    this->ordenaCriterio( ponderadoIgual); // Aqui temos uma lista de vertices ordenados pelo grau

    while(candidatos.size() > 0)
    {
        No *aux = candidatos.at(0); // Retira o maior para colocar na solu��o
        this->subConjuntoDeVerticesPond.push_back(aux); // Coloca o maior na solu��o
        this->atulizarVetor(aux); // Atualiza o vetor, apagando da lista de candidatos o que n� est� no auxiliar

    }

    return subConjuntoDeVerticesPond;

}
