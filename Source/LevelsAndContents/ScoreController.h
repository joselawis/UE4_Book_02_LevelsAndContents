#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScoreController.generated.h"


UCLASS()
class LEVELSANDCONTENTS_API AScoreController : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AScoreController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Reference UMG Asset in the Editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> ScoreTextWidget;

	// Variable to hold the widget after creating it
	TWeakObjectPtr<class UUserWidget> pScoreTextWidget;

	// Variable to hold specifically the score TextBlock in the widget
	TWeakObjectPtr<class UTextBlock> pScoreText;

	// Increase the internal score the specified amount
	UFUNCTION(BlueprintCallable, Category = "Score")
	void IncreaseScore(int amount);

private:
	int score;
};
