class __declspec(dllexport) Float2
{
public:
	Float2(float x, float y);
	float GetX();
	float GetY();

private:
	float m_x{};
	float m_y{};
};