unsigned gcd(unsigned a, unsigned b)
{
	if (a == 0)
	{
		return b;
	}
	if (b == 0)
	{
		return a;
	}
	if (a > b)
	{
		return gcd(b,a%b);
	}
	else
	{
		return gcd(a, b%a);
	}
}