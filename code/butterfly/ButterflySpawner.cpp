for (size_t i = 0; i < numberOfButterfly; i++)
{
	const FVector Loc(Origin.X + i * 15, Origin.Y, Origin.Z);
	AButterflyActor* const SpawnedActorRef = GetWorld()->SpawnActor<AButterflyActor>(ButterflyActor, Loc, GetActorRotation());
	ButterflyActors.Add(SpawnedActorRef);
}