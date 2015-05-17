#include "global.h"
#include <string>

enum ENControllerType {
	AfterImage = 0,
	AfterImageTime = 1,
	AllPalFX = 2,
	AngleAdd = 3,
	AngleDraw = 4,
	AngleMul = 5,
	AngleSet = 6,
	AppendToClipboard = 7,
	AssertSpecial = 8,
	AttackDist = 9,
	AttackMulSet = 10,
	BGPalFX = 11,
	BindToParent = 12,
	BindToRoot = 13,
	BindToTarget = 14,
	ChangeAnim = 15,
	ChangeAnim2 = 16,
	ChangeState = 17,
	ClearClipboard = 18,
	CtrlSet = 19,
	DefenceMulSet = 20,
	DestroySelf = 21,
	DisplayToClipboard = 22,
	EnvColor = 23,
	EnvShake = 24,
	Explod = 25,
	ExplodBindTime = 26,
	ForceFeedback = 27,
	FallEnvShake = 28,
	GameMakeAnim = 29,
	Gravity = 30,
	Helper = 31,
	HitAdd = 32,
	HitBy = 33,
	HitDef = 34,
	HitFallDamage = 35,
	HitFallSet = 36,
	HitFallVel = 37,
	HitOverride = 38,
	HitVelSet = 39,
	LifeAdd = 40,
	LifeSet = 41,
	MakeDust = 42,
	ModifyExplod = 43,
	MoveHitReset = 44,
	NotHitBy = 45,
	Null = 46,
	Offset = 47,
	PalFX = 48,
	ParentVarAdd = 49,
	ParentVarSet = 50,
	Pause = 51,
	PlayerPush = 52,
	PlaySnd = 53,
	PosAdd = 54,
	PosFreeze = 55,
	PosSet = 56,
	PowerAdd = 57,
	PowerSet = 58,
	Projectile = 59,
	RemoveExplod = 60,
	ReversalDef = 61,
	ScreenBound = 62,
	SelfState = 63,
	SprPriority = 64,
	StateTypeSet = 65,
	SndPan = 66,
	StopSnd = 67,
	SuperPause = 68,
	TargetBind = 69,
	TargetDrop = 70,
	TargetFacing = 71,
	TargetLifeAdd = 72,
	TargetPowerAdd = 73,
	TargetState = 74,
	TargetVelAdd = 75,
	TargetVelSet = 76,
	Trans = 77,
	Turn = 78,
	VarAdd= 79,
	VarRandom= 80,
	VarRangeSet= 81,
	VarSet= 82,
	VelAdd= 83,
	VelMul= 84,
	VelSet= 85,
	Width= 86,
};

//This are all documented Controllers
//TODO: find the undocumented controllers
static char* strControllerTypes[] = {
  "AfterImage",
  "AfterImageTime",
  "AllPalFX",
  "AngleAdd",
  "AngleDraw",
  "AngleMul",
  "AngleSet",
  "AppendToClipboard",
  "AssertSpecial",
  "AttackDist",
  "AttackMulSet",
  "BGPalFX",
  "BindToParent",
  "BindToRoot",
  "BindToTarget",
  "ChangeAnim",
  "ChangeAnim2",
  "ChangeState",
  "ClearClipboard",
  "CtrlSet",
  "DefenceMulSet",
  "DestroySelf",
  "DisplayToClipboard",
  "EnvColor",
  "EnvShake",
  "Explod",
  "ExplodBindTime",
  "ForceFeedback",
  "FallEnvShake",
  "GameMakeAnim",
  "Gravity",
  "Helper",
  "HitAdd",
  "HitBy",
  "HitDef",
  "HitFallDamage",
  "HitFallSet",
  "HitFallVel",
  "HitOverride",
  "HitVelSet",
  "LifeAdd",
  "LifeSet",
  "MakeDust",
  "ModifyExplod",
  "MoveHitReset",
  "NotHitBy",
  "Null",
  "Offset",
  "PalFX",
  "ParentVarAdd",
  "ParentVarSet",
  "Pause",
  "PlayerPush",
  "PlaySnd",
  "PosAdd",
  "PosFreeze",
  "PosSet",
  "PowerAdd",
  "PowerSet",
  "Projectile",
  "RemoveExplod",
  "ReversalDef",
  "ScreenBound",
  "SelfState",
  "SprPriority",
  "StateTypeSet",
  "SndPan",
  "StopSnd",
  "SuperPause",
  "TargetBind",
  "TargetDrop",
  "TargetFacing",
  "TargetLifeAdd",
  "TargetPowerAdd",
  "TargetState",
  "TargetVelAdd",
  "TargetVelSet",
  "Trans",
  "Turn",
  "VarAdd",
  "VarRandom",
  "VarRangeSet",
  "VarSet",
  "VelAdd",
  "VelMul",
  "VelSet",
  "Width",
  0,

       };
       
