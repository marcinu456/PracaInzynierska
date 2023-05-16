FVector AButterflyActor::UpdatePosition(FVector position)
{
	float LocalDeltaTime = ButterflyChange;

	position.X = (position.X + sigma * (position.Y - position.X) * LocalDeltaTime);
	position.Y = (position.Y + (-position.X * position.Z + rho * position.X - position.Y) * LocalDeltaTime);
	position.Z = (position.Z + (position.X * position.Y - beta * position.Z) * LocalDeltaTime);

	return position;
}