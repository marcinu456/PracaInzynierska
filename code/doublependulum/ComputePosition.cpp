void APendulum::computePosition()
{
	x0 = px + length0 * FMath::Sin(theta0);
	y0 = py + length0 * FMath::Cos(theta0);

	x1 = x0 + length1 * FMath::Sin(theta1);
	y1 = y0 + length1 * FMath::Cos(theta1);
	
	auto Frector = GetActorLocation();
	FVector StarPos1 = { Frector.X, px,py, };
	FVector EndPos1 = { Frector.X, x0, y0, };
	FVector EndPos2 = { Frector.X,x1, y1, };

	TArray<FVector> Path;
	Path.Add(StarPos1);
	Path.Add(EndPos1);
	Path.Add(EndPos2);

	FirstColumn->ClearSplinePoints(false);
	int32 index = 0;
	for (auto& Point : Path)
	{
		FVector LocalPosition = FirstColumn->GetComponentTransform().InverseTransformPosition(Point);
		FirstColumn->AddPoint(FSplinePoint(index, LocalPosition, ESplinePointType::Constant), false);
		index++;
	}

	FirstColumn->UpdateSpline();

	int32 SegmentNum = Path.Num() - 1;
	for (int32 i = 0; i < SegmentNum; ++i)
	{
		if (ColumnsPathMeshPool.Num() <= i)
		{
			USplineMeshComponent* SplineMesh = NewObject<USplineMeshComponent>(this);
			SplineMesh->SetMobility(EComponentMobility::Movable);
			SplineMesh->AttachToComponent(FirstColumn, FAttachmentTransformRules::KeepRelativeTransform);
			SplineMesh->SetStaticMesh(FirstColumnArchMesh);
			SplineMesh->SetMaterial(0, FirstColumnArchMaterial);
			SplineMesh->RegisterComponent();

			ColumnsPathMeshPool.Add(SplineMesh);
		}

		USplineMeshComponent* SplineMesh = ColumnsPathMeshPool[i];
		SplineMesh->SetVisibility(true);

		FVector StarPos, StartTangent, EndPos, EndTangent;
		FVector Tangent = { 0,0,0 };
		FirstColumn->GetLocalLocationAndTangentAtSplinePoint(i, StarPos, StartTangent);
		FirstColumn->GetLocalLocationAndTangentAtSplinePoint(i + 1, EndPos, EndTangent);
		SplineMesh->SetStartAndEnd(StarPos, Tangent, EndPos, Tangent);
	}
}