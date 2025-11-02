#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <Dibujo.hpp>
#include <GestorDibujos.hpp>

using namespace ftxui;
int main()
{
    auto screen = Screen::Create(
        Dimension::Fixed(80),
        Dimension::Fixed(24));

    const std::vector<std::u32string> pez_derecha = {
        U"  __  ",
        U" /o \\/ ",
        U" \\__/\\<",
        U" /  \\/ ",
        U" \\____/ "
    };

    const std::vector<std::u32string> pez_izquierda = {
        U"  __  ",
        U" \\/o\\ ",
        U" >/\\__\\",
        U" /\\/  \\",
        U" \\____/ "
    };

    const std::vector<std::u32string> burbuja = {
        U" o ",
        U"O  ",
        U" o "
    };

    const std::vector<std::u32string> alga = {
        U" | ",
        U" / ",
        U" | ",
        U" \\ ",
        U" | "
    };

    const std::vector<std::u32string> coral_1 = {
        U" ( ) ",
        U"( Y )",
        U" \\|/ "
    };

    const std::vector<std::u32string> coral_2 = {
        U"  ^  ",
        U" /|\\ ",
        U"//|\\\\"
    };

    const std::vector<std::u32string> langosta_derecha = {
        U"  \\ / ", // Antenas
        U"__(o.o)>", // Cuerpo y pinza
        U"  / \\ "  // Patas
    };

    const std::vector<std::u32string> arena = {
        U".,.~.,.~.,.~.,.~.,.~.,.~.,.~.,.~.,.~.,.~.,.~.,.~.,.~.,.~.,.~.,.~.,.~.,.~.,.~.,.~.,.~.,.~."
    };

    GestorDibujos gestor;

    gestor.Agregar(Dibujo(5, 10, burbuja, ftxui::Color::Blue));               // [0] BURBUJA
    gestor.Agregar(Dibujo(7, 2, pez_izquierda, ftxui::Color::White));         // [1] PEZ BLANCO
    gestor.Agregar(Dibujo(15, 12, burbuja, ftxui::Color::Blue));              // [2] BURBUJA
    gestor.Agregar(Dibujo(3, 5, pez_izquierda, ftxui::Color::Green));         // [3] PEZ VERDE
    gestor.Agregar(Dibujo(25, 15, burbuja, ftxui::Color::Blue));              // [4] BURBUJA
    gestor.Agregar(Dibujo(11, 10, pez_izquierda, ftxui::Color::Purple));      // [5] PEZ MORADO
    gestor.Agregar(Dibujo(10, 18, alga, ftxui::Color::Green));                // [6] ALGA 1 (y=18, 5 alto, termina en 22)
    gestor.Agregar(Dibujo(70, 17, alga, ftxui::Color::Green));                // [7] ALGA 2 (y=17, 5 alto, termina en 21)
    gestor.Agregar(Dibujo(60, 8, pez_derecha, ftxui::Color::Yellow));         // [8] PEZ AMARILLO
    gestor.Agregar(Dibujo(50, 16, pez_derecha, ftxui::Color::Red));           // [9] PEZ ROJO
    gestor.Agregar(Dibujo(35, 18, burbuja, ftxui::Color::Blue));              // [10] BURBUJA EXTRA
    gestor.Agregar(Dibujo(55, 14, burbuja, ftxui::Color::Blue));              // [11] BURBUJA EXTRA
    gestor.Agregar(Dibujo(0, 23, arena, ftxui::Color::Yellow));               // [12] ARENA (en la última fila)
    gestor.Agregar(Dibujo(20, 19, alga, ftxui::Color::Green));                // [13] ALGA EXTRA 1
    gestor.Agregar(Dibujo(65, 19, alga, ftxui::Color::Green));                // [14] ALGA EXTRA 2
    gestor.Agregar(Dibujo(25, 20, coral_1, ftxui::Color::RGB(255, 165, 0)));  // [15] CORAL NARANJA
    gestor.Agregar(Dibujo(35, 20, coral_2, ftxui::Color::RGB(139, 69, 19)));  // [16] CORAL CAFE
    gestor.Agregar(Dibujo(45, 20, coral_1, ftxui::Color::Green));             // [17] CORAL VERDE
    gestor.Agregar(Dibujo(2, 20, langosta_derecha, ftxui::Color::Red));       // [18] LANGOSTA

    
    int frames = 300; 
    for (int frame = 0; frame < frames; ++frame)
    {
        // Limpia la pantalla
        screen.Clear();

        int anim_horizontal = frame % 20; // Para peces rápidos
        int anim_vertical = frame % 15;   // Para burbujas
        int anim_langosta = frame % 50;   // Para langosta (mas lenta)

        // se mueven a la derecha
        gestor.dibujos[1].x = 7 + anim_horizontal;  // PEZ BLANCO
        gestor.dibujos[3].x = 3 + anim_horizontal;  // PEZ VERDE
        gestor.dibujos[5].x = 11 + anim_horizontal; // PEZ MORADO
        gestor.dibujos[18].x = 2 + anim_langosta;   // LANGOSTA se mueve

        // se mueven a la izquierda
        gestor.dibujos[8].x = 60 - anim_horizontal; // PEZ AMARILLO
        gestor.dibujos[9].x = 50 - anim_horizontal; // PEZ ROJO

        // Burbujas (suben y reaparecen abajo)
        gestor.dibujos[0].y  = 10 - anim_vertical;   // BURBUJA 1
        gestor.dibujos[2].y  = 12 - anim_vertical;   // BURBUJA 2
        gestor.dibujos[4].y  = 15 - anim_vertical;   // BURBUJA 3
        gestor.dibujos[10].y = 18 - anim_vertical;   // BURBUJA EXTRA 1
        gestor.dibujos[11].y = 14 - anim_vertical;   // BURBUJA EXTRA 2

        
        gestor.DibujarTodos(screen);

        // Imprime la pantalla y resetea el cursor
        std::cout << screen.ToString();
        std::cout << screen.ResetPosition();
        std::cout << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(120));
    }

    return 0;
}