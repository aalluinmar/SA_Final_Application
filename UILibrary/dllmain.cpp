// dllmain.cpp : Defines the entry point for the DLL application.
#include "framework.h"
class MyPanel : public emPanel {
public:
        MyPanel(ParentArg parent, const emString & name);
protected:
        virtual void Input(emInputEvent & event, const emInputState & state,
                           double mx, double my);
private:
        bool XKeyDown;
        bool ButtonDown;
        double LastMX, LastMY;
};

MyPanel::MyPanel(ParentArg parent, const emString & name)
        : emPanel(parent,name)
{
        XKeyDown=false;
        ButtonDown=false;
}

void MyPanel::Input(
        emInputEvent & event, const emInputState & state, double mx, double my
)
{
        if (event.IsKey(EM_KEY_E) && state.IsNoMod()) {
                emLog("The E key was pressed without any modifier keys.");
                event.Eat();
        }

        if (event.IsKey(EM_KEY_G) && state.IsShiftAltMod()) {
                emLog("The Shift+Alt+G key combination was pressed.");
                event.Eat();
        }

        emInputHotkey hotkey(EM_KEY_CTRL, EM_KEY_V);
        if (hotkey.Match(event,state)) {
                emLog("The %s key combination was pressed.", hotkey.GetString().Get());
                event.Eat();
        }

        if (event.GetChars()=="$") {
                emLog("A key combination that prints the dollar sign was pressed.");
                event.Eat();
        }

        if (event.IsKey(EM_KEY_X)) {
                emLog("The X key was pressed.");
                XKeyDown=true;
                event.Eat();
        }
        if (XKeyDown && !state.Get(EM_KEY_X)) {
                emLog("The X key was released.");
                XKeyDown=false;
        }

        if (event.IsKey(EM_KEY_LEFT_BUTTON)) {
                emLog("The left mouse button was pressed at (%g, %g).", mx, my);
                ButtonDown=true;
                LastMX=mx;
                LastMY=my;
                // We do not eat the event here so that emPanel::Input still
                // sets the focus on this panel by the button event. Otherwise
                // we should call Focus().
        }
        if (ButtonDown && (LastMX!=mx || LastMY!=mx)) {
                emLog("The mouse was dragged to (%g, %g).", mx, my);
                LastMX=mx;
                LastMY=my;
        }
        if (ButtonDown && !state.Get(EM_KEY_LEFT_BUTTON)) {
                emLog("The left mouse button was released.");
                ButtonDown=false;
        }

        // Call the base class. It changes the focus by certain input events.
        emPanel::Input(event,state,mx,my);
}
{
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
