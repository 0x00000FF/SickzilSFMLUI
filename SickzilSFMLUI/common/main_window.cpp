#include <SFML/Graphics.hpp>
#include <main_window.hpp>

#include <iostream>

int main_window::get_exit_code() const
{
	return this->exit_code;
}

void main_window::begin_window_loop()
{
    while (this->isOpen())
    {
        Event event;
        this->pollEvent(event);

        std::cout << event.type << std::endl;

        this->dispatch_event_to_children(event);

        clear();

        for (auto& object : m_objects)
            this->draw(*object);

        display();
    }
}

void main_window::dispatch_event_to_children(const Event &event)
{
    switch (event.type)
    {
        case Event::MouseLeft:
            break;

        case Event::MouseEntered:
            break;

        case Event::MouseMoved:
            break;

        case Event::MouseButtonPressed:
            break;

        case Event::MouseButtonReleased:
            break;

        case Event::MouseWheelScrolled:
            break;

        case Event::KeyPressed:
            break;

        case Event::KeyReleased:
            break;

        case Event::Resized:
            // TODO: Dispatch Resize Event to Child Objects
            break;

        case Event::Closed:
            // TODO: Check file was modified and alert

            this->close();
            break;

        default:
            break;
    }
}