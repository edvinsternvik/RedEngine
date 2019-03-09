#pragma once
#include <chrono>

class Time {
private:
	static Time* instance;

	double m_deltaTime;
	std::chrono::time_point<std::chrono::steady_clock> m_start;
	std::chrono::time_point<std::chrono::steady_clock> m_stop;
	Time();
public:
	static Time* getInstance();

	inline static const double getDeltaTime() { return instance->m_deltaTime; }

	friend class RedEngine;
private:
	void updateDeltaTime();
};

