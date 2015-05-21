#include "global.h"



//is for debug output
char *strState[]={ 
     "stand",
     "crouch",
     "air",
     "liedown",
     "attack",
     "idle",
     "hit",
     "none",
     "unchange"}; 
/*
================================================================================
Main Player class which represents one Player
Handels everything the loading and acting of the player

Todo:
Change CSffManager,CAirManager,CStateManager to pointers
to add a CreateHelper function which returns a new Player 
instace which will be a copy of its parent

================================================================================
*/

CPlayer::CPlayer()
{
	bRightFaced=true;
	bAlive=true;
	bDebugInfo=false;
	bHitDefPresit=false;
	bHitCounterPresit=false;
	bMoveHitPresit=false;
	bHitDef=false;
	nLife=1000;
	nPower=1000;
	nStateTime=0;
	nStateType=0;
	nPhysic=0;
	nMoveType=0;
	x=y=0;
	xVel=0;
	yVel=0;
	m_ControllerExec.SetPlayer(this);
}

CPlayer::~CPlayer()
{
                   
}
//Set all the pointers to all the managers
void CPlayer::SetPointers(CVideoSystem *p,CAllocater *a,CGameTimer *t)
{
     m_pAlloc=a;
     m_pVideoSystem=p;
     m_pTimer=t;
     
     m_SffManager.SetPointers(p,a,t,&m_AirManager);
     m_StateManager.SetAlloc(a);
     m_AirManager.SetAlloc(a);
     m_CmdManager.SetGameTimer(t);
     
    
}

//Load the player by his given .def filename
//ToDo:Handel the .def file loading
bool CPlayer::LoadPlayer(const char* strPlayer)
{
    
     CStateParser StateParser;
     //rest memory allocater    
     m_pAlloc->ResetAllocater(); 
     
     m_SffManager.ResetManager();
     m_StateManager.Reset();
     m_AirManager.ResetManager();
     
	 StateParser.ParseStateFile("common1.cns",m_StateManager,m_pAlloc);
	 StateParser.ParseStateFile("kfm/kfm.cns",m_StateManager,m_pAlloc);

	 m_CmdManager.LoadCMDFile("kfm/kfm.cmd");
     //StateParser.ParseStateFile("cns.txt",m_StateManager,m_pAlloc);
	 //StateParser.ParseStateFile("kfm/kfm.cns",m_StateManager,m_pAlloc);
     m_AirManager.OpenAir("kfm/kfm.air");


     
     m_SffManager.LoadActToSff("kfm/kfm.act");
     m_SffManager.LoadSffFile("kfm/kfm.sff");
     //Make always masked blit
     m_SffManager.SetBltFlags(CSffManager::BLT_NORMALMASKED);
     m_SffManager.PrepareAnim(0);
     
    
     ChangeState(0);    
     
	 return true;
}

void CPlayer::SetKeys(Uint16 sdl_code[])
{
	if (sdl_code)
	{
		m_CmdManager.RegisterKeys(sdl_code);
	}
}


/*
================================================================================
Handles the players Physic 
================================================================================
*/
void CPlayer::HandlePhysic()
{
     x+=xVel;
     y+=yVel;
}
/*
================================================================================
Handles the FSM of the player
-checks all trigger 
-and activate controllers  
================================================================================
*/
void CPlayer::HandleFSM()
{
	if (m_CmdManager.GetCurrentCommandName() && strcmp(m_CmdManager.GetCurrentCommandName(), "holddown") == 0)
	{
		int a;
		a = 0;
	}
	//execute -3 .. -1 state
	for (int index = -3; index < 0; index++)
	{
		PLSTATEDEF *tmpStateDef = m_StateManager.GetStateDef(index);
		if (tmpStateDef)
		{
			for(u16 i=0;i < tmpStateDef->nHowManyState; i++)
			{
				if( CheckState(&tmpStateDef->lpState[i]) )
					ExecuteController(&tmpStateDef->lpState[i]);           
			}
		}
	}

	//check every state in this statedef
	for(u16 i=0;i < lpCurrStatedef->nHowManyState; i++)
	{
		if( CheckState(&lpCurrStatedef->lpState[i]) )
			ExecuteController(&lpCurrStatedef->lpState[i]);           
	}
        
}
/*
================================================================================
Checks all the triggers in the current state
================================================================================
*/
bool CPlayer::CheckState(PLSTATE* tempState)
{
	if (!tempState || !tempState->triggers)
	{
		return false;
	}

	bool bTriggerAll=true;
	bool bTrigger=false;
	PLTRIGGER *triggers = tempState->triggers;
	for (u16 i=0; i < tempState->nHowManyTriggers; i++)
	{
		if (triggers[i].nTriggerType == TRIGGERALL)
		{
			bTriggerAll = m_pVMachine->Execute(triggers[i].pInts) == 1.0;
			if (!bTriggerAll)
			{
				return false;
			}
		}
		else
		{
			bTrigger |= m_pVMachine->Execute(triggers[i].pInts) == 1.0;
		}
	}

	if (bTriggerAll && bTrigger)
	{
		tempState->persistCount++;
		if (tempState->persistent == 0 && tempState->persistCount == 1)
		{
			return true;
		}
		else if (tempState->persistent == 0)
		{
			return false;
		}

		if (tempState->persistCount % tempState->persistent == 0)
		{
			return true;
		}
	}
	
    return false;
}

