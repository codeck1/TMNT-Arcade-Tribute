#include <vector>
#pragma once

using namespace std;

class Animation
{
public:
	bool loop = true;
	float speed = 1.0f;
	int pivot = 0;
	int pivotY = 0;
	int mirror = 1;
	vector<SDL_Rect> frames;

private:
	float current_frame = 0.0f;
	int loops = 0;

public:
	Animation()
	{}

	Animation(const Animation& anim) : loop(anim.loop), speed(anim.speed), frames(anim.frames), pivot(anim.pivot), pivotY(anim.pivotY)
	{}

	SDL_Rect& GetCurrentFrame()
	{
		float last_frame = (float) frames.size();

		current_frame += speed;
		if (current_frame >= last_frame)
		{
			current_frame = (loop) ? 0.0f : MAX(last_frame - 1.0f, 0.0f);
			loops++;
		} 

		return frames[(int)current_frame];
	}

	bool Finished() const
	{
		return loops > 0;
	}

	void Reset()
	{
		loops = 0;
		current_frame = 0.0f;
	}
};