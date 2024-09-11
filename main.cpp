#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <sstream>

// g++ main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system
// x(t) = A sin(a*t + phi)
// y(t) = B sin(bt)

int main(){
    // Configuración de la ventana
    sf::RenderWindow window(sf::VideoMode(800, 800), "Curvas de Lissajous");

    // Constantes
    const int num_puntos = 1000;
    const float A = 180.0f;
    const float B = 120.0f;
    const float a = 7.0f;
    const float b = 9.0f;
    const float phi = M_PI / 5;

    sf::VertexArray grafica(sf::LinesStrip, num_puntos);

    for (int i = 0; i < num_puntos; i++){
        float t = i * 0.01;

        float x = 400 + A * std::sin(a*t + phi);
        float y = 400 + B * std::sin(b*t);

        grafica[i].position = sf::Vector2f(x, y);
        grafica[i].color = sf::Color::Red;
    }

    // Cargar leyenda
    sf::Font font;
    font.loadFromFile("OpenSans.ttf");

    sf::Text leyenda;
    leyenda.setFont(font);
    leyenda.setCharacterSize(20);
    leyenda.setFillColor(sf::Color::White);
    leyenda.setPosition(80, 10);

    std::ostringstream oss;
    oss << "Amp 1 = " << A << "\tAmp 2 = " << B << "\tFrec 1 = " << a << "\tFrec 2 = " << b << "\tPhase = " << phi;
    leyenda.setString(oss.str());


    while (window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        // Limpiar la ventana con un color de fondo
        window.clear(sf::Color::Black);

        // Dibujar la gráfica
        window.draw(grafica);

        // Dibujar la leyenda
        window.draw(leyenda);

        // Mostrar todo en la ventana
        window.display();
    }

    return 0;
}