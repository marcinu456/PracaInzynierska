void APendulum::computeAnglesEuler(float dt)
{
	double u = 1 + mass0 + mass1;
	theta0bis =
		(g * (sin(theta1) * cos(theta0 - theta1) - u * sin(theta0))
			- (length1 * pow(theta1prim, 2) + length0 * pow(theta0prim, 2) * cos(theta0 - theta1)) * sin(theta0 - theta1))
		/ (length0 * (u - pow(cos(theta0 - theta1), 2)));
	theta1bis =
		(g * u * (sin(theta0) * cos(theta0 - theta1) - sin(theta1)) + (u * length0 * pow(theta0prim, 2)
			+ length1 * pow(theta1prim, 2) * cos(theta0 - theta1)) * sin(theta0 - theta1))
		/ (length1 * (u - pow(cos(theta0 - theta1), 2)));


	theta0prim = theta0prim + theta0bis * dt;
	theta1prim = theta1prim + theta1bis * dt;

	theta0 = theta0 + theta0prim * dt;
	theta1 = theta1 + theta1prim * dt;
}