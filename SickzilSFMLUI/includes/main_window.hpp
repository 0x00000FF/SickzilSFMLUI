#ifndef __MAIN_WINDOW_HPP__
#define __MAIN_WINDOW_HPP__

#include <SFML/Graphics.hpp>
#include <memory>

#include <draw_object.hpp>

using namespace sf;

struct ui_options
{

};

using up_options = std::unique_ptr<ui_options>;
using up_object  = std::unique_ptr<draw_object>;

class main_window : public sf::RenderWindow
{
public: 
	main_window(const ui_options& _options) : RenderWindow(VideoMode(400, 400), "SickzilMachine")
	{
		while (this->isOpen()) 
		{
			Event event;
			pollEvent(event);

			switch (event.type)
			{
			    case Event::MouseButtonPressed:
			        break;

			    case Event::MouseButtonReleased:
			        break;

			    case Event::KeyPressed:
			        break;

			    case Event::KeyReleased:
			        break;

			    case Event::MouseWheelScrolled:
			        break;

				case Event::Closed:
					this->close();
					break;

			    default:
			        break;
			}

			clear();

			for (auto& object : m_objects)
				this->draw(*object);

			display();
		}
	}

	const int get_exit_code() const;

private:
	int exit_code = 0;

	up_options               m_options;
	std::vector<up_object>   m_objects;
};

#endif