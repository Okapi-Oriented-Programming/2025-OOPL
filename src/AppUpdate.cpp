#include "App.hpp"
#include "AppUtil.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

void App::Update() {

    // TODO: Add your own logics to finish the tasks in README.md

    /*
     *  Do not touch the code below as they serve the purpose for validating the tasks,
     *  rendering the frame, and exiting the game.
    */
    if (Util::Input::IsKeyPressed(Util::Keycode::UP)) {
        m_Giraffe->SetPosition(m_Giraffe->GetPosition() + glm::vec2(0, 5)); // 向上移動
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::DOWN)) {
        m_Giraffe->SetPosition(m_Giraffe->GetPosition() + glm::vec2(0, -5)); // 向下移動
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::LEFT)) {
        m_Giraffe->SetPosition(m_Giraffe->GetPosition() + glm::vec2(-5, 0)); // 向左移動
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::RIGHT)) {
        m_Giraffe->SetPosition(m_Giraffe->GetPosition() + glm::vec2(5, 0)); // 向右移動
    }

    ValidTask();

    if (m_EnterDown) {
        if (!Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
            ValidTask();
        }
    }
    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    m_Root.Update();
}