//All triggers       
static char * strTriggerType[] = {
  "Abs",
  "Acos",
  "Alive",
  "Anim",
  "AnimElem",
  "AnimElemNo",
  "AnimElemTime",
  "AnimExist",
  "AnimTime",
  "Asin",
  "Atan",
  "AuthorName",
  "BackEdgeBodyDist",
  "BackEdgeDist",
  "CanRecover",
  "Ceil",
  "Command",
  "Const",
  "Cos",
  "Ctrl",
  "DrawGame",
  "E",
  "Exp",
  "Facing",
  "Floor",
  "FrontEdgeBodyDist",
  "FrontEdgeDist",
  "FVar",
  "GameTime",
  "GetHitVar",
  "HitCount",
  "HitDefAttr",
  "HitFall",
  "HitOver",
  "HitPauseTime",
  "HitShakeOver",
  "HitVel",
  "ID",
  "IfElse",
  "InGuardDist",
  "IsHelper",
  "IsHomeTeam",
  "Life",
  "LifeMax",
  "Log",
  "Ln",
  "Lose",
  "MatchNo",
  "MatchOver",
  "MoveContact",
  "MoveGuarded",
  "MoveHit",
  "MoveType",
  "MoveReversed",
  "Name",
  "NumEnemy",
  "NumExplod",
  "NumHelper",
  "NumPartner",
  "NumProj",
  "NumProjID",
  "NumTarget",
  "P1Name",
  "P2BodyDist",
  "P2Dist",
  "P2Life",
  "P2MoveType",
  "P2Name",
  "P2StateNo",
  "P2StateType",
  "P3Name",
  "P4Name",
  "PalNo",
  "ParentDist",
  "Pi",
  "Pos",
  "Power",
  "PowerMax",
  "PlayerIDExist",
  "PrevStateNo",
  "ProjCancelTime",
  "ProjContact",
  "ProjContactTime",
  "ProjGuarded",
  "ProjGuardedTime",
  "ProjHit",
  "ProjHitTime",
  "Random",
  "RootDist",
  "RoundNo",
  "RoundsExisted",
  "RoundState",
  "ScreenPos",
  "SelfAnimExist",
  "Sin",
  "StateNo",
  "StateType",
  "SysFVar",
  "SysVar",
  "Tan",
  "TeamMode",
  "TeamSide",
  "TicksPerSecond",
  "Time",
  "TimeMod",
  "UniqHitCount",
  "Var",
  "Vel",
  "Win",
  0,
       };


CStateParser::CStateParser()
{
                        
}

CStateParser::~CStateParser()
{
                            
}

void CStateParser::Error(const char * strErrorMsg,CTokenizer &tok)
{
     throw(CError("Parser error:\nin file %s at line %i:\n%s",tok.GetFileName()
                                                         ,tok.GetLineNumber()
                                                         ,strErrorMsg));                  
}

