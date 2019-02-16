#pragma once
#include <chrono>

class Time {
private:
	double m_deltaTime;
	std::chrono::time_point<std::chrono::steady_clock> m_start;
	std::chrono::time_point<std::chrono::steady_clock> m_stop;
public:
	Time();
	~Time();

	inline const double getDeltaTime() const { return m_deltaTime; }

	friend class RedEngine;
private:
	void updateDeltaTime();
};

