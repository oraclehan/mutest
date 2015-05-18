;-------------------------------------------------------------------
; Format:
; [Statedef STATENO]
; type = ?      S/C/A/L  stand/crouch/air/liedown
; movetype = ?  I/A/H    idle/attack/gethit
; physics = ?   S/C/A/N  stand/crouch/air/none
; juggle = ?             air juggle points move requires
;
; [State STATENO, ?]     ? - any number you choose
; type = ?
; ...

;-------------------------------------------------------------------
;Intro
[Statedef 190]
type = S
movetype = I
physics = S
anim = 190

[State 190,0]
type = AssertSpecial
trigger1 = RoundState = 0
trigger2 = RoundState = 1
flag = nobardisplay
flag2 = intro

[State 190,3]
type = PlaySnd
trigger1 = time = 10
value = 0,2
volume = 255

[State 190,4]
type = ChangeState
trigger1 = Animtime = 0;RoundState = 2
value = 0
ctrl = 1

;----------------------------------------
;Example Basic - Ground
[Statedef 200]
type = S
movetype = A
physics = S
anim = 200
ctrl = 0

[State 200, 2]
type = HitDef
trigger1 = AnimElem = 3
attr = S, NA
damage = 75,0;105,0
animtype = Light
guardflag = MA
hitflag = MAF
priority = 3, Hit 
pausetime = 12, 10
sparkno = 0
sparkxy = 5, -85
hitsound = s3, 4
guardsound = 6, 0
ground.type = High
ground.slidetime = 5
ground.hittime  = 10
ground.velocity = -4
airguard.velocity = -1.9,-.8
air.type = High
air.velocity = -1.4,-3 
air.hittime = 12 
getpower = 0,0

[State 200, add bar if not max]
type = PowerAdd
trigger1 = Movehit
trigger1 = Var(1) != 1
value = 60
persistent = 0

[State 200,3]
type = ChangeState
trigger1 = AnimTime = 0
value = 0
ctrl = 1



;----------------------------------------
;Example Crouching basic
[Statedef 300]
type = S
movetype = A
physics = C
anim = 300
ctrl = 0

[State 300, 2]
type = HitDef
trigger1 = AnimElem = 2
attr = S, NA
damage = 105,0
animtype = Light
guardflag = MA
hitflag = MAF
priority = 3, Hit 
pausetime = 12, 10
sparkno = 0
sparkxy = 5, -85
hitsound = s3, 4
guardsound = 6, 0
ground.type = Low
ground.slidetime = 5
ground.hittime  = 10
ground.velocity = -4
airguard.velocity = -1.9,-.8
air.type = High
air.velocity = -1.4,-3 
air.hittime = 12 
getpower = 0,0

[State 300, add bar if not max]
type = PowerAdd
trigger1 = Movehit
trigger1 = Var(1) != 1
value = 50
persistent = 0

[State 300,3]
type = ChangeState
trigger1 = AnimTime = 0
value = 11
ctrl = 1


;--------------------------
;Exceed - use any state number you want
[Statedef 1000]
type = S
movetype = A
physics = N
anim = 1000
ctrl = 0
velset = 0,0

[State 6001, pause]
type = SuperPause
trigger1 = time = 2
time = 30
anim = -1
sprpriority = 0
sound = s3,7
persistent = 1
darken = 0

[State 190,3]
type = PlaySnd
trigger1 = time = 1
value = 4,1
volume = 255

[State 6001, pause]
type = Explod
trigger1 = time = 2
anim = 16000
pos = 20,-45
postype = p1
supermovetime = 23
removetime = 23
sprpriority = 2

[State 6001, pause]
type = Explod
trigger1 = time = 2
anim = 17000
pos = -10,0 ;pos = 8,8 for original size
scale = 1.1,1.1 ;delete line if wish to use original size
postype = left
supermovetime = 22
removetime = 22
sprpriority = -2

[State 6001, pause]
type = EnvColor
trigger1 = time = 2
value = 0,0,0
time = 22
under = 1

[State 1000, pow]
type = PowerAdd
trigger1 = Movehit
value = 0
persistent = 1

[State 1000,3]
type = ChangeState
trigger1 = AnimTime = 0
value = 0
ctrl = 1

;--------------------------
;DM: Use any value you want
[Statedef 6000]
type = S
movetype = A
physics = S
anim = 0
ctrl = 0

[State 6001, pause]
type = SuperPause
trigger1 = time = 2
time = 32
anim = -1
sprpriority = 0
sound = s3,7
persistent = 1

[State 190,3]
type = PlaySnd
trigger1 = time = 2
value = 4,0
volume = 255

[State 6001, pause]
type = Explod
trigger1 = time = 2
anim = 15000
pos = 45,-90
postype = p1
supermovetime = 32
removetime = 32
sprpriority = -2

