// Copyright 2015-2018 Piperift. All Rights Reserved.
#pragma once

#include "IPropertyTypeCustomization.h"
#include "PropertyHandle.h"
#include "SListView.h"


class FRelationDatabaseCustomization : public IPropertyTypeCustomization
{

public:

	/**
	* Creates a new instance.
	*
	* @return A new struct customization for Anchor Type.
	*/
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	/** IPropertyTypeCustomization interface */
	virtual void CustomizeHeader(TSharedRef<class IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<class IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder& StructBuilder, IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;

	TSharedRef<SWidget> MakeColumnWidget(uint32 RelationIndex, FName ColumnName);

private:

	TSharedRef<SWidget> CreateFactionWidget(TSharedRef<IPropertyHandle> PropertyHandle);

	/** Make the widget for a row entry in the data table row list view */
	TSharedRef<ITableRow> MakeRelationWidget(TSharedPtr<uint32> RelationIndex, const TSharedRef<STableViewBase>& OwnerTable);

	void OnRelationsScrolled(double InScrollOffset);

	void OnRelationSelected(TSharedPtr<uint32> InNewSelection, ESelectInfo::Type InSelectInfo);

	void RefreshRelations();

	void OnFactionFilterChanged(const FText& Text, FName Faction);

	FReply OnNewRelation();
	FReply OnDeleteRelation(uint32 Index);
	FReply OnClearRelations();


	/** Handle to the struct properties being customized */
	TSharedPtr<IPropertyHandle> StructHandle;
	TSharedPtr<IPropertyHandle> ListHandle;
	TSharedPtr<IPropertyHandleArray> ListHandleArray;


	/** Array of the relations that are available for editing */
	TArray<TSharedPtr<uint32>> AvailableRelations;

	/** Array of the relations that are available for editing */
	TArray<TSharedPtr<uint32>> VisibleRelations;

	/** List view responsible for showing the rows in VisibleRows for each entry in AvailableColumns */
	TSharedPtr<SListView<TSharedPtr<uint32>>> RelationListView;


	static const FName FactionAId;
	static const FName FactionBId;
	static const FName AttitudeId;
	static const FName DeleteId;
};

