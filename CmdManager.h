#ifndef __COMMAND_MANAGER__CMDMANAGER_H__
#define __COMMAND_MANAGER__CMDMANAGER_H__

//Tokenizer by Nate Pendelton

class CCmdManager
{
// To Get the Game time
CGameTimer *m_pTimer;     
public:
    CCmdManager( int keyBufferSize = 120 );
    ~CCmdManager();
    
    bool LoadCMDFile( const char* file);  // returns false upon load failure
    
    void Update(bool facingRight );
    
    const char* GetCurrentCommandName();
    
    void SetGameTimer(CGameTimer *t){m_pTimer=t;}

	void RegisterKeys(Uint16 sdl_code[]);
    
protected:
    PLCOMMAND* m_Commands;
    int m_CommandCount;  
    const char* m_CurrCommandName;

    //this is the Keyboard buffer
    PLCOMMANDFRAMEINPUT* m_KeyBuffer;
    short m_KeyBufferSize;
    short m_KeyIndex;

    inline int AdjustKeyIndex( int keyIndex, int increment )  
        { return ( keyIndex + increment + m_KeyBufferSize ) % m_KeyBufferSize; }

private:
	Uint16 GetKeyModOnRelease();
	Uint16 GetKeyMustBeHeld();	//PLC_KEY_MUST_BE_HELD
	Uint16 GetKeyModDetectAs4Way();// PLC_KEYMOD_DETECT_AS_4WAY
	Uint16 GetKeyModBanOtherInput(); //PLC_KEYMOD_BAN_OTHER_INPUT
	Uint16 GetAllDirectionsBitField();//PLC_ALL_DIRECTIONS_BITFIELD

	// 记录自己关心的键位
	Uint16 m_keyMap[KEY_COUNT];

	bool m_keyPressed[KEY_COUNT];


};

#endif

