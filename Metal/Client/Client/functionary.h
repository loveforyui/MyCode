#pragma once

template <typename T>
void SafeDelete(T& obj)
{
	if (obj)
	{
		delete obj;
		obj = nullptr;
	}
}

template <typename T>
T _Distance(T x1, T y1, T x2, T y2)
{
    T result = sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
    return result;
}