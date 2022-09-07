void AVRCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Move_Y"), this, &AVRCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Move_X"), this, &AVRCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("TurnRate"), this, &AVRCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AVRCharacter::LookUpAtRate);
	PlayerInputComponent->BindAction(TEXT("Teleport"), IE_Pressed, this, &AVRCharacter::SetupTeleport);
	PlayerInputComponent->BindAction(TEXT("Teleport"), IE_Released, this, &AVRCharacter::BeginTeleport);
	PlayerInputComponent->BindAction(TEXT("GripLeft"), IE_Pressed, this, &AVRCharacter::GripLeft);
	PlayerInputComponent->BindAction(TEXT("GripLeft"), IE_Released, this, &AVRCharacter::ReleaseLeft);
	PlayerInputComponent->BindAction(TEXT("GripRight"), IE_Pressed, this, &AVRCharacter::GripRight);
	PlayerInputComponent->BindAction(TEXT("GripRight"), IE_Released, this, &AVRCharacter::ReleaseRight);
	PlayerInputComponent->BindAction(TEXT("TriggerRight"), EInputEvent::IE_Pressed, this, &AVRCharacter::RightTriggerPressed);
	PlayerInputComponent->BindAction(TEXT("TriggerRight"), EInputEvent::IE_Released, this, &AVRCharacter::RightTriggerReleased);
	PlayerInputComponent->BindAction(TEXT("TriggerLeft"), EInputEvent::IE_Pressed, this, &AVRCharacter::LeftTriggerPressed);
	PlayerInputComponent->BindAction(TEXT("TriggerLeft"), EInputEvent::IE_Released, this, &AVRCharacter::LeftTriggerPressed);

	PlayerInputComponent->BindAction(TEXT("ResetVR"), IE_Pressed, this, &AVRCharacter::ResetVR);
	PlayerInputComponent->BindAction<FFooDelegate>(TEXT("RotateLeft"), IE_Pressed, this, &AVRCharacter::Rotation,-30.f);
	PlayerInputComponent->BindAction<FFooDelegate>(TEXT("RotateRight"), IE_Pressed, this, &AVRCharacter::Rotation,30.f);
}