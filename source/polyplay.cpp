#define OLC_PGE_APPLICATION
#include "polyplay.h"
#include "entity.h"


	Polyplay::Polyplay()
	{
		sAppName = "Example";
	}

	bool Polyplay::RayVsSide(olc::vf2d lineStart, olc::vf2d lineEnd, olc::vf2d rayStart, olc::vf2d rayEnd, olc::vf2d* _intersection, float* t) {
		
		olc::vf2d line_r1s = lineStart;
		olc::vf2d line_r1e = lineEnd;
		olc::vf2d line_r2s = rayStart;
		olc::vf2d line_r2e = rayEnd;

		float h = (line_r2e.x - line_r2s.x) * (line_r1s.y - line_r1e.y) - (line_r1s.x - line_r1e.x) * (line_r2e.y - line_r2s.y);
		float t1 = ((line_r2s.y - line_r2e.y) * (line_r1s.x - line_r2s.x) + (line_r2e.x - line_r2s.x) * (line_r1s.y - line_r2s.y)) / h;
		float t2 = ((line_r1s.y - line_r1e.y) * (line_r1s.x - line_r2s.x) + (line_r1e.x - line_r1s.x) * (line_r1s.y - line_r2s.y)) / h;
		
		

		

		if (t1 <= 1.0f && t1 >= 0.0f && t2 <= 1.0f && t2 >= 0.0f) {
			*t = t1;
			return true;
		}
		return false;
		
	}

	void Polyplay::CalculateNormal(olc::vf2d &_side, olc::vf2d &_velocity, olc::vf2d &_normal) {
		_normal.x = -_side.y;
		_normal.y = _side.x;
		if (_velocity.x * _side.x + _velocity.y * _side.y < 0.0f) {
			_normal.x = _side.y;
			_normal.y = -_side.x;
		}
		_normal = {
			_normal.x / (sqrtf(_normal.x * _normal.x + _normal.y * _normal.y)), _normal.y / (sqrtf(_normal.x * _normal.x + _normal.y * _normal.y))
		};
		
	}

	bool Polyplay::OnUserCreate()
	{
		
		polyvec.push_back(new Polygon_{ { 20.0f, 20.0f }, {80.0f, 20.0f}, {80.0f, 200.0f}, {20.0f, 100.0f} });
		Player = new DynamicPolygon_{ { 200.0f, 200.0f }, {220.0f, 220.0f}, {200.0f, 210.0f} };

		
		
		
		// Called once at the start, so create things here
		return true;
	}

	bool Polyplay::OnUserUpdate(float fElapsedTime)
	{
		
		Player->Update(this, fElapsedTime);
		
		Clear(olc::BLUE);

		for(int i = 0; i < polyvec.size(); i++)
			polyvec[i] -> Draw(this);
		Player->Draw(this);
		
		return true;
	}

