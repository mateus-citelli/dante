#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

extern float fSpeed;
sf::Vector2f getRequestedPlayerMovement();
int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode({1920, 1080}), "DANTE");


    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("../assets/sprites/dante/dante.png")) //verifica se o sprite existe. se nao, o programa nao abre.
    {
        return -1;
    }
    sf::Sprite player(playerTexture); //carrega o sprite do personagem
    player.setScale(sf::Vector2f(10, 10)); //define o tamanho do personagem
    player.setOrigin(sf::Vector2f(8,8)); //define origem do personagem


    sf::Texture enemyTexture;
    if (!enemyTexture.loadFromFile("../assets/sprites/enemy/dm.png")){ //verifica se o sprite existe. se nao, o programa nao abre.
        return -1;
    }
    sf::Sprite enemy(enemyTexture); //carrega o sprite do inimigo
    enemy.setScale(sf::Vector2f(10, 10)); //define o tamanho do inimigo
    enemy.setPosition(sf::Vector2f(960, 540)); //define a posicao do inimigo na tela.
    enemy.setOrigin(sf::Vector2f(8, 8)); //define a origem do inimigo

    sf::Clock clock; //cria um relogio para controlar o tempo do jogo



    while (window.isOpen()) //loop para manter a janela do jogo aberta
    {
        sf::Time timeSinceLastFrame = clock.restart(); //reinicia o relogio a cada frame
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        player.move(getRequestedPlayerMovement()*(timeSinceLastFrame.asSeconds() * fSpeed)); //move o personagem de acordo com o input do jogador

    window.clear(sf::Color::Black);
    window.draw(player); //coloca o personagem na tela a cada loop
    window.draw(enemy);  //coloca o inimigo na tela a cada loop
    window.display();
}
}