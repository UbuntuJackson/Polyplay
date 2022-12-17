#include "entity.h"
#include "olcPixelGameEngine.h"

Polygon::Polygon(std::initializer_list<olc::vf2d> ls) {
	
	points.resize(ls.size());
	std::copy(ls.begin(), ls.end(), points.begin());
	
}

void Polygon::DrawPolygon() {
	for (int i = 0; i < points.size(); i++) {
		
	}
}