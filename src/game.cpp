#include "game.hpp"

Game::Game()
    : m_window("Event Manager", sf::Vector2u(800, 600)) {
    m_clock.restart();
    srand(time(NULL));

    m_texture.loadFromFile("Mushroom.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
	m_sprite.setPosition(0,0);

	m_window.GetEventManager()->AddCallback("Move", &Game::MoveSprite,this);

}

Game::~Game() {}

sf::Time Game::GetElasped() { return m_clock.getElapsedTime(); }
void Game::RestartClock() { m_clock.restart(); }
Window *Game::GetWindow() { return &m_window; }

void Game::HandleInput() {
    // Input handling

}

void Game::MoveSprite(EventDetails *l_details) {
    sf::Vector2i mousepos = m_window.GetEventManager()->GetMousePos(m_window.GetRenderWindow());
    m_sprite.setPosition(mousepos.x, mousepos.y);
    std::cout << "Moving sprite to: " << mousepos.x << ":" << mousepos.y << std::endl;
}

void Game::Update() {
    m_window.Update(); // Update window events
    
}

void Game::Render() {
    m_window.BeginDraw(); // Clear
    
    // Render
    m_window.GetRenderWindow()->draw(m_sprite);

    m_window.EndDraw(); // Display
}