void CStateParser::ParseStateFile(const char* strFileName,CStateManager &StateManager,CAllocater *a)
{
     //Set pointer to allocater
     m_pAlloc=a;
     
     CTokenizer tok;
     bool foundState=false;
     
     if( !tok.OpenFile(strFileName) )
        throw(CError("CStateParser::ParseState: File %s not found",strFileName));
        
     tok.SetIsCaseSensitive(false);
     tok.SetReturnNegativeSeperatelyFromNumber(false);
        

     while( !tok.AtEndOfFile() )
     {
          foundState=false;
          
          if( tok.CheckToken("[") )
          {
            
             if( tok.CheckToken("statedef") )
             {
                 foundState=true;
                 if(!tok.CheckTokenIsNumber())
                     Error("Expected a number in statedef block",tok);
                     
                 StateManager.AddStateDef(tok.GetInt());
                
                 //Skip useless stuff
                 while( !tok.AtEndOfLine() )
                         tok.GetToken();
                
                //parse the state def
                ParseStateDef(tok,StateManager);        
                         
                         
             }
             if( tok.CheckToken("state") )
             {
               foundState=true;  
               
               if(!tok.CheckTokenIsNumber())
                     Error("Expected a number in state block",tok);
                 
			   int stateno = tok.GetInt();

			   tok.CheckToken(",");

// 			   if(!tok.CheckTokenIsQuotedString()
// 				   && !tok.CheckTokenIsNumber())
// 				   Error("Expected a number in state block",tok);

			   std::string str = tok.GetToken();
               StateManager.AddState(stateno, str.c_str());
                                  
			   while(!tok.AtEndOfLine())
				   tok.GetToken();  
                         
				PareseState(tok,StateManager);
                   
             }
    
          
          }
          
          //skip useless stuff
          if(!foundState)
             tok.GetToken(); 
            
     }
     
     tok.CloseFile();
}

void CStateParser::ParseStateDef(CTokenizer &tok,CStateManager &StateManager)
{
while( !tok.CheckToken("[",false) && !tok.AtEndOfFile() )
{
     //parse state type
     if( tok.CheckToken("type") )
     {
         if( !tok.CheckToken("=") )
            Error("expected =",tok);
         
         //to get a single char   
         char c=tok.GetToken()[0];
         //make sure we use uperchars
         if(c >= 97)
            c-=32;
            
                  
         switch(c)
         {
            case 'S':
             StateManager.SetStateDefType(stand); 
            break;
            
            case 'C':
             StateManager.SetStateDefType(crouch);     
            break;
                        
            case 'A':
             StateManager.SetStateDefType(air); 
            break;
            
            case 'L':
             StateManager.SetStateDefType(liedown);     
            break;
            
            case 'U':
             StateManager.SetStateDefType(untouch);    
            break;
            
            default:
              Error("Unknown statetype",tok);
            break;
                      
                  
         }

     } else if( tok.CheckToken("movetype") )
     {
         if( !tok.CheckToken("=") )
            Error("expected '=' in line ",tok);
            
         //to get a single char   
         char c=tok.GetToken()[0];
         //make sure we use uperchars
         if(c >= 97)
            c-=32;
           
         switch(c)
         {
            case 'A':
             StateManager.SetStateMoveType(attack);
            break;

            case 'I':
             StateManager.SetStateMoveType(idle);
            break;

            case 'H':
             StateManager.SetStateMoveType(hit);
            break;

            case 'U':
             StateManager.SetStateMoveType(untouch);
            break;
            
            default:
              Error("Unknown movetype",tok);
            break;
            
                  
                  
         }      
           
              
         
     } else if( tok.CheckToken("physics") )
     {
         if( !tok.CheckToken("=") )
            Error("expected =",tok);
         
         //to get a single char   
         char c=tok.GetToken()[0];
         //make sure we use uperchars
         if(c >= 97)
            c-=32;
            
                  
         switch(c)
         {
            case 'S':
             StateManager.SetStatePhysicType(stand); 
            break;
            
            case 'C':
             StateManager.SetStatePhysicType(crouch);     
            break;
                        
            case 'A':
             StateManager.SetStatePhysicType(air); 
            break;
            
            case 'N':
             StateManager.SetStatePhysicType(none);     
            break;
            
            case 'U':
             StateManager.SetStatePhysicType(untouch);    
            break;
            
             default:
              Error("Unknown physic type",tok);
            break;
                      
                  
         }
            
            
            
     } else if( tok.CheckToken("anim") )
     {
        if( !tok.CheckToken("=") )
            Error("expected =",tok);
         
         if(!tok.CheckTokenIsNumber())
           Error("Expected a number for anim",tok);
           
         StateManager.SetStateAnim(tok.GetInt());  
      
            
     } else if( tok.CheckToken("velset") )
     {
       if( !tok.CheckToken("=") )
            Error("expected =",tok);
            
       float x=tok.GetFloat();
       
       if( !tok.CheckToken(",") )
          Error("expected ,",tok);
          
       float y=tok.GetFloat();
       
       StateManager.SetVelSet(x,y);     

     } else if( tok.CheckToken("ctrl") )
     {
         if( !tok.CheckToken("=") )
            Error("expected =",tok);
                                 
         if(!tok.CheckTokenIsNumber())
          Error("Expected a number for ctrl",tok);
            
          StateManager.SetStateCtrl(tok.GetInt());    
            
     } else if( tok.CheckToken("poweradd") )
     {
        if( !tok.CheckToken("=") )
            Error("expected =",tok);
            
        if(!tok.CheckTokenIsNumber())
           Error("Expected a number for poweradd",tok);      
            
        StateManager.SetStatePowerAdd(tok.GetInt());  
            
     } else if( tok.CheckToken("juggle") )
     {
        if( !tok.CheckToken("=") )
            Error("expected =",tok);
            
        if(!tok.CheckTokenIsNumber())
           Error("Expected a number for juggle",tok);
           
       StateManager.SetStateJuggle(tok.GetInt());              
            
     } else if( tok.CheckToken("facep2") )
     {
        if( !tok.CheckToken("=") )
            Error("expected =",tok);
            
        if( !tok.CheckTokenIsNumber() )
            Error("Expected a number for facep2",tok);
            
        StateManager.SetStateFaceP2(tok.GetInt());   
            
     } else if( tok.CheckToken("hitdefpersist") )
     {
        if( !tok.CheckToken("=") )
            Error("expected =",tok);
            
        if( !tok.CheckTokenIsNumber() )
            Error("Expected a number for hitdefpersist",tok); 
            
        StateManager.SetStateHitDefPresit(tok.GetInt());   
            
     } else if( tok.CheckToken("movehitpersist") )
     {
        if( !tok.CheckToken("=") )
            Error("expected =",tok);
            
        if( !tok.CheckTokenIsNumber() )
            Error("Expected a number for movehitpersist",tok);
            
        StateManager.SetMoveHitPresit(tok.GetInt());  
            
     } else if( tok.CheckToken("hitcountpersist") )
     { 
        if( !tok.CheckToken("=") )
            Error("expected =",tok);
            
        if( !tok.CheckTokenIsNumber() )
            Error("Expected a number for hitcountpersist",tok);
            
        StateManager.SetStateHitCounterPresit(tok.GetInt());  
            
            
     } else if( tok.CheckToken("sprpriority") )
     {
         if( !tok.CheckToken("=") )
            Error("expected =",tok); 
            
         if( !tok.CheckTokenIsNumber() )
            Error("Expected a number for sprpriority",tok);
            
         StateManager.SetSprPriority(tok.GetInt()); 
            
     }else //faile in statedef
     {
         
          throw(CError("Unknown token at line %s",tok.GetToken()));
          break;
     }
     

}
    
}

