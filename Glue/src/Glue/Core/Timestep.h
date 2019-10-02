#pragma once

#include <iostream>

namespace Glue
{
	class Timestep
	{
	private:
		float m_Time;
	public:
		Timestep(float time = 0.0f)
			: m_Time(time)
		{	
		}

		operator float() const { return m_Time; }

		float GetSeconds() const {  return m_Time; }
		float GetMillis() const { return m_Time * 1000.0f; }
	};
}