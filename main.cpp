#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <iostream>

class Game : public olc::PixelGameEngine
{
public:
    Game()
	{
		sAppName = "Test with olcPixelGameEngine";
    }

    olc::vd2d position;
    olc::vd2d velocity = { 0, 0};
    olc::vd2d size = { 30, 30 };
    float speed = 30;

public:
	bool OnUserCreate() override
	{
        std::cout << "Start!";
        olc::vd2d screenSize = {ScreenWidth(), ScreenHeight()};
        position = (screenSize / 2) - size / 2;
        return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
        olc::vf2d mousePos = { float(GetMouseX()), float(GetMouseY())};

        velocity.x = 0;
        velocity.y = 0;

        if(GetKey(olc::Key::S).bHeld) {
            velocity.y += 1;
        }
        
        if(GetKey(olc::Key::W).bHeld) {
            velocity.y -= 1;
        }

        if(GetKey(olc::Key::D).bHeld) {
            velocity.x += 1;
        }

        if(GetKey(olc::Key::A).bHeld) {
            velocity.x -= 1;
        }

        Clear(olc::BLACK);
        DrawCircle(mousePos, 3, olc::YELLOW);

        // Update position
        position += velocity * fElapsedTime * speed;

        // Draw character
        DrawRect(position, size, olc::GREEN);

        return true;
	}
};


int main()
{
	Game demo;
	if (demo.Construct(320, 180, 4, 4))
		demo.Start();

	return 0;
}