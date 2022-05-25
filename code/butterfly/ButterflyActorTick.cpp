void AButterflyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DeltaTime = ButterflyChange;
	auto position = GetActorLocation();

	position.X = (position.X + sigma * (position.Y - position.X) * DeltaTime);
	position.Y = (position.Y + (-position.X * position.Z + rho * position.X - position.Y) * DeltaTime);
	position.Z = (position.Z + (position.X * position.Y - beta * position.Z) * DeltaTime);

	SetActorLocation(position);
}