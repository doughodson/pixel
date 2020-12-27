
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include <cmath>
#include <cstdlib>
#include <memory>

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
	float fBatSpeed = 250.0f;

   olc::vf2d vBall = {200.0f, 200.0f};
   olc::vf2d vBallVel = {200.0f, -100.0f};

   float fBallRadius = 5.0f;

   olc::vi2d vBlockSize = { 16, 16 };
   std::unique_ptr<int[]> blocks;

public:
	bool OnUserCreate() override
	{
      blocks = std::make_unique<int[]>(24*30);
      for (int y=0; y<30; y++) {
         for( int x=0; x < 24; x++) {
            if (x == 0 || y == 0 || x == 23)
               blocks[y*24+x] = 10;
            else
               blocks[y*24+x] = 0;
         }
      }
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
      // draw screen
      Clear(olc::DARK_BLUE);
      for (int y = 0; y < 30; y++)for (int y = 0; y < 30; y++) {
         for (int x = 0; x < 24; x++) {
            switch (blocks[y * 24 + x]) {
            case 0: // do nothing
               break;
            case 10: // draw Boundary
               FillRect(olc::vi2d(x, y) * vBlockSize, vBlockSize, olc::WHITE);
            break;
            }
         }
      }
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