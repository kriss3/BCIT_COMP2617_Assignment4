#pragma once

template <typename T>
T gcd(T a, T b)
{
	if (b == 0)
	{
		return a;
	}
		
	return gcd(abs(b), abs(a) % abs(b));
}
