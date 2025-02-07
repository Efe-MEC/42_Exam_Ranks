unsigned char	reverse_bits(unsigned char octet)
{
	unsigned int	i;
	unsigned char	res = 0;

	i = 8;
	while (i--)
	{
		res = (res << 1) | (octet & 1);
		octet = octet >> 1;
	}
	return (res);
}