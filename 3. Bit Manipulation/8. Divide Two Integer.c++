#include<bits/stdc++.h>
using namespace std;

//Que.- You are given two integers, ‘dividend’ and ‘divisor’. You are required to divide
//      the integers without using multiplication, division, and modular operators.

//Time : ~O(logN)^2
//Space : O(1)

int divideTwoInteger(int dividend, int divisor) {
	if(dividend == divisor)
		return 1;

	bool sign = true;
	if(dividend < 0 && divisor > 0)
		sign = false;
	if(dividend >= 0 && divisor < 0)
		sign = false;

	int n = abs(dividend), d = abs(divisor);
	long ans = 0;

	while(n >= d){
		int cnt = 0;
		while(n >= (d << (cnt+1)))
			cnt++;

		ans += (1 << cnt);
		n -= (d << cnt);
	}

	if(ans == (1 << 31) && sign == true)
		return INT_MAX;
	if(ans == (1 << 31) && sign == false)
		return INT_MIN;

	return sign ? ans : -ans;
}