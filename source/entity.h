#pragma once
#include "olcPixelGameEngine.h"

class Polygon {
public:
	std::vector<olc::vf2d> points;
	Polygon(std::initializer_list<olc::vf2d> ls);
	void DrawPolygon();
};