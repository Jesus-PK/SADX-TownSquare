#pragma once

// Individual StartPosition values - Since all characters will use the same one for this stage, I can only write 1 global definition for each act and call it individually for each character. Use the instruction: helperFunctions.RegisterStartPosition(Characters_X, SpeedHighwayX); in the Init.
	StartPosition SpeedHighway0 = { LevelIDs_SpeedHighway, 0, { 3975, -1500, 4790 }, 0xC000 };
	StartPosition SpeedHighway1 = { LevelIDs_SpeedHighway, 1, { 572, -19220, 0 }, 0xC000 };
	StartPosition SpeedHighway2 = { LevelIDs_SpeedHighway, 2, { 152.2f, 0, 342.48f }, 0xC000 };