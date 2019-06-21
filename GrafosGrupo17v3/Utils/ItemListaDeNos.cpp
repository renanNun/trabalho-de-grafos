#include "ItemListaDeNos.h"
#include <iostream>

using namespace std;

ItemListaDeNos::ItemListaDeNos(ItemListaDeNos* ant, ItemListaDeNos* prox, No* no)
{
    this->anterior = ant;
    this->proximo = prox;
    this->item = no;
    this->pontuacaoNoCluster = 0;
    this->clusterAtualSendoTestado = -1;
}

ItemListaDeNos::~ItemListaDeNos()
{
    //dtor
}


void ItemListaDeNos::setItem(No* novoItem){
    this->item = novoItem;
}

No* ItemListaDeNos::getItem(){
    return this->item;
}

void ItemListaDeNos::setAnterior(ItemListaDeNos* novoAnterior){
    this->anterior = novoAnterior;
}

ItemListaDeNos* ItemListaDeNos::getAnterior(){
    return this->anterior;
}

void ItemListaDeNos::setProximo(ItemListaDeNos* novoProximo){
    this->proximo = novoProximo;
}

ItemListaDeNos* ItemListaDeNos::getProximo(){
    return this->proximo;
}

void ItemListaDeNos::setPontuacaoNoCluster(float novoValor){
    this->pontuacaoNoCluster = novoValor;
}

void ItemListaDeNos::addPontuacaoNoCluster(float valorAdicionado){
    this->pontuacaoNoCluster = this->pontuacaoNoCluster + valorAdicionado;
}

float ItemListaDeNos::getPontuacaoNoCluster(){
    return this->pontuacaoNoCluster;
}

void ItemListaDeNos::setClusterAtualSendoTestado(int cluster){
    this->clusterAtualSendoTestado = cluster;
}

int ItemListaDeNos::getClusterAtualSendoTestado(){
    return this->clusterAtualSendoTestado;
}
