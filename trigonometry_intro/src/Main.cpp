#include "Platform/Platform.hpp"

#define width 1500
#define height 1000
#define pi 3.14159265

int main() {
	sf::RenderWindow window(sf::VideoMode(width, height), "Trigonometry intro");
	window.clear(sf::Color::White);

	int scaleFactor = 200;

	sf::RectangleShape point(sf::Vector2f(3, 3));
	point.setFillColor(sf::Color::Black);

	for (float angle = 0; angle <= 2 * pi; angle += 0.01) {
		float y = std::sinf(angle) * scaleFactor;
		point.setPosition(angle * scaleFactor + 30, -y + 300);

		window.draw(point);
	}

	window.display();

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	return 0;
}
