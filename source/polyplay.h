#pragma once

#include "olcPixelGameEngine.h"
//#include "entity.h"

class Polygon_;
class DynamicPolygon_;
struct Ray;

class Polyplay : public olc::PixelGameEngine
{
public:
	Polyplay();
	DynamicPolygon_ *Player;
	std::vector<Polygon_*> polyvec;
	
	bool RayVsSide(olc::vf2d lineStart, olc::vf2d lineEnd, olc::vf2d rayStart, olc::vf2d rayEnd, olc::vf2d*, float* t);
	void CalculateNormal(olc::vf2d& _side, olc::vf2d& _velocity, olc::vf2d& _normal);

	bool OnUserCreate();

	bool OnUserUpdate(float fElapsedTime);
};