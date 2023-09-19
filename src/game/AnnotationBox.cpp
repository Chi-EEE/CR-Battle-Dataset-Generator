#include "AnnotationBox.h"

AnnotationBox::AnnotationBox(std::string text, sf::FloatRect rect) : text(text), rect(rect)
{
}

AnnotationBox::~AnnotationBox()
{

}

void AnnotationBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::RectangleShape box;
	box.setSize(sf::Vector2f{ rect.width, rect.height });
	box.setPosition(sf::Vector2f{ rect.left, rect.top });
	target.draw(box, states);
}