void CPlayer::ExecuteController(PLSTATE* tempState)
{
	if (!tempState)
	{
		return;
	}
	lpCurrState = tempState;
	m_ControllerExec.ExecuteController(tempState->nType);
	lpCurrState = nullptr;
}

//updates all interlal stuff of the player
void CPlayer::UpDatePlayer()
{
	m_CmdManager.Update(bRightFaced);

	memset(strCommand, 0, sizeof(strCommand));

	if (m_CmdManager.GetCurrentCommandName())
	{
		PrintMessage("cur command is %s", m_CmdManager.GetCurrentCommandName());
		_snprintf(strCommand, sizeof(strCommand)-1,"%s", m_CmdManager.GetCurrentCommandName());
	}
	
	HandleFSM();
	HandlePhysic();
	UpDateFacing();
	nStateTime++;
    
}

//handles the facing of the player
void CPlayer::UpDateFacing()
{
 if(bRightFaced)
    m_SffManager.SetBltFlags(CSffManager::BLT_NORMALMASKED);           
 else
    m_SffManager.SetBltFlags(CSffManager::BLT_FLIPHMASKED);

}

//draw debug info of the player
void CPlayer::Debug()
{
     ActionElement *Anim=m_SffManager.GetCurrAnimation();
     
     //Print information about the current Animation
     m_pVideoSystem->DrawText(0,10,"Action %3i | AnimElem %3i/%3i | AnimTime %3i/%3i ",Anim->nActionNumber
                                                                ,Anim->nCurrentImage+1
                                                                ,Anim->nNumberOfElements
                                                                ,Anim->nCurrTime
                                                                ,Anim->nCompletAnimTime);
     
     m_pVideoSystem->DrawText(0,20,"StateType=%s | MoveType=%s | Physic=%s",strState[nStateType],
                                                                                         strState[nMoveType],
                                                                                         strState[nPhysic]);
     m_pVideoSystem->DrawText(0,30,"x=%3f,y=%3f",x,y-nGround);
     m_pVideoSystem->DrawText(0,40,"HitDef %i | State %i | StateTime %i",bHitDef,
                                                                         10,
                                                                         this->nStateTime);



}

//Change State controller
void CPlayer::ChangeState(s32 nStateNumber)
{
     //restet StateTime 
     nStateTime=0;
     //get the statedef
	 if (!m_StateManager.GetStateDef(nStateNumber))
	 {
		 PrintMessage("Error, not find state %d", nStateNumber);
		 return;
	 }
     lpCurrStatedef=m_StateManager.GetStateDef(nStateNumber);

	 PrintMessage("player  change to state %d", nStateNumber);
     
     //Set StateType
     if(lpCurrStatedef->type!=untouch)
        nStateType=lpCurrStatedef->type;
     //Set Physic    
     if(lpCurrStatedef->physics!=untouch)
        nPhysic=lpCurrStatedef->physics;
     
     if(lpCurrStatedef->movetype!=untouch)
        nMoveType=lpCurrStatedef->movetype;
     //Set the Ctrl flag  
     if(lpCurrStatedef->bCtrl != -1)
        bCtrl=lpCurrStatedef->bCtrl;
        
     bHitDefPresit                  =lpCurrStatedef->bHitdefpersist;
     bHitCounterPresit              =lpCurrStatedef->bHitcountpersist;
     bMoveHitPresit                 =lpCurrStatedef->bMovehitpersist;
     
     //change anim if needed
	 if(lpCurrStatedef->nAnim != -1)
		 PlayAnim(lpCurrStatedef->nAnim);

	 if(lpCurrStatedef->Velset.x != -3333)
		 xVel=lpCurrStatedef->Velset.x;

	 if(lpCurrStatedef->Velset.y != -3333)
		 yVel=lpCurrStatedef->Velset.y;

	 if(lpCurrStatedef->nSprpriority != 255)
		 nSprPrio=lpCurrStatedef->nSprpriority;

	 if(lpCurrStatedef->nPoweradd != -3333)
		 nPower+=lpCurrStatedef->nPoweradd;

	 if(lpCurrStatedef->nJuggle != -3333)
		 PrintMessage("TODO:Handel juggle parameter of Statedef");
                             
	for(u16 index=0; index < lpCurrStatedef->nHowManyState; index++)
	{
		lpCurrStatedef->lpState[index].persistCount = 0;
	}
        
}

