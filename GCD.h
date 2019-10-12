#pragma once

template <typename T>
T gcd(T a, T b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b); // 105 and 30
}
