#ifndef ANNOTATIONBOX_H
#define ANNOTATIONBOX_H

#pragma once

#include "SFML/Graphics.hpp"

class AnnotationBox : public sf::Drawable
{
public:
    AnnotationBox(std::string text, sf::FloatRect rect);
    ~AnnotationBox();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    std::string text;
    sf::FloatRect rect;
};

#endif