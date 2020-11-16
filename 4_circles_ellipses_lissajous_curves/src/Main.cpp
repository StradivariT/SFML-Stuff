#include "Platform/Platform.hpp"

double dRand(double min, double max);

int main() {
	srand(time(NULL));

	const int width {1500}, height {1000};
	sf::RenderWindow window(sf::VideoMode(width, height), "Circles, Ellipses and Lissajous Curves");

	const double circleRadius {7};
	const int circleAmount {30};

	std::vector<sf::CircleShape> circles(circleAmount, sf::CircleShape(circleRadius));
	for (int i = 0; i < circleAmount; i++) {
		circles.at(i).setFillColor(sf::Color::White);
		circles.at(i).setOrigin(sf::Vector2f(circleRadius, circleRadius));
	}

	const double pi {3.14159265}, minRand {0.25}, maxRand {1.25};

	std::vector<sf::Vector2f> speeds(circleAmount);
	for (int i = 0; i < circleAmount; i++)
		speeds.at(i) = sf::Vector2f(pi * dRand(minRand, maxRand), pi * dRand(minRand, maxRand));

	std::vector<sf::Vector2f> angles(circleAmount, sf::Vector2f(0, 0));
	sf::Vector2f windowCenter(width / 2.0, height / 2.0);

	const double xPathRadius {600}, yPathRadius {350};

	sf::Clock clock;
	sf::Time delta;

	sf::Event event;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		for (int i = 0; i < circleAmount; i++) {
			circles.at(i).setPosition(windowCenter + sf::Vector2f(std::cos(angles.at(i).x) * xPathRadius, std::sin(angles.at(i).y) * yPathRadius));
			window.draw(circles.at(i));
		}

		window.display();

		delta = clock.restart();
		for (int i = 0; i < circleAmount; i++)
			angles.at(i) += speeds.at(i) * delta.asSeconds();
	}

	return 0;
}

double dRand(double min, double max) {
	double temp = (double)rand() / RAND_MAX;
	return min + temp * (max - min);
}