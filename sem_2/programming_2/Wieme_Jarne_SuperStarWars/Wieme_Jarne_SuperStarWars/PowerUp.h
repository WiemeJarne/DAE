#pragma once
class Texture;

class PowerUp final
{
public:
	explicit PowerUp(const Point2f& bottomLeftPos);
	PowerUp(const PowerUp& powerUp) = delete;
	PowerUp(PowerUp&& powerUp) = delete;
	~PowerUp();

	PowerUp& operator=(const PowerUp& rhs) = delete;
	PowerUp& operator=(PowerUp&& rhs) = delete;

	void Draw( ) const;
	bool IsOverlapping(const Rectf& rect) const;

private:
	const Texture* m_pTexture;
	Rectf m_Shape;
};