void CPlayer::PlayAnim(s32 nAnimNo)
{
	nAnimNumber = nAnimNo;
	m_SffManager.PrepareAnim(nAnimNumber);
}

//Draw the Player
void CPlayer::DrawPlayer()
{
    m_SffManager.BlitAnim((s16)x,(s16)y);
        
    //draw debug info
    if(bDebugInfo)
       Debug();       
}
/*
================================================================================
Trigger helpers
================================================================================
*/
bool CPlayer::IsAnimAviable(s32 nAnim)
{
     if(m_AirManager.GetAction(nAnim) == NULL)
     return false;
     else
     return true;
}

float CPlayer::GetParamValue( PARAMVALUES value )
{
	float ret = 0.0;
	switch(value) {
		case PA_VALUE:
 			if (lpCurrState && lpCurrState->controller) 
 			{
				COMMONCTRLDATA * pData = (COMMONCTRLDATA *)lpCurrState->controller;
 				ret = m_pVMachine->Execute(pData->value);
 			}
			break;
		case PA_XVALUE:
			if (lpCurrState && lpCurrState->controller) 
			{
				COMMONCTRLDATA * pData = (COMMONCTRLDATA *)lpCurrState->controller;
				ret = xVel;
				if (pData->velx)
				{
					ret = m_pVMachine->Execute(pData->velx);
				}
			}
			break;
		case PA_YVALUE:
			if (lpCurrState && lpCurrState->controller) 
			{
				COMMONCTRLDATA * pData = (COMMONCTRLDATA *)lpCurrState->controller;
				ret = yVel;
				if (pData->vely)
				{
					ret = m_pVMachine->Execute(pData->vely);
				}
			}
			break;
		case PA_VAR:
			if (lpCurrState && lpCurrState->controller) 
			{
				COMMONCTRLDATA * pData = (COMMONCTRLDATA *)lpCurrState->controller;
				ret = NOPARAM;
				if (pData->var)
				{
					ret = m_pVMachine->Execute(pData->var);
				}
			}
			break;
		case PA_FVAR:
			if (lpCurrState && lpCurrState->controller) 
			{
				COMMONCTRLDATA * pData = (COMMONCTRLDATA *)lpCurrState->controller;
				ret = NOPARAM;
				if (pData->fvar)
				{
					ret = m_pVMachine->Execute(pData->fvar);
				}
			}
			break;
		case PA_SYSVAR:
			if (lpCurrState && lpCurrState->controller) 
			{
				COMMONCTRLDATA * pData = (COMMONCTRLDATA *)lpCurrState->controller;
				ret = NOPARAM;
				if (pData->sysvar)
				{
					ret = m_pVMachine->Execute(pData->sysvar);
				}
			}
			break;
		case PA_SYSFVAR:
			if (lpCurrState && lpCurrState->controller) 
			{
				COMMONCTRLDATA * pData = (COMMONCTRLDATA *)lpCurrState->controller;
				ret = NOPARAM;
				if (pData->sysfvar)
				{
					ret = m_pVMachine->Execute(pData->sysfvar);
				}
			}
			break;
	}
	return ret;
}

void CPlayer::SetVar(int index, int value)
{
	if (index >= 200)
	{
		return;
	}
	m_Var[index] = value;
}
void CPlayer::SetFVar(int index, float value)
{
	if (index >= 200)
	{
		return;
	}
	m_Var[index] = value;
}
void CPlayer::SetSysVar(int index, int value)
{
	if (index >= 200)
	{
		return;
	}
	m_pEngine->m_sysVar[index] = value;
}
void CPlayer::SetSysFVar(int index, float value)
{
	if (index >= 200)
	{
		return;
	}
	m_pEngine->m_sysVar[index] = value;
}

int CPlayer::GetVar( int index )
{
	if (index >= 200)
	{
		return -1;
	}
	return m_Var[index];
}

float CPlayer::GetFVar( int index )
{
	if (index >= 200)
	{
		return -1;
	}
	return m_Var[index];
}

int CPlayer::GetSysVar( int index )
{
	if (index >= 200)
	{
		return -1;
	}
	return m_pEngine->m_sysVar[index];
}

float CPlayer::GetSysFVar( int index )
{
	if (index >= 200)
	{
		return -1;
	}
	return m_pEngine->m_sysVar[index];
}


