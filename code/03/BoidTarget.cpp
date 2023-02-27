#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoidTarget.generated.h"

UCLASS()
class PRAYVR_API ABoidTarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoidTarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UStaticMeshComponent* Mesh;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
