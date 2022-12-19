#pragma once

#include "olcPixelGameEngine.h"
#include "entity.h"

class Polyplay : public olc::PixelGameEngine
{
public:
	Polyplay();
	std::vector<Polygon_*> polyvec;
	
	bool RayVsSide(Ray* r, olc::vf2d* rayStart, olc::vf2d* rayEnd, olc::vf2d*, float* t);

	bool OnUserCreate();

	bool OnUserUpdate(float fElapsedTime);
};