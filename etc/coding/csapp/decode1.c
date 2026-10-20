void decode1(long *xp, long *yp, long *zp) {
	//x become z, z becomes y, y becomes x
	long x = *xp;
	long y = *yp;
	long z = *zp;
	*yp = x;
	*zp = y;
	*xp = z;
	return
}

