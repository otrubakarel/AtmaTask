#include "Combat/HealthWidget.h"
#include "Components/ProgressBar.h"

void UHealthWidget::SetHealthPercent(float HealthPercent)
{
	HealthBar->SetPercent(HealthPercent);
}