void CStateParser::PareseState(CTokenizer &tok,CStateManager &StateManager)
{
    std::string ret;     
	while( !tok.CheckToken("[",false) && !tok.AtEndOfFile() )
	{
		if( tok.CheckToken("type") )
		{
		   if( !tok.CheckToken("=") )
			   throw(CError("expected ="));
           
		   ret = tok.GetToken();
		   nController=GetControllerType(ret.c_str(),tok );
      
        
		} else if ( tok.CheckToken("triggerall") )
		{
			if( !tok.CheckToken("=") )
			   Error("expected =",tok);
         
			//fix me add triggerall
		
			ParseTrigger(tok,StateManager);
			StateManager.AddTriggerToState(0);

		}else  if( tok.CheckToken("trigger1") 
					||  tok.CheckToken("trigger2")
					||  tok.CheckToken("trigger3")
					||  tok.CheckToken("trigger4")
					||  tok.CheckToken("trigger5")
					||  tok.CheckToken("trigger6")
					||  tok.CheckToken("trigger7")
					||  tok.CheckToken("trigger8")
					||  tok.CheckToken("trigger9")
					||  tok.CheckToken("trigger10")
					||  tok.CheckToken("trigger11")
					||  tok.CheckToken("trigger12")
					||  tok.CheckToken("trigger13")
					||  tok.CheckToken("trigger14")
					||  tok.CheckToken("trigger15")
					||  tok.CheckToken("trigger16")
					||  tok.CheckToken("trigger17")
					||  tok.CheckToken("trigger18")
					||  tok.CheckToken("trigger19")
					||  tok.CheckToken("trigger20"))        
		{
			if( !tok.CheckToken("=") )
				Error("expected =",tok);
			ParseTrigger(tok,StateManager);
			StateManager.AddTriggerToState(1);
		}
		else break;
    

       
	}
	//parse the controller
	ParserController(tok,StateManager,nController); 
	StateManager.AddTypeToState(nController);
}

