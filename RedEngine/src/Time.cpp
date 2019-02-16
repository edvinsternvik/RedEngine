#include "Time.h"
#include <iostream>

Time::Time() : m_start(std::chrono::high_resolution_clock::now()) {
}


Time::~Time() {
}

void Time::updateDeltaTime() {
	m_stop = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double, std::ratio<1, 1>> dur = m_stop - m_start;
	m_deltaTime = dur.count();

	m_start = std::chrono::high_resolution_clock::now();
}
