#include "global.h"

/*
================================================================================
Represents the main fighting engine in which
all fighters are represented and the stages

================================================================================
*/

CEngine::CEngine()
{
                  
}

CEngine::~CEngine()
{
  delete m_pVMp1;
  delete m_pVMp2;
}

/*
================================================================================
Init the engine clall the function once at the start
of OpenMugen
================================================================================
*/
void CEngine::InitEngine(CMemManager *m,CVideoSystem *v,CGameTimer *t)
{
     //Set All pinter to CEngine class
    m_pMemManager=m;
    m_pVideoSystem=v;
    m_pTimer=t;
     
    //Set all needed pointer to need class by class player
    player1.SetPointers(v,m->GetAllocater(P1),t);
    player2.SetPointers(v,m->GetAllocater(P2),t);
    player3.SetPointers(v,m->GetAllocater(P3),t);
    player4.SetPointers(v,m->GetAllocater(P4),t);
    
    //get the virtual machines
    m_pVMp1 = new CVirtualMachine;
    m_pVMp2 = new CVirtualMachine;
    
    //Set players to the VM
    m_pVMp1->SetPlayers(&player1,&player2);
    m_pVMp2->SetPlayers(&player2,&player1);
    
    //now set the VM to the player
    player1.SetVM(m_pVMp1);
    player2.SetVM(m_pVMp2);

	player1.SetEngine(this);
	player2.SetEngine(this);
    
    
    /*Set the gournd limit of the player 
     This value should be read out the stage def*/
    player1.SetGroundValue(220);
    player2.SetGroundValue(220);
    
    //this values also should read out of the stage def
    
    player1.SetPos(70,220);
    player2.SetPos(240,220);
    
	Uint16 sdlk_code1[] = {
		SDLK_w,
		SDLK_s,
		SDLK_a,
		SDLK_d,
		SDLK_u,
		SDLK_i,
		SDLK_o,
		SDLK_j,
		SDLK_k,
		SDLK_l,
		SDLK_1,
		SDLK_2,
		
	};

	Uint16 sdlk_code2[] = {
		SDLK_UP,
		SDLK_DOWN,
		SDLK_LEFT,
		SDLK_RIGHT,
		SDLK_KP4,
		SDLK_KP5,
		SDLK_KP6,
		SDLK_KP1,
		SDLK_KP2,
		SDLK_KP3,
		SDLK_3,
		SDLK_4,
	};
    player1.SetKeys(sdlk_code1);
	player2.SetKeys(sdlk_code2);
    player1.LoadPlayer("player1");
    player2.LoadPlayer("player2");
    
    player2.FaceLeft();
    player1.SetDebug(true);
//    player1.VelSetY(-2.4f);
     
}
/*
================================================================================
Upates all the engine members and draw them to the screen
Handels also AI and player movement
================================================================================
*/
void CEngine::RunEngine()
{
  player1.UpDatePlayer();
  player2.UpDatePlayer();

  player1.DrawPlayer();
  player2.DrawPlayer();
     
}
