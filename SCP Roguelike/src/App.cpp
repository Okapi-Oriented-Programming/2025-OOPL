#include "App.hpp"

#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"

void App::Start() {
    LOG_TRACE("Start");

    m_Player->SetZIndex(1);
    m_Hand->SetZIndex(2);
    m_Root.AddChild(m_Player);
    m_Root.AddChild(m_Hand);

    //Start Obj
    m_Player->Start();
    m_Hand->Start();

    m_CurrentState = State::UPDATE;
}

void App::Update() {
    
    m_Player->Update();
    m_Hand->Update();
    m_Root.Update();
    
    /*
     * Do not touch the code below as they serve the purpose for
     * closing the window.
     */
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }
}

void App::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
}
