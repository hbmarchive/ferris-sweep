SendMode Input

#SingleInstance, Off
#Persistent

if ( ScriptInstanceExist() ) {
  ExitApp
}

GroupAdd, Explorer, ahk_class ExploreWClass
GroupAdd, Explorer, ahk_class CabinetWClass

; Select or start apps
+^!#1::SwitchTo("Chrome.exe", "chrome.exe")
+^!#2::SwitchTo("WindowsTerminal.exe", "wt.exe")
+^!#3::SwitchTo("Teams.exe", "teams.exe")
+^!#4::SwitchToExplorer()
+^!#5::SwitchTo("mstsc.exe", "mstsc.exe")
+^!#6::SwitchTo("Spotify.exe", "spotify.exe")

; Minimize window
+^!#m::
WinGetActiveTitle, title
WinMinimize, %title%
return

; Maximize window
+^!#j::
WinGetActiveTitle, title
WinGet, WinState, MinMax, %title%
If (WinState)
 WinRestore, %title%
else
 WinMaximize, %title%
return

; Close window
+^!#k::
WinGetActiveTitle, title
WinKill, %title%
return

; Switch to the app if it is running or launch it
SwitchTo(name, launch) {
  if ( WinExist("ahk_exe" name ) )
    WinActivate
  else
    Run, %launch%
}

; Switch to explorer if there are windows open or open one
SwitchToExplorer() {
  if WinExist("ahk_group Explorer") {
    WinGet, vWinList, List, ahk_group Explorer
    Loop, % vWinList
      WinActivate, % "ahk_id " vWinList%A_Index%
    ;WinRestore, ahk_group Explorer
    ;WinActivate, ahk_group Explorer
  } else {
    Run, explorer.exe
  }
}

; Detects whether this script is already running
ScriptInstanceExist() {
  static title := " - Shortcuts - AutoHotkey v" A_AhkVersion
  dhw := A_DetectHiddenWindows
  DetectHiddenWindows, On
  WinGet, match, List, % A_ScriptFullPath . title
  DetectHiddenWindows, % dhw
  return (match > 1)
}
