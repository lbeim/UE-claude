// Copyright NM 2026
#include "SOSCInspectorPanel.h"

#include "OSCBridgeReceiver.h"

#include "Widgets/Views/SHeaderRow.h"
#include "Widgets/Views/STableRow.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SSpacer.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/SBoxPanel.h"

#define LOCTEXT_NAMESPACE "OSCBridgeEditor"

namespace OSCInspectorColumns
{
	const FName Address(TEXT("Address"));
	const FName ArgTypes(TEXT("ArgTypes"));
	const FName Hz(TEXT("Hz"));
	const FName LastValue(TEXT("LastValue"));
	const FName Count(TEXT("Count"));
	const FName LastSeen(TEXT("LastSeen"));
}

class SOSCInspectorRow : public SMultiColumnTableRow<TSharedPtr<FOSCBridgeAddressStats>>
{
public:
	SLATE_BEGIN_ARGS(SOSCInspectorRow) {}
		SLATE_ARGUMENT(TSharedPtr<FOSCBridgeAddressStats>, Item)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, const TSharedRef<STableViewBase>& OwnerTable)
	{
		Item = InArgs._Item;
		SMultiColumnTableRow<TSharedPtr<FOSCBridgeAddressStats>>::Construct(FSuperRowType::FArguments(), OwnerTable);
	}

	virtual TSharedRef<SWidget> GenerateWidgetForColumn(const FName& ColumnName) override
	{
		if (!Item.IsValid())
		{
			return SNullWidget::NullWidget;
		}

		auto MakeText = [](const FString& Str)
		{
			return SNew(STextBlock).Text(FText::FromString(Str)).Margin(FMargin(4, 2));
		};

		if (ColumnName == OSCInspectorColumns::Address)
		{
			return MakeText(Item->Address.ToString());
		}
		if (ColumnName == OSCInspectorColumns::ArgTypes)
		{
			return MakeText(Item->ArgTypeSignature);
		}
		if (ColumnName == OSCInspectorColumns::Hz)
		{
			return MakeText(FString::Printf(TEXT("%.1f"), Item->HzEMA));
		}
		if (ColumnName == OSCInspectorColumns::LastValue)
		{
			return MakeText(Item->LastValueDisplay);
		}
		if (ColumnName == OSCInspectorColumns::Count)
		{
			return MakeText(FString::Printf(TEXT("%lld"), Item->Count));
		}
		if (ColumnName == OSCInspectorColumns::LastSeen)
		{
			const double Since = FPlatformTime::Seconds() - Item->LastSeenSeconds;
			return MakeText(FString::Printf(TEXT("%.1fs"), Since));
		}
		return SNullWidget::NullWidget;
	}

private:
	TSharedPtr<FOSCBridgeAddressStats> Item;
};

void SOSCInspectorPanel::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(SVerticalBox)

		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(8, 6)
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.FillWidth(1.0f)
			[
				SNew(STextBlock)
				.Text_Lambda([this]() { return GetStatusText(); })
			]

			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(4, 0, 0, 0)
			[
				SNew(SButton)
				.Text(LOCTEXT("ClearStats", "Clear Stats"))
				.OnClicked(this, &SOSCInspectorPanel::OnClearStats)
			]
		]

		+ SVerticalBox::Slot()
		.FillHeight(1.0f)
		.Padding(4, 0, 4, 4)
		[
			SAssignNew(ListView, SListView<FStatsPtr>)
			.ListItemsSource(&Rows)
			.OnGenerateRow(this, &SOSCInspectorPanel::OnGenerateRow)
			.HeaderRow(
				SNew(SHeaderRow)

				+ SHeaderRow::Column(OSCInspectorColumns::Address)
				.DefaultLabel(LOCTEXT("ColAddress", "Address"))
				.FillWidth(0.36f)
				.SortMode_Lambda([this]() { return GetSortMode(OSCInspectorColumns::Address); })
				.OnSort(this, &SOSCInspectorPanel::OnSortColumn)

				+ SHeaderRow::Column(OSCInspectorColumns::ArgTypes)
				.DefaultLabel(LOCTEXT("ColArgTypes", "Types"))
				.FillWidth(0.08f)

				+ SHeaderRow::Column(OSCInspectorColumns::Hz)
				.DefaultLabel(LOCTEXT("ColHz", "Hz"))
				.FillWidth(0.08f)
				.SortMode_Lambda([this]() { return GetSortMode(OSCInspectorColumns::Hz); })
				.OnSort(this, &SOSCInspectorPanel::OnSortColumn)

				+ SHeaderRow::Column(OSCInspectorColumns::LastValue)
				.DefaultLabel(LOCTEXT("ColLastValue", "Last Value"))
				.FillWidth(0.32f)

				+ SHeaderRow::Column(OSCInspectorColumns::Count)
				.DefaultLabel(LOCTEXT("ColCount", "Count"))
				.FillWidth(0.08f)
				.SortMode_Lambda([this]() { return GetSortMode(OSCInspectorColumns::Count); })
				.OnSort(this, &SOSCInspectorPanel::OnSortColumn)

				+ SHeaderRow::Column(OSCInspectorColumns::LastSeen)
				.DefaultLabel(LOCTEXT("ColLastSeen", "Last Seen"))
				.FillWidth(0.08f)
			)
		]
	];

	RegisterActiveTimer(0.1f, FWidgetActiveTimerDelegate::CreateSP(this, &SOSCInspectorPanel::RefreshTick));
}

