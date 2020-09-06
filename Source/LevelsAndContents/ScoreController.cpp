#include "ScoreController.h"
#include "Blueprint/UserWidget.h"
#include "TextWidgetTypes.h"
#include "TextBlock.h"

// Sets default values
AScoreController::AScoreController() :
	score(0)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AScoreController::BeginPlay()
{
	Super::BeginPlay();

	if (ScoreTextWidget) // Check if the Asset is assigned in the blueprint.
	{
		// Create the widget and store it.
		pScoreTextWidget = CreateWidget<UUserWidget>(GetGameInstance(), ScoreTextWidget);
		
		// now you can use the widget directly since you have a reference for it.
		// Extra check to  make sure the pointer holds the widget.
		if (pScoreTextWidget.IsValid())
		{
			// let add it to the view port
			pScoreTextWidget->AddToViewport();

			// and retrieve the TextBlock widget within it
			pScoreText = (UTextBlock*) pScoreTextWidget->GetWidgetFromName("ScoreText");
		}
	}
}

// Called every frame
void AScoreController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AScoreController::IncreaseScore(int amount)
{
	// Increase the score and update the text widget
	if (pScoreText.IsValid()) {
		score += amount;
		pScoreText->SetText(FText::FromString(FString::FromInt(score)));
	}
}
