#include "Sala.h"

Sala::Sala(int numPortas, int numJanelas, int numLampadas, int numTVs) 
    : Portas(numPortas, false), Janelas(numJanelas, false), 
      Lampadas(numLampadas, false), TVs(numTVs, false), temperatura(20) {
    // Construtor inicializa os vetores com o número especificado de elementos
    // Todos os elementos são inicializados como `false` (desligados/fechados)
}

void Sala::CH_Porta(int index, bool _x) {
    if (index >= 0 && index < Portas.size()) {
        Portas[index] = _x;
        std::cout << "Porta " << index << " " << (Portas[index] ? "aberta" : "fechada") << std::endl;
    } else {
        std::cerr << "Índice de porta inválido!" << std::endl;
    }
}

void Sala::CH_Janela(int index, bool _x) {
    if (index >= 0 && index < Janelas.size()) {
        Janelas[index] = _x;
        std::cout << "Janela " << index << " " << (Janelas[index] ? "aberta" : "fechada") << std::endl;
    } else {
        std::cerr << "Índice de janela inválido!" << std::endl;
    }
}

void Sala::CH_Lampada(int index, bool _x) {
    if (index >= 0 && index < Lampadas.size()) {
        Lampadas[index] = _x;
        std::cout << "Lâmpada " << index << " " << (Lampadas[index] ? "ligada" : "desligada") << std::endl;
    } else {
        std::cerr << "Índice de lâmpada inválido!" << std::endl;
    }
}

void Sala::CH_TV(int index, bool _x) {
    if (index >= 0 && index < TVs.size()) {
        TVs[index] = _x;
        std::cout << "TV " << index << " " << (TVs[index] ? "ligada" : "desligada") << std::endl;
    } else {
        std::cerr << "Índice de TV inválido!" << std::endl;
    }
}

void Sala::CH_Temperatura(int _x) {
    temperatura = _x;
    std::cout << "Temperatura definida para " << temperatura << " graus" << std::endl;
}
