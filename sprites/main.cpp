
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

   std::unique_ptr<olc::Sprite> sprTile;

public:
   bool OnUserCreate() override
   {
      blocks = std::make_unique<int[]>(24*30);

      for (int y = 0; y < 30; y++) {
         for (int x = 0; x < 24; x++) {
            if (x == 0 || y == 0 || x == 23)
               blocks[y * 24 + x] = 10;
            else
               blocks[y * 24 + x] = 0;

            if (x > 2 && x <= 20 && y > 3 && y <= 5)
               blocks[y * 24 + x] = 1;
            if (x > 2 && x <= 20 && y > 5 && y <= 7)
               blocks[y * 24 + x] = 2;
            if (x > 2 && x <= 20 && y > 7 && y <= 9)
               blocks[y * 24 + x] = 3;
	      }
      }
      // load sprite
      sprTile = std::make_unique<olc::Sprite>("./gfx/tut_tiles.png");
      return true;
   }

   bool OnUserUpdate(float fElapsedTime) override
   {
      // draw screen
      Clear(olc::DARK_BLUE);
      SetPixelMode(olc::Pixel::MASK);  // don't draw pixels which has any transparency
      for (int y = 0; y < 30; y++)for (int y = 0; y < 30; y++) {
         for (int x = 0; x < 24; x++) {
            switch (blocks[y * 24 + x]) {
               case 0: // do nothing
                  break;
               case 10: // draw boundary
                  DrawPartialSprite(olc::vi2d(x, y) * vBlockSize, sprTile.get(), olc::vi2d(0, 0) * vBlockSize, vBlockSize);
                  break;
               case 1: // draw red block
                  DrawPartialSprite(olc::vi2d(x, y) * vBlockSize, sprTile.get(), olc::vi2d(1, 0) * vBlockSize, vBlockSize);
                  break;
               case 2: // draw green block
                  DrawPartialSprite(olc::vi2d(x, y) * vBlockSize, sprTile.get(), olc::vi2d(2, 0) * vBlockSize, vBlockSize);
                  break;
               case 3: // draw yellow block
                  DrawPartialSprite(olc::vi2d(x, y) * vBlockSize, sprTile.get(), olc::vi2d(3, 0) * vBlockSize, vBlockSize);
                  break;
            }
         }
      }
      SetPixelMode(olc::Pixel::NORMAL); // draw all pixels
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