TSharedRef<ITableRow> SOSCInspectorPanel::OnGenerateRow(FStatsPtr Item, const TSharedRef<STableViewBase>& OwnerTable)
{
	return SNew(SOSCInspectorRow, OwnerTable).Item(Item);
}

EActiveTimerReturnType SOSCInspectorPanel::RefreshTick(double InCurrentTime, float InDeltaTime)
{
	AOSCBridgeReceiver* Receiver = AOSCBridgeReceiver::GetActiveReceiver();

	if (Receiver)
	{
		TArray<FOSCBridgeAddressStats> Snapshot = Receiver->GetAllAddressStats();
		Rows.Reset(Snapshot.Num());
		for (const FOSCBridgeAddressStats& S : Snapshot)
		{
			Rows.Add(MakeShared<FOSCBridgeAddressStats>(S));
		}
		SortRows();
	}
	else
	{
		Rows.Reset();
	}

	if (ListView.IsValid())
	{
		ListView->RequestListRefresh();
	}
	return EActiveTimerReturnType::Continue;
}

void SOSCInspectorPanel::OnSortColumn(EColumnSortPriority::Type Priority, const FName& Column, EColumnSortMode::Type Mode)
{
	SortColumn = Column;
	SortMode = Mode;
	SortRows();
	if (ListView.IsValid())
	{
		ListView->RequestListRefresh();
	}
}

EColumnSortMode::Type SOSCInspectorPanel::GetSortMode(const FName Column) const
{
	return SortColumn == Column ? SortMode : EColumnSortMode::None;
}

void SOSCInspectorPanel::SortRows()
{
	if (SortMode == EColumnSortMode::None)
	{
		return;
	}

	const bool bAscending = SortMode == EColumnSortMode::Ascending;
	const FName Col = SortColumn;

	Rows.Sort([Col, bAscending](const FStatsPtr& A, const FStatsPtr& B) -> bool
	{
		if (!A.IsValid() || !B.IsValid())
		{
			return false;
		}
		bool LessThan = false;
		if (Col == OSCInspectorColumns::Address)
		{
			LessThan = A->Address.LexicalLess(B->Address);
		}
		else if (Col == OSCInspectorColumns::Hz)
		{
			LessThan = A->HzEMA < B->HzEMA;
		}
		else if (Col == OSCInspectorColumns::Count)
		{
			LessThan = A->Count < B->Count;
		}
		return bAscending ? LessThan : !LessThan;
	});
}

FText SOSCInspectorPanel::GetStatusText() const
{
	AOSCBridgeReceiver* Receiver = AOSCBridgeReceiver::GetActiveReceiver();
	if (!Receiver)
	{
		return LOCTEXT("NoReceiver", "No active OSC Bridge Receiver in level");
	}

	return FText::FromString(FString::Printf(
		TEXT("%s:%d   %s   %d addresses"),
		*Receiver->ReceiveIPAddress,
		Receiver->Port,
		Receiver->IsListening() ? TEXT("● LISTENING") : TEXT("○ idle"),
		Rows.Num()));
}

FReply SOSCInspectorPanel::OnClearStats()
{
	if (AOSCBridgeReceiver* Receiver = AOSCBridgeReceiver::GetActiveReceiver())
	{
		Receiver->ClearStats();
		Rows.Reset();
		if (ListView.IsValid())
		{
			ListView->RequestListRefresh();
		}
	}
	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
