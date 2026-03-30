#include "raylib.h"
#include <string>
#include <iostream>
#include <cmath>

#include "TAD_Sensor.h"
#include "TAD_Carga.h"
#include "TAD_Nave.h"
#include "TAD_Camera.h"
#include "TAD_Log.h"
#include "TAD_Hangar.h"

using namespace std;

/*
USAR ISSO NO TERMINAL PRA RODAR:

# 1. Cria a pasta de build e configura o projeto
cmake -B build

# 2. Compila tudo
cmake --build build

# 3. Executa o simulador
./build/app

*/

// Globais de TAD
ListaSensores listaSensores = {{}, 0};
ListaCargas listaCargas = {nullptr};
ListaNaves listaNaves = {nullptr, nullptr};
ListaCameras listaCameras = {nullptr, 0};
Pilha pilhaLogs = {nullptr};
Fila filaHangar = {nullptr, nullptr};

int telaAtual = 0; // 0 a 5
string inputTexto = "";
string ultimaMensagem = "Bem-vindo à Estação Estelar";

// Funções utilitárias
int safeStoi(const string& str, int defVal = 0) {
    try {
        return stoi(str);
    } catch (...) {
        return defVal;
    }
}

// Função auxiliar para desenhar botão
bool DrawButton(Rectangle rect, const char* text, Color color) {
    bool clicked = false;
    Vector2 mousePoint = GetMousePosition();
    if (CheckCollisionPointRec(mousePoint, rect)) {
        DrawRectangleRec(rect, Fade(color, 0.7f));
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            clicked = true;
        }
    } else {
        DrawRectangleRec(rect, color);
    }
    DrawRectangleLinesEx(rect, 2, BLACK);
    
    int textWidth = MeasureText(text, 20);
    DrawText(text, rect.x + (rect.width - textWidth) / 2, rect.y + (rect.height - 20) / 2, 20, BLACK);
    return clicked;
}

// Captura texto digitado
void CapturarEntrada() {
    int key = GetCharPressed();
    while (key > 0) {
        if ((key >= 32) && (key <= 125) && (inputTexto.length() < 30)) {
            inputTexto += (char)key;
        }
        key = GetCharPressed();
    }
    if (IsKeyPressed(KEY_BACKSPACE)) {
        if (inputTexto.length() > 0) {
            inputTexto.pop_back();
        }
    }
}

// --- Funções de desenho de cada TAD (Visual) ---

void DesenharModuloSensores() {
    DrawText("Módulo 1: Sensores (Lista Estática)", 400, 150, 30, DARKGRAY);
    
    // Desenha array (tamanho fixo 5)
    for (int i = 0; i < 5; i++) {
        Rectangle r = { (float)(340 + i * 120), 250, 100, 80 };
        DrawRectangleRec(r, LIGHTGRAY);
        DrawRectangleLinesEx(r, 2, BLACK);
        DrawText(TextFormat("[%d]", i), r.x + 10, r.y + 10, 20, BLACK);
        if (i < listaSensores.tamanho) {
            DrawText(TextFormat("ID: %d", listaSensores.dados[i].id), r.x + 10, r.y + 35, 20, DARKBLUE);
            DrawText(TextFormat("%.1f C", listaSensores.dados[i].temperatura), r.x + 10, r.y + 55, 20, RED);
        } else {
            DrawText("Vazio", r.x + 20, r.y + 35, 20, GRAY);
        }
    }
    
    if (DrawButton({ 350, 450, 150, 50 }, "Inserir", GREEN)) {
        int id = inputTexto.length() > 0 ? safeStoi(inputTexto, GetRandomValue(1, 100)) : GetRandomValue(1, 100);
        inserirSensor(listaSensores, id, 25.5f);
        ultimaMensagem = "Tentativa de inserir Sensor (id: " + to_string(id) + ")";
        inputTexto = "";
    }
    if (DrawButton({ 550, 450, 150, 50 }, "Remover", RED)) {
        int id = inputTexto.length() > 0 ? safeStoi(inputTexto, 0) : 0;
        removerSensor(listaSensores, id);
        ultimaMensagem = "Tentativa de remover Sensor (id: " + to_string(id) + ")";
        inputTexto = "";
    }
}

