#include "ListaDeNos.h"
#include <iostream>

#include "../No.h"
#include "ItemListaDeNos.h"

using namespace std;

ListaDeNos::ListaDeNos()
{
    this->length = 0;
    this->primeiro = nullptr;
    this->ultimo = nullptr;
}

ListaDeNos::~ListaDeNos()
{
    //dtor
}

int ListaDeNos::getLength(){
    return this->length;
}

void ListaDeNos::adicionaNo(No* novoNo, int clusterSendoTestado){
    if(this->ultimo != nullptr){
        ItemListaDeNos* novoItem = new ItemListaDeNos(ultimo, nullptr, novoNo);
        novoItem->setClusterAtualSendoTestado(clusterSendoTestado);
        ultimo->setProximo(novoItem);
        this->ultimo = novoItem;
        length++;
    }
    else{
        ItemListaDeNos* novoItem = new ItemListaDeNos(nullptr, nullptr, novoNo);
        novoItem->setClusterAtualSendoTestado(clusterSendoTestado);
        this->primeiro = novoItem;
        this->ultimo = novoItem;
        length++;
    }
}

void ListaDeNos::insereNo(int posicao, No* novoNo, int clusterSendoTestado){
    if (posicao >= length){
        this->adicionaNo(novoNo, clusterSendoTestado);
        std::cout<< "Posicao maior ou igual ao tamanho da lista, o no sera adicionado na ultima posicao" << std::endl;
    }
    else if (posicao == 0){
        ItemListaDeNos* novoItem = new ItemListaDeNos(nullptr, this->primeiro ,novoNo);
        novoItem->setClusterAtualSendoTestado(clusterSendoTestado);
        this->primeiro->setAnterior(novoItem);
        this->primeiro = novoItem;
        length++;
    }
    else{
        int i;
        ItemListaDeNos* antigoItemDaPosicao = this->primeiro;
        for(i = 0; i<posicao;i++){
            antigoItemDaPosicao = antigoItemDaPosicao->getProximo();
            i++;
        }
        ItemListaDeNos* novoItem = new ItemListaDeNos(antigoItemDaPosicao->getAnterior(), antigoItemDaPosicao, novoNo);
        novoItem->setClusterAtualSendoTestado(clusterSendoTestado);
        antigoItemDaPosicao->getAnterior()->setProximo(novoItem);
        antigoItemDaPosicao->setAnterior(novoItem);
    }
}

ItemListaDeNos* ListaDeNos::getItem(int posicao){
    if(posicao >= length){
        std::cout << "Erro: Posicao maior do que ultimo termo" << std::endl;
        return nullptr;
    }
    else if(posicao < 0){
        std::cout << "Erro: Nao existe posicao menor que zero em uma lista" << std::endl;
        return nullptr;
    }
    else {
        ItemListaDeNos* percorredor = primeiro;
        for(int i = 0; i<posicao; i++){
            percorredor = percorredor ->getProximo();
        }
        return percorredor;
    }
}

No* ListaDeNos::getNo(int posicao){
    ItemListaDeNos* aux = this->getItem(posicao);
    return aux->getItem();
}


void ListaDeNos::apagaItem(ItemListaDeNos* apagado){
    ItemListaDeNos* anterior = apagado->getAnterior();
    ItemListaDeNos* proximo = apagado->getProximo();
    if(proximo == nullptr && anterior == nullptr){
        primeiro = nullptr;
        ultimo = nullptr;
        this->length = 0;
        delete apagado;
    }
    else if(proximo == nullptr){
        anterior->setProximo(nullptr);
        ultimo = anterior;
        this->length = this->length - 1;
        delete apagado;
    }
    else if (anterior == nullptr){
        proximo->setAnterior(nullptr);
        primeiro = proximo;
        this->length = this->length - 1;
        delete apagado;
    }
    else {
        proximo->setAnterior(anterior);
        anterior->setProximo(proximo);
        this->length = this->length - 1;
        delete apagado;
    }
}

void ListaDeNos::setPeso(int novoPeso){
    this->peso = novoPeso;
}

void ListaDeNos::addPeso(int adicionado){
    this->peso = this->peso + adicionado;
}

int ListaDeNos::getPeso(){
    return this->peso;
}

No* ListaDeNos::popNo(int index){
    ItemListaDeNos* itemAtual = this->getItem(index);
    No* noASerRetornado = itemAtual->getItem();
    this->apagaItem(itemAtual);
    return noASerRetornado;
}
