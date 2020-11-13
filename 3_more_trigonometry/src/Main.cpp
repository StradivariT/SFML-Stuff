#include "Platform/Platform.hpp"

sf::CircleShape getNewCircle(double radius, sf::Vector2f position, sf::Color color);

int main() {
	const int width {1500}, height {1000}, halfHeight {height / 2};
	sf::RenderWindow window(sf::VideoMode(width, height), "More trigonometry");

	int radius {75};

	sf::CircleShape movingCircle = getNewCircle(radius, sf::Vector2f(width / 4, halfHeight), sf::Color::Black);
	sf::CircleShape scalingCircle = getNewCircle(radius, sf::Vector2f(width / 2, halfHeight), sf::Color::Black);
	sf::CircleShape transparencyCircle = getNewCircle(radius, sf::Vector2f(width * 0.75, halfHeight), sf::Color::Black);

	const double PI {3.14159265};
	double angle {0}, speed {PI};

	sf::Clock clock;
	sf::Time delta;

	sf::Event event;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);

		float angleSin {std::sinf(angle)};

		float newY {static_cast<float>(halfHeight) + angleSin * 300};
		movingCircle.setPosition(sf::Vector2(movingCircle.getPosition().x, newY));
		window.draw(movingCircle);

		scalingCircle.setScale(angleSin, angleSin);
		window.draw(scalingCircle);

		float newAlpha = 255 * std::abs(angleSin);
		transparencyCircle.setFillColor(sf::Color(0, 0, 0, newAlpha));
		window.draw(transparencyCircle);

		window.display();

		angle += speed * delta.asSeconds();
		delta = clock.restart();
	}

	return 0;
}

sf::CircleShape getNewCircle(double radius, sf::Vector2f position, sf::Color color) {
	sf::CircleShape circle(radius);
	circle.setPosition(position);
	circle.setFillColor(color);
	circle.setOrigin(sf::Vector2f(radius, radius));

	return circle;
}