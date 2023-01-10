#pragma once
#include "olcPixelGameEngine.h"
#include "polyplay.h"

struct Ray{
public:
	olc::vf2d start;
	olc::vf2d end;

};

class Polygon_ {
public:
	
	olc::vf2d vel;
	std::vector<olc::vf2d> points;
	Polygon_(std::initializer_list<olc::vf2d> ls);
	void Update(Polyplay* polyplay);
	void Draw(olc::PixelGameEngine* pge);
};

class DynamicPolygon_ {
public:
	olc::vf2d vel;
	std::vector<olc::vf2d> points;
	DynamicPolygon_(std::initializer_list<olc::vf2d> ls);
	//float GetClosestTime(Polyplay* polyplay);
	void Update(Polyplay* polyplay, float _elapsedTime);
	void Draw(olc::PixelGameEngine* pge);
};