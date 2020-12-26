
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include <cmath>

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
	float fBatSpeed = 260.0f;

   olc::vf2d vBall = {200.0f, 200.0f};
   olc::vf2d vBallVel = {300.0f, 300.0f};

   float fBallRadius = 5.0f;

public:
	bool OnUserCreate() override
	{
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
      // handle user input
      if (GetKey(olc::Key::LEFT).bHeld) fBatPos -= fBatSpeed * fElapsedTime;
      if (GetKey(olc::Key::RIGHT).bHeld) fBatPos += fBatSpeed * fElapsedTime;

      // constrain bat position (paddle)
      if (fBatPos < 11.0f) fBatPos = 11.0f;
		if (fBatPos + fBatWidth > float(ScreenWidth()) - 10.0f) fBatPos = float(ScreenWidth()) - 10.0f - fBatWidth;

      // update ball
      vBall += vBallVel * fElapsedTime;

      // crude arena detection - this approach sucks
      if (vBall.y <= 10.0f) vBallVel.y *= -1.0f;
      if (vBall.x <= 10.0f) vBallVel.x *= -1.0f;
      if (vBall.x >= float(ScreenWidth()) - 10.0f) vBallVel.x *= -1.0f;

      // check bat
      if (vBall.y >= (float(ScreenHeight()) - 20.0f) && (vBall.x > fBatPos) && (vBall.x < fBatPos + fBatWidth)) vBallVel.y *= -1.0f;

      // check if ball has gone off screen
      if (vBall.y > ScreenHeight()) {
         // reset ball location
         vBall = { 200.0f, 200.0f };
         // choose random direction
         float fAngle = (float(rand()) / float(RAND_MAX)) * 2.0f * 3.14159f;
         vBallVel = { 300.0f * std::cos(fAngle), 300.0f * std::sin(fAngle) };
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
	if (demo.Construct(512, 480, 2, 2, false, true))
		demo.Start();
	return 0;
}