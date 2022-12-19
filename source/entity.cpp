#include "entity.h"
#include "olcPixelGameEngine.h"

Polygon_::Polygon_(std::initializer_list<olc::vf2d> ls) {
	
	points.resize(ls.size());
	std::copy(ls.begin(), ls.end(), points.begin());
	
}

void Polygon_::Draw(olc::PixelGameEngine* pge) {
	for (int i = 0; i < points.size(); i++) {
		pge->DrawLine(points[i], points[(i + 1) % points.size()], olc::WHITE);
	}
}

DynamicPolygon_::DynamicPolygon_(std::initializer_list<olc::vf2d> ls) {

	points.resize(ls.size());
	std::copy(ls.begin(), ls.end(), points.begin());

}

void DynamicPolygon_::Update(olc::PixelGameEngine* pge) {
	for (int i = 0; i < points.size(); i++) {
		//pge->DrawLine(points[i], points[(i + 1) % points.size()], olc::WHITE);
	}
}

void DynamicPolygon_::Draw(olc::PixelGameEngine* pge) {
	for (int i = 0; i < points.size(); i++) {
		pge->DrawLine(points[i], points[(i + 1) % points.size()], olc::WHITE);
	}
}