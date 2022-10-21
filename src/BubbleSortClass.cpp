#include "Platform/Platform.hpp"

class BubbleSort
{
private:
	int x;
	int y;
	int n;
	std::vector<int> sizes;
	sf::RenderWindow* w;
	bool sorted = false;

public:
	BubbleSort(int screenHeight, int screenWidth, int numOfRectangles, sf::RenderWindow* window)
	{
		x = screenHeight;
		y = screenWidth;
		n = numOfRectangles;
		w = window;
		int m;
		for (int i = 0; i < n; i++)
		{
			m = std::rand() % y;
			sizes.push_back(m);
		}
	}

	void Draw()
	{
		w->clear();
		for (int i = 0; i < n; i++)
		{
			sf::RectangleShape shape(sf::Vector2f(x / n, sizes[i]));
			if (sorted)
			{
				shape.setFillColor(sf::Color::Green);
			}
			else
			{
				shape.setFillColor(sf::Color::White);
			}
			shape.setPosition(i * (x / n), y - shape.getSize().y);
			w->draw(shape);
		}
		w->display();
	}

	void Sort()
	{
		int cur_min;
		int min_pos;
		int temp;
		for (int i = 0; i < n - 1; i++)
		{
			cur_min = sizes[i];
			min_pos = i;
			for (int j = i + 1; j < n; j++)
			{
				if (sizes[j] < cur_min)
				{
					cur_min = sizes[j];
					min_pos = j;
				}
			}
			if (min_pos != i)
			{
				temp = sizes[i];
				sizes[i] = cur_min;
				sizes[min_pos] = temp;
			}
			Draw();
			// Sleep because it goes really fast if you don't and I want it to look cooler
			Sleep(10);
		}
		sorted = true;
		Draw();
	}
};