void DesenharModuloCargas() {
    DrawText("Módulo 2: Cargas (Lista Simplesmente Encadeada)", 300, 150, 30, DARKGRAY);
    
    NoCarga* atual = listaCargas.head;
    int i = 0;
    while (atual != nullptr && i < 8) {
        DrawRectangle(100 + i * 140, 250, 100, 60, SKYBLUE);
        DrawRectangleLines(100 + i * 140, 250, 100, 60, BLACK);
        DrawText(atual->nome.c_str(), 110 + i * 140, 270, 20, BLACK);
        
        if (atual->prox != nullptr) {
            DrawLine(200 + i * 140, 280, 240 + i * 140, 280, BLACK);
            DrawTriangle({235.0f + i * 140, 275.0f}, {235.0f + i * 140, 285.0f}, {245.0f + i * 140, 280.0f}, BLACK);
        }
        atual = atual->prox;
        i++;
    }
    if (listaCargas.head == nullptr) {
        DrawText("Lista Vazia", 550, 270, 20, GRAY);
    }
    
    if (DrawButton({ 350, 450, 150, 50 }, "Inserir", GREEN)) {
        string nome = inputTexto.empty() ? "CargaX" : inputTexto;
        inserirCarga(listaCargas, nome, 10.0f);
        ultimaMensagem = "Tentativa de inserir Carga: " + nome;
        inputTexto = "";
    }
    if (DrawButton({ 550, 450, 150, 50 }, "Remover", RED)) {
        string nome = inputTexto;
        removerCarga(listaCargas, nome);
        ultimaMensagem = "Tentativa de remover Carga: " + nome;
        inputTexto = "";
    }
}

void DesenharModuloNaves() {
    DrawText("Módulo 3: Naves (Lista Duplamente Encadeada)", 300, 150, 30, DARKGRAY);
    
    NoNave* atual = listaNaves.head;
    int i = 0;
    while (atual != nullptr && i < 6) {
        DrawRectangle(100 + i * 180, 250, 120, 60, ORANGE);
        DrawRectangleLines(100 + i * 180, 250, 120, 60, BLACK);
        DrawText(atual->nome.c_str(), 110 + i * 180, 270, 20, BLACK);
        
        if (atual->prox != nullptr) {
            // Seta prox >>>
            DrawLine(220 + i * 180, 270, 280 + i * 180, 270, BLACK);
            DrawTriangle({270.0f + i * 180, 265.0f}, {270.0f + i * 180, 275.0f}, {280.0f + i * 180, 270.0f}, BLACK);
            // Seta ant <<<
            DrawLine(220 + i * 180, 290, 280 + i * 180, 290, BLACK);
            DrawTriangle({230.0f + i * 180, 285.0f}, {230.0f + i * 180, 295.0f}, {220.0f + i * 180, 290.0f}, BLACK);
        }
        atual = atual->prox;
        i++;
    }
    if (listaNaves.head == nullptr) {
        DrawText("Lista Vazia", 550, 270, 20, GRAY);
    }

    if (DrawButton({ 350, 450, 150, 50 }, "Inserir", GREEN)) {
        string nome = inputTexto.empty() ? "NaveX" : inputTexto;
        inserirNave(listaNaves, nome);
        ultimaMensagem = "Tentativa de inserir Nave: " + nome;
        inputTexto = "";
    }
    if (DrawButton({ 550, 450, 150, 50 }, "Remover", RED)) {
        string nome = inputTexto;
        removerNave(listaNaves, nome);
        ultimaMensagem = "Tentativa de remover Nave: " + nome;
        inputTexto = "";
    }
}

void DesenharModuloCameras() {
    DrawText("Módulo 4: Câmeras (Lista Circular)", 400, 150, 30, DARKGRAY);
    
    NoCamera* atual = listaCameras.head;
    if (atual != nullptr) {
        int i = 0;
        int qtde = listaCameras.tamanho > 0 ? listaCameras.tamanho : 1; 
        do {
            float angulo = (i * 2.0f * PI) / qtde;
            Vector2 pos = { (float)(640 + 200 * cos(angulo)), (float)(300 + 100 * sin(angulo)) };
            DrawCircleV(pos, 40, PURPLE);
            DrawCircleLines(pos.x, pos.y, 40, BLACK);
            DrawText(TextFormat("ID:%d", atual->id), pos.x - 25, pos.y - 10, 20, WHITE);
            atual = atual->prox;
            i++;
        } while(atual != listaCameras.head && atual != nullptr && i < 15);
    } else {
        DrawText("Lista Vazia", 550, 300, 20, GRAY);
    }

    if (DrawButton({ 350, 480, 150, 50 }, "Inserir", GREEN)) {
        int id = inputTexto.length() > 0 ? safeStoi(inputTexto, GetRandomValue(1, 100)) : GetRandomValue(1, 100);
        inserirCamera(listaCameras, id, "Setor A");
        ultimaMensagem = "Tentativa de inserir Câmera (id: " + to_string(id) + ")";
        inputTexto = "";
    }
    if (DrawButton({ 550, 480, 150, 50 }, "Remover", RED)) {
        int id = inputTexto.length() > 0 ? safeStoi(inputTexto, 0) : 0;
        removerCamera(listaCameras, id);
        ultimaMensagem = "Tentativa de remover Câmera (id: " + to_string(id) + ")";
        inputTexto = "";
    }
}

