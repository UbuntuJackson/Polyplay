#include "entity.h"
#include "polyplay.h"
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

void DynamicPolygon_::Update(Polyplay* polyplay, float _elapsedTime) {
	olc::vf2d intersectionP;
	float time;
	std::vector<float> times;
	
	if (polyplay->GetKey(olc::Key::LEFT).bHeld) vel.x -= 0.1f * _elapsedTime;
	if (polyplay->GetKey(olc::Key::RIGHT).bHeld) vel.x += 0.1f * _elapsedTime;
	if (polyplay->GetKey(olc::Key::UP).bHeld) vel.y -= 0.1f * _elapsedTime;
	if (polyplay->GetKey(olc::Key::DOWN).bHeld) vel.y += 0.1f * _elapsedTime;

	for (int p = 0; p < points.size(); p++) {
		for (int i = 0; i < polyplay->polyvec.size(); i++) { //for every polygon
			for (int j = 0; j < polyplay->polyvec[i]->points.size(); j++) { //for every point in every polygon
				if (polyplay->RayVsSide(points[p], (points[p] + vel), polyplay->polyvec[i]->points[j], polyplay->polyvec[i]->points[(j + 1) % polyplay->polyvec[i]->points.size()], &intersectionP, &time)) {
					
					times.push_back(time);
					

				}
				
			}
		}
		
	}
	


	if (times.size() != 0) std::cout << times[0] << std::endl;
	std::sort(times.begin(), times.end(), [](const float& a, const float& b)
		{
			return a < b;
		});

	if(times.size() != 0) vel -= vel * (1 - times[0]);

	for (int p = 0; p < points.size(); p++) points[p] += vel;

	
}

/*float DynamicPolygon_::GetClosestTime(Polyplay* polyplay) {
	for (int p = 0; p < points.size(); p++) {
		for (int i = 0; i < polyplay -> polyvec.size(); i++) {
			for (int j = 0; j < polyplay -> polyvec[i]->points.size(); j++) {
				if (polyplay-> RayVsSide(&ray, &polyvec[i]->points[j], &polyvec[i]->points[(j + 1) % polyvec[i]->points.size()], &intersectionP, &time)) {
					DrawLine(ray.pos.x, ray.pos.y, ray.pos.x + ray.vel.x, ray.pos.y + ray.vel.y, olc::WHITE);
					std::cout << "1" << std::endl;

				}
				else {
					DrawLine(ray.pos.x, ray.pos.y, float(GetMouseX()), float(GetMouseY()), olc::YELLOW);
					std::cout << "0" << std::endl;

				}
			}
		}
	}
}*/

void DynamicPolygon_::Draw(olc::PixelGameEngine* pge) {
	for (int i = 0; i < points.size(); i++) {
		pge->DrawLine(points[i], points[(i + 1) % points.size()], olc::WHITE);
	}
}