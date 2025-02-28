#include "App.hpp"
#include "Bee.hpp"
#include "AppUtil.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"


float lastTime = 0.0f;

void App::Update() {

    // TODO: Add your own logics to finish the tasks in README.md
    glm::vec2 giraffePosition = m_Giraffe->GetPosition();
    /*
     *  Do not touch the code below as they serve the purpose for validating the tasks,
     *  rendering the frame, and exiting the game.
    */
    if (Util::Input::IsKeyPressed(Util::Keycode::UP)) {
        giraffePosition.y += 5;  // 向上移动
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::DOWN)) {
        giraffePosition.y -= 5;  // 向下移动
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::LEFT)) {
        giraffePosition.x -= 5;  // 向左移动
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::RIGHT)) {
        giraffePosition.x += 5;  // 向右移动
    }

    m_Giraffe->SetPosition(giraffePosition);

    if (giraffePosition.x < m_ChestPosition.x + m_ChestWidth &&
        giraffePosition.x + m_GiraffeWidth > m_ChestPosition.x &&
        giraffePosition.y < m_ChestPosition.y + m_ChestHeight &&
        giraffePosition.y + m_GiraffeHeight > m_ChestPosition.y) {
        m_ChestVisible = false;  // 隐藏箱子
        m_Chest->SetVisible(false);
        }

    for (size_t i = 0; i < m_Doors.size(); ++i) {
        // 先確認門是「可見」的，才進行碰撞檢測
        if (!m_Doors[i]->IsVisible()) {
            continue;
        }

        glm::vec2 doorPosition = m_Doors[i]->GetPosition();

        if (giraffePosition.x < doorPosition.x + m_DoorWidth &&
            giraffePosition.x + m_GiraffeWidth > doorPosition.x &&
            giraffePosition.y < doorPosition.y + m_DoorHeight &&
            giraffePosition.y + m_GiraffeHeight > doorPosition.y) {

            // 創建一個新的「開門」物件
            auto openDoor = std::make_shared<Character>(GA_RESOURCE_DIR"/Image/Character/door_open.png");
            openDoor->SetPosition(doorPosition);
            openDoor->SetZIndex(5);  // 確保門的圖層正確
            openDoor->SetVisible(true); // 確保新門也是可見的

            // 用新的「開門」物件替換原來的「關門」物件
            m_Root.RemoveChild(m_Doors[i]); // 移除舊門
            m_Doors[i] = openDoor;
            m_Root.AddChild(m_Doors[i]); // 加入新門
            }

    }


    if (m_Phase == Phase::COUNTDOWN && !hasExecuted) {
        m_Ball = std::make_shared<AnimatedCharacter>(ballFrames,true,false);
        m_Ball->SetZIndex(5);
        m_Ball->SetPosition({-112.5f, -140.5f});
        m_Ball->SetVisible(true);
        m_Root.AddChild(m_Ball);

        hasExecuted = true;
    }



    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }

    if (m_EnterDown) {
        if (!Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
            ValidTask();
        }
    }
    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    m_Root.Update();
}
