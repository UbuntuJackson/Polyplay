#define OLC_PGE_APPLICATION
#include "polyplay.h"
#include "entity.h"


	Polyplay::Polyplay()
	{
		sAppName = "Example";
	}

	bool Polyplay::RayVsSide(Ray* r, olc::vf2d* rayStart, olc::vf2d* rayEnd, olc::vf2d* _intersection, float* t) {
		
		olc::vf2d line_r1s = r->pos;
		olc::vf2d line_r1e = r->pos + r->vel;
		olc::vf2d line_r2s = *rayStart;
		olc::vf2d line_r2e = *rayEnd;

		float h = (line_r2e.x - line_r2s.x) * (line_r1s.y - line_r1e.y) - (line_r1s.x - line_r1e.x) * (line_r2e.y - line_r2s.y);
		float t1 = ((line_r2s.y - line_r2e.y) * (line_r1s.x - line_r2s.x) + (line_r2e.x - line_r2s.x) * (line_r1s.y - line_r2s.y)) / h;
		float t2 = ((line_r1s.y - line_r1e.y) * (line_r1s.x - line_r2s.x) + (line_r1e.x - line_r1s.x) * (line_r1s.y - line_r2s.y)) / h;
		
		

		

		if (t1 <= 1.0f && t1 >= 0.0f && t2 <= 1.0f && t2 >= 0.0f) {
			return true;
		}
		return false;
		
	}

	bool Polyplay::OnUserCreate()
	{
		
		polyvec.push_back(new Polygon_{ { 20.0, 20.0 }, {80.0, 20.0}, {80.0, 200.0}, {20.0, 100.0} });
		

		
		
		
		// Called once at the start, so create things here
		return true;
	}

	bool Polyplay::OnUserUpdate(float fElapsedTime)
	{
		Ray ray{ {100.0f, 20.0f} };
		float time;
		//olc::vf2d collisionNormal = nullptr;

		ray.vel = { float(GetMouseX()) - ray.pos.x, float(GetMouseY()) - ray.pos.y };

		Clear(olc::BLUE);

		
		

		olc::vf2d intersectionP;
		// called once per frame
		for (int i = 0; i < polyvec.size(); i++){
			for (int j = 0; j < polyvec[i]->points.size(); j++) {
				if(RayVsSide(&ray, &polyvec[i]->points[j], &polyvec[i]->points[(j + 1) % polyvec[i]->points.size()], &intersectionP, &time)){
					DrawLine(ray.pos.x, ray.pos.y, ray.pos.x + ray.vel.x, ray.pos.y + ray.vel.y , olc::WHITE);
					std::cout << "1" << std::endl;
					
				}
				else {
					DrawLine(ray.pos.x, ray.pos.y, float(GetMouseX()), float(GetMouseY()), olc::YELLOW);
					std::cout << "0" << std::endl;
					
				}
			}
		}

		

		for(int i = 0; i < polyvec.size(); i++)
			polyvec[i] -> Draw(this);
		
		return true;
	}

