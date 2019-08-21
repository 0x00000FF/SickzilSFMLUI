#ifndef __MAIN_WINDOW_HPP__
#define __MAIN_WINDOW_HPP__

#include <SFML/Graphics.hpp>
#include <memory>

#include <draw_object.hpp>

using namespace sf;

struct ui_options
{
    int         width = 400;
    int         height = 500;
    std::string title = "SickzilMachine";
};

using up_options = std::unique_ptr<ui_options>;
using up_object  = std::unique_ptr<draw_object>;

class main_window : public sf::RenderWindow
{
public: 
	main_window(const ui_options& _options)
	: RenderWindow(VideoMode(_options.width, _options.height), _options.title)
	{

	    begin_window_loop();
	}

	int get_exit_code() const;

	void      begin_window_loop();
	void      dispatch_event_to_children(const Event& event);

private:
	int exit_code = 0;

	up_options               m_options;
	std::vector<up_object>   m_objects;
};

#endif