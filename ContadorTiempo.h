#pragma once
#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>
using namespace std;



class ContadorTiempo {
	public:
		std::chrono::time_point<std::chrono::system_clock> m_StartTime;
		std::chrono::time_point<std::chrono::system_clock> m_EndTime;
		bool m_bRunning = false;
    void start()
    {
        m_StartTime = std::chrono::system_clock::now();
        m_bRunning = true;
    }
    
    void stop()
    {
        m_EndTime = std::chrono::system_clock::now();
        m_bRunning = false;
    }

	double elapsedMilliseconds()
	{
		std::chrono::time_point<std::chrono::system_clock> endTime;

		if (m_bRunning)
		{
			endTime = std::chrono::system_clock::now();
		}
		else
		{
			endTime = m_EndTime;
		}

		return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_StartTime).count();
	}

	double elapsedSeconds()
	{
		return elapsedMilliseconds() / 1000.0;
	}
};