void ARabbitAgent::Move()
{
	Super::Move();

	float ConstantZ = GetActorLocation().Z;

	if (hp <= RABBIT_MAX_HUNGRY_HP_LEVEL) {
		TArray<AActor*> Plants;

		UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlantAgent::StaticClass(), Plants);
		if (Plants.Num() > 0) {
			size_t atractorIndex = 0;
			auto atractor = Cast<APlantAgent>(Plants[atractorIndex])->GetActorLocation() - GetActorLocation();
			float atractortDist = atractor.Size();
			for (int j = 1; j < Plants.Num(); j++) {
				auto* plant = Cast<APlantAgent>(Plants[j]);
				FVector vec = plant->GetActorLocation() - GetActorLocation();
				float dist = vec.Size();
				if (dist < atractortDist) {
					atractorIndex = j;
					atractor = vec;
					atractortDist = dist;
				}
			}
			SetActorLocation(GetActorLocation() + atractor / atractortDist * RABBIT_VELOCITY);

			atractorPlant = Cast<APlantAgent>(Plants[atractorIndex]);
		}
	}
	else {
		TArray<AActor*> Rabbits;

		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ARabbitAgent::StaticClass(), Rabbits);

		int i = 0;
		for (int j = 0; j < Rabbits.Num(); j++) {

			if (Cast<ARabbitAgent>(Rabbits[j]) == this)
			{
				i = j;
				break;
			}

		}

		size_t atractorIndex = 0;
		auto atractor = GetActorLocation();
		float atractortDist = 1000;
		for (int j = 1; j < Rabbits.Num(); j++) {
			auto partner = Cast<ARabbitAgent>(Rabbits[j]);
			auto vec = partner->GetActorLocation() - GetActorLocation();
			float dist = vec.Size();
			if (dist < atractortDist && partner->hp > RABBIT_MAX_HUNGRY_HP_LEVEL && j != i) {
				atractorIndex = j;
				atractor = vec;
				atractortDist = dist;
			}
		}
		auto partner = Cast<ARabbitAgent>(Rabbits[atractorIndex]);
		if (this != partner) {
			SetActorLocation(GetActorLocation() + atractor / atractortDist * RABBIT_VELOCITY);

			atractorRabbit = partner;

		}
	}

	SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, ConstantZ));

	if (hp != 0) {
		hp--;
	}
	else {
		OnDestroy();
	}
}