if (Rabbits.Num() == 0)
{
	const FVector Origin = GetActorLocation();
	TArray<UStaticMeshComponent*> Components;
	RabbitActor.GetDefaultObject()->GetComponents<UStaticMeshComponent>(Components);
	ensure(Components.Num() > 0);
	for (int i = 0; i < RABBIT_COUNT; i++) {
		const FVector Loc(Origin.X + FMath::RandRange(-50, 50), Origin.Y + FMath::RandRange(-50, 50), Origin.Z);
		auto const SpawnedActorRef = GetWorld()->SpawnActor<ARabbitAgent>(RabbitActor, Loc, GetActorRotation());
		if (SpawnedActorRef)
		{
			SpawnedActorRef->hp = RABBIT_MAX_HUNGRY_HP_LEVEL;
			SpawnedActorRef->SetUpAgent(true);
		}
	}
}