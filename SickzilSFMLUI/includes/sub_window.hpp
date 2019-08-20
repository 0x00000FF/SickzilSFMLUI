#ifndef __SUB_WINDOW_HPP__
#define __SUB_WINDOW_HPP__

#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include <controls.hpp>
#include <draw_object.hpp>

using namespace sf;

struct sub_window_appearances
{
    sf::RectangleShape window_panel;
    sf::RectangleShape title_bar;
    sf::Text           title_text;

    sf::RectangleShape window_close_button;
    sf::Text           window_close_x;
};

class sub_window : public draw_object
{
public:
	sub_window() : sub_window("Window", {100, 100}) { }
	sub_window(const std::string& title);
	sub_window(const std::pair<int, int>& resolution);
	sub_window(const std::string& title, const std::pair<int, int>& res);

	sub_window(const sub_window& _clone) = default;
	sub_window(sub_window&&) = delete;

	void draw(RenderTarget& target, RenderStates states) const;

	const std::pair<int, int> get_size () const;
	void                      set_size (const std::pair<int, int>& size);

	const sf::Color           get_border_color() const;
	void                      set_border_color(const sf::Color& color);

	const sf::Color           get_fg_color() const;
	void                      set_fg_color(const sf::Color& color);

	const sf::Color           get_bg_color() const;
	void                      set_bg_color(const sf::Color& color);

protected:
    bool                      m_dragging       = false;

private:
    std::pair<int, int>       m_position;
	std::vector<control>      m_sub_controls;
	sub_window_appearances    m_appearance;

public:
	std::string               title;
};

#endif