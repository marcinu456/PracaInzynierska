int AGridActor::CountAliveNeighbors(const int i, const int j) 
{
	int NumAliveNeighbors = 0;
	for (int k = -1; k <= 1; k++) {
		for (int l = -1; l <= 1; l++) {
			if (!(l == 0 && k == 0)) {
				const int effective_i = i + k;
				const int effective_j = j + l;
				if ((effective_i >= 0 && effective_i < Height) && (effective_j >= 0 && effective_j < Width)) {
					if (CellActors[effective_j + effective_i * Width]->GetAlive()) {
						NumAliveNeighbors++;
					}
				}
			}
		}
	}
	return NumAliveNeighbors;
}