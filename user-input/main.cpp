
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

   olc::vf2d vBall = {200.0f, 200.0f };

public:
	bool OnUserCreate() override
	{
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
      // Erase previous frame
      Clear(olc::DARK_BLUE);

      // draw boundary
      DrawLine(10, 10, ScreenWidth() - 10, 10, olc::YELLOW);    // top edge
      DrawLine(10, 10, 10, ScreenHeight() - 10, olc::YELLOW);   // left edge
      DrawLine(ScreenWidth() - 10, 10, ScreenWidth() - 10, ScreenHeight() - 10, olc::YELLOW);  // right edge

      // draw bat
	   FillRect(int(fBatPos), ScreenHeight() - 20, int(fBatWidth), 10, olc::GREEN);

	   // draw ball
      FillCircle(vBall, 5, olc::CYAN);

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