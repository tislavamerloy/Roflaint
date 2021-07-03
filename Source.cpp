#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

int main() {
	enum class mode {
		print,
		erase,
		nothing
	}mainmode;
	mainmode = mode::nothing;
	
	ContextSettings setings;
	setings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(500, 500), "Roflaint", Style::Default, setings);
	
	Image image_Logo;
	image_Logo.loadFromFile("logo.png");
	window.setIcon(333,333, image_Logo.getPixelsPtr());

	while (window.isOpen()) {
		
		CircleShape circle(1.f);
		CircleShape circle_Erase(30.f);
		circle_Erase.setFillColor(Color::Black);
		circle_Erase.setOrigin(Vector2f(25, 30));
		
		Event event;
		while (window.pollEvent(event)) {

			if (event.type == Event::Closed) {
				window.close();
			}
			////////
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Right) {
					mainmode = mode::erase;
				}
				if (event.mouseButton.button == Mouse::Left) {
					mainmode = mode::print;
				}
			}
			if (event.type == Event::MouseButtonReleased) {
				mainmode = mode::nothing;
			}
			////////
			if (event.type == Event::MouseMoved) {
				if (mainmode == mode::print) {
					circle.setPosition(Vector2f(event.mouseMove.x, event.mouseMove.y));
				} else if (mainmode == mode::erase) {
					circle_Erase.setPosition(Vector2f(event.mouseMove.x, event.mouseMove.y));
				} 
			}
			
		}

		window.draw(circle);
		window.draw(circle_Erase);
		window.display();
	}

    return 0;
}