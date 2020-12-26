
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class BreakOut : public olc::PixelGameEngine
{
public:
	BreakOut()
	{
		sAppName = "TUTORIAL - BreakOut Clone";
	}

public:
	bool OnUserCreate() override
	{
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
      // Erase previous frame
      Clear(olc::DARK_BLUE);

      // Draw Boundary
      DrawLine(10, 10, ScreenWidth() - 10, 10, olc::YELLOW);    // top edge
      DrawLine(10, 10, 10, ScreenHeight() - 10, olc::YELLOW);   // left edge
      DrawLine(ScreenWidth() - 10, 10, ScreenWidth() - 10, ScreenHeight() - 10, olc::YELLOW);  // right edge
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