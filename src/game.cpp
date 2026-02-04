#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

float fSpeed = 200.0f; //velocidade do personagem

sf::Vector2f getRequestedPlayerMovement()
{
    sf::Vector2f vRequestedPlayerMovement(0.0f, 0.0f); //cria o movimento do personagem.

    //caso o player aperte W, A, S ou D, o personagem anda para uma das direcoes especificadas.
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        vRequestedPlayerMovement += sf::Vector2f(0.0f,-1.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
        vRequestedPlayerMovement += sf::Vector2f(1.0f,0.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        vRequestedPlayerMovement += sf::Vector2f(0.0f,1.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        vRequestedPlayerMovement += sf::Vector2f(-1.0f,0.0f);
    }
    
    return vRequestedPlayerMovement;
}