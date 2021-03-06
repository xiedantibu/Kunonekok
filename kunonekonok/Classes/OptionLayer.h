//
//  OptionLayer.h
//  parasite-city
//
//  Created by damingdan on 14-2-18.
//
//

#pragma once
#include "cocos2d.h"
#include "CharacterSprite.h"
using namespace cocos2d;

const int JoystickBgRadius = 64;
const int JoystickRadius = 32;

class OptionDelegate
{
public:
    virtual void onWalk(Direction direction) = 0;
    virtual void onStop() = 0;
};

class OptionLayer:public Layer
{
public:
    OptionLayer();
    ~OptionLayer();
    
    virtual bool init();
    CREATE_FUNC(OptionLayer);
    
    // override
    void onTouchesBegan(const std::vector<Touch*>& touches, Event *event);
    void onTouchesMoved(const std::vector<Touch*>& touches, Event *event);
    void onTouchesEnded(const std::vector<Touch*>& touches, Event *event);
    
    CC_SYNTHESIZE(OptionDelegate*, delegator, Delegator);
    
    void setLocation(const Point location);
    Point getLocation();
    
    void setRadius(const float radius);
    float getRadius();
    
private:
    Sprite *joystick;
    
    Point location;
    float radius;
    
    void activeJoystick(Point position);
    void inactiveJoystick();
    void updateJoystick(Point direction, float distance);
	void initJoystick();
};