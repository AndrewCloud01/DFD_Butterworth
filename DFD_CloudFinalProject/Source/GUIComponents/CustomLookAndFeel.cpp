/*
  ==============================================================================

    CustomLookAndFeel.cpp
    Created: 19 Sep 2014 7:23:32pm
    Author:  Joshua Marler

  ==============================================================================
*/

#include "CustomLookAndFeel.h"


//Basic override of drawRotarySlider function
// Made to look like a regular Pot
void CustomLookAndFeel::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                                       const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
{
const float radius = jmin(width/2, height/2)-4.0f;
const float centreX = x+width *0.5f;
const float centreY = y+height*0.5f;
const float rx = centreX - radius;
const float ry = centreY - radius;
const float rw = radius *2.0f;
const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);

g.setColour(Colours::lightslategrey);       // Knob Color
g.fillEllipse(rx,ry,rw,rw);

Path p;
const float pointerLength = radius * 0.33f;
const float pointerThickness = 2.0f;
p.addRectangle(-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
p.applyTransform(AffineTransform::rotation(angle).translated(centreX,centreY));

g.setColour(Colours::white);          // Slit Color
g.fillPath(p);

}

