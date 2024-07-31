#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include <string>

class Sala {
public:
    Sala();
    void CH_Porta(bool _x); // alterar status da Porta 
    void CH_Janela(bool _x); // alterar status da Janela
    void CH_Lampada(bool _x); // alterar status da lampada
    void CH_TV(bool _x); // alterar status da TV
    void CH_Temperatura(int _x); // Definir temperatura

    // função que Adicionar sensor na Sala ??????

private:
    bool Porta;
    bool Janela;
    bool Lampada;
    bool TV;
    int temperatura;
};

#endif // BOOK_H