void CStateParser::ParseTrigger(CTokenizer &tok,CStateManager &StateManager)
{
    tok.SetReturnNegativeSeperatelyFromNumber(true);
    EvaluateExpression(tok,StateManager);
    tok.SetReturnNegativeSeperatelyFromNumber(false);
}

//Generates the Opcode sequenz for the trigger statement
//evaluates and + and - expression
void CStateParser::EvaluateExpression(CTokenizer &tok,CStateManager &StateManager)
{
      
     Term(tok,StateManager);
     
     while( tok.CheckToken("+",false) || tok.CheckToken("-",false) && !tok.AtEndOfLine() )
     {  
        
    
        if( tok.CheckToken("+") )
        {
            Term(tok,StateManager);
            StateManager.AddInstruction(OP_ADD,0,"#");
           
        }
        
        if( tok.CheckToken("-") )
        {
           Term(tok,StateManager);
           StateManager.AddInstruction(OP_SUB,0,"#");
             
        }
  
     }
}

//evaluates and * and / expression
void CStateParser::Term(CTokenizer &tok,CStateManager &StateManager)
{
         
     Primary(tok,StateManager);
     
     //search for operators 
     while( tok.CheckToken("*",false) || tok.CheckToken("/",false)  || 
            tok.CheckToken("=",false) || tok.CheckToken("!=",false) ||
            tok.CheckToken("<",false) || tok.CheckToken("<=",false) ||
            tok.CheckToken(">",false) || tok.CheckToken(">=",false) ||
            tok.CheckToken(":",false) || tok.CheckToken("&&",false) || 
            tok.CheckToken("||",false)|| tok.CheckToken("^^",false) ||
            tok.CheckToken("&",false) || tok.CheckToken("~",false)  ||
            tok.CheckToken("|",false) || tok.CheckToken("^",false)  || 
            tok.CheckToken("%",false) || tok.CheckToken("(", false) 	
			&& !tok.AtEndOfLine() )  
     {  
      
            if( tok.CheckToken("*") )
            {
                //Have we a ** operator?
                if( tok.CheckToken("*") )
                {
                    Primary(tok,StateManager);
                    StateManager.AddInstruction(OP_SQUARE,0,"#");
                    
                }else
                {
                    Primary(tok,StateManager);
                    StateManager.AddInstruction(OP_MUL,0,"#");
                }
            }
         
           if( tok.CheckToken("/") )
           {
               Primary(tok,StateManager);
               StateManager.AddInstruction(OP_DIV,0,"#");
           }
           
           if( tok.CheckToken("=") )
           {    
                //check for intervall operator
                if( tok.CheckToken("(") )
                {
                    //evaluate first expression                   
                    EvaluateExpression(tok,StateManager);
                    if( !tok.CheckToken(",") )
                        Error("Expectetd a , in intervall operator",tok);

                    //evaluate second expression 
                    EvaluateExpression(tok,StateManager);
                    
                    //intervall op =(,)
                    if( tok.CheckToken(")") )
                    {
                        StateManager.AddInstruction(OP_INTERVALOP4,0,"#");
                    }else if( tok.CheckToken("]") )
                    {
                         StateManager.AddInstruction(OP_INTERVALOP3,0,"#");
                    }
                    
                }else if (tok.CheckToken("[") )
                {
                    //evaluate first expression                   
                    EvaluateExpression(tok,StateManager);
                    if( !tok.CheckToken(",") )
                        Error("Expectetd a , in intervall operator",tok);

                    //evaluate second expression 
                    EvaluateExpression(tok,StateManager);
                    
                    //intervall op =[,)
                    if( tok.CheckToken(")") )
                    {
                       StateManager.AddInstruction(OP_INTERVALOP2,0,"#");
                    }else if( tok.CheckToken("]") )
                    {
                         StateManager.AddInstruction(OP_INTERVALOP1,0,"#");
                    }
                      
                }
                else // is the = op
                {                
                //evalute the right side of the operator
                EvaluateExpression(tok,StateManager);
                StateManager.AddInstruction(OP_EQUAL,0,"#");
                }
           }
           
           if( tok.CheckToken(":") )
           {    //evalute the right side of the operator
                if(tok.CheckToken("="))
                {
                 EvaluateExpression(tok,StateManager);
                 PrintMessage("TODO:Handel assign operator :=");
                }
           }
           
           if( tok.CheckToken("!=") )
           {    //evalute the right side of the operator
                //check for intervall operator
                if( tok.CheckToken("(") )
                {
                    //evaluate first expression                   
                    EvaluateExpression(tok,StateManager);
                    if( !tok.CheckToken(",") )
                        Error("Expectetd a , in intervall operator",tok);

                    //evaluate second expression 
                    EvaluateExpression(tok,StateManager);
                    
                    //intervall op !=(,)
                    if( tok.CheckToken(")") )
                    {
                        StateManager.AddInstruction(OP_INTERVALOP8,0,"#");
                    }else if( tok.CheckToken("]") )
                    {
                         StateManager.AddInstruction(OP_INTERVALOP7,0,"#");
                    }
                    
                }else if (tok.CheckToken("[") )
                {
                    //evaluate first expression                   
                    EvaluateExpression(tok,StateManager);
                    if( !tok.CheckToken(",") )
                        Error("Expectetd a , in intervall operator",tok);

                    //evaluate second expression 
                    EvaluateExpression(tok,StateManager);
                    
                    //intervall op !=[,)
                    if( tok.CheckToken(")") )
                    {
                       StateManager.AddInstruction(OP_INTERVALOP6,0,"#");
                    }else if( tok.CheckToken("]") )
                    {
                         StateManager.AddInstruction(OP_INTERVALOP5,0,"#");
                    }
                      
                }
                else // is the != op
                {                
					//evalute the right side of the operator
					EvaluateExpression(tok,StateManager);
					StateManager.AddInstruction(OP_NOTEQUAL,0,"#");
                }
                //EvaluateExpression(tok,StateManager);
                //StateManager.AddInstruction(OP_NOTEQUAL,0,"#");
           }
           
           if( tok.CheckToken("<") )
           {    //evalute the right side of the operator
                EvaluateExpression(tok,StateManager);
                StateManager.AddInstruction(OP_LESS,0,"#");
           }
           
           if( tok.CheckToken("<=") )
           {    //evalute the right side of the operator
                EvaluateExpression(tok,StateManager);
                StateManager.AddInstruction(OP_LESSEQUAL,0,"#");
           }
           
           if( tok.CheckToken(">") )
           {    //evalute the right side of the operator
                EvaluateExpression(tok,StateManager);
                StateManager.AddInstruction(OP_GREATER,0,"#");
           }
           
           if( tok.CheckToken(">=") )
           {    //evalute the right side of the operator
                EvaluateExpression(tok,StateManager);
                StateManager.AddInstruction(OP_GRAETEREQUAL,0,"#");
           }
           
           if( tok.CheckToken("&&") )
           {    //evalute the right side of the operator
                EvaluateExpression(tok,StateManager);
                StateManager.AddInstruction(OP_LOGAND,0,"#");
           }
           
           if( tok.CheckToken("||") )
           {    //evalute the right side of the operator
                EvaluateExpression(tok,StateManager);
                StateManager.AddInstruction(OP_LOGOR,0,"#");
           }
           
           if( tok.CheckToken("^^") ) // is this realy needed?
                                      //FIXME:Cant read ^^
           {    //evalute the right side of the operator
                EvaluateExpression(tok,StateManager);
                StateManager.AddInstruction(OP_LOGXOR,0,"#");
           }
           
           if( tok.CheckToken("&") ) 
           {    //evalute the right side of the operator
                Primary(tok,StateManager);
                StateManager.AddInstruction(OP_AND,0,"#");
           }
           
           if( tok.CheckToken("~") ) 
           {    //evalute the right side of the operator
                Primary(tok,StateManager);
                StateManager.AddInstruction(OP_NOT,0,"#");
           }
           
           if( tok.CheckToken("|") ) 
           {    //evalute the right side of the operator
                Primary(tok,StateManager);
                StateManager.AddInstruction(OP_OR,0,"#");
           }
           
           if( tok.CheckToken("^") ) 
           {    //evalute the right side of the operator
                Primary(tok,StateManager);
                StateManager.AddInstruction(OP_XOR,0,"#");
           }
           
           if( tok.CheckToken("%") ) 
           {    //evalute the right side of the operator
                Primary(tok,StateManager);
                StateManager.AddInstruction(OP_MOD,0,"#");
           }

		   if (tok.CheckToken("("))
		   {
			   EvaluateExpression(tok,StateManager);

			   if( !tok.CheckToken(")") )
				   Error("Missing )",tok);
		   }
           
      }
     
}
//evaluates a primary
void CStateParser::Primary(CTokenizer &tok,CStateManager &StateManager)
{
     //a negate operator
     if( tok.CheckToken("-") )
     {
           //EvaluateExpression(tok,StateManager);
           Primary(tok,StateManager);
           StateManager.AddInstruction(OP_NEG,0,"#");  
     }else if( tok.CheckTokenIsNumber() )  //we have a number
     {
         StateManager.AddInstruction(OP_PUSH,tok.GetFloat(),"#");                       
     }else if( tok.CheckTokenIsQuotedString() ) //it is a "quitedstring"
     {
         StateManager.AddInstruction(OP_PUSH,0,tok.GetToken());  
     }else if( tok.CheckToken("(") ) //here we have to check a lot of possibilitys
     {
         EvaluateExpression(tok,StateManager);
         
         if( !tok.CheckToken(")") )
                Error("Missing )",tok);
         
     }else if( tok.CheckToken("!") )
     {
          Primary(tok,StateManager);
          StateManager.AddInstruction(OP_NOT,0,"#");
     }
     else //check for a trigger name
     {
		 std::string ret = tok.GetToken();
         int i=GetTriggerType(ret.c_str(),tok);
                 
		 if ( i == OP_Vel - OP_Abs) 
		 {
			 if (tok.CheckToken("x"))
			 {
				 StateManager.AddInstruction(OP_Vel,1.0,"#");
			 }
			 else if  (tok.CheckToken("y"))
			 {
				 StateManager.AddInstruction(OP_Vel,0.0,"#");
			 }
		 }else if ( i == OP_Pos - OP_Abs) 
		 {
			 if (tok.CheckToken("x"))
			 {
				 StateManager.AddInstruction(OP_Pos,1.0,"#");
			 }
			 else if  (tok.CheckToken("y"))
			 {
				 StateManager.AddInstruction(OP_Pos,0.0,"#");
			 }
		 }
		 else if ( i == OP_Const - OP_Abs) 
		 {
			 if (!tok.CheckToken("("))
				 Error("Missing (",tok);

			 StateManager.AddInstruction(OP_Const,0.0,tok.GetToken());
			 if (!tok.CheckToken(")"))
				 Error("Missing )",tok);
		 }
		 else if ( i == OP_IfElse - OP_Abs) 
		 {
			 if (!tok.CheckToken("("))
				 Error("Missing (",tok);

			 EvaluateExpression(tok,StateManager);
			 if (!tok.CheckToken(","))
				 Error("Missing ,",tok);

			 Term(tok,StateManager);

			 if (!tok.CheckToken(","))
				 Error("Missing ,",tok);

			 Term(tok,StateManager);

			 StateManager.AddInstruction(OP_IfElse,0,"#");
			 if (!tok.CheckToken(")"))
				 Error("Missing )",tok);
		 }
		 else if (i == OP_StateType - OP_Abs)
		 {
			 if (!tok.CheckToken("="))
				 Error("Missing =",tok);
			 StateManager.AddInstruction(OP_StateType,0,tok.GetToken());
			 
		 }
		 else if (i == OP_GetHitVar - OP_Abs)
		 {
			 if (!tok.CheckToken("("))
				 Error("Missing (",tok);
			 StateManager.AddInstruction(OP_GetHitVar,0,tok.GetToken());
			 if (!tok.CheckToken(")"))
				 Error("Missing )",tok);
		 }
		 else
		 {
			 StateManager.AddInstruction(i+OP_Abs,0,"#");

		 }
      
     }
 
}


