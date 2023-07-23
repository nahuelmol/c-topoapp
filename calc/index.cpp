using std::cout;


float MagneticInclination(int mlat, char type[]){
	char rad[] = "rad";
	if(type == rad){
		mlat = mlat * R2D;
	}

	float m_inclination = atan(2 * tan(mlat));

	return m_inclination;
}

float MagneticLatitud(int micl, char type[]){
	char rad[] = "rad";
	if (type == rad){
		micl = micl * R2D;
	}

	float m_latitud = atan((tan(micl))/2);

	return m_latitud;
}

float PaleomagneticLongitud(float mlat, float dec, float plat, float xlong){
	float plon;
	plon = asin((cos(mlat) * sin(dec))/cos(plat)) + xlong;

	return plon;

}

float PaleomagneticLatitud(float l_geographic, float l_magnetic, float dec){
	float platitud;

	platitud = asin(sin(l_geographic) * sin(l_magnetic) + cos(l_geographic) * cos(l_magnetic) * cos(dec));
	return platitud;

}

float theorigravity(float disNS, float xlong){
	float CT = CCT * sin(2 * xlong) * disNS;

	return CT;
}

float BouguerAnomaly(float disER){
	float CAL = GVGT * disER;
	return CAL;
}

float AirAnomamly(){
	return 0.0;
}

float BoguerCorrection(float disER){
	float CB = 2 * PI * RHO * (CUG * exp(-11)) * disER;
	return CB;
}

