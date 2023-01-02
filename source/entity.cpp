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
	//std::vector<float> times;
	std::vector<olc::vf2d> contacts;
	olc::vf2d contact_normal;
	olc::vf2d contact_side;
	std::vector<std::pair<float, olc::vf2d>> times;
	
	if (polyplay->GetKey(olc::Key::LEFT).bHeld) vel.x -= 0.1f * _elapsedTime;
	if (polyplay->GetKey(olc::Key::RIGHT).bHeld) vel.x += 0.1f * _elapsedTime;
	if (polyplay->GetKey(olc::Key::UP).bHeld) vel.y -= 0.1f * _elapsedTime;
	if (polyplay->GetKey(olc::Key::DOWN).bHeld) vel.y += 0.1f * _elapsedTime;

	for (int p = 0; p < points.size(); p++) {
		for (int i = 0; i < polyplay->polyvec.size(); i++) { //for every polygon
			for (int j = 0; j < polyplay->polyvec[i]->points.size(); j++) { //for every point in every polygon
				if (polyplay->RayVsSide(points[p], (points[p] + vel), polyplay->polyvec[i]->points[j], polyplay->polyvec[i]->points[(j + 1) % polyplay->polyvec[i]->points.size()], &intersectionP, &time)) {
					contact_side = polyplay->polyvec[i]->points[j] - polyplay->polyvec[i]->points[(j + 1) % polyplay->polyvec[i]->points.size()];
					times.push_back({ time, contact_side});
					std::sort(times.begin(), times.end(), [](const std::pair<float, olc::vf2d>& a, const std::pair<float, olc::vf2d>& b)
						{
							return a.first < b.first;
						});

					std::cout << contact_normal.x << ", " << contact_normal.y << std::endl;

					
					polyplay->CalculateNormal(
						times[0].second,
						vel,
						contact_normal
					);
					vel += contact_normal * olc::vf2d(std::abs(vel.x), std::abs(vel.y)) * (1 - times[0].first);
					

				}
				
			}
		}
		
	}
	

	
	
	
	for (int p = 0; p < points.size(); p++){
		points[p] += vel;
		
	}

	
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
		pge->DrawLine(points[i], points[i] + vel, olc::RED);
	}
}