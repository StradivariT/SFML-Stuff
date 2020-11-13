#include "Platform/Platform.hpp"
#include <cstdlib>
#include <ctime>

#define width 1000
#define height 700

int main() {
	srand(static_cast<unsigned>(time(0)));

	sf::RenderWindow window(sf::VideoMode(width, height), "Introduction");
	window.clear(sf::Color::White);

	for (int i = 0; i < 100; i++) {
		sf::Vector2f lineStart(width * static_cast<float>(rand()) / (static_cast<float>(RAND_MAX)), height * static_cast<float>(rand()) / (static_cast<float>(RAND_MAX)));
		sf::Vector2f lineEnd(width * static_cast<float>(rand()) / (static_cast<float>(RAND_MAX)), height * static_cast<float>(rand()) / (static_cast<float>(RAND_MAX)));

		float xDiff = lineEnd.x - lineStart.x;
		float yDiff = lineEnd.y - lineStart.y;
		float hyp = std::sqrtf(xDiff * xDiff + yDiff + yDiff);

		float angle = std::atan(yDiff / xDiff) * 180 / 3.14159265;

		sf::RectangleShape rect(sf::Vector2(hyp, 1.0F));
		rect.rotate(angle);
		rect.setPosition(lineStart);
		rect.setFillColor(sf::Color::Black);

		window.draw(rect);
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
