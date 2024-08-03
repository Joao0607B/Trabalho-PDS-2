#include "Sala.h"

Sala::Sala() : Porta(false), Janela(false), Lampada(false), TV(false), temperatura(20) {
    // Construtor inicializa os membros com valores padrão.
}

void Sala::CH_Porta(bool _x) {
    Porta = _x;
    std::cout << "Porta " << (Porta ? "aberta" : "fechada") << std::endl;
}

void Sala::CH_Janela(bool _x) {
    Janela = _x;
    std::cout << "Janela " << (Janela ? "aberta" : "fechada") << std::endl;
}

void Sala::CH_Lampada(bool _x) {
    Lampada = _x;
    std::cout << "Lampada " << (Lampada ? "ligada" : "desligada") << std::endl;
}

void Sala::CH_TV(bool _x) {
    TV = _x;
    std::cout << "TV " << (TV ? "ligada" : "desligada") << std::endl;
}

void Sala::CH_Temperatura(int _x) {
    temperatura = _x;
    std::cout << "Temperatura definida para " << temperatura << " graus" << std::endl;
}
