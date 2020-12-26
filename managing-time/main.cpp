
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class BreakOut : public olc::PixelGameEngine
{
public:
	BreakOut()
	{
		sAppName = "TUTORIAL - BreakOut Clone";
	}

private:
   float fBatPos = 20.0f;
	float fBatWidth = 40.0f;
	float fBatSpeed = 0.8f;

   olc::vf2d vBall = {200.0f, 200.0f };
   float fBallRadius = 5.0f;

public:
	bool OnUserCreate() override
	{
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
      // handle user input
      if (GetKey(olc::Key::LEFT).bHeld) fBatPos -= fBatSpeed;
      if (GetKey(olc::Key::RIGHT).bHeld) fBatPos += fBatSpeed;

      // constrain bat position (paddle)
      if (fBatPos < 11.0f) fBatPos = 11.0f;
		if (fBatPos + fBatWidth > float(ScreenWidth()) - 10.0f) fBatPos = float(ScreenWidth()) - 10.0f - fBatWidth;

      // cheat! moving the ball with mouse
      if (GetMouse(0).bHeld) {
         vBall = { float(GetMouseX()), float(GetMouseY()) };
      }

      if (GetMouseWheel() > 0) fBallRadius += 1.0f;
      if (GetMouseWheel() < 0) fBallRadius -= 1.0f;
      if (fBallRadius < 5.0f) fBallRadius = 5.0f;

      // erase previous frame
      Clear(olc::DARK_BLUE);

      // draw boundary
      DrawLine(10, 10, ScreenWidth() - 10, 10, olc::YELLOW);    // top edge
      DrawLine(10, 10, 10, ScreenHeight() - 10, olc::YELLOW);   // left edge
      DrawLine(ScreenWidth() - 10, 10, ScreenWidth() - 10, ScreenHeight() - 10, olc::YELLOW);  // right edge

      // draw bat
	   FillRect(int(fBatPos), ScreenHeight() - 20, int(fBatWidth), 10, olc::GREEN);

	   // draw ball
      FillCircle(vBall, int(fBallRadius), olc::CYAN);

      return true;
	}
};

int main()
{
	BreakOut demo;
	if (demo.Construct(512, 480, 2, 2))
		demo.Start();
	return 0;
}