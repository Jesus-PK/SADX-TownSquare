#pragma once

// Individual StartPosition values for each act - Since all characters will share the same StartPosition, we can set up a loop for the helperFunction that we will call on main.cpp, this will apply these to all characters with less code. If you were to call these individually, you need to use the instruction: helperFunctions.RegisterStartPosition(Characters_X, SpeedHighwayX); in the Init to assign them individually per character. You will need to do that if you create more than one startpos with different coordinates.
	StartPosition SpeedHighway0 = { LevelIDs_SpeedHighway, 0, { 3975, -1500, 4790 }, 0xC000 };
	StartPosition SpeedHighway1 = { LevelIDs_SpeedHighway, 1, { 572, -19220, 0 }, 0xC000 };
	StartPosition SpeedHighway2 = { LevelIDs_SpeedHighway, 2, { 152.2f, 0, 342.48f }, 0xC000 };