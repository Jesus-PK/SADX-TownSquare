#pragma once

// This lets Tails finish his stage on Speed Highway Act 3 without getting a "You Lose" message when hitting the capsule. This also lets you win against Eggman in Act 3 even if he finishes first. Use the instruction: TailsFix(); in the OnFrames.
	void TailsFix()
		{
			if (CurrentCharacter == Characters_Tails && CurrentLevel == LevelIDs_SpeedHighway && CurrentAct == 2)
				{
					SetTailsRaceVictory();
				}
		}