// Copyright NM 2026
#include "OSCBridgeEditorLog.h"
#include "SOSCInspectorPanel.h"

#include "Editor.h"
#include "EngineUtils.h"
#include "Engine/World.h"
#include "Framework/Docking/TabManager.h"
#include "Modules/ModuleManager.h"
#include "Styling/AppStyle.h"
#include "Widgets/Docking/SDockTab.h"
#include "WorkspaceMenuStructure.h"
#include "WorkspaceMenuStructureModule.h"

#include "OSCBridgeReceiver.h"

DEFINE_LOG_CATEGORY(LogOSCBridgeEditor);

#define LOCTEXT_NAMESPACE "OSCBridgeEditor"

static const FName OSCInspectorTabName(TEXT("OSCBridgeInspector"));

class FOSCBridgeEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override
	{
		FGlobalTabmanager::Get()->RegisterNomadTabSpawner(
				OSCInspectorTabName,
				FOnSpawnTab::CreateRaw(this, &FOSCBridgeEditorModule::SpawnInspectorTab))
			.SetDisplayName(LOCTEXT("InspectorTabTitle", "OSC Inspector"))
			.SetTooltipText(LOCTEXT("InspectorTabTooltip", "Live view of OSC messages received by OSC Bridge Receivers in the current world."))
			.SetGroup(WorkspaceMenu::GetMenuStructure().GetDeveloperToolsMiscCategory())
			.SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), TEXT("Icons.Visible")));

		BeginPIEHandle = FEditorDelegates::BeginPIE.AddRaw(this, &FOSCBridgeEditorModule::HandleBeginPIE);
		EndPIEHandle   = FEditorDelegates::EndPIE.AddRaw(this, &FOSCBridgeEditorModule::HandleEndPIE);
	}

	virtual void ShutdownModule() override
	{
		FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(OSCInspectorTabName);

		if (BeginPIEHandle.IsValid())
		{
			FEditorDelegates::BeginPIE.Remove(BeginPIEHandle);
		}
		if (EndPIEHandle.IsValid())
		{
			FEditorDelegates::EndPIE.Remove(EndPIEHandle);
		}
	}

private:
	TSharedRef<SDockTab> SpawnInspectorTab(const FSpawnTabArgs& Args)
	{
		return SNew(SDockTab)
			.TabRole(ETabRole::NomadTab)
			[
				SNew(SOSCInspectorPanel)
			];
	}

	void HandleBeginPIE(bool bIsSimulating)
	{
		AOSCBridgeReceiver* Active = AOSCBridgeReceiver::GetActiveReceiver();
		if (Active && Active->IsListening())
		{
			UE_LOG(LogOSCBridgeEditor, Display, TEXT("PIE starting — stopping editor-mode OSC receiver to free port."));
			Active->StopListening();
			bWasEditorListening = true;
		}
	}

	void HandleEndPIE(bool bIsSimulating)
	{
		if (!bWasEditorListening || !GEditor)
		{
			return;
		}
		bWasEditorListening = false;

		UWorld* EditorWorld = GEditor->GetEditorWorldContext().World();
		if (!EditorWorld)
		{
			return;
		}

		for (TActorIterator<AOSCBridgeReceiver> It(EditorWorld); It; ++It)
		{
			AOSCBridgeReceiver* R = *It;
			if (R && R->bListenInEditor && !R->IsListening())
			{
				UE_LOG(LogOSCBridgeEditor, Display, TEXT("PIE ended — resuming editor-mode OSC receiver."));
				R->StartListening();
			}
		}
	}

	FDelegateHandle BeginPIEHandle;
	FDelegateHandle EndPIEHandle;
	bool bWasEditorListening = false;
};

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOSCBridgeEditorModule, OSCBridgeEditor);
