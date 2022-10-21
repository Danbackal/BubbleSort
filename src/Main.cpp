#include "Platform/Platform.hpp"
#include "BubbleSortClass.cpp"

int main()
{
	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	window.create(sf::VideoMode(800.0f * screenScalingFactor, 400.0f * screenScalingFactor), "Bubble Sort Baby!");
	platform.setIcon(window.getSystemHandle());

	sf::Event event;
	BubbleSort bubbles(window.getSize().x, window.getSize().y, 200, &window);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		bubbles.Draw();
		bubbles.Sort();
	}

	return 0;
}
