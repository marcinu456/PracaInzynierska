void ABoid::CalculateSeparation(FVector& Separation, ABoid* Boid) {
	FVector Sub = GetActorLocation() - Boid->GetActorLocation();
	Separation += Sub * Sub.GetSafeNormal().Size();
}

void ABoid::CalculateAlignment(FVector& Alignment, ABoid* Boid) {
	Alignment += Boid->GetActorForwardVector();
}

void ABoid::CalculateCohesion(FVector& Cohesion, ABoid* Boid) {
	Cohesion += Boid->GetActorLocation();
}