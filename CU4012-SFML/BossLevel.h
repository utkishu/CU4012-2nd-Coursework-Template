#pragma once

#include "Level.h"
class BossLevel :
    public BaseLevel
{
public:

    BossLevel(sf::RenderWindow* hwnd, Input* in, GameState* gs);
    ~BossLevel();

    void handleInput(float dt) override;
    void update(float dt) override;
    void render() ;

private:

    Background bossBg;
    sf::Texture bossBgTex;

};

