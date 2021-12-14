#pragma once
class BouncingCircle;

class Box
{
public:
	Box(const Rectf boundingRect);
	~Box();
	void Draw();
	void Update(float elapsedSec);

private:
	Rectf m_BoundingRect;
	static const int m_AmountOfCircles{ 5 };
	BouncingCircle* m_PtrCircles[m_AmountOfCircles];
};

