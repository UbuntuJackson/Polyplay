#pragma once

#include "olcPixelGameEngine.h"

class Polyplay : public olc::PixelGameEngine
{
public:
	Polyplay();

public:
	bool OnUserCreate();

	bool OnUserUpdate(float fElapsedTime);
};