void ACellActor::Update()
{
	if (AliveNext) {
		StaticMeshComponent->SetMaterial(0, ClickedMaterial);
		Alive = true;
		SetActorHiddenInGame(false);
	}
	else {
		SetActorHiddenInGame(true);
		StaticMeshComponent->SetMaterial(0, EndCursorOverMaterial);
		Alive = false;
	}
}