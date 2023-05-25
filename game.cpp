#include "game.h"

//private
void Game::initializeVariables()
{
    this->window = nullptr;
}

void Game::initWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 800;

    this->window = new sf::RenderWindow(this->videoMode, "Tic-Tac-Toe", sf::Style::Default);
    this->window->setFramerateLimit(144);
}

void Game::initEnemies()
{
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.f);
}

//construtor / destructors
Game::Game()
{
    this->initializeVariables();
    this->initWindow();
    this->initEnemies();
}

Game::~Game()
{
    delete this->window;
}

//accessors

const bool Game::running() const
{
    return this->window->isOpen();
}

//functions

void Game::pollEvents()
{
    // Continuously check for events
    while (this->window->pollEvent(this->ev))
    {
        // Handle different types of events
        switch (this->ev.type)
        {
            // If the user clicks the close button of the window
            case sf::Event::Closed:
                // Close the game window
                this->window->close();
                break;
                
            // If a key is pressed
            case sf::Event::KeyPressed:
                // Check if the pressed key is the Escape key
                if (this->ev.key.code == sf::Keyboard::Escape)
                {
                    // Close the game window
                    this->window->close();
                }
                break;
        }
    }
}

void Game::render()
{
    /*
        @return void

        -clear old frame
        -render objects
        -display frame in window

        Renders the game objects
    */
    this->window->clear();//This line of code clears the previous frame by filling the window with a black color

    //Draw game objects
    this->window->draw(this->enemy);

    this->window->display();
}

void Game::update()
{
    this->pollEvents();

    //update mouse position
    //relative ti the screen
    std::cout << "mouse pos: " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << "\n";
    //relative to the window
    std::cout << "mouse pos: " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << "\n";
    
}