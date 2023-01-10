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
		
		*_intersection = lineStart + t1 * (lineEnd - lineStart);
		*t = t1;
		
		

		if (t1 <= 1.0f && t1 >= 0.0f && t2 <= 1.0f && t2 >= 0.0f) {
			
			
			return true;
		}
		return false;
		
	}

	void Polyplay::CalculateNormal(const olc::vf2d &_side, const olc::vf2d &_velocity, olc::vf2d &_normal) {
		_normal.x = _side.y;
		_normal.y = -_side.x;
		if (_normal.y > 0.0f) {
			_normal.x = -_side.y;
			_normal.y = _side.x;
		}
		if (_velocity.x * _normal.x + _velocity.y * _normal.y > 0.0f) {
			_normal.x = -_side.y;
			_normal.y = _side.x;
		}
		if (std::abs(_velocity.x * _normal.x + _velocity.y * _normal.y) <= 0.00000001f) {
			if (_normal.y >= 0.0f) {
				_normal.x = -_side.y;
				_normal.y = _side.x;
			}
		}
		
		_normal = _normal.norm();
		
	}

	bool Polyplay::OnUserCreate()
	{
		
		//polyvec.push_back(new Polygon_{ { 20.0f, 20.0f }, {80.0f, 20.0f}, {80.0f, 200.0f}, {20.0f, 100.0f} });
		polyvec.push_back(new Polygon_{ { 100.0f, 50.0f }, {200.0f, 50.0f}, {200.0f, 60.0f}, {100.0f, 60.0f} });
		polyvec.push_back(new Polygon_{ { 50.0f, 50.0f }, {75.0f, 50.0f}, {50.0f, 75.0f} });
		polyvec.push_back(new Polygon_{ { 0.0f, 50.0f }, {50.0f, 50.0f}, {50.0f, 230.0f}, {0.0f, 230.0f} });
		polyvec.push_back(new Polygon_{ { 0.0f + 50.0f, 100.0f }, {100.0f + 50.0f, 200.0f}, {100.0f + 50.0f, 230.0f}, {0.0f + 50.0f, 230.0f} });
		polyvec.push_back(new Polygon_{ { 100.0f + 50.0f, 200.0f }, {200.0f + 50.0f, 200.0f}, {200.0f + 50.0f, 240.0f}, {100.0f + 50.0f, 240.0f} });
		Player = new DynamicPolygon_{ { 20.0f, 20.0f }, {30.0f, 20.0f}, {30.0f, 30.0f}, {20, 30 } };

		
		
		
		// Called once at the start, so create things here
		return true;
	}

	bool Polyplay::OnUserUpdate(float fElapsedTime)
	{
		Clear(olc::BLUE);
		Player->Update(this, fElapsedTime);
		
		

		for(int i = 0; i < polyvec.size(); i++)
			polyvec[i] -> Draw(this);
		Player->Draw(this);
		
		return true;
	}

