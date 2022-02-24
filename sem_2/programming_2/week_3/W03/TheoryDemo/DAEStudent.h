#pragma once
#include "Person.h"
class DAEStudent final : public Person
{
public:
	enum class Major{GD, SD, GGP, IGP, VFX, ANI};

	DAEStudent(const std::string& firstName, const std::string& lastName, Major major);
	~DAEStudent();

	void Identify() const;

private:
	std::string GetName() const;
	Major m_Major;
};