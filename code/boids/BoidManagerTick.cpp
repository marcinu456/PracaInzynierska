void ABoidManager::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	
	if (ManagedBoids.Num() != 0) {
		for (ABoid* Boid : ManagedBoids) {
			Boid->CalculateBoidRotation();
			Boid->UpdateBoidRotation(DeltaTime);
			Boid->CalculateBoidPosition(DeltaTime);
			Boid->UpdateBoidPosition();
		}
	}
}