int CStateParser::GetControllerType(const char * strType,CTokenizer &tok)
{
    int i=0;
    while(strControllerTypes[i])
    {
       if(strcmpi(strType,strControllerTypes[i]) == 0)
          return i;       
          
       i++;
                                
    }
    Error(strType,tok);
   
    return -1;   
}

int CStateParser::GetTriggerType(const char * strTrigger,CTokenizer &tok)
{
    int i=0;
    while(strTriggerType[i])
    {
       if(strcmpi(strTrigger,strTriggerType[i]) == 0)
          return i;
          
          
       i++;   
                                
    }
    Error(strTrigger,tok);
       
    return -1;
    
}

//Parse a controller
void CStateParser::ParserController(CTokenizer &tok,CStateManager &StateManager,
                                    u16 nControllerType)
{
                                
     switch(nControllerType)
     {
        //ChangeState 
		case ChangeAnim:
			ParseChangeAnim(tok, StateManager);
			break;
        case ChangeState:
			ParseChangeState(tok,StateManager);   
			break;
		case VelSet:
			ParseVelSetState(tok,StateManager);   
			break;
                            
     }
}

void CStateParser::ParseVelSetState(CTokenizer &tok,CStateManager &StateManager)
{
	while( !tok.CheckToken("[", false) && !tok.AtEndOfFile() )
	{
		StateManager.NewInst();
		if( tok.CheckToken("y") )
		{
			if( !tok.CheckToken("=") )
				Error("expected =",tok);  

			EvaluateExpression(tok,StateManager);
		}else if( tok.CheckToken("x") )
		{
			if( !tok.CheckToken("=") )
				Error("expected =",tok);

			EvaluateExpression(tok,StateManager);  

		}else if (tok.CheckToken("persistent") ) 
		{
			if( !tok.CheckToken("=") )
				Error("expected =",tok);

			EvaluateExpression(tok,StateManager); 
		}
	}

	StateManager.NewInst(); 
}

