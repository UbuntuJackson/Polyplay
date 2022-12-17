#define OLC_PGE_APPLICATION
#include "polyplay.h"
#include "entity.h"


	Polyplay::Polyplay()
	{
		sAppName = "Example";
	}


	bool Polyplay::OnUserCreate()
	{
		Polygon poly{  { 20.0, 20.0 }, {30.0, 30.0}, {-7.0, 6.0}  };
		// Called once at the start, so create things here
		return true;
	}

	bool Polyplay::OnUserUpdate(float fElapsedTime)
	{
		// called once per frame
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(100 + rand() % 100, 100 + rand() % 100, 100 + rand() % 100));
		return true;
	}

