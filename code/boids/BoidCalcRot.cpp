void ABoid::CalculateBoidRotation() {
	TArray<ABoid*> CloseBoids = CalculateClosestBoids(AmountOfBoidsToObserve);
	FVector InterpolatedForwardVector = FVector::ZeroVector;
	FVector AlignmentVector = FVector::ZeroVector;
	FVector CohesionVector = FVector::ZeroVector;
	FVector SeparationVector = FVector::ZeroVector;
	FVector TargetVector = FVector::ZeroVector;

	if (CloseBoids.Num() != 0) {
		for (int index = 0; index < CloseBoids.Num(); index++) {
			ABoid* Boid = CloseBoids[index];
			CalculateAlignment(AlignmentVector, Boid);
			CalculateCohesion(CohesionVector, Boid);
			CalculateSeparation(SeparationVector, Boid);
		}
		AlignmentVector /= CloseBoids.Num();
		CohesionVector /= CloseBoids.Num();
		SeparationVector /= CloseBoids.Num();

		AlignmentVector.Normalize();
		CohesionVector.Normalize();
		SeparationVector.Normalize();
	}

	if (Manager->IsBoidsFollowTarget()) {
		TargetVector = CalculateTarget();
	}
	
	InterpolatedForwardVector += AlignmentVector * Manager->GetAlignmentWeight();
	InterpolatedForwardVector += CohesionVector * Manager->GetCohesionWeight();
	InterpolatedForwardVector += SeparationVector * Manager->GetSeparationWeight();
	InterpolatedForwardVector += TargetVector * Manager->GetTargetWeight();
	InterpolatedForwardVector *= TurnSpeed;
	InterpolatedForwardVector.Normalize();
	NextBoidRotation = UKismetMathLibrary::MakeRotFromX(InterpolatedForwardVector);
}