[State 6001, pause]
type = EnvColor
trigger1 = time = 2
value = 0,0,0
time = 32
under = 1

[State 6000, pow use if max]
type = PowerAdd
trigger1 = AnimElem = 1
trigger1 = var(1) = 1
value = -400
persistent = 1

[State 6000, pow use if normal]
type = PowerAdd
trigger1 = AnimElem = 1
trigger1 = var(1) != 1
value = -1000
persistent = 1

[State 6000, pow]
type = PowerAdd
trigger1 = Movehit
value = 0
persistent = 1

[State 6000,end]
type = ChangeState
trigger1 = AnimTime = 0
value = 0
ctrl = 1

;---------------------------------------------------------------------
; Override common states (use same number to override) :
;---------------------------------------------------------------------
; Jump Start
[Statedef 40]
type = S
physics = S
anim = 40
ctrl = 0
sprpriority = 1

[State 40, 1]
type = VarSet
trigger1 = Time = 0
sysvar(1) = 0

[State 40, 1]
type = VarSet
trigger1 = command = "hijump"
trigger2 = prevstateno=100 && command = "holdup"
var(2) = 1

[State 40, 2]
type = VarSet
trigger1 = command = "holdfwd"
sysvar(1) = 1

[State 40, 3]
type = VarSet
trigger1 = command = "holdback"
sysvar(1) = -1

[State 40, jump]
type = VelSet
trigger1 = AnimTime = 0 && !var(2)
x = ifelse(sysvar(1)=0, const(velocity.jump.neu.x), ifelse(sysvar(1) = 1, const(velocity.jump.fwd.x), const(velocity.jump.back.x)))
y = const(velocity.jump.y)

[State 40, hijump]
type = VelSet
trigger1 = AnimTime = 0 && var(2)
x = IfElse(sysvar(1)=0,0,IfElse(sysvar(1)=1,4,-4))
y = const(velocity.jump.y)

[State 40, 6]
type = ChangeState
trigger1 = AnimTime = 0
value = 50
ctrl = 1


; Jump Up
[Statedef 50]
type = A
physics = A

[State 50, AfterImage]
type = AfterImage
trigger1 = Time = 0 && var(2)
time = 12
timegap = 1
framegap = 2
length = 10
trans = none
;palcolor = 256
;palinvertall = 0
palbright = 0,0,0
palcontrast = 256,256,256
palpostbright = 0,0,0

[State 50, 1]
type = VarSet
trigger1 = Time = 0
sysvar(1) = 0

[State 50, reset]
type = VarSet
trigger1 = Time = 0
var(2) = 0

[State 50, 2]
type = ChangeAnim
trigger1 = Time = 0
value = ifelse((vel x)=0, 41, ifelse((vel x)>0, 42, 43))

[State 50, 3]
type = ChangeAnim
trigger1 = Vel y > -2
trigger1 = SelfAnimExist(anim + 3)
persistent = 0
value = Anim + 3

;---------------------------------------------------------------------
; States that are always executed (use statedef -2)
;---------------------------------------------------------------------

[Statedef -2]

;Enemy Taunts
[State -2, Taunt]
type = PowerAdd
trigger1 = (p2stateno = 195) && (enemy, statetime < 20)
trigger1 = var(1) != 1
value = 11

;Maximum Bar Code
[State -2, var]
type = VarSet
trigger1 = Power = 0
v = 1
value = 0
ignorehitpause = 1

[State -2, var]
type = VarSet
trigger1 = Power >= 3000
v = 1
value = 1
ignorehitpause = 1

[State -2, 2]
type = PowerAdd
trigger1 = var(1) = 1
trigger1 = stateno != [5000, 5101]
value = -1

[State -2, 2]
type = PowerAdd
trigger1 = var(1) = 1
trigger1 = stateno = [5000, 5101]
value = -2

[State -2, var]
type = VarSet
trigger1 = Power <= 2000
v = 1
value = 0
ignorehitpause = 1

;Exceed Use Code
[State -2, ex]
type = VarSet
trigger1 = Stateno = 1000
v = 51
value = 0
ignorehitpause = 1
persistent = 1

[State -2, ex]
type = VarSet
trigger1 = RoundNo = 1
trigger1 = RoundState = 0
v = 51
value = 1
ignorehitpause = 1

[State -2, Debug display]
trigger1 = 1
type = DisplayToClipboard
ignorehitpause = 1
text = "DIZZY VAR = %d GUARD CRUSH = %d"
params = var(13) , var(11)

