#ifndef __SUB_WINDOW_HPP__
#define __SUB_WINDOW_HPP__

#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include <draw_object.hpp>

using namespace sf;

class sub_window : public draw_object
{
public:
	sub_window();
	sub_window(const std::string& title);
	sub_window(const std::pair<int, int>& resolution);
	sub_window(const std::string& title, const std::pair<int, int>& res) 
		: sub_window(title), sub_window(res) {}

	sub_window(const sub_window& _clone);
	sub_window(sub_window&&) = delete;

	void draw(RenderTarget& target, RenderStates states) const;

private:
	std::vector<draw_object&> m_sub_controls;
	std::string               m_title;
};

#endif