void CStateParser::ParseChangeAnim(CTokenizer &tok,CStateManager &StateManager)
{
	CHANGEANIM *temp=(CHANGEANIM*) m_pAlloc->Alloc(sizeof(CHANGEANIM));
	//TODO:Check for Required parameters and print error msg
	while( !tok.CheckToken("[", false) && !tok.AtEndOfFile() )
	{
		StateManager.NewInst();
		if( tok.CheckToken("value") )
		{
			if( !tok.CheckToken("=") )
				Error("expected =",tok);  

			EvaluateExpression(tok,StateManager);
		}else if( tok.CheckToken("ctrl") )
		{
			if( !tok.CheckToken("=") )
				Error("expected =",tok);

			EvaluateExpression(tok,StateManager);  

		}else if ( tok.CheckToken("anim") )
		{
			if( !tok.CheckToken("=") )
				Error("expected =",tok); 

			EvaluateExpression(tok,StateManager); 

		}else if (tok.CheckToken("persistent"))
		{
			if( !tok.CheckToken("=") )
				Error("expected =",tok); 

			EvaluateExpression(tok,StateManager); 
		}            
	}

	StateManager.NewInst(); 
}

void CStateParser::ParseChangeState(CTokenizer &tok,CStateManager &StateManager)
{
     CHANGESTATE *temp=(CHANGESTATE*) m_pAlloc->Alloc(sizeof(CHANGESTATE));
     //TODO:Check for Required parameters and print error msg
     while( !tok.CheckToken("[", false) && !tok.AtEndOfFile() )
     {
             StateManager.NewInst();
            if( tok.CheckToken("value") )
            {
                if( !tok.CheckToken("=") )
                  Error("expected =",tok);  
                          
                EvaluateExpression(tok,StateManager);
            }else if( tok.CheckToken("ctrl") )
            {
                if( !tok.CheckToken("=") )
                  Error("expected =",tok);

                 EvaluateExpression(tok,StateManager);  
                  
            }else if ( tok.CheckToken("anim") )
            {
                 if( !tok.CheckToken("=") )
                  Error("expected =",tok); 
                  
                 EvaluateExpression(tok,StateManager); 
                  
            }            
     }

      StateManager.NewInst(); 
}
