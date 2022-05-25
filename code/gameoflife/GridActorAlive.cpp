void AGridActor::UpdateAliveNext(const int Index, const int NumAliveNeighbors) 
{
	const bool IsAlive = CellActors[Index]->GetAlive();
	if (IsAlive && (NumAliveNeighbors < 2))
	{
		CellActors[Index]->SetAliveNext(false);
	}
	else if (IsAlive && ((NumAliveNeighbors == 2) || (NumAliveNeighbors == 3)))
	{
		CellActors[Index]->SetAliveNext(true);
	}
	else if (IsAlive && (NumAliveNeighbors > 3))
	{
		CellActors[Index]->SetAliveNext(false);
	}
	else if (!IsAlive && (NumAliveNeighbors == 3))
	{
		CellActors[Index]->SetAliveNext(true);
	}
	else 
	{
		CellActors[Index]->SetAliveNext(CellActors[Index]->GetAlive());
	}
}