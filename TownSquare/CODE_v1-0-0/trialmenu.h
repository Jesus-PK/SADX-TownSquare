#pragma once

// Since it's not possible yet to individually edit already existing Trial Menu entries with HelperFunctions, I edited the whole array without them.


// Sonic Action Stages list on the Trial menu - Use the instruction: *(TrialLevelList*)0x7EF5EC = SonicActionStages; in the Init.
TrialLevelListEntry SonicActionStages_list[] = {
	{ LevelIDs_EmeraldCoast, 0 },
	{ LevelIDs_WindyValley, 0 },
	{ LevelIDs_Casinopolis, 0 },
	{ LevelIDs_IceCap, 0 },
	{ LevelIDs_TwinklePark, 0 },
	{ LevelIDs_SpeedHighway, 2 },
	{ LevelIDs_RedMountain, 0 },
	{ LevelIDs_SkyDeck, 0 },
	{ LevelIDs_LostWorld, 0 },
	{ LevelIDs_FinalEgg, 0 }
};

TrialLevelList SonicActionStages = { arrayptrandlengthT(SonicActionStages_list, int) };


// Metal Sonic Action Stages list on the Trial menu - Use the instruction: *(TrialLevelList*)0x7EF61C = MetalSonicActionStages; in the Init.
TrialLevelListEntry MetalSonicActionStages_list[] = {
	{ LevelIDs_EmeraldCoast, 0 },
	{ LevelIDs_WindyValley, 0 },
	{ LevelIDs_Casinopolis, 0 },
	{ LevelIDs_IceCap, 0 },
	{ LevelIDs_TwinklePark, 0 },
	{ LevelIDs_SpeedHighway, 2 },
	{ LevelIDs_RedMountain, 0 },
	{ LevelIDs_SkyDeck, 0 },
	{ LevelIDs_LostWorld, 0 },
	{ LevelIDs_FinalEgg, 0 }
};

TrialLevelList MetalSonicActionStages = { arrayptrandlengthT(MetalSonicActionStages_list, int) };


// Tails Action Stages list on the Trial menu - Use the instruction: *(TrialLevelList*)0x7EF5F4 = TailsActionStages; in the Init.
TrialLevelListEntry TailsActionStages_list[] = {
	{ LevelIDs_WindyValley, 2 },
	{ LevelIDs_Casinopolis, 1 },
	{ LevelIDs_IceCap, 2 },
	{ LevelIDs_SkyDeck, 0 },
	{ LevelIDs_SpeedHighway, 2 }
};

TrialLevelList TailsActionStages = { arrayptrandlengthT(TailsActionStages_list, int) };