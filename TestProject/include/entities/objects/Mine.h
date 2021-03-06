#ifndef TESTPROJECT_MINE_H
#define TESTPROJECT_MINE_H

#include <entity/Entity.h>

class Mine
	: public goap::Entity
{
public:
    Mine(const glm::vec2& pos = glm::vec2());

	void update(float dt) override {}
    void render(void* renderer) override;

private:
    sf::Font mFont;
    sf::RectangleShape mRect;
};

Mine::Mine(const glm::vec2& pos)
    : goap::Entity(pos)
{
    // Load font
    mFont.loadFromFile("impact.ttf");

    // Set up render rect
    mRect.setSize(sf::Vector2f(32, 32));
    mRect.setFillColor(sf::Color::Color(rand(), rand(), rand()));
}

void Mine::render(void* renderer)
{
    sf::RenderWindow* renderWindow = (sf::RenderWindow*)renderer;

    // Draw body
    mRect.setPosition(mPosition.x, mPosition.y);
    renderWindow->draw(mRect);

    // Write contents
    sf::Text text;
    text.setFont(mFont);
    text.setColor(sf::Color::White);

    text.setCharacterSize(16);

    text.setPosition(mPosition.x + 40.0f, mPosition.y);
    text.setString("Mine");
    renderWindow->draw(text);
}

#endif /* TESTPROJECT_MINE_H */