#pragma once
#include <chrono>

class Time {
private:
	static Time* instance;

	double m_deltaTime;
	std::chrono::high_resolution_clock::time_point m_start;
	std::chrono::high_resolution_clock::time_point m_stop;
	Time();
public:
	static Time* Instantiate();

	inline static const double getDeltaTime() { return instance->m_deltaTime; }

	friend class RedEngine;
private:
	void updateDeltaTime();
};

