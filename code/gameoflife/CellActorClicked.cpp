void ACellActor::Clicked()
{
		if (Alive) {
			StaticMeshComponent->SetMaterial(0, BeginCursorOverMaterial);
			Alive = false;
		}
		else {
			StaticMeshComponent->SetMaterial(0, ClickedMaterial);
			Alive = true;
		}
}