#pragma once
#include "window.hpp"
#include "event_manager.hpp"
#include <iostream>

class Game {
  public:
    Game();
    ~Game();

    void HandleInput();
    void Update();
    void Render();
    Window *GetWindow();

    sf::Time GetElasped();
    void RestartClock();

    void MoveSprite(EventDetails *l_details);

  private:
    Window m_window;
    sf::Clock m_clock;

    sf::Texture m_texture;
    sf::Sprite m_sprite;
};