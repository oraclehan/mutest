//    Open Mugen is a redevelopment of Elecbyte's M.U.G.E.N wich will be 100% compatible to it
//    Copyright (C) 2004  Sahin Vardar
//
//    If you know bugs or have a wish on Open Muegn or (money/girls/a car) for me ;-)
//    Feel free and email me: sahin_v@hotmail.com  ICQ:317502935
//    Web: http://openmugen.sourceforge.net/
//    --------------------------------------------------------------------------
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#include "Input.h"

//Constructor
CInput::CInput()
{

}
//Destructor
CInput::~CInput()
{

}
//Process InputData
void CInput::ProcessInput()
{
    Uint8 *keystate = SDL_GetKeyState(NULL);
    
	for(const auto& item : m_keyMap)
	{
		item.second(keystate[item.first]);
	}
}

CInput * CInput::GetInstance()
{
	static CInput *Instance = nullptr;
	if (!Instance)
	{
		Instance = new CInput;
	}
	return Instance;
}

void CInput::RegKeys( Uint16 key,const std::function<void(Uint8)> & func )
{
	if (m_keyMap.find(key) == m_keyMap.end())
	{
		m_keyMap[key] = func;
	}
	
}
