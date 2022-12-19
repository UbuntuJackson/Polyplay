#pragma once
#include "olcPixelGameEngine.h"

struct Ray{
public:
	olc::vf2d pos;
	olc::vf2d vel;

};

class Polygon_ {
public:
	std::vector<olc::vf2d> points;
	Polygon_(std::initializer_list<olc::vf2d> ls);
	void Draw(olc::PixelGameEngine* pge);
};

class DynamicPolygon_ {
public:
	std::vector<olc::vf2d> points;
	DynamicPolygon_(std::initializer_list<olc::vf2d> ls);
	void Update(olc::PixelGameEngine* pge);
	void Draw(olc::PixelGameEngine* pge);
};