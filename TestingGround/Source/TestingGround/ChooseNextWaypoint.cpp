// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Get Patrol route
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();
	if (!ensure(PatrolRoute)) { EBTNodeResult::Failed; }
	auto PatrollingPoints = PatrolRoute->GetPatrolPoints();
	if (PatrollingPoints.Num() == 0 ) 
	{
		UE_LOG(LogTemp, Warning, TEXT("No Patrolling Points Assigned!"))
		EBTNodeResult::Failed;
	}

	//Set New Waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrollingPoints[Index]);

	//Cycle Index
	auto NextIndex = (Index + 1) % (PatrollingPoints.Num());
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	return EBTNodeResult::Succeeded;
}