;==================================================================================
; ------- DIZZY CODE --------
;===============================================
[State -2, reset Dizzy]
type = VarSet
trigger1 = RoundState = 0 || RoundState = 3 || (movetype = H &&  var(14) = 1 && stateno != 5250)
ignorehitpause = 1
var(13) = 0

[State -2, reset Dizzy]
type = VarSet
trigger1 = var(13) <= 0 && var(14) = 1
ignorehitpause = 1
var(14) = 0

[State -2, DIZZY CODE]
type = VarAdd
trigger1 = (var(13) = [1,999]) && movetype = H && enemy, hitdefattr = SCA, HA, HP
var(13) = -50
ignorehitpause = 1 

[State -2, DIZZY CODE]
type = VarAdd
trigger1 = (var(13) = [1,999]) && movetype = H && gethitvar(hitcount) >= 5 
var(13) = -20
ignorehitpause = 1 

[State -2, DIZZY CODE]
type = VarAdd
trigger1 = var(13) = [1,999]
var(13) = -1
ignorehitpause = 1 

[State -2, DIZZY CODE]
type = Varset
trigger1 = var(13) > 1000
var(13) = 1000
ignorehitpause = 1 
;----------------


;----------------------------------------------------------------------
; States that are executed when in self's state file (use statedef -3)
;----------------------------------------------------------------------

[Statedef -3]

[State -3, jump]
type = PlaySnd
triggerall = time = 1
trigger1 = StateNo = 50
value = 3,2
volume = 200

[State -3, dash]
type = PlaySnd
triggerall = time = 1
trigger1 = StateNo = 100
value = 3,4
volume = 200

[State -3, hop]
type = PlaySnd
triggerall = time = 1
trigger1 = StateNo = 105
value = 3,5
volume = 200

[State -3, land]
type = PlaySnd
triggerall = time = 1
trigger1 = StateNo = 52
trigger2 = StateNo = 106
value = 3,3
volume = 200

[State -3, land]
type = PlaySnd
triggerall = time = 1
trigger1 = StateNo = 150
trigger2 = StateNo = 152
trigger3 = StateNo = 154
value = 3,1
volume = 200

;----------------------------------------------------------------------------------------------
; State -3 / Guard Crush System / var(11) : Guard Crush Variable
;----------------------------------------------------------------------------------------------

[State -3, Light Hit Guard]
type = VarAdd
triggerall = var(11) > 0
trigger1 = stateno = 5001
trigger1 = anim = 5000
trigger2 = stateno = 5001
trigger2 = anim = 5010
trigger3 = stateno = 5011
trigger3 = anim = 5020 
persistent = 0
var(11) = -1
ignorehitpause = 1

[State -3, Medium Hit Guard]
type = VarAdd
triggerall = var(11) > 0
trigger1 = stateno = 5001
trigger1 = anim = 5001
trigger2 = stateno = 5001
trigger2 = anim = 5011
trigger3 = stateno = 5011
trigger3 = anim = 5021 
persistent = 0
var(11) = -3
ignorehitpause = 1

[State -3, Strong Hit Guard]
type = VarAdd
triggerall = var(11) > 0
trigger1 = stateno = 5001
trigger1 = anim = 5002
trigger2 = stateno = 5001
trigger2 = anim = 5012
trigger3 = stateno = 5011
trigger3 = anim = 5022 
persistent = 0
var(11) = -6
ignorehitpause = 1

[State -3, Fall Hit Guard]
type = VarAdd
trigger1 = var(11) > 0
trigger1 = PrevStateNo = 5050
persistent = 0
var(11) = -10
ignorehitpause = 1

[State -3, Special Add]
type = VarAdd ; Add when hitshaketime had at lease 15 ticks - Heavy Guard
triggerall = GetHitVar(hitshaketime) = 15
trigger1 = stateno = 150
trigger2 = stateno = 152
var(11) = 6
ignorehitpause = 1

[State -3, Special Add 2]
type = Varadd ; Add when hitshaketime had at lease 12 ticks - Medium Guard
triggerall = GetHitVar(hitshaketime) = 12
trigger1 = stateno = 150
trigger2 = stateno = 152
var(11) = 4
ignorehitpause = 1

[State -3, Special Add 3]
type = Varadd ; Add when hitshaketime had at lease 8 ticks - Light Guard
triggerall = GetHitVar(hitshaketime) = 8
trigger1 = stateno = 150
trigger2 = stateno = 152
var(11) = 2
ignorehitpause = 1

[State -3, Guard Crush]
type = ChangeState ; Change To Guard Crush When Var(11) Limits Are Reached.
trigger1 = var(11) >= 55
value = 9000
ctrl = 0
ignorehitpause = 1

;-------------------
;MEE Template Files
;   provided by
;  Kitsune Sniper
;       ***
; Thanks, Kitsune!
;-------------------
