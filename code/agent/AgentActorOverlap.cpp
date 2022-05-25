void ARabbitAgent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	if (Cast<APlantAgent>(OtherActor) == atractorPlant && atractorPlant)
	{
		atractorPlant->OnDestroy();
		hp = RABBIT_MAX_HP;
		atractorPlant = nullptr;
	}
	else if (Cast<ARabbitAgent>(OtherActor) == atractorRabbit && atractorRabbit)
	{
		hp = RABBIT_MAX_HUNGRY_HP_LEVEL;
		atractorRabbit->hp = RABBIT_MAX_HUNGRY_HP_LEVEL;
		for (int j = 0; j < RABBIT_REPRODUCE_COUNT; j++) {
			const FVector Loc(GetActorLocation().X + FMath::RandRange(-50, 50), GetActorLocation().Y + FMath::RandRange(-50, 50), GetActorLocation().Z);
			auto const SpawnedActorRef = GetWorld()->SpawnActor<ARabbitAgent>(RabbitActor, Loc, GetActorRotation());
			if (SpawnedActorRef)
			{
				SpawnedActorRef->hp = RABBIT_MAX_HUNGRY_HP_LEVEL;
				SpawnedActorRef->SetUpAgent(true);
			}

		}
		atractorRabbit = nullptr;
	}
}