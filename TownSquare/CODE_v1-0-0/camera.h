#pragma once

// Code to force Free Camera only on Act3 of Speed Highway, only applies on stage start / restart - Use the instruction: RoundMasterList[LevelIDs_SpeedHighway] = ForceFreeCameraSH2; in the Init.
	void ForceFreeCameraSH(task* tsk)
		{
			if (tsk)
				{
					EnableFreeCamera(1);
					tsk->exec = (TaskFuncPtr)Obj_SpeedHighway;
					Obj_SpeedHighway((ObjectMaster*)tsk);
				}
		}