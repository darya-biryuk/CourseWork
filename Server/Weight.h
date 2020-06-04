#pragma once
class Weight
{
private:
	float w;
public:
	Weight();
	~Weight();
	void setWeight(float w)
	{
		this->w = w;
	}
	float getWeight() { return w; }
	};

