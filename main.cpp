#include <SFML/Graphics.hpp>
#include <cmath>

// g++ main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system
// x(t) = A sin(a*t + phi)
// y(t) = B sin(bt)

int main(){
    // Configuración de la ventana
    sf::RenderWindow window(sf::VideoMode(800, 800), "Curvas de Lissajous");

    // Constantes
    const int num_puntos = 1000;
    const float A = 250.0f;
    const float B = 250.0f;
    const float a = 3.0f;
    const float b = 2.0f;
    const float phi = M_PI / 2;

    sf::VertexArray grafica(sf::LinesStrip, num_puntos);

    for (int i = 0; i < num_puntos; i++){
        float t = i * 0.01;

        float x = 400 + A * std::sin(a*t + phi);
        float y = 400 + B * std::sin(b*t);

        grafica[i].position = sf::Vector2f(x, y);
        grafica[i].color = sf::Color::Red;
    }

    while (window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        // Limpiar la ventana con un color de fondo
        window.clear(sf::Color::Black);

        // Dibujar la gráfica del seno
        window.draw(grafica);

        // Mostrar todo en la ventana
        window.display();
    }

    return 0;
}