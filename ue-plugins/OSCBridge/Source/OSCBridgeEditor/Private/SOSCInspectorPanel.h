// Copyright NM 2026
#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Views/SListView.h"
#include "UObject/WeakObjectPtr.h"

class AOSCBridgeReceiver;
struct FOSCBridgeAddressStats;

class SOSCInspectorPanel : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SOSCInspectorPanel) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

private:
	using FStatsPtr = TSharedPtr<FOSCBridgeAddressStats>;

	TSharedRef<ITableRow> OnGenerateRow(FStatsPtr Item, const TSharedRef<STableViewBase>& OwnerTable);
	EActiveTimerReturnType RefreshTick(double InCurrentTime, float InDeltaTime);

	void OnSortColumn(EColumnSortPriority::Type Priority, const FName& Column, EColumnSortMode::Type Mode);
	EColumnSortMode::Type GetSortMode(const FName Column) const;
	void SortRows();

	FText GetStatusText() const;
	FReply OnClearStats();

	TArray<FStatsPtr> Rows;
	TSharedPtr<SListView<FStatsPtr>> ListView;

	FName SortColumn = FName(TEXT("Address"));
	EColumnSortMode::Type SortMode = EColumnSortMode::Ascending;
};