void DesenharModuloLogs() {
    DrawText("Módulo 5: Logs (Pilha LIFO)", 450, 150, 30, DARKGRAY);
    
    NoLog* atual = pilhaLogs.topo;
    int i = 0;
    while (atual != nullptr && i < 8) {
        DrawRectangle(540, 380 - i * 40, 200, 40, YELLOW);
        DrawRectangleLines(540, 380 - i * 40, 200, 40, BLACK);
        DrawText(atual->mensagem.c_str(), 550, 390 - i * 40, 20, BLACK);
        atual = atual->prox;
        i++;
    }
    if (pilhaLogs.topo == nullptr) {
        DrawText("Pilha Vazia", 590, 390, 20, GRAY);
    }

    if (DrawButton({ 350, 450, 150, 50 }, "Push", GREEN)) {
        string msg = inputTexto.empty() ? "Log Event" : inputTexto;
        push(pilhaLogs, msg);
        ultimaMensagem = "Tentativa de fazer Push: " + msg;
        inputTexto = "";
    }
    if (DrawButton({ 550, 450, 150, 50 }, "Pop", RED)) {
        string res = pop(pilhaLogs);
        ultimaMensagem = "Tentativa de Pop. Retornou: " + res;
        inputTexto = "";
    }
}

void DesenharModuloHangar() {
    DrawText("Módulo 6: Hangar (Fila FIFO)", 450, 150, 30, DARKGRAY);
    
    NoNaveHangar* atual = filaHangar.frente;
    int i = 0;
    while (atual != nullptr && i < 8) {
        DrawRectangle(200 + i * 110, 280, 100, 60, LIME);
        DrawRectangleLines(200 + i * 110, 280, 100, 60, BLACK);
        DrawText(atual->nome.c_str(), 210 + i * 110, 300, 20, BLACK);
        atual = atual->prox;
        i++;
    }
    if (filaHangar.frente == nullptr) {
        DrawText("Fila Vazia", 550, 300, 20, GRAY);
    }

    if (DrawButton({ 350, 450, 150, 50 }, "Enqueue", GREEN)) {
        string nome = inputTexto.empty() ? "NaveH" : inputTexto;
        enqueue(filaHangar, nome);
        ultimaMensagem = "Tentativa de Enqueue: " + nome;
        inputTexto = "";
    }
    if (DrawButton({ 550, 450, 150, 50 }, "Dequeue", RED)) {
        string res = dequeue(filaHangar);
        ultimaMensagem = "Tentativa de Dequeue. Retornou: " + res;
        inputTexto = "";
    }
}

int main() {
    InitWindow(1280, 720, "Estação Estelar");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        CapturarEntrada();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Header
        DrawRectangle(0, 0, 1280, 100, DARKBLUE);
        DrawText("LOGÍSTICA ESTELAR", 30, 35, 30, WHITE);
        
        // Navigation Buttons
        if (DrawButton({ 460, 30, 120, 40 }, "1. Sensores", telaAtual == 0 ? GOLD : LIGHTGRAY)) telaAtual = 0;
        if (DrawButton({ 590, 30, 120, 40 }, "2. Cargas", telaAtual == 1 ? GOLD : LIGHTGRAY)) telaAtual = 1;
        if (DrawButton({ 720, 30, 120, 40 }, "3. Naves", telaAtual == 2 ? GOLD : LIGHTGRAY)) telaAtual = 2;
        if (DrawButton({ 850, 30, 120, 40 }, "4. Câmeras", telaAtual == 3 ? GOLD : LIGHTGRAY)) telaAtual = 3;
        if (DrawButton({ 980, 30, 120, 40 }, "5. Logs", telaAtual == 4 ? GOLD : LIGHTGRAY)) telaAtual = 4;
        if (DrawButton({ 1110, 30, 120, 40 }, "6. Hangar", telaAtual == 5 ? GOLD : LIGHTGRAY)) telaAtual = 5;

        // Input Box (Global para todas as telas)
        DrawText("Input:", 350, 600, 20, DARKGRAY);
        DrawRectangle(420, 580, 400, 40, LIGHTGRAY);
        DrawRectangleLines(420, 580, 400, 40, BLACK);
        DrawText(inputTexto.c_str(), 430, 590, 20, BLACK);
        
        // Desenho específico da aba selecionada
        switch (telaAtual) {
            case 0: DesenharModuloSensores(); break;
            case 1: DesenharModuloCargas(); break;
            case 2: DesenharModuloNaves(); break;
            case 3: DesenharModuloCameras(); break;
            case 4: DesenharModuloLogs(); break;
            case 5: DesenharModuloHangar(); break;
        }

        // Footer / StatusBar
        DrawRectangle(0, 680, 1280, 40, LIGHTGRAY);
        DrawText(("Status: " + ultimaMensagem).c_str(), 20, 690, 20, DARKBLUE);

        DrawText(TextFormat("Tela %d/6", telaAtual + 1), 1150, 690, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}